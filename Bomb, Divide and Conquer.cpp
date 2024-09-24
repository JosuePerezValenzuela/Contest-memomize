#include <iostream>
#include <vector>

using namespace std;

//Algoritmo Stoer_Wagner (Encontrar el corte minimo en un grafo no dirigido ponderado)
//Corte minimo => conjunto de aristas a eliminar que divide el grafo en 2 componenetes conexas, asi
//mismo el peso de eliminar todas las aristas es el minimo posible
struct Stoer_Wagner{
    vector <vector <long long>> pesos;//Grafo en forma de matriz

    //Constructor recibe N para definir que la matriz sera N x N
    Stoer_Wagner(long long N){
        pesos.resize(N, vector <long long> (N, 0));//Redimensiona para tener una matriz llena de 0
    }

    //Agregar una arista
    void AddEdge(long long desde, long long hasta, long long capacidad){
        pesos[desde][hasta] += capacidad;
        pesos[hasta][desde] += capacidad;
    }

    //Metodo para encontrar el corte minimo en el grafo, devuelve el (peso total del corte, vector con los nodos para formar el corte) 
    pair <long long, vector <long long>> getMinimoCorte(){
        long long N = pesos.size(); //Tam de la matriz
        vector <long long> usado(N), corte, mejorCorte;
        long long mejorPeso = -1;

        //Se debe iterar desde N-1 hasta 0, lo cual representa las fases del algoritmo Stoer_Wagner
        for (long long fase = N-1; fase >= 0; fase--){
            vector <long long> p = pesos[0];
            vector <long long> añadido = usado;
            long long anterior, ultimo = 0;
            for (long long i = 0; i < fase; i++){
                anterior = ultimo;
                ultimo = -1;
                for(long long j = 1; j < N; j++)
                if(!añadido[j] && (ultimo == -1 || p[j] > p[ultimo])) ultimo = j;
                  if(i == fase - 1){
                    for(long long j = 0; j < N; j++) pesos[anterior][j] += pesos[ultimo][j];
                    for(long long j = 0; j < N; j++) pesos[j][anterior] = pesos[anterior][j];
                    usado[ultimo] = true;
                    corte.push_back(ultimo);
                    if(mejorPeso == -1 || p[ultimo] < mejorPeso){
                        mejorCorte = corte;
                        mejorPeso = p[ultimo];
                    }
                  }else{
                    for(long long j = 0; j < N; j++)
                        p[j] += pesos[ultimo][j];
                    añadido[ultimo] = true; 
                  }
            }
        }
        return make_pair(mejorPeso, mejorCorte);
    }
};

int main(){
    long long N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        long long n, m;
        cin >> n >> m;
        Stoer_Wagner SW(n);
        for(int i = 0; i < m; i++ ){
            long long a, b, c;
            cin >> a >> b >> c;
            SW.AddEdge(a-1, b-1, c);
        }
        cout << "Case #" << i << ": " << SW.getMinimoCorte().first << endl;
    }
}
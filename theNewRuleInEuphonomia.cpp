#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

vector <int> primos;
int cantPrimos;

void encontradorPrimosEratostenes(){
    const int max = 1000000;
    vector<bool> marcadorPrimo(max, true);
    cantPrimos = 0;
    int limite = sqrt(max);
    for(int i = 2; i < limite; i++){
        if(marcadorPrimo[i] == true){
            for(int j = i * i ; j < max; j += i){
                marcadorPrimo[j] = false;
            }
        }
    }
    for(int i = 2; i <= max; i++){
        if(marcadorPrimo[i] == true){
            primos.push_back(i);
            cantPrimos++;
        }
    }
    
}

int buscador(int valor){
    int top, down, med;
    down = 0;
    top = cantPrimos;
    while(down <= top){
        med = down + ((top - down) / 2);
        if(valor == primos[med]){
            return med;
        }else if (valor > primos[med]){
            down = med + 1;
        }else{
            top = med - 1;
        }
    }
    return down;
}

int main(){
    int N, contador, i, j, caso;
    caso = 1;
    encontradorPrimosEratostenes();
    while((cin >> N) && N != 0){
        i = 0;
        contador = 0;
        while(primos[i] < N){
            j = buscador(N - primos[i]);
            while (i < j){
                if(primos[i] + primos[j] <= N){
                    contador += (j - i);
                    break;
                }
                j--;
            }
            i++;
        }
        cout << "Case " << caso << ": " << contador << "\n";
        caso++;
    }
    return 0;
}
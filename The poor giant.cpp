#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int matriz [502][502];

//Recorrido en profundidad (A fondo una rama y retrocedo), con memorizacion
int dfs(int n, int k){
    int &valor = matriz[n][k];
    if( valor != -1){ //Si ya tiene un valor asignado
        return valor;
    }
    if(n <= 1){//Caso base
        return 0;
    }
    int i, aux;
    valor = 16777215;
    //Bucle para calcular el costo aux
    for(i = 1; i <= n; i++){
        //Calculo sobre la manzana
        aux = n * (k + i) + dfs (i - 1, k) + dfs (n - i, k + i);
        //Nos quedamos con el valor minimo
        valor = min(valor, aux);
    }
    return valor;
}

int main(){
    memset(matriz, -1, sizeof(matriz));
    int t, n, k;
    int caso = 0;
    cin >> t;
    while(t--){
        cin >> n >> k;
        caso++;
        cout << "Case " << caso << ": " << dfs(n, k) << endl; 
    }
    return 0;
}
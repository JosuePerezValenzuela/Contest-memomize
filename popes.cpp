#include <bits/stdc++.h>
//Trae todoo lo necesario
using namespace std;

int main(){
    long long tiempo;
    while (cin >> tiempo){
        int n;
        cin >> n;
        long long lista[n];
        for (int i = 0; i < n; i++){
            long long leido;
            cin >> leido;
            lista[i] = leido;
        }
        long long resp = 0, pIni = 0, pFin = 0;
        for (int i = 0; i < n; i++){
            //lower_bound -> Iterdor del primer elemento en el rango que es mayor o igual al valor buscado (Lista [i])
            long long ini = lower_bound(lista, lista+n, lista[i]) - lista;
            //upper_bound -> Iterador del primer elemento en el rango que es estrictamente mayor al valor buscado
            long long fin = upper_bound(lista, lista+n, lista[i] + tiempo - 1) - lista;
            if(fin - ini > resp){//Mejore mi respuesta parcial?
                resp = fin - ini;
                pIni = lista[ini];
                pFin = lista[fin - 1];
            }
        }
        cout << resp << " " << pIni << " " << pFin << endl;
    }
}
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    int m, q;
    int cont = 1;
    while( cin >> m >> q && (m != 0 && q != 0)){
        int lista[m];
        int lista2[q];
        for(int i = 0; i < m; i++){
            cin >> lista[i];
        }
        for(int i = 0; i < q; i++){
            cin >> lista2[i];
        }
        sort(lista, lista + m);
        cout << "CASE# " << cont << ":" << endl;
        for(int i = 0; i < q; i++){
            int* pos = lower_bound(lista, lista + m, lista2[i]);
            if(pos != lista + m && *pos == lista2[i]){
                cout << lista2[i] << " found at " << pos - lista + 1 << endl;
            }else{
                cout << lista2[i] << " not found" << endl;
            }
        }
        cont++;
    }
}
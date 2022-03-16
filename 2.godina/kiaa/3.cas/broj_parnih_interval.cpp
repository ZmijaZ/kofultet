#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//pravimo stablo tako da ako je broj paran pisemo 1, inace 0

void napravi_stablo(vector<int>&niz, vector<int>&stablo, int i, int x, int y){
    
    if(x == y){
        
        if(niz[x] % 2 == 0)
            stablo[i] = 1;
        else
            stablo[i] = 0;
        return;
    }
    
    int s = (x+y)/2;

    napravi_stablo(niz, stablo, 2*i, x, s);
    napravi_stablo(niz, stablo, 2*i+1, s+1, y);
    
    stablo[i] = stablo[2*i] + stablo[2*i+1];
}

//suma segmenta prethodno napravljenog stabla (sa parnim indikatorima) ce dati broj parnih na istom segmentu

int suma_segmenta(vector<int>&stablo, int i, int x, int y, int a, int b){
    
    if(x > b || y < a)
        return 0;
    
    if(x >= a && y <=b)
        return stablo[i];
    
    int s = (x+y)/2;
    
    return suma_segmenta(stablo, i*2, x, s, a, b) + suma_segmenta(stablo, i*2+1, s+1, y, a, b);
    
}

int main(){

    int n;
    cin >> n;
    vector<int>niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<int>stablo(velicina);
    
    napravi_stablo(niz, stablo, 1, 0, n-1);
    
    for(int x : stablo)
        cout << x << " ";
    cout << '\n';
    
    int a, b;
    cin >> a >> b;
    
    cout << suma_segmenta(stablo, 1, 0, n-1, a, b) << '\n';
    
    cout << '\n';
    
    return 0;    
}

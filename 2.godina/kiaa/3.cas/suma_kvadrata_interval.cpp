#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void napravi_stablo(vector<int>&niz, vector<int>&stablo, int x, int y, int i){
    
    if(x == y){
        stablo[i] = niz[x]*niz[x];
        return;
    }
    
    int s = (x+y)/2;
    
    napravi_stablo(niz, stablo, x, s, 2*i);
    napravi_stablo(niz, stablo, s+1, y, 2*i+1);
    
    stablo[i] = stablo[i*2] + stablo[i*2+1];
    
}

int zbir_segmenta(vector<int>&stablo, int x, int y, int a, int b, int i){
    
    if(y < a || x > b)
        return 0;
    
    if(x >= a && y <= b)
        return stablo[i];
    
    int s = (x+y)/2;
    
    return zbir_segmenta(stablo, x, s, a, b, 2*i) + zbir_segmenta(stablo, s+1, y, a, b, 2*i+1);
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
    
    cout << zbir_segmenta(stablo, 1, 0, n-1, a, b) << '\n';
    
    cout << '\n';
    
    return 0;    
}

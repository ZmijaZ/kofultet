#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void napravi_stablo(vector<int> &niz, vector<int> &stablo, int n){
    
    copy_n(niz.begin(), n, stablo.begin() + n);
    
    for(int i = n-1; i >= 1; i--)
        stablo[i] = stablo[i*2] + stablo[i*2+1];
}

int suma_segmenta(vector<int> &stablo, int x, int y, int a, int b, int i){
    
    if(x > b || y < a)
        return 0;
    
    if(x >= a && y <= b)
        return stablo[i];
    
    int s = (x + y)/2;
    
    return suma_segmenta(stablo, x, s, a, b, 2*i) + suma_segmenta(stablo, s+1, y, a, b, 2*i+1);
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
    
    napravi_stablo(niz, stablo, n);
    
    for(int x : stablo)
        cout << x << " ";
    cout << '\n';
    
    int a, b;
    cin >> a >> b;
    
    cout << suma_segmenta(stablo, 0, n-1, a, b, 1) << '\n';
    
    cout << '\n';
    
    return 0;    
}

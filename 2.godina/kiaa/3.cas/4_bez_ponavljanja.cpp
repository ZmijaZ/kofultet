#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void napravi_stablo(vector<int>&stablo, int x, int y, int i, int index){
    
    if(x == y){
        stablo[i] = 1;
        return;
    }
    
    int s = (x+y)/2;
    
    if(index <= s)
        napravi_stablo(stablo, x, s, 2*i, index);
    else
        napravi_stablo(stablo, s+1, y, 2*i+1, index);
    
    stablo[i] = stablo[2*i] + stablo[2*i+1];
}

int inverzije(vector<int>&stablo, int x, int y, int a, int b, int i){
    
    if(x > b || y < a)
        return 0;
    
    if(x >= a && y <=b)
        return stablo[i];
    
    int s = (x+y)/2;
    
    return inverzije(stablo, x, s, a, b, 2*i) + inverzije(stablo, s+1, y, a, b, 2*i+1);
}

int main(){
    
    int n;
    cin >> n;
    vector<int>niz(n);
    
    int maks = 0;
    for(int i = 0; i<n; i++){
        cin >> niz[i];
        maks = max(maks, niz[i]);
    }
    
    int visina = ceil(log2(maks));
    int velicina = 2*pow(2, visina);
    
    vector<int>stablo(velicina);
    
    fill(stablo.begin(), stablo.end(), 0);
    
    int resenje = 0;
    
    for(int i = 0; i<n; i++){
        
        resenje += inverzije(stablo, 1, maks, niz[i] + 1, maks, 1);
        
        napravi_stablo(stablo, 1, maks, 1, niz[i]);
        
    }
    
    cout << resenje << '\n';
    
    return 0;
}

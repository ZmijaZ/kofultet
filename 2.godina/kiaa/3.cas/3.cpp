#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void napravi_stablo(vector<int>&niz, vector<int>&stablo, int n){
    
    copy_n(niz.begin(), n, stablo.begin() + n);
    
    for(int i = n-1; i>=1; i--)
        stablo[i] = stablo[2*i] + stablo[2*i+1];
}

void azuriraj_stablo(vector<int>&stablo, int i, int x, int y, int index, int broj){
    
    if(x == y){
        stablo[i] = broj;
        return;
    }
    
    int s = (x+y)/2;
    
    if(index <= s)
        azuriraj_stablo(stablo, 2*i, x, s, index, broj);
    else
        azuriraj_stablo(stablo, 2*i+1, s+1, y, index, broj);
    
    stablo[i] = stablo[2*i] + stablo[2*i+1];
    
}

int main(){
    
    int n;
    cin >> n;
    vector<int>niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<int> stablo(velicina);
    
    napravi_stablo(niz, stablo, n);
    for(int x : stablo)
        cout << x << " ";
    cout << '\n';
    
    int index, broj;
    cin >> index >> broj;
    
    azuriraj_stablo(stablo, 1, 0, n-1, index, broj);
    
    for(int x : stablo)
        cout << x << " ";
    cout << '\n';
    
    return 0;
}

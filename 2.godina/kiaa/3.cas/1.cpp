#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void napravi_segmentno_stablo_iterativno(vector<int>&niz, vector<int>&stablo, int n){
    
    copy_n(niz.begin(), n, stablo.begin() + n);
    
    for(int i = n-1; i >= 1; i--)
        stablo[i] = stablo[2*i] + stablo[2*i+1];
}

void napravi_segmentno_stablo_rekurzivno(vector<int>&niz, vector<int>&stablo, int i, int l, int d){
    
    if(l == d){
        stablo[i] = niz[l];
        return;
    }
    
    int s = (l+d)/2;
    
    napravi_segmentno_stablo_rekurzivno(niz, stablo, 2*i+1, l, s);
    napravi_segmentno_stablo_rekurzivno(niz, stablo, 2*i+2, s+1, d);
    
    stablo[i] = stablo[2*i+1] + stablo[2*i+2];
}

int main(){
    
    int n;
    cin >> n;
    vector<int>niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    int visina = ceil(log2(n));
    int velicina = 2 * pow(2, visina);
    
    vector<int> stablo(velicina);
    
    napravi_segmentno_stablo_iterativno(niz, stablo, n);
    
    for(int x : stablo)
        cout << x << " ";
    
    cout << '\n';
    
    return 0;
}

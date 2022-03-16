#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void napravi_drvo(vector<int>&niz, vector<int>&stablo, int x, int y, int k){
    
    if(x == y){
        stablo[k] = niz[x];
        return;
    }
    
    int s = x + (y-x)/2;
    
    napravi_drvo(niz, stablo, x, s, 2*k);
    napravi_drvo(niz, stablo, s+1, y, 2*k+1);
    
    stablo[k] = stablo[2*k] + stablo[2*k+1];
}

int suma_segmenta(vector<int>&niz, vector<int>&stablo, int x, int y, int a, int b, int k){
    
    if(x > b || y < a)
        return 0;
    if(x >= a && y <=b)
        return stablo[k];
    
    int s = x + (y-x)/2;
    
    return suma_segmenta(niz, stablo, x, s, a, b, 2*k) + suma_segmenta(niz, stablo, s+1, y, a, b, 2*k+1);
    
}

void azuriraj(vector<int>&niz, vector<int>&stablo, int x, int y, int vrednost, int indeks, int k){
    
    if(x == y){
        stablo[k] = vrednost;
        return;
    }
    
    int s = x + (y-x)/2;
    
    if(indeks > s)
        azuriraj(niz, stablo, s+1, y, vrednost, indeks, 2*k);
    else
        azuriraj(niz, stablo, x, s, vrednost, indeks, 2*k+1);
    
    stablo[k] = stablo[2*k] + stablo[2*k+1];
    
}

int main(){
    
    int n;
    cin >> n;
    vector<int>niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    int visina = floor(log2(n));
    int velicina = 2*pow(2, visina);
    vector<int>stablo(velicina);
    
    napravi_drvo(niz, stablo, 0, n-1, 1);

    for(int i = 0; i<velicina; i++)
        cout << stablo[i] << " ";
    cout <<'\n';
    
    int a, b;
    cin >> a >> b;
    cout <<'\n';
    
    azuriraj(niz, stablo, 0, n-1, a, b, 1);
    for(int i = 0; i<velicina; i++)
        cout << stablo[i] << " ";
    cout <<'\n';
    
    return 0;
}

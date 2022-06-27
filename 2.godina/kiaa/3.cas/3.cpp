#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void napravi_stablo(vector<int>&niz, vector<int>&stablo, int l, int d, int k){

    if(l == d){
        stablo[k] = niz[l];
        return;
    }

    int s = l + (d-l)/2;

    napravi_stablo(niz, stablo, l, s, 2*k);
    napravi_stablo(niz, stablo, s+1, d, 2*k+1);

    stablo[k] = stablo[2*k] + stablo[2*k+1];
}

void azuriraj_stablo(vector<int>&stablo, int l, int d, int indeks, int vrednost, int k){

    if(l == d){
        stablo[k] = vrednost;
        return;
    }

    int s = l + (d-l)/2;

    if(indeks <= s)
        azuriraj_stablo(stablo, l, s, indeks, vrednost, 2*k);
    else
        azuriraj_stablo(stablo, s+1, d, indeks, vrednost, 2*k+1);

    stablo[k] = stablo[2*k+1] + stablo[2*k];
}

int main(){

    cout << "Koliko brojeva se nalazi u nizu? ";
    int n;
    cin >> n;

    vector<int>niz(n);
    cout << "Koji su to brojevi? ";
    for(int i = 0; i<n; i++)
        cin >> niz[i];

    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);

    vector<int>stablo(velicina);
    napravi_stablo(niz, stablo, 0, n-1, 1);

    cout << "Stablo ima oblik: \n";
    for(int x : stablo)
        cout << x << " ";
    cout << '\n';

    cout << "Koja pozicija se menja, cime? ";
    int indeks, vrednost;
    cin >> indeks >> vrednost;

    azuriraj_stablo(stablo, 0, n-1, indeks, vrednost, 1);

    cout << "Stablo ima oblik: \n";
    for(int x : stablo)
        cout << x << " ";

    cout << '\n';

    return 0;
}

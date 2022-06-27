#include <iostream>
#include <vector>
#include <cmath>

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

void azuriraj_stablo(vector<int>&niz, vector<int>&stablo, int l, int d, int indeks, int vrednost, int k){

    if(l == d){
        stablo[k] = vrednost;
        return;
    }

    int s = l + (d-l)/2;

    if(indeks <= s)
        azuriraj_stablo(niz, stablo, l, s, indeks, vrednost, 2*k);
    else
        azuriraj_stablo(niz, stablo, s+1, d, indeks, vrednost, 2*k+1);

    stablo[k] = stablo[2*k] + stablo[2*k+1];
}

void napravi_stablo_veceg(vector<int>&niz, vector<int>&stablo, int l, int d, int k, int x){

    if(l == d){
        if(niz[l] > x)
            stablo[k] = 1;
        else
            stablo[k] = 0;
        return;
    }

    int s = l + (d-l)/2;

    napravi_stablo_veceg(niz, stablo, l, s, 2*k, x);
    napravi_stablo_veceg(niz, stablo, s+1, d, 2*k+1, x);

    stablo[k] = stablo[2*k] + stablo[2*k+1];

}

int suma_segmenta(vector<int>&niz, vector<int>&stablo, int l, int d, int a, int b, int k){

    if(a > d || b < l)
        return 0;

    if(a>=l && b<=d)
        return stablo[k];

    int s = l + (d-l)/2;

    return suma_segmenta(niz, stablo, l, s, a, b, 2*k) + suma_segmenta(niz, stablo, s+1, d, a, b, 2*k+1);
}

int main(){

    int n, q, x;
    cin >> n >> q >> x;

    vector<int>niz(n);

    for(int i = 0; i<n; i++)
        cin >> niz[i];

    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);

    vector<int>stablo(velicina);



    for(int i = 0; i<q; i++){

        int indeks, vrednost, a, b;
        cin >> indeks >> vrednost >> a >> b;

        vector<int>pomocno(velicina);

        napravi_stablo_veceg(niz, pomocno, 0, n-1, 1, x);

        napravi_stablo(niz, stablo, 0, n-1, 1);

        for(int i = 0; i<velicina; i++)
            cout << stablo[i] << " ";
        cout << '\n';

        for(int i = 0; i<velicina; i++)
            cout << pomocno[i] << " ";
        cout << '\n';






    }





    return 0;
}

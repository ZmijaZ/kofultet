#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void napravi_stablo_rekurzivno(vector<int>&niz, vector<int>&stablo, int l, int d, int k){

    if(l == d){
        stablo[k] = niz[l];
        return;
    }

    int s = l + (d-l)/2;

    napravi_stablo_rekurzivno(niz, stablo, l, s, 2*k);
    napravi_stablo_rekurzivno(niz, stablo, s+1, d, 2*k+1);

    stablo[k] = stablo[2*k] + stablo[2*k+1];
}

void napravi_stablo_iterativno(vector<int>&niz, vector<int>&stablo, int n){

    copy_n(niz.begin(), n, stablo.begin() + n);

    for(int k = n-1; k>=1; k--)
        stablo[k] = stablo[2*k] + stablo[2*k+1];

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
    napravi_stablo_rekurzivno(niz, stablo, 0, n-1, 1);

    cout << "Stablo ima oblik: \n";
    for(int x : stablo)
        cout << x << " ";

    cout << '\n';

    return 0;
}

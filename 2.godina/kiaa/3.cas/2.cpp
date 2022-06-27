#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void napravi_stablo(vector<int> &niz, vector<int> &stablo, int l, int d, int k){

    if(l == d){
        stablo[k] = niz[l];
        return;
    }

    int s = l + (d-l)/2;

    napravi_stablo(niz, stablo, l, s, 2*k);
    napravi_stablo(niz, stablo, s+1, d, 2*k+1);

    stablo[k] = stablo[2*k+1] + stablo[2*k];

}

int zbir_segmenta(vector<int>&niz, vector<int>&stablo, int l, int d, int a, int b, int k){

    if(a > d || b < l)
        return 0;
    if(l >= a && d <= b)
        return stablo[k];

    int s = l + (d-l)/2;

    return zbir_segmenta(niz, stablo, l, s, a, b, 2*k) + zbir_segmenta(niz, stablo, s+1, d, a, b, 2*k+1);

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
    int velicina = 2*(pow(2, visina));

    vector<int>stablo(velicina);

    napravi_stablo(niz, stablo, 0, n-1, 1);
    cout << "Stablo ima oblik: \n";
    for(int x : stablo)
        cout << x << " ";
    cout << '\n';

    cout << "Zbir kog segmenta se trazi? ";
    int a, b;
    cin >> a >> b;
    int zbir = zbir_segmenta(niz, stablo, 0, n-1, a, b, 1);

    cout << "Zbir od " << a << " do " << b << " je: " << zbir;
    cout << '\n';

    return 0;
}

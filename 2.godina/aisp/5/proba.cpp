#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool najveci (int k, int x, vector <int>&niz, int n){
    k--;
    int prethodni = niz[0];
    
    for(int i = 1; i<n && k>0; i++){
        if(niz[i] - prethodni >= x){
            k--;
            prethodni = niz[i];
        }
    }
    return k == 0;
}

int main(){
        
    int k;
    cin >> k;
    
    int n;
    cin >> n;
    vector <int> niz(n);
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    sort(begin(niz), end(niz));
    
    int l = 1;
    int d = niz[n-1];
    int resenje = -1;
    
    while(l<=d){
        if(najveci(k, s, niz, n)){
            resenje = s;
            l = s+1;
        }
        else
            d = s-1;
    }
        
    cout << resenje << '\n';
    return 0;
}

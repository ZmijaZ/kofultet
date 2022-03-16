#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool najveciBroj(int x, int k, int n, vector<int>&niz){
    k--;
    int prethodna = niz[0];
    
    for(int i = 0; i<n && k>0; i++){
        if(niz[i] - prethodna >= x){
            k--;
            prethodna = niz[i];
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
    
    int l = 1, d = niz[n-1];
    int resenje = -1;
    
    while(l<=d){
        int s = l+ (d-l)/2;
        if(najveciBroj(s, k, n, niz)){
            l = s+1;
            resenje = s;
        }
        else
            d = s-1;
            
        }
        
    cout << resenje << '\n';
    return 0;
}

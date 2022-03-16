#include <iostream>
#include <vector>

using namespace std;

// mora long long zbog test primera

int binarna(int l, int d, vector<long long> a, long long x){
       while(l <= d){
        int s = l+(d-l)/2;
        
        if(a[s] % x == 0)
            l = s+1;
        else
            d = s-1;
    }
    return l;
}

int main(){

    int n;
    cin >> n;
    
    vector<long long> niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    long long k;
    while(cin >> k){
        int l = 0;
        int d = n-1;
        cout << binarna(l, d, niz, k) << '\n';
    }
    
return 0;
}

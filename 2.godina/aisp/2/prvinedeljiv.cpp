#include <iostream>
#include <vector>

using namespace std;

int binarna(int l, int d, vector <int> a, int k){

    while(l<d){
        int s = l+(d-l)/2;
        
        if(a[s] % k == 0)
            l = s+1;
        else
            d = s-1;
    }
    return l;
}

int main(){
    int n;
    cin >> n;
    
    vector <int> niz (n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    int l = 0; int d= n-1;
    
    int k;
    while(cin >> k)
        cout << binarna(l, d, niz, k) << '\n';

return 0;
}

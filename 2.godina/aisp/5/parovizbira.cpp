#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int x;
    cin >> x;
    
    int n;
    cin >> n;
    vector <int> niz(n);
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    sort(begin(niz), end(niz));
    
    int l = 0;
    int d = n-1;
    int brojac = 0;
    
    while(l<d){
        if( (niz[l] + niz[d]) == x){
            brojac++;
            l++;
            d--;
        }
        else if(niz[l] + niz[d] < x) 
            l++;
        else if(niz[l] + niz[d] > x)
            d--;
    }
    
    cout << brojac << '\n';
    
    return 0;
}

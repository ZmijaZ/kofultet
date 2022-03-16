#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int s;
    cin >> s;
    
    int n;
    cin >> n;
    vector<int> niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    sort(begin(niz), end(niz));
    
    int l = 0;
    int d = n-1;
    
    int brojac = 0;
    
    while(l < d){
        if(niz[l] + niz[d] == s){
            brojac++;
            l++;
            d--;
        }
        else if(niz[l] + niz[d] > s)
            d--;
        else
            l++;
    }
    cout << brojac << '\n';
    return 0;
}

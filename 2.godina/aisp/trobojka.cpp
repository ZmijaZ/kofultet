#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> niz(n);
    
    for(int i = 0; i<n; i++)
       cin >> niz[i];
    
    int x, y;
    cin >> x;
    cin >> y;
    
    int l = 0;
    int d = n;
    int i = 0;
    while(i<d){
        if(niz[i] < x){
           swap(niz[i], niz[l]);
           l++;
           i++;
        }
        else if(niz[i] <= y)
            i++;
        else{
            d--;
            swap(niz[i], niz[d]);
        }
    }
    i = 0;
    while(niz[i] < x){
        cout << niz[i] << ' ';
        i++;
    }
        cout << '\n';
    while(niz[i] <= y){
        cout << niz[i] << ' ';
        i++;
    }
        cout << '\n';
    while(i < n){
        cout << niz[i] << ' ';
        i++;
    }
        cout << '\n';
    
return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarna(int x, int n, vector<int>a){
    
    int l = 0;
    int d = n-1;
    while(l <= d){
        int s = l + (d-l)/2;
        if(a[s] >= x && a[s+1] < x)
            return s+1;
        if(a[s] >= x && a[s+1] >=x){
            if(l != n-1)
                l = s+1;
            else
                return s+1;
        }
        if(a[s] < x)
            d = s-1;
    }
    
    return 0;
}

int main(){
    int n;
    cin >> n;
    
    vector <int> bodovi(n);
    for(int i = 0; i<n; i++)
        cin >> bodovi[i];
    
    
    int m;
    cin >> m;

    vector <int>prag(m);
       
    for(int i = 0; i<m; i++)
        cin >> prag[i];
    
    
    for(int i = 0; i<m; i++)
            cout << binarna(prag[i], n, bodovi) << "\n";
    return 0;
}

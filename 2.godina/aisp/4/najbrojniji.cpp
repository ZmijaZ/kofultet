#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector <string> niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
        
    sort(begin(niz), end(niz));
    
    int brojac = 1;
    int max = 1;
    
    for(int i = 1; i<n; i++){
        if(niz[i-1] == niz[i]){
            brojac++;
            if(brojac > max)
                max = brojac;
        }
        else
            brojac = 1;
    }
    
    cout << max << '\n';
    
    return 0;
}

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
    
    sort(begin(niz), end(niz));
    
    auto it = unique(begin(niz), end(niz));
    niz.erase(it, end(niz));
    
    n = niz.size();
    
    int max = 1;
    int brojac = 1;
    int pocetak = 0;
    int maxPocetak = 0;
    
    for(int i = 0; i<n; i++){
        if(niz[i] - niz[i-1] == 1){
            brojac++;
            if(brojac > max){
                max = brojac;
                maxPocetak = pocetak;
            }
        }
        else{
            pocetak = i;
            brojac = 1;
            }
        
    }
    
    for(int i = maxPocetak; i<maxPocetak + max; i++)
        cout << niz[i] << '\n';
        
    return 0;
}

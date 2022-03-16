#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> niz(n);
    
    for(int i=0; i<n; i++)
        cin >> niz[i];
    
    int zbir = niz[0];
    for(int i = 0; i<n; i++){
        if(niz[i] > zbir)
            break;
        
        zbir+=niz[i];
        
    }
        cout << zbir++ << '\n';
    return 0;
}

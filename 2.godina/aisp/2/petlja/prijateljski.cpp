#include <iostream>

using namespace std;

int64_t zbirDelioca(int64_t n){
    
    int64_t suma = 0;
    
    for(int64_t i = 1; i<=n/2; i++)
        if(n%i == 0)
            suma+=i;
    return suma;
}

int main(){
    
    int64_t n, m;
    cin >> n >> m;
    
    for(int64_t i = n; i<=m; i++){
        if(zbirDelioca(i) == i)
            cout << zbirDelioca(i) << '\n';
    }
    return 0;
}

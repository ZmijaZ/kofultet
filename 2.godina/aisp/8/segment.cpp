#include <iostream>
#include <map>

using namespace std;

int main(){
    
    int z, n, x;
    cin >> z >> n;
    
    map <int, int> brPrefiksa;
    brPrefiksa[0] = 1;
    int suma = 0, brojac = 0;
    
    while(n){
        
        cin >> x;
        suma += x;
        brojac += brPrefiksa[suma - z];
        brPrefiksa[suma]++;
        
        
        n--;
    }
    cout << brojac << '\n';
    return 0;
}

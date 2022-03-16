#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int max = n*(n+1)/2;
    
    int i;
    int suma = 0;
    while(n){
        cin >> i;
        suma+=i;
        n--;
    }
    
    cout << max-suma << '\n';
    return 0;
}

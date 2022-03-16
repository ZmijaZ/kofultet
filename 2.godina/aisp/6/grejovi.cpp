#include <iostream>

using namespace std;

string grejov_kod(unsigned n, unsigned k){
    
    string zapis = "";
    
    while(n){
        if(k < (1u << (n-1)))
            zapis+="0";
        else{
            zapis+="1";
            k = (1u << n) - 1 - k;
        }
        n--;
    }
    
    return zapis;
}

int main(){
    
    unsigned n, k;
    cin >> n >> k;
    
    cout << grejov_kod(n, k) << '\n';
    
    return 0;
}

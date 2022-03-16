#include <iostream>

using namespace std;

string grejov_kod(unsigned n, unsigned k){
    if (n == 0)
        return "";
    if(k < (1u << (n-1)))
        return "0" + grejov_kod(n-1, k);
    else
        return "1" + grejov_kod(n-1, (1u<<n) -1-k);
    
    
}

int main(){
    unsigned n, k;
    cin >> n >> k;
    
    cout << grejov_kod(n,k) <<'\n';
    
    return 0;
}

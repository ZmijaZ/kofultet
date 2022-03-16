#include <iostream>

using namespace std;

unsigned long long euklid(unsigned long long a, unsigned long long b){
    while(b){
        int nzd = a%b;
        a = b;
        b = nzd;
    }
    return a;
}


int main(){
    
    unsigned long long m;
    unsigned long long p;
    unsigned long long k;
    
    cin >> m;
    cin >> p;
    cin >> k;
    unsigned long long res = euklid(euklid(p,m), k);

    cout << res << '\n';
    
    return 0;
}

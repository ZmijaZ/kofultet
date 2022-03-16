#include <iostream>

using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    int l, d;
    if(n == 0)
        l = 0;
    else
        l = n-(n%k);
    if(n%k == 0)
        d = n;
    else
        d = n + (k - (n%k));
    
    cout << l << '\n';
    cout << d << '\n';
    
    return 0;
}

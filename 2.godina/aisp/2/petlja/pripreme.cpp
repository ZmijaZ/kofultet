#include <iostream>
#include <iomanip>

using namespace std;

int main(){
        
    int n;
    cin >> n;
    
    double p, d;
    
    while(cin >> p >> d)
        cout << n/2*(2*p + (n-1)*d)/1000 << setprecision(3) << '\n';
    
    return 0;
}

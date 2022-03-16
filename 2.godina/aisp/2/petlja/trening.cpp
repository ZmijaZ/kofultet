#include <iostream>
#include <iomanip>

using namespace std;

int main(){
        
    int n;
    cin >> n;
    
    int p, d;
    
    while(cin >> p >> d)
        cout << p + (n-1)*d << '\n';
    
    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int64_t a, b, c;
    cin >> a >> b >> c;
    
    if (a > b) swap(a, b);
    
    int64_t rez;
    
    if(b-a >= c)
        rez = (a+c)*b;
    else{
        int64_t preostalo = c- (b-a);
        a = b + preostalo/2;
        b = b + (preostalo+1)/2;
        
        rez = a*b;
    }
    cout << rez << '\n';
    return 0;
}

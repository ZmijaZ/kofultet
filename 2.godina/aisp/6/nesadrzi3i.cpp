#include <iostream>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int brojBez3 = 1;
    int devetke = 1;
    
    while(n){
        int c = n%10;
        if(c<3)
            brojBez3 = c*devetke + brojBez3;
        else if(c == 3)
            brojBez3 = c*devetke;
        else
            brojBez3 = (c-1)*devetke + brojBez3;
        devetke*=9;
        n/=10;
    }
    
    cout << brojBez3 << '\n';
    
    return 0;
}

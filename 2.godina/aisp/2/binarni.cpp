#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    string s;
    
    while(n){
        if(n%2 == 0)
            s = "0" + s;
        else
            s = "1" + s;
        n/=2;
    }
    
    while(32 - s.length())
        s = '0' + s;
    
    cout << s<< '\n';

return 0;
}

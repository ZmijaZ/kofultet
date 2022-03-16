#include <iostream>

using namespace std;

int main(){
    int n;
    long long broj = 0;
    int i = 1;
    while(cin >> n && i<9){
        broj*=10;
        broj+=n;
        i++;
    }
    cout << broj << '\n';
    
return 0;
}

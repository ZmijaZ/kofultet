#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i;
    double m = sqrt(n);
        while(n%2 == 0){
            cout << 2 << ' ';
                n/=2;
        }
        
        for(i = 3; i<=m; i++){
            while(n%i == 0){
                cout << i << ' ';
                n/=i;
            }
        }

    if(n>2)
        cout << n;

    
    cout << '\n';
return 0;
}

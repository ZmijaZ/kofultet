#include <iostream>

//JOS UVEK NISAM SAM URADIO ! ! !

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int broj_nacina = 0;

    for(int m = 2; m+m*(m-1)/2 <=n; m++)
        if((n-m*(m-1)/2)%m == 0)
            broj_nacina++;
            
    cout << broj_nacina << '\n';

return 0;
}

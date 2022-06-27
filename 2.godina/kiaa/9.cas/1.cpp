#include <iostream>

using namespace std;

int mod(int a, int m){

    if(a < 0)
        return (m + a % m) % m;
    return a % m;
}

int zbir(int a, int b, int m){

    return (a + b) % m;

}

int razlika(int a, int b, int m){

    return (m + a-b) % m;
}

int proizvod(int a, int b, int m){

    return (a*b)%m;

}

int stepen(int a, int b){

    int res = 1;
    while(b > 0){

        if(b & 1 == 1)
            res*=a;

        a*=a;
        b >>=1;
    }

    return res;
}

int main(){

    int a, b, m;
    cin >> a >> b >> m;

    cout << mod(a, b) << '\n';
    cout << zbir(a, b, m) << '\n';
    cout << razlika(a, b, m) << '\n';
    cout << proizvod(a, b, m) << '\n';
    cout << stepen(a, b) << '\n';

    return 0;
}

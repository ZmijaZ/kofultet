#include <iostream>
#include <tuple>

using namespace std;

int euklid(int a, int b, int &x, int &y){

    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    while(r2 > 0){

        int q = r1/r2;

        tie(r1, r2) = make_pair(r2, r1 - q * r2);
        tie(x1, x2) = make_pair(x2, x1 - q * x2);
        tie(y1, y2) = make_pair(y2, y1 - q * y2);
    }

    x = x1;
    y = y1;

    return r1;
}

int mod(int a, int m){

    if(a < 0)
        return (m + a%m)%m;
    return (a % m);
}

int inverz(int a, int m){

    int x, y;
    int d = euklid(a, m, x, y);
    if(d != 1)
        return -1;

    return mod(x, m);

}

int main(){

    int a, m;
    cin >> a >> m;

    cout << inverz(a, m) << '\n';

    return 0;
}

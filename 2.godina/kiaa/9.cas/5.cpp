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

bool diofant(int a, int b, int c, int &x, int &y){

    int d = euklid(abs(a), abs(b), x, y);

    if(c < 0)
        tie(a, b, c) = tuple(-a, -b, -c);
    if(c % d != 0)
        return false;
    if(a < 0)
        x*=-1;
    if(b < 0)
        y*=-1;

    x*= c/d;
    y*= c/d;

    return true;

}

int main(){

    int a, b, c;
    cin >> a >> b >> c;

    int x, y;

    if(diofant(a, b, c, x, y))
        cout << a << '*' << x << " + " << b << '*' << y << " = " << c;
    else
        cout << "Nema resenja!";

    cout <<'\n';

    return 0;
}

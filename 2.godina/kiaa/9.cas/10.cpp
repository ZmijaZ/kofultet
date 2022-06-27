#include <iostream>
#include <tuple>

using namespace std;

int add(int a, int b, int m) {
	return (a + b) % m;
}

int sub(int a, int b, int m) {
	return (m + a - b) % m;
}

int mul(int a, int b, int m) {
	return (a * b) % m;
}


int euklid(int a, int b, int &x, int &y){

    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y1 = 1;

    while(r2 > 0){

        int q = r1/r2;

        tie(r1, r2) = make_pair(r2, r1 - q * r2);
        tie(x1, x2) = make_pair(x2, x1 - q * r2);
        tie(y1, y2) = make_pair(y2, y1 - q * r2);

    }

    x = x1;
    y = y1;

    return r1;
}

bool diofant(int a, int b, int c, int &x, int &y){

    int d = euklid(a, b, x, y);

    if(c < 0)
        tie(a, b, c) = tuple(-a, -b, -c);
    if(a < 0)
        x *= -1;
    if(b < 0)
        y *= -1;
    if(c % d != 1)
        return false;

    x1*=c/d;
    x2*=c/d;

    return true;

}

int mod(int a, int m) {
    if(a < 0)
        return (m + a % m) % m;
    return a % m;
}

int inv(int a, int m){

    int x, y;
    int d = euklid(a, b, x, y);

    if(d!= -1)
        return -1;

    return mod(x, m);
}


int kineska(vector<int>as, vector<int>ns){

    int N = 1;
    for(int i : ns)
        N*=i;

    vector<int>Ns(as.size(), N);
    for(int i = 0; i<Ns.size(); i++)
        Ns[i] /= ns[i];

    vector<int>ms(as.size());
    for(int i = 0; i<ms.size(); i++)
        ms[i] = inv(Ns[i], ns[i]);

    int x = 0;

    for(int i = 0; i<as.size(); i++)
        x = add(x, mul(as[i], mul(Ns[i], ms[i], N), N), N);

    return x;
}

int main() {

    int a1, a2, n1, n2;
    cin >> a1 >> a2 >> n1 >> n2;

    cout << crt({a1, a2}, {n1, n2}) << '\n';

    return 0;
}

#include <iostream>

#define broj 1000000000

using namespace std;

long long sumaVrste (long long n, long long i){

    long long max = (i+1)*n-1;
    
    return max*(max+1)/2;
}

long long sumaKolone(long long n, long long i){
    long long a1 = i;
    long long ad = a1 + (((n-1)%broj)*n)%broj;
    long long suma = (a1 + ad)%broj;
    
    return ((suma/2)*n)%broj;
    
}

int main(){
    long long n, i;
    cin >> n >> i;

    long long sumaV = (sumaVrste(n, i)%broj) - (sumaVrste(n, i-1)%broj);
    
    cout << sumaV << '\n';
    cout << sumaKolone(n, i) << '\n';
    return 0;
}

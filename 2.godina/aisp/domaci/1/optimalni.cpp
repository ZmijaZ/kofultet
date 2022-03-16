#include <iostream>
#include <vector>

using namespace std;

int main(){
    unsigned n;
    cin >> n;
    
    vector <int> niz(n);
    
    unsigned ukupno = 0;
    
    for(int i = 0; i<n; i++){
        cin >> niz[i];
        ukupno+=niz[i];
    }
    unsigned suma = 0;
    unsigned min = ukupno - suma;
    unsigned iMin = 0;
    for(int i = 0; i<n; i++){
        ukupno-=niz[i];
        suma+=niz[i];
        if(ukupno > suma){
            if( (ukupno-suma) < min){
                min = ukupno-suma;
                iMin = i;
            }
        }
        else{
            if( (suma - ukupno) < min){
                min = suma - ukupno;
                iMin = i;
            }
        }
    }
    
    
    cout << iMin << '\n';
    
    
    
}

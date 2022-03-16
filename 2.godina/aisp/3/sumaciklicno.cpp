#include <iostream>
#include <vector>

#define M 1234567
using namespace std;

int zbir(int a, int b){
    return ((a%M) + (b%M)) % M;
}

int mnoz(int a, int b){
    return ((a%M) * (b%M)) % M;
}

int razl (int a, int b) {
 return (M+ (a%M) - (b%M)) %M; //dodavanjem M garantujemo pozitivnu vrednost;   
}

int main(){
    int n;
    cin >> n;
    vector <int> niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
        
    int tezinskiZbir = 0;
    int zbirSvih = 0;

    for(int i = 0; i<n; i++){
        zbirSvih = zbir(zbirSvih, niz[i]);
        tezinskiZbir = zbir(tezinskiZbir, mnoz(i, niz[i]));
    }
    int maxZbir = tezinskiZbir;
    int maxI = 0;
    for(int i = 1; i<n; i++){
        tezinskiZbir = razl(zbir(tezinskiZbir, mnoz(n, niz[i-1])), zbirSvih); 
        if(tezinskiZbir > maxZbir){
            maxZbir = tezinskiZbir;
            maxI = i;
        }
    }
    cout << maxI << '\n' << maxZbir << '\n';
        

return 0;
}

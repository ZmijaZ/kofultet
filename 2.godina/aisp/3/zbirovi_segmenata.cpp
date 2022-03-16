#include <iostream>
#include <vector>

using namespace std;

int suma_segmenata(int a, int b, vector <int> sume){
   return sume[++b] - sume[a]; 
}

int main(){
    int n;
    cin >> n;
    vector <int> niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    vector <int> sume(n+1);
    int zbir = 0;
    for(int i = 0; i<n+1; i++){
        sume[i] = zbir;
        zbir+=niz[i];
    }
    
    int k;
    int a, b;
    cin >> k;
    while(k){
        cin >> a;
        cin >> b;
        k--;
        
        cout << suma_segmenata(a, b, sume) << '\n';
    }  
return 0;
}
        

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    unsigned brojac = 0;
    
    vector <int> v(n);
    for(int i = 0; i<n; i++)
        cin >> v[i];
        
    set <int> brojevi;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(brojevi.find(-v[i]-v[j]) != brojevi.end())
                brojac++;            
        }
     brojevi.insert(v[i]);   
    }
    
    cout << brojac << '\n';
    
    return 0;
}

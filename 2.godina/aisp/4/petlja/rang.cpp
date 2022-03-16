#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector <string> imena(n);
    vector <int> bodovi(n);
    vector <int> rezerva(n);
    
    for(int i = 0; i<n; i++){
        cin >> imena[i] >> bodovi[i];
        rezerva[i] = bodovi[i];
    }
    
    
    
    sort(begin(bodovi), end(bodovi));
    
    cout << '\n';
    
    for(int i = 0; i<n; i++)
        cout << imena[i] << " " <<  lower_bound(begin(bodovi), end(bodovi), rezerva[i]) << '\n';
        
    return 0;
}

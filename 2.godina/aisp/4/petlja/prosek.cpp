#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool poredi(vector<int> a, vector<int> b){
    
    int suma = 0;
    int sumb = 0;
    int n = a.size();
    
    for(int i = 0; i<n; i++){
        suma+=a[i];
        sumb+=b[i];
    }
    
    if(suma > sumb)
        return true;
    else if(sumb > suma)
        return false;
    
    return true;
}

int main(){
    
    int u, o;
    cin >> u >> o;
    
    vector<vector<int>> matrica(u, vector<int>(o)); 

    
    for(int i = 0; i<u; i++)
        for(int j = 0; j < o; j++)
            cin >> matrica[i][j];
        
    

    sort(begin(matrica), end(matrica), poredi);
    
    for(int i = 0; i<u; i++){
        for(int j = 0; j<o; j++)
            cout << matrica[i][j] << " "; 
        cout << '\n';
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void particije(int n, int max, vector<int> particija){
    if(n == 0){
        for(int x: particija)
            cout << x << " " ;
        cout << '\n';
        return;
    }
    
    if(max > 1)
        particije(n, max - 1, particija);
    
    if(max <= n){
        particija.push_back(max);
        particije(n-max, max, particija);
        particija.pop_back();
    }
}

int main(){
    
    int n;
    cin >> n;
 
    vector<int> particija;
    particije(n, n, particija);
        
    return 0;
}

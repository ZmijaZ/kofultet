#include <iostream>
#include <vector>

using namespace std;

void particije(int n, int maxS, vector<int>& particija){
    if(n==0){
        for(int x: particija)
            cout << x << " ";
        cout << '\n';
        return;
    }
    
    for(int sabirak = 1; sabirak <= min(maxS, n); sabirak++){
        particija.push_back(sabirak);
        particije(n-sabirak, sabirak, particija);
        particija.pop_back();
    }
    
}

int main(){
    
    int n;
    cin >> n;
    
    vector<int>particija;
    particije(n, n, particija);
    
    return 0;
}

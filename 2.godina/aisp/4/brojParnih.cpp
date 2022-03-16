#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
        
    sort(begin(niz), end(niz));
    
    int brojac = 0;
    int brojPojavljivanja = 1;
    
    for(int i = 1; i<n; i++){
        if(niz[i] == niz[i-1])
            brojPojavljivanja++;
        else{
            if(brojPojavljivanja % 2 == 0)
                brojac++;
            brojPojavljivanja=1;
        }
    }
    if(brojPojavljivanja % 2== 0)
        brojac++;

    cout << brojac << '\n';
    
    return 0;
}

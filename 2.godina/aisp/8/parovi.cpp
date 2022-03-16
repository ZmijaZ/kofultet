#include <iostream>
#include <set>

using namespace std;

int main(){
    
    int s, n, x;
    cin >> s >> n;
    
    set <int> skup;
    
    int brojac = 0;
    
    while(n){
        cin >> x ;
        if(skup.find(s-x) != end(skup))
            brojac++;
        skup.insert(x);
        
        n--;
    }
    
    cout << brojac << '\n';
    return 0;
}

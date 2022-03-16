#include <iostream>
#include <set>

using namespace std;

int main(){
    
    int n, x;
    cin >> n;
    
    set <int> skup;
    
    int max = -1;
    
    while(n){
        cin >> x;
        if(skup.find(x) != skup.end())
            if(x > max)
                max = x;
        skup.insert(x);
        
        n--;
    }
    if(max == -1)
        cout << "nema" << '\n';
    else
        cout << max << '\n';
    return 0;
}

#include <iostream>
#include <set>

using namespace std;

int main(){
    
    int n, m;
    cin >> n;
    
    int x;
    
    multiset<int> a;
    while(n){
        cin>>x;
        a.insert(x);
        n--;
    }
    multiset<int> b;
    cin >> m;
    while(m){
        cin >> x;
        b.insert(x);
        m--;
    }
    
    cout << (a == b ? "da" : "ne") << '\n';
    return 0;
}

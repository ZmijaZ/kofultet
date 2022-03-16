#include <iostream>
#include <set>

using namespace std;

set <int> s;

void dodaj(int x){
    s.insert(x);
}

void obrisi(int x){
    s.erase(x);
}

int najblizi(int x){
    auto it = s.lower_bound(x);
    if(it == end(s))
        return *(--it);
    if(it == begin(s))
        return *it;
    int a = *it;
    int b = *(it-1);
    if(abs(a-x) < abs(b-x))
        return a;
    return b;
}

int main(){
        
    int n;
    cin >> n;
    
    while(n){
        
        string op;
        cin >> op;
        int x;
        cin >> x;
        
        if(op == "dodaj")
            dodaj(x);
        else if(op == "obrisi")
            obrisi(x);
        else if(op == najblizi)
            najblizi(x);
        
        n--;
    }
    cout << x << '\n';
    return 0;
}

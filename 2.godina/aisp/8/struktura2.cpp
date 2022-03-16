#include <iostream>
#include <map>

using namespace std;

map <int, int> m;
int uvecanje = 0;

int vrednost (int x){
    return m[x] + uvecanje;
}

void uvecaj(int x, int y){
    m[x] += y;
    
}

void obrisi(int x){
    m.erase(x);
}

void dodaj(int x, int y){
    m[x] = y - uvecanje;
    
}


int main(){
    
    int n;
    cin >> n;
    
    while(n){
        string op;
        cin >> op;
        if(op == "...
        
        n--;
    }
    
    return 0;
}

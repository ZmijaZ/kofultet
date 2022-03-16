#include <iostream>
#include <vector>

using namespace std;

struct Graf{
    
    vector<vector<int>>povezanost;
    
    vector<bool>poseceno;
    
    int V;
    
};

void inicijalizuj_graf(Graf &g, int V){
    
    g.V = V;
    
    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    
}

void dodaj_cvor(Graf&g, int u, int v){
    
    g.povezanost[u].push_back(v);
    
}

void DFS_obilazak(Graf&g, int v){
    
    g.poseceno[v] = true;
    cout << v << " ";
    
    auto begin = g.povezanost[v].begin();
    auto end = g.povezanost[v].end();
    
    while(begin != end){
        
        if(!g.poseceno[*begin])
            DFS_obilazak(g, *begin);
        
        begin++;
    }
    
}

int main(){
    
    int V;
    cin >> V;
    Graf g;
    inicijalizuj_graf(g, V);
    
    int upiti;
    cin >> upiti;
    for(int i = 0; i<upiti; i++){
        int od, u;
        cin >> od >> u;
        dodaj_cvor(g, od, u);
    }
    
    int tmp;
    cin >> tmp;
    
    DFS_obilazak(g, tmp);
    
    return 0;
}

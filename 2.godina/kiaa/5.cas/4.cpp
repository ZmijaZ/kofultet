#include <iostream>
#include <vector>

using namespace std;

struct Graf{
    
    int V;
    vector<vector<int>>povezanost;
    vector<bool>posecenost;
    int komponente;
    
};

void inicijalizuj_graf(Graf&g, int V){
    
    g.V = V;
    g.povezanost.resize(V);
    g.posecenost.resize(V, false);
    g.komponente = 0;
}

void dodaj_cvor(Graf&g, int u, int v){
    
    g.povezanost[u].push_back(v);
    g.povezanost[v].push_back(u);
    
}

void DFS(Graf&g, int v){
    
    g.posecenost[v] = true;
    
    auto begin = g.povezanost[v].begin();
    auto end = g.povezanost[v].end();
    
    while(begin != end){
        
        if(!g.posecenost[*begin])
            DFS(g, *begin);
        
        begin++;
    }
}

int broj_komponenti(Graf&g){
    
    for(int i = 0; i<g.V; i++)
        
        if(!g.posecenost[i]){
            g.komponente++;
            DFS(g, i);
        }
        
    return g.komponente;
    
}

int main(){
    
    Graf g;
    int V;
    cin >> V;
    inicijalizuj_graf(g, V);
    
    int n;
    cin >> n;
    
    for(int i = 0; i<n; i++){
        
        int od, u;
        cin >> od >> u;
        dodaj_cvor(g, od, u);
        
    }
    
    cout << broj_komponenti(g) << '\n';
    
    return 0;
}

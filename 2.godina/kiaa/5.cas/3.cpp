#include <iostream>
#include <vector>

using namespace std;

struct Graf{
    
    vector<vector<int>>povezanost;
    vector<bool>posecenost;
    int V;
    
    //govori da li smo nasli ciljani cvor
    bool nadjen;
};

void inicijalizuj_graf(Graf&g, int V){
    
    g.V = V;
    
    g.povezanost.resize(V);
    g.posecenost.resize(V, false);
    g.nadjen = false;
    
}

void dodaj_cvor(Graf&g, int u, int v){
    
    g.povezanost[u].push_back(v);
    
}

void DFS(Graf&g, int u, int v, vector<int>&rezultat){
    
    if(u == v){
        
        rezultat.push_back(v);
        g.nadjen = true;
        return;
    }
    
    g.posecenost[u] = true;
    rezultat.push_back(u);
    
    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();
    
    while(begin != end){
        
        if(!g.posecenost[*begin] && !g.nadjen)
            DFS(g, *begin, v, rezultat);
        
        rezultat.pop_back();
        
        begin++;
    }
    
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
    
    vector<int>rezultat;
    
    int u, v;
    cin >> u >> v;
    DFS(g, u, v, rezultat);
    
    int i;
    for (i = 0; i < (int)(rezultat.size() - 1); i++)
      cout << rezultat[i] << " -> ";

    cout << rezultat[i] << endl;
    
    
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    vector<int>stepen;

    vector<int>tezina;
};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    g.stepen.resize(V, 0);
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);
    g.povezanost[v].push_back(u);

    g.stepen[v]++;
    g.stepen[u]++;

}

void DFS(Graf &g, int u){

    g.poseceno[u] = true;

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin])
            DFS(g, *begin);

        begin++;

    }
}

void obrisi_granu(Graf &g, int u, int v){

    g.povezanost[u].erase(find(g.povezanost[u].begin(), g.povezanost[u].end(), v));
    g.povezanost[v].erase(find(g.povezanost[v].begin(), g.povezanost[v].end(), u));

}

bool validna_grana(Graf &g, int u, int v){

    if(g.povezanost[u].size() == 1)
        return true;

    obrisi_granu(g, u, v);

    fill(g.poseceno.begin(), g.poseceno.end(), false);

    DFS(g, u);

    dodaj_granu(g, u, v);

    if(!g.poseceno[v])
        return false;

    return true;
}

int broj_neparnih(Graf &g){

    int brojac = 0;
    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] % 2 == 1)
            brojac++;

    return brojac;
}

int nadji_neparnu_granu(Graf &g){

    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] % 2 == 1)
            return i;

    return -1;
}

int nadji_parnu_granu(Graf &g){

    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] % 2 == 0)
            return i;

    return -1;
}

void ispisi(Graf &g, int u){

    for(int v : g.povezanost[u]){

        if(validna_grana(g, u, v)){
            cout << u << " -> " << v << '\n';
            obrisi_granu(g, u, v);
            ispisi(g, v);
            break;
        }

    }

}

void fleri(Graf &g, int u){


        ispisi(g, u);

}

int main(){

    int V;
    cin >> V;

    Graf g;
    inicijalizuj_graf(g, V);

    int n;
    cin >> n;

    int cena;
    cin >> cena;

    int zbir = 0;

    for(int i = 0; i<n; i++){

        int u, v, broj;
        cin >> u >> v >> broj;
        dodaj_granu(g, u, v);

        zbir+=broj;
    }

    int u;
    cin >> u;
    fleri(g, u);

    cout << zbir*cena << '\n';

    return 0;
}

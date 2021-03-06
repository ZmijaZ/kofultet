#include <iostream>
#include <vector>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    int brojac;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    g.brojac = 0;
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);
    g.povezanost[v].push_back(u);

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

int broj_komponenti(Graf &g){

    for(int i = 0; i<g.V; i++)
        if(!g.poseceno[i]){
            DFS(g, i);
            g.brojac++;
        }

    return g.brojac;

}

int main(){

    cout << "Koliko cvorova je u grafu? ";
    int V;
    cin >> V;

    Graf g;
    inicijalizuj_graf(g, V);

    cout << "Koliko grana je u grafu? ";
    int n;
    cin >> n;

    cout << "Koje su to grane? ";
    for(int i = 0; i<n; i++){

        int u, v;
        cin >> u >> v;
        dodaj_granu(g, u, v);

    }

    cout << "Broj komponenti povezanosti je: " << broj_komponenti(g);

    cout << '\n';

    return 0;
}

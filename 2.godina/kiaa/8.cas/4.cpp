#include <iostream>
#include <vector>


using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    vector<int>stepen;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    g.stepen.resize(V, 0);

}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

    g.stepen[v]++;

}

void DFS(Graf &g, int u){

    g.poseceno[u] = true;

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin]){

            DFS(g, *begin);;

        begin++;
    }
}

Graf obrni_graf(Graf &g){

    Graf pom_g;
    inicijalizuj_graf(pom_g, g.V);

    for(int i = 0; i<g.V; i++)
        for(int u : g.povezanost[i])
            dodaj_granu(pom_g, u, i);

    return pom_g;
}

int broj_neposecenih(Graf &g){

    int brojac = 0;

    for(int i = 0; i<g.V; i++)
        if(g.poseceno[i] == false && (g.povezanost[i].size()>0 || g.stepen[i]>0))
            brojac++;

    return brojac;

}

bool kosaraju(Graf &g){

    int pocetak;
    for(int i = 0; i<g.V; i++)
        if(g.povezanost[i].size()){
            pocetak = i;
            break;
        }

    DFS(g, pocetak);

    if(broj_neposecenih(g) > 0)
        return false;

    Graf pom_g = obrni_graf(g);

    if(broj_neposecenih(pom_g) > 0)
        return false;

    return true;
}

bool jeste_ojlerov(Graf &g){

    if(kosaraju(g) == false)
        return false;

    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] != g.povezanost[i].size())
            return false;

    return true;

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

    if(jeste_ojlerov(g))
        cout << "Jeste ojlerov :)";
    else
        cout << "Nije ojlerov!";
    cout << '\n';

    return 0;
}

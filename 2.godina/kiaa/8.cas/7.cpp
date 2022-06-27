#include <iostream>
#include <vector>

#define MAX 26

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

        if(!g.poseceno[*begin])
            DFS(g, *begin);

        begin++;
    }

}

int broj_neposecenih(Graf &g){

    int brojac = 0;

    for(int i = 0; i<g.V; i++)
        if(!g.poseceno[i] && g.povezanost[i].size() > 0)
            brojac++;

    return brojac;
}

Graf obrni_graf(Graf &g){

    Graf pom_g;
    inicijalizuj_graf(pom_g, g.V);

    for(int i = 0; i<g.V; i++)
        for(int u : g.povezanost[i])
            dodaj_granu(pom_g, u, i);

    return pom_g;

}

bool kosaraju(Graf &g, int u){

    DFS(g, u);

    if(broj_neposecenih(g))
        return false;

    Graf pom_g = obrni_graf(g);

    DFS(pom_g, u);

    if(broj_neposecenih(pom_g))
        return false;

    return true;
}

bool ojlerov(Graf &g, int u){

    if(!kosaraju(g, u))
        return false;

    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] != (int)g.povezanost[i].size())
            return false;

    return true;
}

void dodaj_reci(Graf &g, vector<string> &reci){

    for(string &rec : reci){

        dodaj_granu(g, rec[0]-'a', rec[rec.size()-1] - 'a');

    }
}

int main(){


    Graf g;
    inicijalizuj_graf(g, MAX);

    cout << "Koliko reci ima? ";
    int n;
    cin >> n;
    vector<string>reci(n);

    cout << "Koje su to reci? ";
    for(int i = 0; i<n; i++)
        cin >> reci[i];

    dodaj_reci(g, reci);

    if(ojlerov(g, reci[0][0] - 'a'))
        cout << "Reci se mogu nadovezati :)";
    else
        cout << "Reci se ne mogu nadovezati!";

    cout << '\n';

    return 0;
}

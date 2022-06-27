#include <iostream>
#include <vector>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

};


void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

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

int broj_neposecenih_grana(Graf &g){

    int brojac = 0;

    for(int i = 0; i<g.V; i++)
        if(g.poseceno[i] == false)
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

bool Kosaraju(Graf &g){

    DFS(g, 0);

    if(broj_neposecenih_grana(g) > 0)
        return false;

    Graf pom_g = obrni_graf(g);

    DFS(pom_g, 0);

    if(broj_neposecenih_grana(pom_g) > 0)
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

    if(Kosaraju(g))
        cout << "Graf je jako povezan :)";
    else
        cout << "Graf nije jako povezan!";


    cout << '\n';

    return 0;
}

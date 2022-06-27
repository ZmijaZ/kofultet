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
    g.povezanost[v].push_back(u);


    g.stepen[u]++;
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

bool jeste_povezan(Graf &g){

    int pocetak;

    for(int i = 0; i<g.V; i++)
        if(g.povezanost[i].size() > 0)
            pocetak = i;

    DFS(g, pocetak);

    for(int i = 0; i<g.V; i++)
        if(g.poseceno[i] == false && g.stepen[i] > 0)
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

int ojler(Graf &g){

    int brojac = broj_neparnih(g);

    if(brojac > 2)
        return 0;

    if(!jeste_povezan(g))
        return 0;

    if(brojac == 0)
        return 2;
    else
        return 1;

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

    if(ojler(g) == 0)
        cout << "Nije ojlerov!";
    else if(ojler(g) == 1)
        cout << "Sadrzi ojlerov put";
    else
        cout << "Sadrzi ojlerov ciklus :)";

    cout << '\n';

    return 0;
}

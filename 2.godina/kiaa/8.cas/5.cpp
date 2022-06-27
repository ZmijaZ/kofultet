#include <iostream>
#include <vector>
#include <algorithm>

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

            DFS(g, *begin);;

        begin++;
    }
}

int broj_neparnih(Graf &g){

    int brojac = 0;

    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] % 2 == 1)
            brojac++;

    return brojac;

}

int cvor_sa_neparnim_stepenom(Graf &g){

    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] % 2 == 1)
            return i;

    return -1;

}

int cvor_sa_parnim_stepenom(Graf &g){

    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] % 2 == 0)
            return i;

    return -1;

}

void obrisi_granu(Graf &g, int u, int v){

    g.povezanost[u].erase(find(g.povezanost[u].begin(), g.povezanost[u].end(), v));

    g.povezanost[v].erase(find(g.povezanost[v].begin(), g.povezanost[v].end(), u));

}

bool jeste_validna(Graf &g, int u, int v){

    if(g.povezanost[u].size() == 1)
        return true;

    obrisi_granu(g, u, v);

    DFS(g, u);

    dodaj_granu(g, u, v);

    if(!g.poseceno[v])
        return false;

    return true;
}

void ispisi_ojlera(Graf &g, int u){

    for(int v: g.povezanost[u]){

        if(jeste_validna(g, u, v)){

            cout << u << " -> " << v << '\n';
            obrisi_granu(g, u, v);
            ispisi_ojlera(g, v);

            break;
        }

    }

}

void fleri(Graf &g){

    int cvor;

    if(broj_neparnih(g) > 0){
        cvor = cvor_sa_neparnim_stepenom(g);
        ispisi_ojlera(g, cvor);

    }

    if(broj_neparnih(g) == 0){
        cvor = cvor_sa_parnim_stepenom(g);
        ispisi_ojlera(g, cvor);

    }


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


    cout << "Ojlerov put/ciklus je: \n";

    fleri(g);

    cout << '\n';

    return 0;
}

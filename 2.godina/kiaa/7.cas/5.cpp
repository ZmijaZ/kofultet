#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Graf{

    int V;
    int **matrica;

    //
    vector<bool>u_stablu;
    vector<int>roditelj;
    vector<int>tezina;

};

void inicijalizuj_graf(Graf &g, int V){

    g.V = V;
    g.matrica = (int**)malloc(V*sizeof(int*));
    for(int i = 0; i<V; i++)
        g.matrica[i] = (int*)calloc(V*sizeof(int), V);

    //
    g.u_stablu.resize(V, false);
    g.roditelj.resize(V, -1);
    g.tezina.resize(V, INT_MAX);
}

void dodaj_granu(Graf &g, int u, int v, int tezina){

    g.matrica[u][v] = tezina;
    g.matrica[v][u] = tezina;

}

int min_grana_van_stabla(Graf &g){

    int min_index = -1;
    int min = INT_MAX;

    for(int i = 0; i < g.V; i++){

        if(g.u_stablu[i] == false && g.tezina[i] < min){
            min = g.tezina[i];
            min_index = i;
        }
    }
    return min_index;
}

void Prim(Graf &g, int u){

    g.tezina[u] = 0;

    int cvor;

    for(int i = 0; i<g.V-1; i++){

        cvor = min_grana_van_stabla(g);
        g.u_stablu[cvor] = true;

        for(int v = 0; v<g.V; v++){
            if(g.matrica[cvor][v] && g.matrica[cvor][v] < g.tezina[v] && g.u_stablu[v] == false){
                g.roditelj[v] = cvor;
                g.tezina[v] = g.matrica[cvor][v];
            }
        }
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

        int u, v, tezina;
        cin >> u >> v >> tezina;
        dodaj_granu(g, u, v, tezina);

    }

    cout << "MST je ";
    Prim(g, 0);

    cout << '\n';

    return 0;
}

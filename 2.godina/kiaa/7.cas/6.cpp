#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Graf{

    int V;
    int **matrica;


};

void inicijalizuj_graf(Graf &g, int V){

    g.V = V;
    g.matrica = (int**)malloc(V*sizeof(int*));
    for(int i = 0; i<V; i++)
        g.matrica[i] = (int*)calloc(V*sizeof(int), V);

}

void dodaj_granu(Graf &g, int u, int v, int tezina){

    g.matrica[u][v] = tezina;

}

void flojd_varsal(Graf &g){

    for(int k = 0; k<g.V; k++)
        for(int i = 0; i<g.V; i++)
            for(int j = 0; j<g.V; j++)
                if(g.matrica[i][j] > g.matrica[i][k] + g.matrica[k][j])
                    g.matrica[i][j] = g.matrica[i][k] + g.matrica[k][j];

    for(int i = 0; i<g.V; i++)
        if(g.matrica[i][i] < 0){
            cout << "Postoji negativni ciklus\n";
            return;
        }

    cout << "Ne postoji negativni ciklus\n";
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

    flojd_varsal(g);

    cout << '\n';

    return 0;
}

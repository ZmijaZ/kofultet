#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    int broj;
};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.broj = INT_MAX;
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

void DFS(Graf &g, int u, int v, int broj){

    if(u == v){

        if(broj < g.broj)
            g.broj = broj;

        return;
    }

    g.poseceno[u] = true;

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin])
            DFS(g, *begin, v, broj+1);

        begin++;
    }

    g.poseceno[u] = false;

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

    cout << "Koje putanja se trazi? ";
    int u, v;
    cin >> u >> v;

    vector<int>rez;

    DFS(g, u, v, 0);
    cout << "Putanja sa najmanje grana je: " << g.broj;

    cout << '\n';

    return 0;
}

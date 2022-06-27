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
    cout << u << " ";

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin])
            DFS(g, *begin);

        begin++;
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

    cout << "Iz koje grane pocinje pretraga? ";
    int u;
    cin >> u;

    cout << "DFS pretraga je: \n";
    DFS(g, u);

    cout << '\n';

    return 0;
}

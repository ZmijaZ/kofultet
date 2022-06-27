#include <iostream>
#include <vector>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    vector<int>boje;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.boje.resize(V, -1);

}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

bool DFS(Graf &g, int u, int boja){

    g.poseceno[u] = true;

    g.boje[u] = boja;

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(g.boje[*begin] == g.boje[u])
            return false;

        if(!g.poseceno[*begin])
            if(!DFS(g, *begin, !boja))
                return false;


        begin++;
    }

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

    if(DFS(g, 0, 0))
        cout << "Jeste bipartitan :)";
    else
        cout << "Nije bipartitan!";

    cout << '\n';

    return 0;
}

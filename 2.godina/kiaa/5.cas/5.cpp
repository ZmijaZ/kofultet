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

void DFS(Graf &g, int u, int v, vector<int>rez){

    if(u == v){

        rez.push_back(v);

        int i;
        int n = rez.size();
        for(i = 0; i<n-1; i++)
            cout << rez[i] << " -> ";
        cout << rez[i] << '\n';

    }

    g.poseceno[u] = true;
    rez.push_back(u);

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin])
            DFS(g, *begin, v, rez);

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

    cout << "Koje putanje se traze? ";
    int u, v;
    cin >> u >> v;

    vector<int>rez;
    cout << "Sve (DFS) putanje su : \n";
    DFS(g, u, v, rez);

    cout << '\n';

    return 0;
}

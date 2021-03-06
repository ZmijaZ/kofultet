#include <iostream>
#include <vector>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    bool postoji_put;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.postoji_put = false;
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

void DFS(Graf &g, int u, int v, vector<int>&rez){

    if(u == v){
        rez.push_back(v);
        g.postoji_put = true;

        return;
    }

    g.poseceno[u] = true;
    rez.push_back(u);

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin] && !g.postoji_put)
            DFS(g, *begin, v, rez);

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

    cout << "Koja putanja se trazi? ";
    int u, v;
    cin >> u >> v;

    vector<int>rez;

    DFS(g, u, v, rez);
    if(g.postoji_put){
        cout << "DFS putanja je: \n";
        int i;
        int n = rez.size();

        for(i = 0; i<n-1; i++)
            cout << rez[i] << " -> ";
        cout << rez[i];
    } else
        cout << "Ne postoji put!";

    cout << '\n';

    return 0;
}

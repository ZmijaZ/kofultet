#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Graf{

    vector<vector<pair<int, int>>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    vector<int>tezina;

};

struct komparator{

    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2){

        return p1.second > p2.second;

    }

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.tezina.resize(V, INT_MAX);
}

void dodaj_granu(Graf &g, int u, int v, int tezina){

    g.povezanost[u].push_back(make_pair(v, tezina));

    g.povezanost[v].push_back(make_pair(u, tezina));

}

void Dijkstra(Graf &g, int u, int v){

    priority_queue<pair<int, int>, vector<pair<int, int>>, komparator>hip;

    g.tezina[u] = 0;

    hip.push(make_pair(u, g.tezina[u]));

    pair<int, int> tmp;

    while(!hip.empty()){

        tmp = hip.top();
        hip.pop();

        if(g.poseceno[tmp.first])
            continue;

        g.poseceno[tmp.first] = true;

        for(auto &sused : g.povezanost[tmp.first]){

            if(g.tezina[sused.first] > g.tezina[tmp.first] + sused.second){
                g.tezina[sused.first] = g.tezina[tmp.first] + sused.second;
                hip.push(make_pair(sused.first, g.tezina[sused.first]));
            }
        }

    }

    cout << u << " -> " << v << " = " << g.tezina[v];

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

    cout << "Koji put se trazi? ";
    int u, v;
    cin >> u >> v;

    cout << "Najblizi put od u do v je: \n";
    Dijkstra(g, u, v);

    cout << '\n';

    return 0;
}

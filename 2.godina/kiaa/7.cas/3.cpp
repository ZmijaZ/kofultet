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

        return p1.second < p2.second;

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

int Dijkstra(Graf &g, int u, int v, int avoid){

    priority_queue<pair<int, int>, vector<pair<int, int>>, komparator>hip;

    g.tezina[u] = 0;

    hip.push(make_pair(u, g.tezina[u]));

    pair<int, int>tmp;

    while(!hip.empty()){

        tmp = hip.top();
        hip.pop();

        if(g.poseceno[tmp.first])
            continue;

        g.poseceno[tmp.first] = true;

        for(auto &sused : g.povezanost[tmp.first]){

            if(sused.first == avoid)
                continue;

            if(g.tezina[sused.first] > sused.second + g.tezina[tmp.first]){
                g.tezina[sused.first] = sused.second + g.tezina[tmp.first];
                hip.push(make_pair(sused.first, g.tezina[sused.first]));
            }
        }
    }

    return g.tezina[v];

}

void obrisi_graf(Graf &g){

    fill(g.poseceno.begin(), g.poseceno.end(), false);
    fill(g.tezina.begin(), g.tezina.end(), INT_MAX);

}

int put_preko_aerodroma(Graf &g, int u, int v, int aerodrom){

    int rezultat = Dijkstra(g, u, aerodrom, -1);
    obrisi_graf(g);
    return rezultat + Dijkstra(g, aerodrom, v, -1);

}

int put_bez_aerodroma(Graf &g, int u, int v, int aerodrom){

    return Dijkstra(g, u, v, aerodrom);

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

    cout << "Koji aerodrom je u pitanju? ";
    int aerodrom;
    cin >> aerodrom;

    cout << "Najblizi put od u do v preko aerodroma je: \n";
    cout << put_preko_aerodroma(g, u, v, aerodrom);
    cout << '\n';

    cout << "Najblizi put od u do v bez aerodroma je: \n";
    cout << put_bez_aerodroma(g, u, v, aerodrom);

    cout << '\n';

    return 0;
}

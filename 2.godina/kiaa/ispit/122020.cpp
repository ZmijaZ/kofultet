#include <iostream>
#include <vector>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    vector<int>roditelj;
    vector<int>times;
    vector<int>lower_times;
    vector<int>artikulacione;
    int time;

    vector<int>tezina;
};


void inicijalizuj_graf(Graf&g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    g.roditelj.resize(V, -1);
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
    g.time = 0;

    g.tezina.resize(V, -1);
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

    g.povezanost[v].push_back(u);

}

void dodaj_tezinu(Graf &g, int u, int tezina){

    g.tezina[u] = tezina;

}

void Tarjan(Graf &g, int u){

    g.poseceno[u] = true;

    g.lower_times[u] = g.times[u] = g.time;

    g.time++;

    int deca = 0;

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin]){

            g.roditelj[*begin] = u;

            Tarjan(g, *begin);

            deca++;

            g.lower_times[u] = min(g.lower_times[u], g.lower_times[*begin]);

            if(g.roditelj[u] == -1 && deca > 1)
                g.artikulacione.push_back(u);

            if(g.roditelj[u] != -1 && g.times[u] <= g.lower_times[*begin])
                g.artikulacione.push_back(u);

        }else if(g.roditelj[u] != *begin)
            g.lower_times[u] = min(g.lower_times[u], g.times[*begin]);


        begin++;
    }

}

int main(){

    Graf g;

    int V;
    cin >> V;

    inicijalizuj_graf(g, V);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){

        int u, v;
        cin >> u >> v;
        dodaj_granu(g, u, v);

    }

    for(int i = 0; i<V; i++){
        int tezina;
        cin >> tezina;

        dodaj_tezinu(g, i, tezina);
    }


    int u;
    cin >> u;

    Tarjan(g, u);

    int brojac = 0;

    for(int x : g.artikulacione)
        brojac += g.tezina[x];

    cout << brojac;


    cout << '\n';

    return 0;
}

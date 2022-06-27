#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    vector<int>roditelj;
    vector<int>artikulacione;
    vector<int>times;
    vector<int>lower_times;
    int time;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.roditelj.resize(V, -1);
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
    g.time = 0;

}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

    g.povezanost[v].push_back(u);
}

void Tarjan(Graf &g, int u){

    g.poseceno[u] = true;

    g.times[u] = g.lower_times[u] = g.time;

    g.time++;

    int deca = 0;

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin]){

            g.roditelj[*begin] = u;
            DFS(g, *begin);

            deca++;

            g.lower_times[u] = min(g.lower_times[u], g.times[u]);

            if(g.roditelj[u] == -1 && deca > 1)
                g.artikulacione.push_back(u);
            if(g.roditelj[u] != -1 && g.times[u] <= g.lower_times[*begin])
                g.artikulacione.push_back(u);

        }
        else if(*begin != roditelj[u])
            g.lower_times[u] = min(g.lower_times[u], g.times[*begin]);


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

    cout << "Topolosko sortiranje: \n";
    Kan(g);

    cout << '\n';

    return 0;
}

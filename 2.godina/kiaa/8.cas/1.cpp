#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    vector<int>times;
    vector<int>lower_times;
    int time;

    stack<int>stek;
    vector<bool>u_steku;
};


void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.times.resize(V, -1);
    g.lower_times.resize(V, -1);
    g.time = 0;

    g.u_steku.resize(V, false);
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

void Tarjan(Graf &g, int u){

    g.poseceno[u] = true;

    g.times[u] = g.lower_times[u] = g.time;
    g.time++;

    g.stek.push(u);

    g.u_steku[u] = true;

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin]){

            Tarjan(g, *begin);

            g.lower_times[u] = min(g.lower_times[u], g.lower_times[*begin]);

        }
        else if(g.u_steku[*begin] == true)
            g.lower_times[u] = min(g.lower_times[u], g.times[*begin]);


        begin++;
    }

    if(g.times[u] == g.lower_times[u]){

        while(1){
            int v = g.stek.top();
            g.stek.pop();

            cout << v << " ";

            g.u_steku[v] = false;

            if(u == v){
                cout << '\n';
                break;
            }

        }
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

    cout << "Komponente jake povezanosti su: \n";
    Tarjan(g, 0);

    cout << '\n';

    return 0;
}

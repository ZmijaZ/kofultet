#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    vector<int>nivo;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.nivo.resize(V);
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

int BFS(Graf &g, int u, int nivo){

    queue<int>red;
    red.push(u);

    g.poseceno[u] = true;

    int tmp;

    int trenutni_nivo = 0;
    g.nivo[u] = trenutni_nivo;

    while(!red.empty()){

        tmp = red.front();
        red.pop();

        auto begin = g.povezanost[tmp].begin();
        auto end = g.povezanost[tmp].end();

        while(begin != end){

            if(!g.poseceno[*begin]){
                red.push(*begin);
                g.poseceno[*begin] = true;
                g.nivo[*begin] = g.nivo[tmp] + 1;
            }
            begin++;
        }

    }

    int brojac = 0;
    for(int x : g.nivo)
        if(x == nivo)
            brojac++;

    return brojac;
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

    cout << "Na kom nivou se trazi broj cvorova? ";
    int nivo;
    cin >> nivo;

    cout << "Broj cvorova na datoj grani je: " << BFS(g, 0, nivo);

    cout << '\n';

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    int brojac;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.brojac = 0;

}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

void DFS(Graf &g, int u, int trenutni_nivo, int trazeni_nivo){

    g.poseceno[u] = true;

    if(trenutni_nivo == trazeni_nivo)
        g.brojac++;

    auto begin = g.povezanost[u].begin();
    auto end = g.povezanost[u].end();

    while(begin != end){

        if(!g.poseceno[*begin])
            DFS(g, *begin, trenutni_nivo+1, trazeni_nivo);

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

    cout << "Koji nivo se trazi? ";
    int nivo;
    cin >> nivo;

    DFS(g, 0, 0, nivo);

    cout << "Ukupno ima " << g.brojac << " grana na datom nivou";

    cout << '\n';

    return 0;
}

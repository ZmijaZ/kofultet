#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    vector<int>stepen;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.stepen.resize(V, 0);
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

    g.stepen[v]++;
}

void Kan(Graf &g){

    queue<int>red;

    for(int i = 0; i<g.V; i++)
        if(g.stepen[i] == 0)
            red.push(i);

    int tmp;

    while(red.size()){

        tmp = red.front();
        red.pop();

        cout << tmp << " ";

        for(int x : g.povezanost[tmp]){
            g.stepen[x]--;

            if(g.stepen[x] == 0)
                red.push(x);
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

    cout << "Topolosko sortiranje: \n";
    Kan(g);

    cout << '\n';

    return 0;
}

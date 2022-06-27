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

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.roditelj.resize(V, -1);
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);
    g.povezanost[v].push_back(u);

}

bool BFS(Graf &g, int u){

    queue<int>red;
    red.push(u);

    g.poseceno[u] = true;

    int tmp;

    while(!red.empty()){

        tmp = red.front();
        red.pop();


        auto begin = g.povezanost[tmp].begin();
        auto end = g.povezanost[tmp].end();

        while(begin != end){

            if(g.poseceno[*begin]){
                if(g.roditelj[tmp] != *begin)
                    return true;
            }

            else if(!g.poseceno[*begin]){
                red.push(*begin);
                g.poseceno[*begin] = true;
                g.roditelj[*begin] = tmp;
            }
            begin++;
        }

    }
    return false;
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

    if(BFS(g, 0))
        cout << "Postoji ciklus";
    else
        cout << "U grafu ne postoji ciklus";

    cout << '\n';

    return 0;
}

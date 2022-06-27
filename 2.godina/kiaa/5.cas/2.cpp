#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

void BFS(Graf &g, int u){

    queue<int>red;
    red.push(u);

    g.poseceno[u] = true;

    int tmp;

    while(!red.empty()){

        tmp = red.front();
        red.pop();

        cout << tmp << " ";

        auto begin = g.povezanost[tmp].begin();
        auto end = g.povezanost[tmp].end();

        while(begin != end){

            if(!g.poseceno[*begin]){
                red.push(*begin);
                g.poseceno[*begin] = true;
            }
            begin++;
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

    cout << "Iz koje grane pocinje pretraga? ";
    int u;
    cin >> u;

    cout << "BFS pretraga je: \n";
    BFS(g, u);

    cout << '\n';

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    //
    vector<int>boje;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

    //
    g.boje.resize(V, -1);
}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

bool BFS(Graf &g, int u){

    queue<int>red;
    red.push(u);

    g.poseceno[u] = true;

    g.boje[u] = 0;

    int tmp;

    while(!red.empty()){

        tmp = red.front();
        red.pop();


        auto begin = g.povezanost[tmp].begin();
        auto end = g.povezanost[tmp].end();

        while(begin != end){

            if(g.boje[*begin] == g.boje[tmp])
                return false;

            if(!g.poseceno[*begin]){
                red.push(*begin);
                g.poseceno[*begin] = true;
                g.boje[*begin] = !g.boje[tmp];
            }
            begin++;
        }

    }
    return true;
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
        cout << "Graf je bipartitan :)";
    else
        cout << "Graf nije bipartitan!";

    cout << '\n';

    return 0;
}

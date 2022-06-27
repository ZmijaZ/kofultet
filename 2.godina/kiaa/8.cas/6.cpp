#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Graf{

    vector<vector<int>>povezanost;
    vector<bool>poseceno;
    int V;

    stack<int>stek;
    vector<int>ojlerov_put;

};

void inicijalizuj_graf(Graf &g, int V){

    g.povezanost.resize(V);
    g.poseceno.resize(V, false);
    g.V = V;

}

void dodaj_granu(Graf &g, int u, int v){

    g.povezanost[u].push_back(v);

}

void hirholcer(Graf &g){

    int u = 0;
    g.stek.push(u);

    int tmp;

    while(!g.stek.empty()){

        if(g.povezanost[u].size()){

            g.stek.push(u);
            tmp = g.povezanost[u].back();
            g.povezanost[u].pop_back();

            u = tmp;
        }
        else{

            g.ojlerov_put.push_back(u);
            u = g.stek.top();
            g.stek.pop();

        }
    }

    int i;
    for(i = g.ojlerov_put.size() - 1; i >= 1; i--)
        cout << g.ojlerov_put[i] << " -> ";

    cout << g.ojlerov_put[i];

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


    cout << "Ojlerov put je: \n";

    hirholcer(g);

    cout << '\n';

    return 0;
}

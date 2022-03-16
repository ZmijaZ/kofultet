#include <iostream>
#include <unordered_map>
#include <vector>

#define MAX 100

using namespace std;



struct Node{
    
    int brojac = 0;
    
    unordered_map<char, Node*> mapa;
    
};

Node* napravi_cvor(){
    
    Node* novi_cvor = new Node();
    novi_cvor->brojac = 0;
    
    return novi_cvor;
}

void dodaj_red(Node* cvor, vector<int> &red, int n, int i, int broj){
    
    if(i == n){
        cvor->brojac++;
        
        if(cvor->brojac > 1)
            cout << "Duplikat je: #" << broj << '\n';
    }
    
    if(cvor->mapa[red[i]] == nullptr)
        cvor->mapa[red[i]] = napravi_cvor();
    
    dodaj_red(cvor->mapa[red[i]], red, n, i+1, broj); 
    
}

void obrisi_stablo(Node* koren){
    
    if(koren == nullptr)
        return;
    
    for(auto &p : koren->mapa)
        obrisi_stablo(p.second);
    
    delete koren;
}

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> matrica;
    matrica = vector<vector<int>>(n, vector<int>(n, 0));
    
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> matrica[i][j];
    
    Node*koren = napravi_cvor();
    
    for(int i = 0; i<n; i++)
        dodaj_red(koren, matrica[i], n, 0, i+1);
 
    obrisi_stablo(koren);
    
    return 0;
}

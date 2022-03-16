#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node{    
    
    string rec;
    
    map<char, Node*> mapa;
    
};

Node* napravi_cvor(){
    
    Node*novi_cvor = new Node();
    novi_cvor->rec = "";
    return novi_cvor;
    
}

void dodaj_rec(Node*koren, string rec, int i){
    
    if(i == (int)rec.size()){
        koren->rec = rec;
        return ;
    }
    
    auto it = koren->mapa.find(rec[i]);
    
    if(it == koren->mapa.end())
        koren->mapa[rec[i]] = napravi_cvor();
    
    dodaj_rec(koren->mapa[rec[i]], rec, i+1);
    
}

void leksikografski(Node*koren){
    
    if(koren->rec != "")
        cout << koren->rec << '\n';
    
    auto begin = koren->mapa.begin();
    auto end = koren->mapa.end();
    
    while(begin != end){
        
        leksikografski(begin->second);
        begin++;
        
    }
}

void obrisi_stablo(Node*koren){
    
    if(koren == nullptr)
        return;
    
    for(auto &p : koren->mapa)
        obrisi_stablo(p.second);
    
    delete koren;
    
}

int main(){
    
    Node*koren = napravi_cvor();
    
    int n;
    cin >> n;
    
    vector<string> reci(n);
    
    for(int i = 0; i<n; i++){
        cin >> reci[i];
        dodaj_rec(koren, reci[i], 0);
    }
    
    leksikografski(koren);
    
    obrisi_stablo(koren);
    
    return 0;
}

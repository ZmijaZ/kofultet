#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node{
  
    string rec;
    unordered_map<char, Node*>mapa;
    
};

Node* napravi_cvor(){
    
    Node* novi_cvor = new Node();
    novi_cvor->rec = "";
    
    return novi_cvor;
}

void dodaj_rec(Node*koren, string &rec, int i){
    
    if(i == (int)rec.size()){
        koren->rec = rec;
        return;
    }
    
    auto it = koren->mapa.find(rec[i]);
    
    if(it == koren->mapa.end())
        koren->mapa[rec[i]] = napravi_cvor();
    
    dodaj_rec(koren->mapa[rec[i]], rec, i+1);
}

Node* autocomplete(Node* koren, string &prefiks, int i){
    
    if(i == (int)prefiks.size())
        return koren;
    
    auto it = koren->mapa.find(prefiks[i]);
    
    if(it == koren->mapa.end())
        return nullptr;
    
    return autocomplete(koren->mapa[prefiks[i]], prefiks, i+1);
}

void ispisi(Node*koren){
    
    if(koren->rec != "")
        cout << koren->rec << '\n';
    
    auto begin = koren->mapa.begin();
    auto end = koren->mapa.end();
    
    while(begin != end){
        
        ispisi(begin->second);
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
    
    int n;
    cin >> n;
    vector<string>reci(n);
    
    Node* koren = napravi_cvor();
    for(int i = 0; i<n; i++){
        cin >> reci[i];
        dodaj_rec(koren, reci[i], 0);
    }
    
    string prefiks;
    cin >> prefiks;
    
    Node* tmp = autocomplete(koren, prefiks, 0);
    ispisi(tmp);
    
    obrisi_stablo(koren);
    
    return 0;
}

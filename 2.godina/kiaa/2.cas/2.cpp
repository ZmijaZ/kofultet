#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node{
    
    bool jeste_list;
    
    unordered_map<char, Node*> mapa;
};

Node* napravi_cvor(){
    
    Node*novi_cvor = new Node();
    novi_cvor->jeste_list = false;
    
    return novi_cvor;
}

void dodaj_rec(Node* koren, string &rec, int i){
    
    if(i == (int)rec.size()){
        koren->jeste_list = true;
        return;
    }
    
    auto it = koren->mapa.find(rec[i]);
    
    if(it == koren->mapa.end())
        koren->mapa[rec[i]] = napravi_cvor();
        
    dodaj_rec(koren->mapa[rec[i]], rec, i+1);
}

void obrisi_stablo(Node* koren){
    
    if(koren == nullptr)
        return;
    
    for(auto &p : koren->mapa)
        obrisi_stablo(p.second);
    
    delete koren;
}

void najveci_prefiks(Node* koren, string &prefiks){
    
    while(koren && !koren->jeste_list && koren->mapa.size() == 1){
        
        auto element = koren->mapa.begin();
        
        prefiks += element->first;
        
        koren = element->second;
    }
}

int main(){
    
    int n;
    cin >>  n;
    vector<string> reci(n);
    
    for(int i = 0; i<n; i++)
        cin >> reci[i];
    
    Node*koren = napravi_cvor();
    
    for(string &s : reci)
        dodaj_rec(koren, s, 0);
    
    string prefiks = "";
    najveci_prefiks(koren, prefiks);
    cout << prefiks << '\n';
    
    return 0;
}

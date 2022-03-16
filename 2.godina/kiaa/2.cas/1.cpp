#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node{
    
    bool jeste_list;
    
    unordered_map<char, Node*>mapa;
};

Node* napravi_cvor(){
    
    Node*novi_cvor = new Node();
    novi_cvor->jeste_list = false;
    
    return novi_cvor;
}

void dodaj_rec(Node*cvor, string &rec, int i){
    
    if(i == (int)rec.size()){
        cvor->jeste_list = true;
        return;
    }
    
    auto it = cvor->mapa.find(rec[i]);
    
    if(it == cvor->mapa.end())
        cvor->mapa[rec[i]] = napravi_cvor();
    
    dodaj_rec(cvor->mapa[rec[i]], rec, i+1);
}

bool nadji_rec(Node*cvor, string&rec, int i){
    
    if(i == (int)rec.size())
        return cvor->jeste_list;
    
    auto it = cvor->mapa.find(rec[i]);
    
    if(it == cvor->mapa.end())
        return false;
    
    return nadji_rec(cvor->mapa[rec[i]], rec, i+1);
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
    
    vector<string> reci(n);
    
    for(int i = 0; i <n; i++)
        cin >> reci[i];
    
    Node* koren = napravi_cvor();
    
    for(string &s : reci)
        dodaj_rec(koren, s, 0);
 
    string trazena;
    cin >> trazena;
    
    cout << nadji_rec(koren, trazena, 0) << '\n';
    
    obrisi_stablo(koren);
    
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node{
    
    string rec;
    int brojac;
    unordered_map<char, Node*> mapa;
};

Node* napravi_cvor(){
    
    Node*novi_cvor = new Node();
    novi_cvor->rec = "";
    novi_cvor->brojac = 0;
    
    return novi_cvor;
}

void dodaj_rec(Node*cvor, string &rec, int i){
    
    if(i == (int)rec.size()){
        cvor->rec = rec;
        cvor->brojac++;
        return;
    }
    
    auto it = cvor->mapa.find(rec[i]);
    
    if(it == cvor->mapa.end())
        cvor->mapa[rec[i]] = napravi_cvor();
    
    dodaj_rec(cvor->mapa[rec[i]], rec, i+1);
}

void max_pojavljivanja(Node*cvor, string &maxrec, int &max){
    
    if(cvor->rec != ""){
        
        if(cvor->brojac>max){
            maxrec = cvor->rec;
            max = cvor->brojac;
        }
        
    }
    
    auto begin = cvor->mapa.begin();
    auto end = cvor->mapa.end();
    
    while(begin != end){
        
        max_pojavljivanja(begin->second, maxrec, max);
        begin++;
    }
    
}

void obrisi_stablo(Node*cvor){
    
    if(cvor == nullptr)
        return;
    
    for(auto &p : cvor->mapa)
        obrisi_stablo(p.second);
    
    delete cvor;
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
    
    int max = 0;
    string rec = "";
    
    max_pojavljivanja(koren, rec, max);
    
    cout << rec << " " << max << '\n';
    
    obrisi_stablo(koren);
    
    return 0;
}

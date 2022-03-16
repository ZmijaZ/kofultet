#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

struct Node{
    
    bool jeste_list;
    
    unordered_map<char, Node*> mapa;
};

Node* napravi_cvor(){
    
    Node* novi_cvor = new Node();
    
    novi_cvor->jeste_list = false;
    
    return novi_cvor;
}

int vrednost(string &broj){
    
    int n = broj.size();
    int resenje = 0;
    
    for(int i = 0, j = n-1; i<n; i++, j--)
        resenje += pow(2, i) * (broj[j] - '0');
    
    
    return resenje;
}

void dodaj_broj(Node* koren, string &broj, int i){
    
    if(i == (int)broj.size()){
        koren->jeste_list = true;
        return;
    }
    
    if(koren->mapa[broj[i] - '0'] == nullptr)
        koren->mapa[broj[i] - '0'] = napravi_cvor(); 
    
    dodaj_broj(koren->mapa[broj[i] - '0'], broj, i+1);
}

void nadji_XOR(Node*koren, string &XOR, string &broj, int i){
    
    if(koren->jeste_list)
        return;
    
    int cifra = broj[i] - '0';
    
    if(koren->mapa[abs(cifra-1)]){
        XOR += '1';
        nadji_XOR(koren->mapa[abs(cifra-1)], XOR, broj, i+1);
    }
    else{
        XOR += '0';
        nadji_XOR(koren->mapa[cifra], XOR, broj, i+1);
        
    }
    
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
    vector<string> brojevi(n);
    
    int max = 0;
    string max_XOR;
    string XOR;
    
     Node* koren = napravi_cvor();
    
    for(int i = 0; i<n; i++){
        XOR = "";
        cin >> brojevi[i];
        dodaj_broj(koren, brojevi[i], 0);
        
        nadji_XOR(koren, XOR, brojevi[i], 0);
        if(vrednost(XOR) > max){
            max = vrednost(XOR);
            max_XOR = XOR;
        }
    }
    
    cout << max_XOR << '\n';
    
    obrisi_stablo(koren);
    
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

struct Node{
    
    Node(){
        levo = desno = nullptr;
    }
    
    int vrednost;
    Node* levo;
    Node* desno;
    
};

void dodaj_node(Node**koren, int vrednost){
    
    if(*koren == nullptr){
        
        *koren = new Node();
        (*koren)->vrednost = vrednost;
        return;
    }
    
    if((*koren)->vrednost > vrednost)
        dodaj_node(&(*koren)->levo, vrednost);
    else
        dodaj_node(&(*koren)->desno, vrednost);
    
}

void obrisi_stablo(Node*koren){
    
    if(koren == nullptr)
        return;
    
    obrisi_stablo(koren->levo);
    obrisi_stablo(koren->desno);
    
    delete(koren);   
}

bool jeste_list(Node*koren){
    
    return(koren->desno == nullptr && koren->levo == nullptr);
    
}

void ispisi_iterativno(Node*list, unordered_map<Node*, Node*>mapa){
    
    Node* tmp = list;
    
    while(mapa[tmp] != nullptr){
        
        cout << tmp->vrednost << " -> ";
        tmp = mapa[tmp];
        
    }
    
    cout << tmp->vrednost;
    cout << '\n';
}

void obilazak(Node*koren){
    
    stack<Node*> stek;
    stek.push(koren);
    
    unordered_map<Node*, Node*> mapa;
    mapa[koren] = nullptr;
    
    Node*tmp;
    
    while(stek.size()){
        
        tmp = stek.top();
        stek.pop();
        
        if(jeste_list(tmp))
            ispisi_iterativno(tmp, mapa);
        if(tmp->desno){
            mapa[tmp->desno] = tmp;
            stek.push(tmp->desno);
        }
        if(tmp->levo){
            mapa[tmp->levo] = tmp;
            stek.push(tmp->levo);
        }
    }
    
    
}

int main(){
    
    int n;
    cin >> n;
    
    vector<int>niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    
    Node*koren = nullptr;
    
    for(int x : niz)
        dodaj_node(&koren, x);
        
    obilazak(koren);
    
    obrisi_stablo(koren);
    
    return 0;
}

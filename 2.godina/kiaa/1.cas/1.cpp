#include <iostream>
#include <deque>
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

void dodaj_node(Node **koren, int vrednost){
    
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

void obrisi_stablo(Node* koren){
    
    if(koren == nullptr)
        return ;
    
    obrisi_stablo(koren->levo);
    obrisi_stablo(koren->desno);
    
    delete koren;
}

void ispisi_stablo(Node* koren){
    
    if(koren == nullptr)
        return;
    
    ispisi_stablo(koren->levo);
    ispisi_stablo(koren->desno);
    
    cout << koren->vrednost << " ";
}

void obilazak(Node* koren, bool leftToRight){
    
    deque<Node*> dek;
    dek.push_back(koren);
    
    leftToRight = !leftToRight;
    
    while(dek.size()){
        
        int n = dek.size();
        
        while(n){
            
            if(leftToRight){
                
                Node*tmp = dek.front();
                dek.pop_front();
                
                n--;
                
                cout << tmp->vrednost << " ";
                
                if(tmp->levo)
                    dek.push_back(tmp->levo);
                if(tmp->desno)
                    dek.push_back(tmp->desno);
            }
            else{
                
                Node*tmp = dek.back();
                dek.pop_back();
                
                n--;
                cout << tmp->vrednost << " ";
                
                if(tmp->desno)
                    dek.push_front(tmp->desno);
                if(tmp->levo)
                    dek.push_front(tmp->levo);
                
            }
        }
        
        leftToRight = !leftToRight;
        cout << '\n';
    }
    
}

int main(){
    
    int n;
    cin >> n;
    
    vector<int> niz(n);
    
    for(int i = 0; i < n; i++)
        cin >> niz[i];
    
    Node* list = nullptr;
    
    for(int x : niz)
        dodaj_node(&list, x);
    
    obilazak(list, true);  //u zavisnosti od smera ispisa pisemo true/false
    
    obrisi_stablo(list);
    
    cout << '\n';
    
    return 0;
}

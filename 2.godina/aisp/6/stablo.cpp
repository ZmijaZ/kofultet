#include <iostream>
#include <algorithm>

using namespace std;

int visina(Cvor*koren){
    if(koren == nullptr)
        return 0;
    return 1 + max(visina(koren->levo), visina(koren->desno) );
    
}

int maxFaktor(Cvor*koren){
    if(koren == nullptr)
        return 0;
    
    int visinaLevo = visina(koren->levo);
    int visinaDesno = visina(koren->desno);

    int faktor = abs(visinaLevo - visinaDesno);
        
    int maxFaktorLevo = maxFaktor(koren->levo);
    int maxFaktorDesno = maxFaktor(koren->desno);
    
    return max({faktor, maxFaktorLevo, maxFaktorDesno});
}

void maxFaktorIvisina(Cvor*koren, int&visina, int&maxFaktor){
    
    if(koren == nullptr){
        visina = maxFaktor = 0;
        return;
    }
    
    int visinaLevo, maxFaktorLevo;
    maxFaktorIvisina(koren->levo, visinaLevo, maxFaktorLevo);
    
    int visinaDesno, maxFaktorDesno;
    maxFaktorIvisina(koren->desno, visinaDesno, maxFaktorDesno);
    
    int faktor = abs(visinaLevo - visinaDesno);
    
    maxFaktor = max({faktor, maxFaktorLevo, maxFaktorDesno});
    visina = 1 + max(visinaLevo, visinaDesno);
}

int main (){
    
    
    return 0;
}

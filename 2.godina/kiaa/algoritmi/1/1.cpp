#include <iostream>
#include <unordered_map>

// PREFIKSNA DRVETAA

//algoritam pravi recnik i proverava postojanje date reci unutar istog. SLOZENOST je O(n)

using namespace std;

struct Cvor{

    bool jeste_rec;
    unordered_map<char, Cvor*>mapa;

};

Cvor* napravi_cvor(){

    Cvor* novi_cvor = new Cvor();

    novi_cvor->jeste_rec = false;

    return novi_cvor;

}

void dodaj_rec(Cvor*koren, string rec, int i){

    if(i == (int)rec.size()){
        koren->jeste_rec = true;
        return;
    }

    auto it = koren->mapa.find(rec[i]);

    if(it == koren->mapa.end())
        koren->mapa[rec[i]] = napravi_cvor();

    dodaj_rec(koren->mapa[rec[i]], rec, i+1);

}

bool pronadji_rec(Cvor*koren, string rec, int i){

    if(i == (int)rec.size())
        return koren->jeste_rec;

    auto it = koren->mapa.find(rec[i]);

    if(it == koren->mapa.end())
        return false;

    return pronadji_rec(koren->mapa[rec[i]], rec, i+1);

}

void obrisi_stablo(Cvor*koren){

    if(koren == nullptr)
        return;

    for(auto &p : koren->mapa)
        obrisi_stablo(p.second);

    delete koren;
}

int main(){

    Cvor*koren = napravi_cvor();

    cout << "Koliko reci se nalazi u recniku? ";
    int n;
    cin >> n;

    cout << "Koje su to reci?\n";
    for(int i = 0; i < n; i++){

        string rec;
        cin >> rec;
        dodaj_rec(koren, rec, 0);

    }

    cout << "Koja rec se trazi? ";
    string rec;
    cin >> rec;

    if(pronadji_rec(koren, rec, 0))
        cout << "\nRec postoji u recniku :)";
    else
        cout << "\nRec ne postoji u recniku!";


    cout << '\n';
    obrisi_stablo(koren);

    return 0;
}

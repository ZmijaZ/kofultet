#include <iostream>
#include <unordered_map>

// PREFIKSNA DRVETAA

//algoritam nalazi najduzi zajednicki prefiks svih reci u recniku. SLOZENOST je O(n)

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

void najduzi_prefiks(Cvor*koren, string &rec){

    while(koren->mapa.size() == 1 && koren->mapa.size() && koren->jeste_rec == false){

        auto element = koren->mapa.begin();

        rec += element->first;

        koren = element->second;
    }

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

    string prefiks = "";
    najduzi_prefiks(koren, prefiks);

    cout << "\nNajduzi prefiks svih reci je: " << prefiks;

    cout << '\n';
    obrisi_stablo(koren);

    return 0;
}

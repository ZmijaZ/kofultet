#include <iostream>
#include <unordered_map>

using namespace std;

struct Cvor{

    bool jeste_list;
    unordered_map<char, Cvor*>mapa;

};

Cvor* napravi_cvor(){

    Cvor* novi_cvor = new Cvor;
    novi_cvor->jeste_list = false;

    return novi_cvor;
}

void dodaj_rec(Cvor*koren, string rec, int i){

    if(i == (int)rec.size()){
        koren->jeste_list = true;
        return;
    }

    auto it = koren->mapa.find(rec[i]);

    if(it == koren->mapa.end())
        koren->mapa[rec[i]] = napravi_cvor();

    dodaj_rec(koren->mapa[rec[i]], rec, i+1);

}

bool nadji_rec(Cvor*koren, string rec, int i){

    if(i == (int)rec.size())
        return koren->jeste_list;

    auto it = koren->mapa.find(rec[i]);

    if(it == koren->mapa.end())
        return false;

    return nadji_rec(koren->mapa[rec[i]], rec, i+1);
}

void obrisi_stablo(Cvor *koren){

    if(koren == nullptr)
        return;

    for(auto &p : koren->mapa)
        obrisi_stablo(p.second);

    delete koren;

}

int main(){

    cout << "Koliko reci se unosi u recnik? ";
    int n;
    cin >> n;

    Cvor*koren = napravi_cvor();

    cout << "Koje su to reci? ";
    for(int i = 0; i<n; i++){
        string rec;
        cin >> rec;
        dodaj_rec(koren, rec, 0);
    }

    cout << "Koja rec se trazi? ";
    string rec;
    cin >> rec;

    if(nadji_rec(koren, rec, 0))
        cout << "Rec postoji u recniku :)";
    else
        cout << "Rec ne postoji u recniku!";

    obrisi_stablo(koren);
    cout << '\n';

    return 0;
}

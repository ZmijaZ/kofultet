#include <iostream>
#include <map>

// PREFIKSNA DRVETAA

//algoritam leksikografski sortira recnik. SLOZENOST je O(n) + O(nlog(n))

using namespace std;

struct Cvor{

    string rec;
    map<char, Cvor*>mapa; //map<char, Cvor*, greater<int>>mapa; ako zelimo obrnuto sortirano

};

Cvor* napravi_cvor(){

    Cvor* novi_cvor = new Cvor();

    novi_cvor->rec = "";

    return novi_cvor;

}

void dodaj_rec(Cvor*koren, string rec, int i){

    if(i == (int)rec.size()){
        koren->rec = rec;
        return;
    }

    auto it = koren->mapa.find(rec[i]);

    if(it == koren->mapa.end())
        koren->mapa[rec[i]] = napravi_cvor();

    dodaj_rec(koren->mapa[rec[i]], rec, i+1);

}

void leksikografski(Cvor*koren){

    if(koren->rec != ""){
        cout << koren->rec << "\n";
        return;
    }

    auto begin = koren->mapa.begin();
    auto end = koren->mapa.end();

    while(begin != end){

        leksikografski(begin->second);
        begin++;
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

    cout << "\nReci sortirane:\n";
    leksikografski(koren);

    obrisi_stablo(koren);

    return 0;
}

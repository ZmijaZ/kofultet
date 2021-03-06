#include <iostream>
#include <unordered_map>

using namespace std;

struct Cvor{

    string rec;
    int brojac;
    unordered_map<char, Cvor*>mapa;

};

Cvor* napravi_cvor(){

    Cvor* novi_cvor = new Cvor;
    novi_cvor->rec = "";
    novi_cvor->brojac = 0;

    return novi_cvor;
}

void dodaj_rec(Cvor*koren, string rec, int i){

    if(i == (int)rec.size()){
        koren->rec = rec;
        koren->brojac++;
        return;
    }

    auto it = koren->mapa.find(rec[i]);

    if(it == koren->mapa.end())
        koren->mapa[rec[i]] = napravi_cvor();

    dodaj_rec(koren->mapa[rec[i]], rec, i+1);

}

void najcesca_rec(Cvor*koren, string &rec, int &max){

    if(koren->rec != ""){
        if(koren->brojac > max){
            max = koren->brojac;
            rec = koren->rec;
        }

    }

    auto begin = koren->mapa.begin();
    auto end = koren->mapa.end();

    while(begin != end){

        najcesca_rec(begin->second, rec, max);
        begin++;
    }

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

    string rec = "";
    int broj = 0;
    najcesca_rec(koren, rec, broj);

    cout << "Najcesca rec je: " << rec << ", " << broj << " puta";

    obrisi_stablo(koren);
    cout << '\n';

    return 0;
}

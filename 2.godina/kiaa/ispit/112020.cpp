#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Cvor{

    string rec;
    unordered_map<char, Cvor*>mapa;

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

Cvor* autocomplete(Cvor*koren, string &prefiks, int i){

    if(i == (int)prefiks.size())
        return koren;

    auto it = koren->mapa.find(prefiks[i]);

    if(it == koren->mapa.end())
        return nullptr;

    return autocomplete(koren->mapa[prefiks[i]], prefiks, i+1);
}

void ispisi(Cvor *koren, int &max, string &rec){

    if(koren->rec != ""){
        if((int)koren->rec.size() > max){
            max = koren->rec.size();
            rec = koren->rec;
        }
    }

    auto begin = koren->mapa.begin();
    auto end = koren->mapa.end();

    while(begin != end){

        ispisi(begin->second, max, rec);

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

    Cvor*koren = napravi_cvor();

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){

        string komanda;
        cin >> komanda;

        if(komanda == "add"){
            string rec;
            cin >> rec;
            dodaj_rec(koren, rec, 0);
        }else{
            string prefiks;
            cin >> prefiks;
            Cvor* tmp = autocomplete(koren, prefiks, 0);
            int max = 0;
            string rec = "";

            if(tmp == nullptr)
                cout << "Nema";
            else
                ispisi(tmp, max, rec);

            cout << rec << " " << max << '\n';

        }

    }

    return 0;
}

#include <iostream>
#include <map>

using namespace std;

struct Cvor{

    string rec;
    map<char, Cvor*, greater<int> >mapa;

};

Cvor* napravi_cvor(){

    Cvor* novi_cvor = new Cvor;
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

void leksikografski(Cvor *koren){

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

    cout << "-----Raspored reci leksikografski-----\n";

    leksikografski(koren);


    return 0;
}

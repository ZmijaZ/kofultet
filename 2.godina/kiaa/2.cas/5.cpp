#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct Cvor{

    string rec;
    int brojac;
    unordered_map<char, Cvor*>mapa;

};

struct komparator{

    bool operator()(Cvor *c1, Cvor *c2){

        return c1->brojac < c2->brojac;

    }

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

void najcesce_reci(Cvor*koren, priority_queue<Cvor*, vector<Cvor*>, komparator>hip){

    if(koren->rec != ""){
        hip.push(koren);
    }

    auto begin = koren->mapa.begin();
    auto end = koren->mapa.end();

    while(begin != end){

        najcesce_reci(begin->second, hip);
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

    cout << "Koliko reci se trazi? ";
    int k;
    cin >> k;

    priority_queue<Cvor*, vector<Cvor*>, komparator>hip;
    najcesce_reci(koren, hip);

    Cvor*tmp;

    cout << "-----Najcesce reci su-----\n";
    while(k && hip.size()){
        tmp = hip.top();
        hip.pop();
        cout << tmp->rec << ", " << tmp->brojac << "\n";

        k--;
    }

    obrisi_stablo(koren);
    cout << '\n';

    return 0;
}

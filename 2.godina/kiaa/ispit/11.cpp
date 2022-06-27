#include <iostream>
#include <vector>

using namespace std;

void manacher(string &rec, int k){

    int n = rec.size();

    string pom = "$";

    for(int i = 0; i<n; i++){

        pom += "#";
        pom += rec[i];

    }

    pom += "#%";

    n = pom.size();

    vector<int>vektor_pom(n);

    int c = 1;
    int d = 1;

    int ogledalo;

    for(int i = 1; i<n-1; i++){

        ogledalo = 2*c - i;

        if(i < d)
            vektor_pom[i] = min(d-i, vektor_pom[ogledalo]);

        while(pom[i + (vektor_pom[i] + 1)] == pom[i - (vektor_pom[i] + 1)])
            vektor_pom[i]++;

        if(i + vektor_pom[i] > d){
            c = i;
            d = i + vektor_pom[i];
        }
    }

    int max = -1;
    int index = -1;

    for(int i = 0; i<n; i++)
        if(vektor_pom[i] >= max){
            max = vektor_pom[i];
            index = i;
        }

    int pocetak = index - max + 1;
    int kraj = 2*max + pocetak;

    string rez = "";

    for(int i = pocetak; i<kraj; i+=2)
        rez += pom[i];

    if(k <= (int)rez.size())
        cout << rez.size() << " " << rez << '\n';
    else
        cout << "-1\n";
}

int main(){

    string rec;
    int k;
    cin >> rec >> k;

    manacher(rec, k);

    return 0;
}

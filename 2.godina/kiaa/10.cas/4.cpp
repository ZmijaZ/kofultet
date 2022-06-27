#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void manacher(string &rec){

    int n = rec.size();

    string pom = "@";

    for(int i = 0; i<n; i++){
        pom+="#";
        pom+=rec[i];
    }

    pom+="#$";

    n = pom.size();

    vector<int>pom_vektor(n);

    int c = 1;
    int d = 1;
    int ogledalo;

    for(int i = 1; i < n-1; i++){

        ogledalo = 2*c-i;

        if(i < d)
            pom_vektor[i] = min(d-i, pom_vektor[ogledalo]);

        while(pom[i + (pom_vektor[i] + 1)] == pom[i - (pom_vektor[i] + 1)])
            pom_vektor[i]++;

        if(i + pom_vektor[i] > d){
            c = i;
            d = i + pom_vektor[i];
        }
    }

    int max_i = max_element(pom_vektor.begin(), pom_vektor.end()) - pom_vektor.begin();
    int max = pom_vektor[max_i];

    int start = max_i - max + 1;

    string rezultat = "";

    int end = start + 2*max;

    for(int i = start; i < end; i+=2)
        rezultat += pom[i];

    cout << rezultat << '\n';

}

int main(){

    string s;
    cin >> s;

    manacher(s);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Predmet{
  string ime;
  double cena;
};

bool poredi (Predmet a, Predmet b){
    if (a.cena >= b.cena)
        return true;
    else
        return false;
    
}

int main(){
    
    double N;
    cin >> N;
    
    int n;
    cin >> n;
    vector <Predmet> predmeti(n);
    for(int i = 0; i<n; i++)
        cin >> predmeti[i].ime >> predmeti[i].cena;
    sort(begin(predmeti), end(predmeti), poredi);
    
    int brojac = 0;
    vector<Predmet>niz(n);
    
    for(int i = 0; i<n; i++){
        if(N < predmeti[i].cena)
            continue;
        else if(N > predmeti[i].cena){
            niz[brojac].cena = predmeti[i].cena;
            niz[brojac].ime = predmeti[i].ime;
            brojac++;
            N-=predmeti[i].cena;
        }
        else{
            niz[brojac].cena = predmeti[i].cena;
            niz[brojac].ime = predmeti[i].ime;
            brojac++;
            N-=predmeti[i].cena;
            break;
        }
            
    }
    
    for(int i = 0; i<brojac; i++)
        cout << niz[i].ime <<  " " << niz[i].cena << '\n';
    
    if(N)
        cout << N << '\n';
    
    return 0;
}

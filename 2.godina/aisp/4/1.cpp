#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Takmicar{
    int bodovi;
    string ime;
};

bool poredi(Takmicar a, Takmicar b){
    if(a.bodovi > b.bodovi)
        return false;
    if(a.bodovi < b.bodovi)
        return true;
    return (a.ime < b.ime);
}

int main(){
    int n;
    cin >> n;
    
    vector <Takmicar> niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i].bodovi >> niz[i].ime;
    
    sort(begin(niz), end(niz), poredi);
        cout << '\n';
    for(int i = 0; i<n; i++){
        cout << niz[i].bodovi << ' ';
        cout << niz[i].ime << '\n';
    }

    return 0;
}

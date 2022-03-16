#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Takmicar{
    string ime;
    int bodovi;
    
};

bool poredi(Takmicar a, Takmicar b){
    if(a.bodovi > b.bodovi)
        return true;
    if(b.bodovi > a.bodovi)
        return false;
    return (a.ime < b.ime);
    
}

int main(){
    
    int n;
    cin >> n;
    
    vector <Takmicar> niz(n);
    
    for(int i = 0; i<n; i++)
        cin >> niz[i].ime >> niz[i].bodovi;
    
    sort(begin(niz), end(niz), poredi);
    
    for(int i = 0; i<n; i++){
        cout << niz[i].ime << ' ';
        cout << niz[i].bodovi << '\n';
    }
    
    return 0;
}

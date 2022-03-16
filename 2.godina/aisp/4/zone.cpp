#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using Par = pair<double, double>;

int main(){
    int n;
    cin >> n;
    
    vector <double>zone(n);
    
    
    double ukupno = 0;
    for(int i = 0; i<n; i++){
        cin >> zone[i];
        ukupno+=zone[i];
    }
    
    vector<double>poluprecnik(n);
    poluprecnik[0] = zone[0];
    
    for(int i = 1; i<n; i++)
        poluprecnik[i] = poluprecnik[i-1] + zone[i];
        
    
    int m;
    cin >> m;
    
    vector <Par>parovi(m);
    
    auto it;
    for(int i = 0; i<m; i++){
        cin >> parovi[i].first;
        cin >> parovi[i].second;
        
        double d = sqrt(parovi[i].first*parovi[i].first +parovi[i].second*parovi[i].second);
        
         it = lower_bound(begin(poluprecnik), end(poluprecnik), d);
    }
    for(int i = 0; i<m; i++){
        if(it == end(poluprecnik))
            cout << "izvan" << '\n';
        else
            cout << it - begin(poluprecnik) << '\n';
        }
    
    return 0;
}

#include <iostream>
#include <map>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    map<char, int> mapa;
    
    for(char c : s)
        mapa[c]++;
    
    int k;
    cin >> k;
    
    for(char c : s)
        if(mapa[c] == 1 && k > 0){
            cout << c << " ";
            k--;
        }
    
    cout <<'\n';
    
    return 0;
}

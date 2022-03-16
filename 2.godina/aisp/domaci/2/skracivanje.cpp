#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    vector <char> niz;
    
    for(char c: s)
        if(niz.empty())
            niz.push_back(c);
        else if(c == niz.back())
            niz.pop_back();
        else
            niz.push_back(c);
    
    int n = niz.size();
        
    for(int i = 0; i<n; i++)
        cout << niz[i];
        
    cout << '\n';
    
    return 0;
}

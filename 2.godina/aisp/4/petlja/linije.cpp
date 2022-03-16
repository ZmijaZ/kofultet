#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string smanji(string a){
    int n = a.length();
    for(int i = 0; i<n; i++){
        char c = a[i];
        c = tolower(c);
        a[i] = c;
    }
    return a;
}

bool poredi(string a, string b){
    a = smanji(a);
    b = smanji(b);
    int n = min(a.length(), b.length());
    for(int i = 0; i<n; i++){
        if(a[i] < b[i])
            return true;
        else if(a[i] > b[i])
            return false;
        else
            continue;
    }
    return false;
    
}

int main(){
    
    vector<string> linije;
    string s;
    while(cin >> s){
        linije.push_back(s);
        sort(begin(linije), end(linije));
    }
    
    for(int j = 0; j < (int)linije.size(); j++)
        cout << smanji(linije[j]) << '\n';
    
    return 0;
}

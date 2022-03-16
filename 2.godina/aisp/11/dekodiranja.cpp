#include <iostream>

using namespace std;

uint64_t brDekodiranja(string& s, int n){//& zbog slozenosti
    
    if(n <= 0)
        return 1;

    int b1 = s[n-1] - '0';
    int b2 = (s[n-1] - '0') * 10 + (s[n-1] - '0');
    
    uint64_t br = 0;
    if(b1 != 0)
        br += brDekodiranja(s, n-1);
    if(b2 >= 0 && b2 <=26)
        br += brDekodiranja(s, n-2);
    
    return br;
    
}

int main(){
    
    string s;
    cin >> s;
    
    cout << brDekodiranja(s, s.size()) << '\n';
        
    return 0;
}

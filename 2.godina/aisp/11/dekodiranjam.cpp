#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector <uint64_t> memo;

uint64_t brDekodiranja(string& s, int n){//& zbog slozenosti
    
    if(memo[n] != -1)
        return memo[n];
    
    if(n <= 0)
        return 1;

    int b1 = s[n-1] - '0';
    int b2 = (s[n-1] - '0') * 10 + s[n-1] - '0';
    
    uint64_t br = 0;
    if(b1 != 0)
        br += brDekodiranja(s, n-1);
    if(b2 >= 0 && b2 <=26)
        br += brDekodiranja(s, n-2);
    
    return memo[n] = br;
    
}

int main(){
    
    string s;
    cin >> s;

    memo = vector<uint64_t>(s.size() + 1, -1);
    
    cout << brDekodiranja(s, s.size()) << '\n';
        
    return 0;
}

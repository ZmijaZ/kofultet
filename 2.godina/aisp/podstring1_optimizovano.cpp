#include <iostream>
#include <string>
//slozenost je O(n) za razliku od prethodnog gde je n^2
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int brojac = 0;
    int n = s.length();
    
    for(int i = 0; i < n; i++){
        if(s[i] == '1')
            brojac++;
    }
    brojac = brojac*(brojac-1)/2;
    
    cout << brojac << '\n';
    return 0;
}

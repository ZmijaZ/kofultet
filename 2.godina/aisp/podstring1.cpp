#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    
    cin >> s;

    int brojac = 0;
    int n = s.length();
    
    int i = 0;
    
    for(i = 0; i<n; i++){
        if(s[i] == '1'){
            for(int j = i; j<n; j++){
                if(s[j+1] == '1')
                    brojac++;
            }
        }
    }
        cout <<  brojac << '\n';
    return 0;
}

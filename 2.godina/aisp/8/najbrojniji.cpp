#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    map<string, int> glasovi;
    
    while(n){

        string ime;
        cin >> ime;
        glasovi[ime]++;
        
        n--;
    }
    
    int max = 0;
    for(auto p : glasovi){
        if(p.second > max)
            max = p.second;
    }
    
    cout << max << '\n';
    
    return 0;
}

#include <iostream>
#include <map>

using namespace std;

int main(){
    
    int n, p;
    cin >> n >> p;
    
    map <int, int> mapa;
    
    
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        mapa[x]++;
    }
    if(p == 0){
        for(auto i: mapa){
            cout << i.first << "\n";
            break;
        }
        return 0;
    }
    
    long long ans = 1;
    long long cnt = 0;
    int prethodni = 0;
    
    for(auto i : mapa){
        if((long long)(i.first - prethodni) * cnt >= p){
            ans = prethodni + p/cnt;
            p = 0;
            break;
        } 
        p -= (i.first - prethodni) * cnt;
        cnt += i.second;
        
        prethodni= i.first;
        ans = i.first;
    }
    
    if(p>0){
        ans += p/n;
    }
    
    cout << ans << '\n';
    return 0;
}

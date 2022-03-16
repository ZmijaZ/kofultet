#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;
    
    queue<long long> q2, q4;
    queue<long long> res;
    
    long long tmp = n;
    res.push(n);
    
    q2.push(tmp*2);
    q4.push(tmp*4-3);
    
    k--;
    while(k){
        
        tmp = min(q2.front(), q4.front());
        q2.push(tmp*2);
        q4.push(tmp*4-3);
        
        res.push(tmp);
        
        if(tmp == q2.front())
            q2.pop();
        if(tmp == q4.front())
            q4.pop();
        
        k--;
    }
    
    k = res.size();
    
    while(!res.empty()){
        cout << res.front() << " ";
        res.pop();
    }
    cout << '\n';
    
    return 0;
}

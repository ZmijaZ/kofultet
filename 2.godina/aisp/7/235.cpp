#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

long long dvaTriPet(long long n){
    
    if(n == 0)
        return 1;
    
    queue<long long>q2;
    queue<long long>q3;
    queue<long long>q5;
    
    q2.push(2);
    q3.push(3);
    q5.push(5);
    
    long long a = 1;
    
    while(n){
        a = min({q2.front(), q3.front(), q5.front()});
        
        q2.push(a*2);
        q3.push(a*3);
        q5.push(a*5);
        
        if(a == q2.front())
            q2.pop();
        if(a == q3.front())
            q3.pop();
        if(a == q5.front())
            q5.pop();
        
        n--;
    }
    return a;
}

int main(){
    long long n;
    cin >> n;
    
    cout << dvaTriPet(n) << '\n';
    
    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int n, k, el;
    cin >> n >> k;
    
    priority_queue<int, vector <int>, greater<int>>pq;
    
    for(int i = 0; i<k; i++){
        cin>>el;
        pq.push(el);
    }
    
    for(int i = k; i<n; i++){
        cin >> el;
        if(el > pq.top()){
            pq.pop();
            pq.push(el);
        }
        
    }
    
    int sum = 0;
    
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    
    cout << sum << '\n';
}

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    
    int n, el;
    cin >> n;
    
    cin >> el;
    
    dequeue<int> deq;
    deq.push_back(el);
    
    
    for(int i = 1; i<n; i++){
        cin >> el;
        
        if(el < deq.front())
            deq.push_front(el);
        else if(el > deq.back())
            deq.push_back(el);
        else{
            cout << "Invalid queue\n";
            break;
        }
    }
        
    while(!deq.empty()){
        cout << deq.front() << " ";
        deq.pop_front();
        
    }
        
    cout << '\n';
    
    return 0;
}

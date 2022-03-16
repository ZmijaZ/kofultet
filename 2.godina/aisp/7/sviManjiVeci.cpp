#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int n, el;
    cin >> n;
    
    deque<int> deq;
    cin >> el;
    
    deq.push_back(el);
    
    for(int i = 1; i<n; i++){
        cin >> el;
        if(el < deq.front())
            deq.push_front(el);
        else if(el > deq.back())
            deq.push_back(el);
        else{
            cout<<"Invalid array!\n";
            break;
        }
    }
    
    while(!deq.empty()){
        cout<<deq.front()<<" ";
        deq.pop_front();
    }
  /*  

     for(int i = 0; i<n; i++)
         cout << deq[i];
    */
    
    cout << '\n';
  
    return 0;
}

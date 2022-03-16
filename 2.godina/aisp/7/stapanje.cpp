#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int n, k, el;
    cin >> k >> n;
    
    vector<int> elementi;
    vector<int> ponavljanja;
    
    for(int i = 0; i<n; i++){
        cin >> el;
        if(!elementi.empty() && ((elementi.back()) != el) && (ponavljanja.back() >=k) ){
            elementi.pop_back();
            ponavljanja.pop_back();
        }
        
        if(!elementi.empty() && (elementi.back() == el) ){
            ponavljanja.back()++;
        }
        else{
            elementi.push_back(el);
            ponavljanja.push_back(1);
        }
    }
    
    if(ponavljanja.back() >=k){
        elementi.pop_back();
        ponavljanja.pop_back();
        
    }
    
    for(int i = 0; i<elementi.size(); i++){
        for(int j = 0; j<ponavljanja[i]; j++)
            cout <<elementi[i] << " ";
    }
    cout << '\n';
    
    return 0;
}

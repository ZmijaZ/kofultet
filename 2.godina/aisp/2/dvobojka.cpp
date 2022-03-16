#include <iostream>
#include <vector>


using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> niz(n);
    
    for(int i =0; i<n; i++)
        cin >> niz[i];
        
    int l = 0;
    int d = n-1;
    
    while(l<=d){
        if(niz[l] % 2 == 0)
            l++;
        else if(niz[d] % 2 == 1)
            d--;
        else
            swap(niz[l++], niz[d--]);
    }
    for(int i =0; i<n; i++)
        cout << niz[i] << ' ';
    cout << '\n';
    
return 0;
}

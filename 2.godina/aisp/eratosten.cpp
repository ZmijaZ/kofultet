#include <iostream>
#include <vector>

//JOS UVEK NISAM SAM URADIO ! ! !

using namespace std;

int main(){
    int n = 100;
    vector<bool> prost(n+1, true);
    
    prost[1] = false;
    for(int d = 2; d*d <= n; d++)
        if(prost[d])
            for(int x = d*d; x<= n; x+=d)
                prost[x] = false;
    for(int i = 1; i<=n; i++)
        if(prost[i])
            cout << i << ' ';
    cout << '\n';
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

// JOS UVEK NISAM SAM URADIO ! ! !

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i<n; i++)
        cin >> a[i];
    long long brojRastucih = 0;
    
    int i = 0;
    
    while(i<n){
        int j = i+1;
        while(j < n && a[j]>a[j-1])
            j++;
        long long k = j-i;
        brojRastucih += k*(k-1)/2;
        i = j;
        
    }
    
    cout << brojRastucih << '\n';
return 0;
}

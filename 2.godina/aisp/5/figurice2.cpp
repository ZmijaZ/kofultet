#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector <int> niz(n);
    for(int i = 0; i<n; i++)
        cin >> niz[i];
    sort(begin(niz), end(niz));
    
    int64_t t;
    cin >> t;
    
    int j = 0;
    int64_t maxK = 0;
    int64_t razlika = 0;
    
    for(int64_t i = 0; i<n; i++){
        while((i-j+1)*(niz[i]-niz[j]) > t){
            j++;
        }
        int64_t trenutnaRazlika = (i-j+1)*(niz[i]-niz[j]);
        if(i - j + 1 > maxK ||
            (i-j+1 == maxK && trenutnaRazlika < razlika)
        ){
            
            maxK = i-j+1;
            razlika = (i-j+1)*(niz[i]-niz[j]);
            
        }
    }
   cout << maxK << " ";
   cout << razlika << '\n';
   
    return 0;
}

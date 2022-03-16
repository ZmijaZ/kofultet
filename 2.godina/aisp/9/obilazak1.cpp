#include <iostream>
#include <string>

using namespace std;

string kld, lkd;

void ldk(int kld_levo, int lkd_levo, int n){
    if(n==0)
        return;
    
    int koren = kld[kld_levo];
    int split = lkd.find(koren);
    
    int len_levo = split - ldk_levo;
    int len_desno = n - len_leno - 1;
    
    ldk(kld_levo+1, lkd_levo, len_levo);
    ldk(kld_levo + 1 + len_levo, split + 1, len_desno);
    
    cout << (char)koren;
}

int main(){
    
    cin >> kld >> lkd;
    
    int n = lkd.size();
    
    ldk(0, 0, n);
    
    cout << '\n';
    return 0;
}

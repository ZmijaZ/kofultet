#include <iostream>
#include <string>

using namespace std;

string kld, lkd;

string postfiksni(string prefiks, string infiks){
    
    if(prefiks == "")
        return "";
    
    char koren = prefiks[0];
    int duzinaL = infiks.find(koren);
    
    string prefiksL = prefiks.substr(1, duzinaL);//krenuvsi od 1, uzmi duzinaL slova
    string infiksL = infiks.substr(0, duzinaL);
    
    string prefiksD = prefiks.substr(1 + duzinaL);
    string infiksD = infiks.substr(1 + duzinaL);
    
    return postfiksni(prefiksL, infiksL) + postfiksni(prefiksD, infiksD) + koren;
}

int main(){

    string prefiks, infiks;
    cin >> prefiks >>  infiks;
    cout << postfiksni(prefiks, infiks) << '\n';
    
    return 0;
}

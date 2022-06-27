#include <iostream>
#include <vector>

using namespace std;

void prefiks_tabela(string s, vector<int>&niz){

    int n = s.size();

    niz[0] = 0;

    int i = 1;
    int j = 0;

    while(i < n){

        if(niz[i] == niz[j]){
            niz[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j!=0)
                j = niz[j-1];
            else{
                niz[i] = 0;
                i++;
            }
        }
    }

    for (char c : s)
        cout << c << " ";
    cout << "\n";


    for (int x : niz)
        cout << x << " ";
    cout << "\n";

}

void KMP(string &text, string &rec){

    int n = text.size();
    int m = rec.size();

    vector<int>tabela(m);

    prefiks_tabela(rec, tabela);

    int i = 0;
    int j = 0;

    while(i < n){

        if(text[i] == rec[j]

    }


}

int main(){

    cout << "Koja rec se trazi? ";
    string rec;
    cin >> rec;

    cout << "U kom tekstu se trazi? ";
    string text;
    cin >> text;

    text = rec + "@" + text;

    int m = rec.size();
    int n = text.size();
    vector<int>zNiz = napraviZniz(text);

    for(char c : text)
        cout << c << " ";
    cout << '\n';

    for(int x : zNiz)
        cout << x << " ";
    cout << '\n';


    for(int i = 0; i<n; i++)
        if(zNiz[i] == m)
            cout << i - m + 1 << " ";

    cout << '\n';

    return 0;
}

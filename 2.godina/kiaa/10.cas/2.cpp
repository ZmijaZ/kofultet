#include <iostream>
#include <vector>

using namespace std;

vector<int>napraviZniz(string &rec){

    int l = 0;
    int d = 0;
    int n = rec.size();

    vector<int>niz(n);

    for(int i = 1; i<n; i++){

        if(i <= d)
            niz[i] = min(niz[i-l], d-i+1);

        while(i + niz[i] < n && rec[niz[i]] == rec[niz[i]+i])
            niz[i]++;

        if(i + niz[i] -1 > d){
            l = i;
            d = i+niz[i] -1;
        }

    }
    return niz;
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
            cout << i - m - 1 << " ";

    cout << '\n';

    return 0;
}

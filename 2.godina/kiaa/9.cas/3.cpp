#include <iostream>

using namespace std;

int nzd(int a, int b){

    int c;
    while(b>0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

pair<int, int>skrati(int a, int b){

    int d = nzd(a, b);
    return{a / d, b / d};

}

int main(){

    int a, b;
    cin >> a >> b;

    pair<int, int>par = skrati(a, b);

    cout << par.first << "/" << par.second <<'\n';

    return 0;
}

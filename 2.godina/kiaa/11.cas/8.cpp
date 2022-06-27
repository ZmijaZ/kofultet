#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tacka{

public:

    Tacka(){};
    Tacka(int _x, int _y){
        x = _x;
        y = _y;
    }

    int get_x()const {return x;}
    int get_y()const {return y;}

private:

    int x;
    int y;

};

Tacka a0;

void zameni(Tacka &a1, Tacka &a2){

    Tacka tmp = a1;
    a1 = a2;
    a2 = tmp;

}

int orijentacija(Tacka p, Tacka q, Tacka r){

    int vrednost = (q.get_y() - p.get_y()) * (r.get_x() - q.get_x()) - (q.get_x() - p.get_x()) * (r.get_y() - q.get_y());

    if(vrednost == 0)
        return 0;

    if(vrednost > 0)
        return 1;
    else
        return 2;

}

bool uporedi(Tacka &a1, Tacka &a2){

    int orijent = orijentacija(a0, a1, a2);

    if(orijent == 0){
        cout << "Postoje 3 tacke koje su kolinearne :) \n";
        exit(EXIT_SUCCESS);
    }

    return orijent == 2;
}

void kolinearne(vector<Tacka> &tacke){

    int n = tacke.size();

    for(int i = 0; i<n; i++){

        zameni(tacke[0], tacke[i]);
        a0 = tacke[0];
        sort(tacke.begin() + 1, tacke.end(), uporedi);

    }

}


int main(){

    cout << "Koliko tacaka postoji? ";
    int n;
    cin >> n;

    vector<Tacka>tacke(n);

    cout << "Koje su to tacke? ";

    for(int i = 0; i<n; i++){

        int x, y;
        cin >> x >> y;
        Tacka tmp(x, y);
        tacke[i] = tmp;
    }

    kolinearne(tacke);

    cout << "Nikoje 3 nisu kolinearne!\n";

    return 0;
}

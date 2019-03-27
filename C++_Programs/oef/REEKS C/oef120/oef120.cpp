#include <cmath>  // abs berekent absolute waarde van een int (fabs is voor double)
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>  // vergelijk met Scanner(String) in Java
#include <string>   // nodig bij het inlezen van een breuk

#include "Breuk.h"

using namespace std;

void deel1() {
    Breuk a(2, 5);
    Breuk b(1, -2);
    cout << a << " + " << b << " = ";
    cout << (a + b) << " [-1/10 ?]" << endl;
    cout << "De tegengestelde breuk van " << a << " is " << -a << " [-2/5 ?]." << endl;
    Breuk f = a + b;
    cout << "De som van " << a << " en " << b << " is " << f << " [-1/10 ?]" << endl;
    Breuk g(f);
    cout << "en dat is gelijk aan de breuk " << g << " [-1/10 ?]." << endl;
    cout << a << " - " << b << " = ";
    cout << (a - b) << " [9/10 ?]" << endl;
    cout << a << " += " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
    a += b;
    cout << a << " [-1/10 ?]" << endl;
    cout << a << " -= " << b << " geeft als resultaat dat de breuk " << a << " verandert in ";
    a -= b;
    cout << a << " [2/5 ?]" << endl;
    cout << "Ik verhoog nu de breuk a=" << a << " met 2 eenheden; dan is a=";
    cout << ++(++a) << " [12/5 ?]" << endl;
    cout << "Na dit uitschrijven zal b=" << b++ << " ook met een eenheid verhoogd zijn, nl. ";
    cout << "b=" << b << " [1/2 ?]" << endl;
    Breuk c(2, 3);
    Breuk d(3, 4);
    Breuk e(1, 2);
    (c -= d) += e;
    cout << "Indien hier 5/12 staat, heb je de operatoren -= en += goed geschreven: " << c << endl;
}
void deel2() {
    Breuk d(2, 10);
    Breuk e(3);
    cout << d << " is stambreuk: " << is_stambreuk(d) << endl;
    Breuk f(3, 4);
    cout << endl
         << "We starten van een breuk, en tellen er telkens een eenheid bij op: " << endl
         << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << " meer dan " << f << " is " << (i + f) << " = " << (f + i) << endl;
    }
    cout << endl
         << "Al deze breuken in een verzameling: " << endl;
    set<Breuk> verz;
    for (int i = 0; i < 10; i++) {
        verz.insert(i + f);
        verz.insert(f + i);
    }
    for (Breuk b : verz) {
        cout << b << endl;
    }
}
void deel3() {
    Breuk a(13, 12);
    Breuk b(2);
    Breuk c;
    cout << endl
         << "Geef c op (onder de vorm teller/noemer (bvb 13/12) of teller (bvb 13) : ";
    cin >> c;
    if (a == c) {
        cout << a << " is gelijk aan " << c << endl;
    }
    if (a != c) {
        cout << a << " is niet gelijk aan " << c << endl;
    }
}
int main() {
    deel1();
    deel2();
    deel3();
    return 0;
}

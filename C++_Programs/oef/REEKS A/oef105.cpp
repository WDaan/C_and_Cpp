#include <iostream>

using namespace std;

struct persoon {
    string naam;
    int leeftijd;
    double lengte;
};

int el_grootte(const string &woord) {
    return woord.length();
}

int el_grootte(int n) {
    return n;
}

double el_grootte(double n) {
    return n;
}

int el_grootte(const persoon &p) {
    //return el_grootte(p.naam);
    //return el_grootte(p.leeftijd);
    return el_grootte(p.lengte) * 100;
}

template <typename T>
T grootste(const T t[], int n) {
    T grootste = t[0];
    for (int i = 1; i < n; i++) {
        if (el_grootte(t[i]) > el_grootte(grootste)) {
            grootste = t[i];
        }
    }
    return grootste;
}

void initialiseer(persoon &p, const string &naam, int leeftijd, double lengte) {
    p.naam = naam;
    p.leeftijd = leeftijd;
    p.lengte = lengte;
}

void print(persoon p) {
    cout << p.naam << " is " << p.leeftijd << " jaar oud en " << p.lengte << "m groot." << endl;
}

int main() {
    double getallen[5] = {5.5, 7.7, 2.2, 9.9, 9.8};
    string woorden[3] = {"geloof", "hoop", "de liefde"};
    cout << grootste(getallen, 5) << endl;
    cout << "De grootste van de drie is " << grootste(woorden, 3) << "." << endl;

    persoon p[3];
    initialiseer(p[0], "Samuel", 12, 1.52);
    initialiseer(p[1], "Jente", 22, 1.81);
    initialiseer(p[2], "Idris", 42, 1.73);
    print(grootste(p, 3));
    return 0;
}
#include "Breuk.h"
#include <cmath>
#include <iostream>
#include <sstream>  // vergelijk met Scanner(String) in Java
#include <string>   // nodig bij het inlezen van een breuk

using namespace std;

/* zet deze functie in het bestand breuk.cpp*/
int mijn_ggd(int a, int b) {
    if (a < 0 || b < 0) {
        return mijn_ggd(abs(a), abs(b));
    }
    if (a < b) {
        return mijn_ggd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return mijn_ggd(b, a % b);
}

void Breuk::normaliseer() {
    int c = mijn_ggd(a, b);
    a /= c;
    b /= c;
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
}

bool is_stambreuk(const Breuk& B) {
    return (B.a == 1);
}

bool Breuk::operator==(const Breuk& B) const {
    return (this->a == B.a && this->b == B.b);
}
bool Breuk::operator!=(const Breuk& B) const {
    return (this->a != B.a || this->b != B.b);
}

bool Breuk::operator<(const Breuk& B) const {
    return (this->a / this->b) < (B.a / B.b);
}

Breuk Breuk::operator+(const Breuk& B) const {
    /*eerst op gelijke noemer zetten*/
    int noemer, teller1, teller2;
    if (b != B.b) {
        noemer = b * B.b;
        teller1 = a * B.b;
        teller2 = B.a * b;
    }
    Breuk som(teller1 + teller2, noemer);
    som.normaliseer();
    return som;
}
Breuk Breuk::operator-(const Breuk& B) const {
    int noemer, teller1, teller2;
    if (b != B.b) {
        noemer = b * B.b;
        teller1 = a * B.b;
        teller2 = B.a * b;
    }
    Breuk ver(teller1 - teller2, noemer);
    ver.normaliseer();
    return ver;
}
Breuk& Breuk::operator++() {
    a += b;
    normaliseer();
    return *this;
}
Breuk& Breuk::operator+=(const Breuk& B) {
    int noemer, teller1, teller2;
    noemer = b * B.b;
    teller1 = a * B.b;
    teller2 = B.a * b;
    a = teller1 + teller2;
    b = noemer;
    normaliseer();
    return *this;
}
Breuk& Breuk::operator-=(const Breuk& B) {
    int noemer, teller1, teller2;
    noemer = b * B.b;
    teller1 = a * B.b;
    teller2 = B.a * b;
    a = teller1 - teller2;
    b = noemer;
    normaliseer();
    // of gwn operator+=(-b);
    return *this;
}

Breuk Breuk::operator-() const {
    Breuk B(-a, b);
    return B;
}

Breuk Breuk::operator++(int x) {
    Breuk temp(*this);
    a += b;
    normaliseer();
    return temp;
}

Breuk operator+(int i, const Breuk& B) {
    Breuk temp(B);
    temp.a += i * temp.b;
    return temp;
}

ostream& operator<<(ostream& os, const Breuk& B) {
    os << B.a << "/" << B.b;
    return os;
}

istream& operator>>(istream& is, Breuk& B) {
    string line;
    if (getline(is, line)) {
        istringstream iss(line);
        char c;
        iss >> B.a;
        if (iss >> c && c == '/') iss >> B.b;
    }
    return is;
}

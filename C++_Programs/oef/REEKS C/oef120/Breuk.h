#ifndef BREUK_H
#define BREUK_H
#include <iostream>
using namespace std;

int mijn_ggd(int a, int b);

class Breuk {
   public:
    Breuk(int a = 0, int b = 1) : a(a), b(b) { normaliseer(); }

    bool operator==(const Breuk& B) const;
    bool operator!=(const Breuk& B) const;
    bool operator<(const Breuk& B) const;
    Breuk operator+(const Breuk& B) const;
    Breuk operator-(const Breuk& B) const;
    Breuk& operator+=(const Breuk& B);
    Breuk& operator-=(const Breuk& B);
    Breuk operator-() const;
    Breuk& operator++(); //++x
    Breuk operator++(int); //x++

    friend ostream& operator<<(ostream& os, const Breuk& B);
    friend istream& operator>>(istream& is, Breuk& B);
    friend Breuk operator+(int i, const Breuk& B);
    friend bool is_stambreuk(const Breuk& B);

   private:
    int a, b;
    void normaliseer();
};
ostream& operator<<(ostream& os, const Breuk& B);
istream& operator>>(istream& is, Breuk& B);
Breuk operator+(int i, const Breuk& B);
bool is_stambreuk(const Breuk& B);

#endif

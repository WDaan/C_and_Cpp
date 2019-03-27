#include <iostream>
using namespace std;
class Rechthoek {
   public:
    Rechthoek(int b = 1, int h = 1) : breedte(b), hoogte(h) {}
    int oppervlakte() const { return breedte * hoogte; }
    int omtrek() const { return (2 * breedte + 2 * hoogte); }
    virtual void print(ostream& os) const {
        os << "Rechthoek: " << hoogte << " op " << breedte << endl;
    }

    // attributen voorzien voor hoogte en breedte
    // (type int)
   protected:
    int breedte, hoogte;
};

ostream& operator<<(ostream& os, const Rechthoek& r) {
    r.print(os);
    return os;
}

// afgeleid van Rechthoek; pas aan in hoofding
class GekleurdeRechthoek : public Rechthoek {
   public:
    GekleurdeRechthoek(int a = 1, int b = 1, string c = "onbekend") : Rechthoek(a, b), color(c) {}
    virtual void print(ostream& os) const {
        Rechthoek::print(os);
        os << " kleur: " << color << endl;
    }

   protected:
    string color = "";  // enkel extra attribuut voor kleur
};

// afgeleid van Rechthoek; pas aan in hoofding
class Vierkant : public Rechthoek {
   public:  // geen extra attributen voorzien!
    Vierkant(int a = 1) : Rechthoek(a, a){};
    virtual void print(ostream& os) const {
        os << "Vierkant: zijde " << breedte << endl;
    }
};

// afgeleid van GekleurdRechthoek en Vierkant; pas aan in hoofding
class GekleurdVierkant : public Vierkant, public GekleurdeRechthoek {
   public:  // geen extra attributen voorzien!
    GekleurdVierkant(int a = 1, string c = "onbekend") : Vierkant(a), GekleurdeRechthoek(a, a, c){};
    virtual void print(ostream& os) const {
        Vierkant::print(os);
        os << " kleur: " << color << endl;
    }
    friend ostream& operator<<(ostream& os, const GekleurdeRechthoek& gv) {
        gv.print(os);
        return os;
    }
};

int main() {
    Rechthoek r1;
    r1.print(cout);
    cout << " oppervlakte: " << r1.oppervlakte() << endl
         << " omtrek: " << r1.omtrek() << endl;
    Rechthoek r2(4, 6);
    cout << r2;
    cout << " oppervlakte: " << r2.oppervlakte() << endl
         << " omtrek: " << r2.omtrek() << endl;
    GekleurdeRechthoek gr1;
    gr1.print(cout);
    cout << " oppervlakte: " << gr1.oppervlakte() << endl
         << " omtrek: " << gr1.omtrek() << endl;
    GekleurdeRechthoek gr2(5, 7);
    cout << gr2;
    cout << " oppervlakte: " << gr2.oppervlakte() << endl
         << " omtrek: " << gr2.omtrek() << endl;
    GekleurdeRechthoek gr3(6, 9, "rood");
    gr3.print(cout);
    cout << " oppervlakte: " << gr3.oppervlakte() << endl
         << " omtrek: " << gr3.omtrek() << endl;
    Vierkant v1;
    cout << v1;
    cout << " oppervlakte: " << v1.oppervlakte() << endl
         << " omtrek: " << v1.omtrek() << endl;
    Vierkant v2(10);
    v2.print(cout);
    cout << " oppervlakte: " << v2.oppervlakte() << endl
         << " omtrek: " << v2.omtrek() << endl;
    GekleurdVierkant gv1;
    cout << gv1;
    cout << " oppervlakte: " << gv1.Vierkant::oppervlakte() << endl
         << " omtrek: " << gv1.Vierkant::omtrek() << endl;
    GekleurdVierkant gv2(12);
    gv2.print(cout);
    cout << " oppervlakte: " << gv2.Vierkant::oppervlakte() << endl
         << " omtrek: " << gv2.Vierkant::omtrek() << endl;
    GekleurdVierkant gv3(15, "geel");
    cout << gv3;
    cout << " oppervlakte: " << gv3.Vierkant::oppervlakte() << endl
         << " omtrek: " << gv3.Vierkant::omtrek() << endl;
    return 0;
}
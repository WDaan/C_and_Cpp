#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class Rechthoek {
   public:
    Rechthoek(int b = 1, int h = 1) : breedte(b), hoogte(h) {}
    int oppervlakte() const { return breedte * hoogte; }
    int omtrek() const { return (2 * breedte + 2 * hoogte); }
    friend ostream& operator<<(ostream& os, const Rechthoek& r);
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
    int oppervlakte() const { return breedte * breedte; };
    int omtrek() const { return 4 * breedte; };
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
    unique_ptr<Rechthoek> r2 = make_unique<Rechthoek>(4, 6);
    unique_ptr<GekleurdeRechthoek> gr1 = make_unique<GekleurdeRechthoek>();
    unique_ptr<GekleurdeRechthoek> gr3 = make_unique<GekleurdeRechthoek>(6, 9, "rood");
    unique_ptr<Vierkant> v2 = make_unique<Vierkant>(10);
    unique_ptr<Vierkant> gv1 = make_unique<GekleurdVierkant>(5, "groen");
    vector<unique_ptr<Rechthoek>> v;
    v.push_back(move(r2));
    v.push_back(move(gr1));
    v.push_back(move(gr3));
    v.push_back(move(v2));
    v.push_back(move(gv1));
    for (int i = 0; i < v.size(); i++) {
        cout << *v[i];
        cout << " oppervlakte: " << v[i]->oppervlakte() << endl
             << " omtrek: " << v[i]->omtrek() << endl;
    }
    return 0;
}
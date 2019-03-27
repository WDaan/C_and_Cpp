#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
using namespace std;

class Langeslang : public vector<unique_ptr<int>> {
   private:
    void schrijf(ostream&) const {
        for (int i = 0; i < this->size(); i++) {
            cout << *(*this)[i] << " ";
        }
    }

   public:
    void vul(const vector<int>& v) {
        for (int i : v) {
            this->push_back(make_unique<int>(i));
        }
    }
    /* of
    void Langeslang ::vul(const vector<int>& v) {
        resize(v.size());
        for (int i = 0; i < size(); i++) {
            (*this)[i] = make_unique<int>(v[i]);
        }
    }
    */
    Langeslang& concatenate(Langeslang& s) {
        int end = size();
        if (this == &s) {
            vector<int> v;
            for (int i = 0; i < s.size(); i++) {
                v.push_back(*s[i]);
            }
            vul(v);
        } else {
            resize(size() + s.size());
            for (int i = 0; i < s.size(); i++) {
                (*this)[end + i] = move(s[i]);
            }
            s.clear();
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Langeslang& l) {
        l.schrijf(out);
        return out;
    }
};

int main() {
    Langeslang a;
    Langeslang b;
    Langeslang c;
    a.vul({1, 2});
    // via a vind je de getallen 1 en 2
    b.vul({3, 4, 5});  // via b vind je de getallen 3, 4 en 5
    c.vul({6, 7});
    // via c vind je de getallen 6 en 7 cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl<<endl;
    a.concatenate(a);  // via a vind je nu de 4 getallen 1, 2, 1 en 2
    cout << "na a.concatenate(a)" << endl;
    cout << "a: " << a << endl
         << "b: " << b << endl
         << "c: " << c << endl
         << endl;
    a.concatenate(b).concatenate(c);
    // via a vind je nu de 9 getallen 1, 2, 1, 2, 3, 4, 5, 6 en 7
    // b is leeg
    // c is leeg
    cout << "na a.concatenate(b).concatenate(c)" << endl;
    cout << "a: " << a << endl
         << "b: " << b << endl
         << "c: " << c << endl
         << endl;
    return 0;
}
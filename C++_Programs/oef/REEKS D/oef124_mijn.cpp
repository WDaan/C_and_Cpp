#include <iostream>
#include <set>
#include <vector>
using namespace std;

template <typename T>
class mijn_vector : public vector<T> {
   public:
    mijn_vector(const vector<T>& v) {
        for (T i : v) {
            this->push_back(i);
        }
    }
    mijn_vector(initializer_list<T> l) {
        for (T i : l) {
            this->push_back(i);
        }
    }
    mijn_vector(int size) {
        this->resize(size);
    }
    void verdubbel(bool param = 0) {
        if (param) {
            this->resize(this->size() * 2);
            int hulp;
            for (int i = this->size(); i >= 0; i--) {
                (*this)[i] = (*this)[i / 2];
            }
        } else {
            for (int i = 0; i < this->size(); i++) {
                (*this)[i] += (*this)[i];  // of *=2 maar werkt niet op string
            }
        }
    }

    friend ostream& operator<<(ostream& os, const mijn_vector<T>& v) {
        int i;
        os << '[';
        for (i = 0; i < v.size() - 1; i++) {
            os << v[i] << " - ";
        }
        os << v[v.size() - 1];
        os << ']' << endl;
        return os;
    }

   private:
};

int main() {
    mijn_vector<int> v{10, 20, 30};
    cout << v;
    v.verdubbel();
    cout << endl
         << "na verdubbelen zonder parameter: " << v;
    v.verdubbel(true);
    cout << endl
         << "na verdubbelen met param true: " << v;
    mijn_vector<int> w(v);
    cout << endl
         << "een kopie van v: " << w;
    mijn_vector<double> u(7);
    cout << endl
         << "een vector met 7 default-elt: " << u;
    for (int i = 0; i < u.size(); i++) {
        u[i] = i * 1.1;
    }
    cout << endl
         << "na opvullen met getallen: " << u;
    u.verdubbel();
    cout << endl
         << "na verdubbelen zonder parameter: " << u;
    mijn_vector<string> s{"papageno", "appelboom", "poezenstaart"};
    cout << endl
         << "een vector met woorden: " << s;
    s.verdubbel();
    cout << endl
         << "na verdubbelen zonder parameter: " << s;
    s.verdubbel(true);
    cout << endl
         << "na verdubbelen met param true: " << s;
    return 0;
}
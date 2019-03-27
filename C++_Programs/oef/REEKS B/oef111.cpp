#include <iostream>
#include <vector>

using namespace std;

struct persoon {
    string naam;
    int leeftijd;
};

ostream& operator<<(ostream& out, const persoon& p) {
    out << p.naam << " (" << p.leeftijd << " j)";
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vt) {
    for (int i = 0; i < vt.size(); i++) {
        out << vt[i] << " ";
    }
    return out;
}

template <typename T>
void schrijf(const vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

int main() {
    vector<int> v;
    v.reserve(3);
    cout << "size: " << v.size() << endl;
    cout << "capaciteit: " << v.capacity() << endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << "size: " << v.size() << endl;
    cout << "capaciteit: " << v.capacity() << endl;
    cout << v;
    cout << endl;
    //persoon
    vector<persoon> vp;
    vp.push_back({"Daan", 18});
    schrijf(vp);
    cout << endl;

    vector<vector<int>> v2(1);
    v2[0].push_back(1);
    cout << v2;

    return 0;
}
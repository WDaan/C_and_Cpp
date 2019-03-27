#include <fstream>
#include "containers.h"

int main() {
    /* regels inlezen*/
    vector<int> v;
    v.reserve(10);
    ifstream inv1;
    inv1.open("regelnummers.txt");
    int r;
    if (inv1.is_open()) {
        inv1 >> r;
        while (inv1.good()) {
            v.push_back(r);
            inv1 >> r;
        }
    }
    inv1.close();
    cout << v << endl;
    /*in map steken */
    map<int, string> mp;
    for (int i = 0; i < v.size(); i++) {
        mp[v[i]];
    }
    /*bestand uilezen */
    ifstream inv2;
    inv2.open("nbible.txt");
    int lijn_counter = 0;
    map<int, string>::iterator it;
    if (inv2.is_open()) {
        string lijn;
        getline(inv2, lijn);
        while (inv2.good() && lijn_counter <= 29454) {
            it = mp.find(lijn_counter);
            if (it != mp.end()) {
                mp[lijn_counter] += lijn;
            }
            getline(inv2, lijn);
            lijn_counter++;
        }
    }
    inv2.close();

    /*uitprinten */
    for (int i : v) {
        cout << i << ": " << mp[i] << endl;
    }

    return 0;
}
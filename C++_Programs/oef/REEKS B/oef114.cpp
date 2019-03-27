#include "containers.h"

int main() {
    map<char, int> mp;
    set<string> aanw;
    string woord;
    cout << "Geef woorden in (stop met STOP) :" << endl;
    cin >> woord;
    while (woord != "STOP") {
        if (aanw.count(woord) == 0) {
            char a = woord[0];
            mp[a] += 1;
            aanw.insert(woord);
        }
        cin >> woord;
    }
    cout << "Geef een letter in: " << endl;
    char l;
    cin >> l;
    cout << "Aantal verschillende woorden beginnend met de letter \"" << l << "\" : " << endl;
    for (pair<char, int> p : mp) {
        char pl = p.first;
        if (pl == l) {
            cout << p.second << endl;
        }
    }
    return 0;
}
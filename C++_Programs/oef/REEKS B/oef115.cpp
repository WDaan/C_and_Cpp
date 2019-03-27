#include <fstream>
#include "containers.h"

int main() {
    ifstream inv;
    inv.open("bible_stop.txt");
    vector<map<char, set<string>>> vmap(30); //geen idee wrm hier char, int zou mss logischer zijn
    string woord;
    cout << "Geef een woord in (stop met STOP): " << endl;
    inv >> woord;
    while (woord != "STOP") {
        int wlengte = woord.length();
        if (wlengte > vmap.size() - 1) {
            vmap.resize(wlengte + 1);
        }
        char el = woord[0];
        int index = (int)el - 97;
        vmap[wlengte][index].insert(woord);
        inv >> woord;
    }

    /* alles uitprinten
    for (int i = 0; i < vmap.size(); i++) {
        if (!vmap[i].empty()) {
            cout << "woorden met woordlengte \"" << i << "\": " << endl;
            for (pair<char, set<string>> p : vmap[i]) {
                cout << "beginnend met letter \"" << (char)(p.first + 97) << "\": " << endl;
                for (string s : p.second) {
                    cout << s << "~";
                }
                cout << endl;
            }
        }
    }
    */

    string sint = "sinterklaas";
    int lengte = sint.length();
    int ind = 's' - 97;

    cout << "Woorden met lengte \"" << lengte << "\" & ";
    cout << "beginnend met letter \"" << (char)(ind + 97) << "\": " << endl
         << endl;
    for (string s : vmap[lengte][ind]) {
        cout << s << "\t---\t";
    }
    cout << endl;

    return 0;
}
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "bestand_niet_lang_genoeg.h"
using namespace std;

string regel_uit_bestand(const string &file, int r) {
    string lijn;
    ifstream inv(file);
    if (!inv.is_open()) {
        throw file;
    }
    while (!inv.eof()) {
        getline(inv, lijn);
        if (lijn != "VERHAAL") {
            throw lijn.c_str();
        }
        for (int i = 1; i < r; i++) {
            lijn = "";
            getline(inv, lijn);
        }
        if (!inv.eof())
            return lijn;
    }
    throw bestand_niet_lang_genoeg(file, r);
}

int main() {
    vector<string> bestandsnamen{"niks", "een", "twee", "drie", "vier", "vijf", "zes", "zeven", "acht", "negen", "tien", "elf", "twaalf"};
    vector<int> nrs{8, 5, 2, 10, 7, 3, 8, 4, 1, 1, 6, 2, 4};
    string bestanden_niet_gevonden = "";
    string bestanden_niet_lang_genoeg = "";
    string eerste_woorden = "";

    for (int i = 0; i < bestandsnamen.size(); i++) {
        try {
            cout << regel_uit_bestand("txts\\" + bestandsnamen[i] + ".txt", nrs[i]) << endl;
        } catch (const string &s) {
            bestanden_niet_gevonden += s + " \n";
        } catch (const bestand_niet_lang_genoeg &b) {
            bestanden_niet_lang_genoeg += b.what();
        } catch (const char *s) {
            eerste_woorden += s;
            eerste_woorden += "  ";
        }
    }
    cout << endl
         << endl
         << "BESTANDEN NIET GEVONDEN:" << endl;
    cout << bestanden_niet_gevonden;
    cout << endl
         << "BESTANDEN NIET LANG GENOEG:" << endl;
    cout << bestanden_niet_lang_genoeg << endl;
    cout << endl
         << "BESTANDEN ZONDER STARTWOORD 'VERHAAL':" << endl;
    cout << "dit waren de woorden die er wel als eerste stonden:" << endl
         << endl;
    cout << eerste_woorden << endl
         << endl;
    return 0;
}

/*

try {
        string lijn = regel_uit_bestand("txts\\een.txt", 6);
        cout << lijn;
    } catch (const string &s) {
        cout << s;
    } catch (const bestand_niet_lang_genoeg &b) {
        cout << b.what();
    } catch (const char *s) {
        cout << s;
    }
*/

/*
for (int i = 0; i < bestandsnamen.size(); i++) {
        try {
            cout << regel_uit_bestand("txts\\" + bestandsnamen[i] + ".txt", nrs[i]) << endl;
        } catch (const string &s) {
            bestanden_niet_gevonden += s + " \n";
        } catch (const bestand_niet_lang_genoeg &b) {
            bestanden_niet_lang_genoeg += b.what();
        } catch (const char *s) {
            eerste_woorden += s;
        }
    }
    cout << endl
         << endl
         << "BESTANDEN NIET GEVONDEN:" << endl;
    cout << bestanden_niet_gevonden;
    cout << endl
         << "BESTANDEN NIET LANG GENOEG:" << endl;
    cout << bestanden_niet_lang_genoeg << endl;
    cout << endl
         << "BESTANDEN ZONDER STARTWOORD 'VERHAAL':" << endl;
    cout << "dit waren de woorden die er wel als eerste stonden:" << endl
         << endl;
    cout << eerste_woorden << endl
         << endl;
    return 0;

*/
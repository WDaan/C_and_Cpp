#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream inv;
    inv.open("lord.txt");
    int freq[26] = {0};

    if (!inv.is_open()) {
        exit(EXIT_FAILURE);
    } else {
        cout << "openen gelukt!" << endl;

        char c;
        inv >> c;
        while (inv.good()) {
            if (c >= 'a' && c <= 'z') {
                freq[c - 97]++;
            }
            inv >> c;
        }
        for (int i = 0; i < 26; i++) {
            cout << "letter " << (char)(i + 97) << " komt " << freq[i] << " keer voor." << endl;
        }
        inv.close();
    }

    return 0;
}
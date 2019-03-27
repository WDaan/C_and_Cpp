#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int i = 0;
    //cout << argc << endl;
    //cout << argv[1] << endl;
    ifstream* inv = new ifstream[argc - 1];
    while (i < argc - 1) {
        inv[i].open(argv[i + 1]);
        i++;
    }
    ofstream uitv;
    uitv.open("mix.txt", ios::app);
    int freq[26] = {0};
    for (int i = 0; i < argc - 1; i++) {
        if (!inv[i].is_open()) {
            exit(EXIT_FAILURE);
        }
    }
    cout << "openen gelukt!" << endl;

    string* lijnen = new string[argc - 1];

    bool ok = true;
    int k = 0;

    while (ok) {
        for (int i = 0; i < argc - 1; i++) {
            /* inlezen */
            if (inv[i].good()) {
                getline(inv[i], lijnen[i]);
            } else {
                ok = false;
            }
        }
        /* uitlezen */
        uitv << lijnen[k] << endl;
        k++;
        if (k == argc - 1) {
            k = 0;
        }
    }

    i = 0;
    while (i < argc - 1) {
        inv[i].close();
        i++;
    }

    delete[] inv;
    return 0;
}
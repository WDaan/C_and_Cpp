#include <iostream>
#include <memory>
using namespace std;

void schrijf(const string* s, int aantal) {
    for (int i = 0; i < aantal; i++) {
        cout << *s++ << " - ";
    }
    cout << endl;
}

void schrijf(const unique_ptr<string>& s) {
    if (s == nullptr) {
        cout << "NULL";
    } else {
        cout << *s;
    }
}

void schrijf(const unique_ptr<string>* p, int aantal) {
    cout << endl;
    for (int i = 0; i < aantal - 1; i++) {
        schrijf(p[i]);
        cout << " - ";
    }
    schrijf(p[aantal - 1]);
}
void verwijder(string* s, int aantal, int volgnr) {
    for (int i = volgnr; i < aantal - 1; i++) {
        s[i] = s[i + 1];
    }
}

void verwijder2(unique_ptr<string>* s, int aantal, int volgnr) {
    if (volgnr < aantal - 1) {
        for (int i = volgnr; i < aantal - 1; i++) {
            s[i] = move(s[i + 1]);
        }
    } else if (volgnr == aantal - 1) {
        s[volgnr].reset();
    }
}

int main() {
    string namen[] = {"Rein", "Ada", "Eppo", "Pascal", "Ilse"};
    schrijf(namen, 5);
    verwijder(namen, 5, 0);
    schrijf(namen, 5);

    unique_ptr<string> pnamen[] = {make_unique<string>("Rein"), make_unique<string>("Ada"), make_unique<string>("Eppo"), make_unique<string>("Pascal"), make_unique<string>("Ilse")};  //vul zelf deze array aan met 5 unieke pointers
    schrijf(pnamen, 5);
    verwijder2(pnamen, 5, 0);
    schrijf(pnamen, 5);

    return 0;
}
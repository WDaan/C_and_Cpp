#include "containers.h"

int main() {
    map<char, set<string>> mp;  //door deze set worden sws unieke woorden opgeslagen
    string woord;
    cout << "Geef woorden in (stop met STOP) :" << endl;
    cin >> woord;
    while (woord != "STOP") {
        char a = woord[0];
        mp[a].insert(woord);  //geen if om te checken of al bestaat, das bij JAVA
        cin >> woord;
    }
    cout << "Geef een letter in: " << endl;
    char l;
    cin >> l;
    cout << "Aantal verschillende woorden beginnend met de letter \"" << l << "\" : " << endl;
    for (string s : mp['l']) {  // of gwn mp[l]
        cout << s << "\t" << endl;
    }
    return 0;
}
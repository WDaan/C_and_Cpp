#include <ctime>
#include <iostream>
#include <random>
#include <string>

using namespace std;

string genereer_string(int n) {
    string s = "";
    int letter;
    for (int i = 0; i < n; i++) {
        letter = rand() % 26;  //van 0 tot 25
        char c = (char)letter + 97;
        s += c;
    }
    return s;
}

void vul_array_met_strings(string t[], int n, int len) {
    for (int i = 0; i < n; i++) {
        t[i] = genereer_string(len);
    }
}

void schrijf(const string t[], int n) {
    for (int i = 0; i < n; i++) {
        cout << t[i] << endl;
    }
}

void bepaal_min_en_max(const string t[], int n, string &max, string &min) {
    for (int i = 0; i < n; i++) {
        if (max.empty() || t[i] > max) {
            max = t[i];
        }
        if (min.empty() || t[i] < min) {
            min = t[i];
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 5;
    string t[n];
    vul_array_met_strings(t, n, 10);
    schrijf(t, n);
    string max, min;
    bepaal_min_en_max(t, n, max, min);
    cout << "Max : " << max << endl
         << "Min : " << min;
    return 0;
}
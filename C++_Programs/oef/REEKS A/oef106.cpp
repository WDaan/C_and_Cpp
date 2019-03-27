#include <iostream>

using namespace std;

template <typename T>
void schrijf(const T t[], int n, bool omgk = false, char teken = ' ') {
    if (!omgk) {
        for (int i = 0; i < n - 1; i++) {
            cout << t[i] << teken;
        }
        cout << t[n - 1];
    } else {
        for (int i = 0; i < n - 1; i++) {
            cout << t[n - 1 - i] << teken;
        }
        cout << t[0];
    }
    cout << endl;
}

int main() {
    int t[] = {1, 3, 5, 7, 9, 11, 13};
    schrijf(t, 7);
    schrijf(t, 7, true);
    schrijf(t, 7, false, '-');
    schrijf(t, 7, true, '-');
    return 0;
}
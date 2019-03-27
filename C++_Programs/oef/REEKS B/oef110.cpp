#include <functional>
#include <iostream>

using namespace std;

void schrijf(const string &s, const int *t, int aantal) {
    cout << s << endl;
    for (int i = 0; i < aantal; i++) {
        cout << t[i] << "\t";
    }
    cout << endl;
}

void vul_array(const int *a, const int *b, int *c, int n, function<int(int x, int y)> f) {
    for (int i = 0; i < n; i++)
        c[i] = f(a[i], b[i]);
}

int main() {
    const int GROOTTE = 10;
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int c[GROOTTE];
    vul_array(a, b, c, GROOTTE, [](int x, int y) { return x + y; });
    schrijf("SOM:", c, GROOTTE);
    vul_array(a, b, c, GROOTTE, [](int x, int y) { return x * y; });
    schrijf("PRODUCT: ", c, GROOTTE);
    vul_array(a, b, c, GROOTTE, [](int x, int y) { return x - y; });
    schrijf("VERSCHIL: ", c, GROOTTE);
    return 0;
}
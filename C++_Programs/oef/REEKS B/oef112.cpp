#include <iostream>
#include <map>
#include <set>
#include <stack>

using namespace std;

/* via methodes */
template <typename T>
void schrijf_set(const set<T>& s) {
    cout << endl;
    for (T t : s) {
        cout << t << endl;
    }
}

template <typename T>
void schrijf_stack(stack<T>& st) {
    cout << endl;
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

template <typename key, typename val>
void schrijf_map(map<key, val>& mp) {
    cout << endl;
    typename map<key, val>::iterator it = mp.begin();
    while (it != mp.end()) {
        cout << it->first << "->"
             << it->second << endl;
        it++;
    }
}
/* via ostreams */

template <typename T>
ostream& operator<<(ostream& out, const set<T>& s) {
    for (T t : s) {
        out << t << endl;
    }
    return out;
}

template <typename T>
ostream& operator<<(ostream& out, stack<T> st) {
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return out;
}

template <typename key, typename val>
ostream& operator<<(ostream& out, const map<key, val>& mp) {
    typename map<key, val>::const_iterator it = mp.begin();
    while (it != mp.end()) {
        out << it->first << "->"
             << it->second << endl;
        it++;
    }
    return out;
}

int main() {
    //set
    set<string> s = {"Daan", "Wijns"};
    //schrijf_set(s);
    cout << s << endl;
    stack<int> n;
    n.push(1);
    n.push(2);
    n.push(3);
    //schrijf_stack(n);
    cout << n << endl;

    map<string, int> lft;
    lft["jan"] = 10;
    lft["an"] = 12;
    lft.insert(pair<string, int>("piet", 11));
    //schrijf_map(lft);
    cout << lft << endl;

    return 0;
}
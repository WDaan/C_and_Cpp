#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;
/* ---------- ostreams ----------- */

/* vector */

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vt) {
    for (int i = 0; i < vt.size(); i++) {
        out << vt[i] << " ";
    }
    out << endl;
    return out;
}

/*set*/
template <typename T>
ostream& operator<<(ostream& out, const set<T>& s) {
    for (T t : s) {
        out << t << endl;
    }
    out << endl;
    return out;
}

/*stack*/
template <typename T>
ostream& operator<<(ostream& out, stack<T> st) {
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    out << endl;
    return out;
}

/*map*/
template <typename key, typename val>
ostream& operator<<(ostream& out, const map<key, val>& mp) {
    typename map<key, val>::const_iterator it = mp.begin();
    while (it != mp.end()) {
        cout << it->first << "->"
             << it->second << endl;
        it++;
    }
    out << endl;
    return out;
}

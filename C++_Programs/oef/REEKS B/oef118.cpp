#include "containers.h"

int main() {
    set<string> s = {"Daan", "Ward", "Marijke", "Jens", "loic", "Marjolein", "Lynn"};
    cout << s << endl;
    set<string>::iterator it = s.begin();
    while (it != s.end()) {
        set<string>::iterator rm_it = it;
        it++;
        if (it != s.end()) {
            it++;
            it++;
        }
        if (rm_it != s.end())
            s.erase(rm_it);
    }
    cout << s << endl;
    return 0;
}
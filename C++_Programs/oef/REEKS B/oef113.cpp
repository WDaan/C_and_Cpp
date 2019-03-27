#include "containers.h"
#define AANTAL 5

int main() {

    //1
    stack<string> st;
    st.push("een");
    st.push("twee");
    st.push("drie");
    cout << st << endl;
    //schrijf_stack(st);  //2de keer lukt niet want hij is leeggemaakt
    
    //2
    vector<string> vt[AANTAL];
    vt[1].reserve(3);
    vt[1].push_back("aap");
    vt[1].push_back("noot");
    vt[1].push_back("mies");
    cout << vt[1] << endl;

    //3
    vector<vector<int>> vv;
    for (int i = 0; i < AANTAL; i++){
        vector<int> v(i);
        for (int k = 0; k < i; k++){
            v[k] = 10 * k;
        }
        vv.push_back(v);
    }
    cout << vv << endl;
    return 0;
}
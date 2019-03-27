#include "containers.h"

void vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(vector<map<string, stack<set<string>>>> &v, int i, const string &sleutel, const string &str1, const string &str2, const string &str3) {
    /*
    set<string> s;
    s.insert(str1);
    s.insert(str2);
    s.insert(str3);
    v[i][sleutel].push(s);
    */
    v[i][sleutel].push({str1, str2, str3});
}

bool i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(const vector<map<string, stack<set<string>>>> &v, int i, const string &woord, const string &element) {
    return v[i].find(woord)->second.top().count(element) > 0;
}

int main() {
    vector<map<string, stack<set<string>>>> v(5);
    int i = 3;
    string sleutel = "sleutel";
    string str1 = "str1";
    string str2 = "str2";
    string str3 = "str3";
    //vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(v, i, sleutel, str1, str2, str3);
    vul_in_i_de_map_stack_bij_sleutel_aan_met_set_van_drie_strings(v, 1, "noot", "do", "re", "mi");
    //cout << v << endl;
    if (i_de_map_beeldt_woord_af_op_stack_waarvan_bovenste_set_dit_element_bevat(v, 1, "noot", "re")) {
        cout << "ja!" << endl;
    }

    return 0;
}
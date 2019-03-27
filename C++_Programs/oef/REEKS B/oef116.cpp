/*

a)  met een set werken & dmv 
set.instert(woord).second == false;
enkel unieke woorden toevoegen... dan gwn set.size();


b) set<string>::iterator it = my_set.find(i-de woord);

for(it != my_set.find(j-de woord)){
    cout ....
}


c) stack<string> st => want last in first out.
void schrijf_stack(stack<T> &st) {
    cout << endl;
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}



d) map<string, int>   & dan woorden overlopen en counten 

kan zonder container, direct tellen

e) map<string, set<int>>

kan zonder container

f) map<string, int> //set<int> indien je alle locaties ook wilt

g) map<string, set<int>> // of vector<int>




















*/
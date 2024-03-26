// #include <iostream>
// #include <stack>
// #include <string>

// using namespace std;

// bool isValidLatex(string s) {
//     stack<char> st;

//     for (char c : s) {
//         if (c == '{' || c == '(' || c == '[') {
//             st.push(c);
//         }
//         else if (c == '}' || c == ')' || c == ']') {
//             if (st.empty()) {
//                 return false;
//             }
//             char top = st.top();
//             st.pop();
//             if ((c == '}' && top != '{') || 
//                 (c == ')' && top != '(') || 
//                 (c == ']' && top != '[')) {
//                 return false;
//             }
//         }
//     }

//     return st.empty();
// }

// int main() {
//     string s;
//     getline(cin, s);

//     if (isValidLatex(s)) cout<<1;
//     else cout<<0;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
bool Latex(string s, int n, int i, int dem) 
{
    if (i == n) return dem == 0;
    if (dem < 0) return false;
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
        return Latex(s, n, i + 1, dem + 1);
    if (s[i] == ')' || s[i] == '}' || s[i] == ']') 
        return Latex(s, n, i + 1, dem - 1);
    return Latex(s, n, i + 1, dem);
}

int main() 
{
    string s;
    getline(cin, s);
    int n = s.length();
    if (Latex(s, n, 0, 0)) cout<<1;
    else cout<<0;
    return 0;
}

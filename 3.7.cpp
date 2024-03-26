#include <bits/stdc++.h>
using namespace std;
string decimal_to_binary (int n) 
    {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) 
    {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}
int main() {
    int n;
    cin >> n;
    string s = decimal_to_binary(n);
    cout<<s<< endl;
    return 0;
}
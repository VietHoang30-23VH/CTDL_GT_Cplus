#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    if (a.length()!=b.length()) cout<<b.length();
    else
    {
        int s=-999;
        for (int i=0;i<a.length();i++)
            if (a[i]!=b[i])
            {
                s=i;
                break;
            }
        if (s<0) cout<<0;
        else cout<<a.length()-s;
    }
    return 0;
}
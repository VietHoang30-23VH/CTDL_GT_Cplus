#include <bits/stdc++.h>
using namespace std;
int main()
{
    int j;cin>>j;
    vector<vector<int>> a;
    for (int i=0;i<j;i++)
    {
        int m,n;
        cin>>m>>n;
        a.push_back({m,n});
    }
    for (int i=0;i<a.size();i++)
    {
        int m=a[i][0];
        int n=a[i][1];
        for (int l=m;l<=n;l++)
        {
            if (l%2==1)
            cout<<l<<endl;
        }
        cout<<endl;
    }
    return 0;
}

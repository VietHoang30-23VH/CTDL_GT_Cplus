#include <bits/stdc++.h>

using namespace std;
bool SapXep(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    cin>>n;
    int a[n+100];
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    sort(a[i],a[i+1],SapXep);
    
    int dem=0;
    for (int i=n;i>=1;i--)
        if (a[i]>=i)
        {
            dem++;
            cout<<i;
            break;
        }
    if (dem==0) cout<<0; 
    return 0;
}
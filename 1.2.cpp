#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n;//số tiền có thể chi,số mặt hàng;
    cin>>n;
    cin>>m;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
    int p=n-1;
    int q=0;
    int gtln=0;
    while(p>=1)
    {
        int s=0;
        while(q<p)
        {
            s=a[p]+a[q];
            if(s>m) break;
            q++;
        }
        s=a[p]+a[q-1];
        if(s<=m)
        {
            if(gtln<s) gtln=s;
        }
        p--;

    }
    cout<<gtln;
}
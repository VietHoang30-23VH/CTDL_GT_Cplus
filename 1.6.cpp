#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int main()
{
    int n,a[MAX],l=0,c=0;
    cin>>n;
    for (int i=0;i<n;i++)
    cin>>a[i];
    // tim gia tri co chi so le lon nhat 
    int max=a[1];
    for (int i=1;i<n;i=i+2)
    {
       if (a[i]>=max)
       {
           max=a[i];
           l=i;
       }
    }
    // tim gia tri co chi so chan nho nhat
    int min=a[0];
    for (int i=0;i<n;i=i+2)
    {
       if (a[i]<=min)
       {
           min=a[i];
           c=i;
       }
    }
    if (a[c]<a[l]) swap (a[c],a[l]);
    int max_sum=0;
    for (int i=0;i<n;i++)
    {
        max_sum+=pow(-1,i)*a[i];
    }
    cout<<max_sum;
    return 0;
}
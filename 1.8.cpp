#include <bits/stdc++.h>
using namespace std;
int swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int n,k,sv[n+1];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>sv[i];
    if(k>n) k=k%n;
    for(int j=0;j<k;j++)
        for(int i=n-1;i>0;i--)
            swap(sv[i],sv[i-1]);
    for(int i=0;i<n;i++)
        cout<<sv[i]<<" ";
    return 0;
}

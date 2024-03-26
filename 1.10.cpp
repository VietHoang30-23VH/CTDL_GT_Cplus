#include <bits/stdc++.h>
void  BinarySearch (std::vector<int> a, std::vector<int>x)
{
    for(int i=0; i<x.size(); i++)
    {
    int l=0, r=a.size()-1,check=0;
    while(l<=r)
    {
        if(a[l]==x[i]) {check=1; break;}
        else if(a[r]==x[i]) {check=1; break;}
        int m=(l+r)/2;
        if(a[m]==x[i]) {check=1; break;}
        else if(a[m]>x[i]) r=m-1;
        else l=m+1;
    }
     if(check==1) std::cout<<"YES"<<"\n";
     else std::cout<<"NO"<<"\n";
    }
}
int main()
{
    int n, q, tmp;
    std::vector<int> a;
    std::vector<int> x;
    std::cin>>n>>q;
    for(int i=0; i<n; i++)
     {
         std::cin>>tmp;
        a.push_back(tmp);
     }
    for(int i=0; i<q; i++)
     {
        std::cin>>tmp;
        x.push_back(tmp);
     }
    sort(a.begin(), a.end());
    BinarySearch(a,x);
    return 0;
} 
/* #include <bits/stdc++.h>
using namespace std;
#define MAX 1000000 
int a[MAX],x[MAX];
int n,q;
int l=0,r=n-1,dem=0;
int Binary(int a[], int x[])
{
    for (int i=0;i<q;i++)
    {
        l=0;r=n-1;dem=0;
        while (l<=r)
        {
            if (a[l]==x[i]) {dem=1; break;}
            else if (a[r]==x[i]) {dem=1;break;}
            int m=(l+r)/2;
            if (a[m]==x[i]) { dem=1; break;}
            else if (a[m]>x[i]) r=m-1;
            else l=m+1;
        }
        if( dem ==1 ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int Sort(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        int max=i;
        for (int j=i+1;j<n;j++)
        {
            if(a[max]<a[j]) max=j;
            swap(a[max],a[i]);
        }
    }
}
int main()
{
    cin>>n>>q;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<q;i++) cin>>x[i];
    
    Sort(a,n);
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    Binary(a,x);
}*/
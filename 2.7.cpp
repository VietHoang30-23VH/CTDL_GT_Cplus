#include<bits/stdc++.h>
using namespace std;
void xacdinh(string *a, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) 
            if(a[j]<a[j+1]) j=j+1;
        if(a[k]>=a[j]) return;
        std::swap(a[k],a[j]);
        k=j;
        j=2*k+1;
    }
}
void xaydung(string *a, int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        xacdinh(a,i,n);
        i--;
    }
}
void sapxep(string *a, int n)
{
    xaydung(a, n);
    while(n>0)
    {
        n=n-1;
        swap(a[0],a[n]);
        xacdinh(a, 0, n);
    }
}
int timkiem(string *a, int n)
{
    string ktr;
    ktr=a[0];
    int dem=0;
	for (int i = 1; i < n; i++){
		if (a[i]!=ktr)
        {
			++dem;
            ktr=a[i];
		}
	}
	return dem+1;
}
int main()
{
    int n;
    cin>>n;
    string a[n];
    for(int i=0; i< n; i++)
    {
        cin>>a[i];;
    }
    sapxep(a,n);
    cout<<timkiem(a,n);
return 0;
}
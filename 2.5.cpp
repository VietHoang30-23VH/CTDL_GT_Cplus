#include<bits/stdc++.h>
using namespace std;
void Heapify(int *a, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) 
            if(a[j]<a[j+1]) j=j+1;
        if(a[k]>=a[j]) return;
        swap(a[k], a[j]);
        k=j;
        j=2*k+1;
    }
}
void BuildHeap(int *a, int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        Heapify(a,i,n);
        i--;
    }
}
void HeapSort(int *a, int n)
{
    BuildHeap(a, n);
    while(n>0)
    {
        n=n-1;
        swap(a[0],a[n]);
        Heapify(a, 0, n);
    }
}
int MEX(int *a, int n)
{
	
	for (int i = 0; i < n; i++)
    {   
        if (a[0]>0) 
        {
            return 0;
            break;
        }
		else if (a[i+1] - a[i] > 1)
        {
			return a[i] + 1;
            break;
		}
	}
	return a[n-1] + 1;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i< n; i++)
    {
        cin>>a[i];;
    }
    HeapSort(a,n);
    cout<<MEX(a,n);
    return 0;
}
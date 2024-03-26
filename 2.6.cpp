#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x,y;
};
void Heapify(Point *a,int k,int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) 
        {
            if(a[j].x<a[j+1].x) j=j+1;
            else if(a[j].x==a[j+1].x)
            {
                if(a[j].y>a[j+1].y) j=j+1;
            }
        }
        if ( a[k].x>a[j].x || (a[k].x==a[j].x && a[k].y<a[j].y) ) return;
        std::dswap(a[k],a[j]);
        k=j;
        j=2*k+1;
    }
}
void BuildHeap(Point *a,int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        Heapify(a,i,n);
        i--;
    }
}
void HeapSort(Point *a,int n)
{
    BuildHeap(a,n);
    while(n>0)
    {
        n=n-1;
        swap(a[0],a[n]);
        Heapify(a,0,n);
    }
}
int n;
int main()
{
   
    cin>>n;
    Point a[n];
    for(int i=0;i<n;i++)
     {
        cin>>a[i].x>>a[i].y;
     }
    HeapSort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].x<<" "<<a[i].y<<"\n";
    }
    return 0;
}

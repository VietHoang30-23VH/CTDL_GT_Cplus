#include<bits/stdc++.h>
using namespace std;
struct Point 
{
    int x,y,z;
};
void Heap_Sort(Point *a, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) 
        {
            if (a[j].x < a[j+1].x) 
                j=j+1;
            else if(a[j].x==a[j+1].x)
            {
                if (a[j].y > a[j+1].y) 
                    j=j+1;
                else if (a[j].y==a[j+1].y)
                {
                    if(a[j].z<a[j+1].z) 
                        j=j+1;
                }
            }
        }
        if ( a[k].x>a[j].x || (a[k].x==a[j].x && a[k].y<a[j].y) || (a[k].x==a[j].x && a[k].y==a[j].y && a[k].z>a[j].z) ) 
            return;
            
        swap(a[k],a[j]);
        k=j;
        j=2*k+1;
    }
}
void Build(Point *a,int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        Heap_Sort(a,i,n);
        i--;
    }
}
void Sorting(Point *a,int n)
{
    Build(a, n);
    while(n>0)
    {
        n=n-1;
        swap(a[0],a[n]);
        Heap_Sort(a, 0, n);
    }
}

int main()
{
    int n;
    cin>>n;
    Point a[n];
    for(int i=0; i< n; i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    Sorting(a,n);
    for(int i=0; i<n; i++)
    {
        cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
    }
return 0;
}
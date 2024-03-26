#include <bits/stdc++.h>
using namespace std;
void BubbleSort(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=n-1;j>i;j--)
        {
            if (a[j]<a[j-1]) 
            swap (a[j-1],a[j]);
        }
    }
}
void SelectionSort(int a[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        int min=i;
        for (int j=i+1;j<n;j++)
        {
            if (a[j]<a[min])
            min=j;
        }swap(a[i],a[min]);
    }
}
void InsertionSort(int a[],int n)
{
    int pos,x;
    for (int i=1;i<n;i++)
    {
        x=a[i];
        pos=i-1;
        while(pos>=0 && a[pos]>x)
        {
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x;
    }
}
// HeapSort
void heapify(int a[],int n,int i)
{
    int min=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n && a[left]> a[min]) min=left;
    if (right<n && a[right]>a[min]) min=right;
    if (min!=i)
    {
        swap(a[i],a[min]);
        heapify(a,n,min);
    }
}
void HeapSort(int a[],int n)
{
    for (int i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for (int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
        cout << "Buoc" << n - i << ": "<<endl;
        for (int j = 0; j < n; j++) {
            cout << a[j] << " ";
            
        }
        cout<<endl;
    }
        cout << endl;
}
void QuickSort(int a[],int l,int r)
{
    int pivot=a[(l+r)/2];
    int i=l;
    int j=r;
    do 
    {
        while (a[i]>pivot) {i++;}
        while (a[j]<pivot) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if (i<r) QuickSort(a,i,r);
    if (j>l) QuickSort(a,l,i);
}
//  MergeSort
void merge(vector<int>a,int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    vector<int>leftarr(n1);
    vector<int>rightarr(n2);
    for (int i=0;i<n1;i++)
    {
        leftarr[i]=a[l+i];
    }
    for (int j=0;j<n2;j++)
    {
        rightarr[i]=a[m+1+j];
    }
    int i=0,j=0,k=l;
    while (i<n1 && j<n2)
    {
        if (leftarr[i]<=rightarr[j])
        {
            a[k]=leftarr[i];
            i++;
        }
        else 
        {
            a[k]=rightarr[j];
            j++;
        }
    }
}
void MergeSort(vector<int>a,int l,int r)
{   
    if (l<r)
    {int m=l+(r-l)/2;
    MergeSort(a,l,m);
    MergeSort(a,m+1,r);
    merge(a,l,m,r);}
}
int main()
{
    int a[100001],n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // Them thuat toan sap xep
    QuickSort(a,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<< " ";
    }
}
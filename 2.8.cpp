// #include <bits/stdc++.h>
// using namespace std;
// void heapify(int N, int i,vector<long long> &color)
// {
//     int largest = i, l = 2 * i + 1, r = 2 * i + 2;
//     if (l < N && color[l] > color[largest])
//         largest = l;
//     if (r < N && color[r] > color[largest])
//         largest = r;
//     if (largest != i) {
//         swap(color[i], color[largest]);
//         heapify(N, largest,color);
//     }
// }
// void heapSort(int N,vector<long long> &color)
// {
//     for (int i = N / 2 - 1; i >= 0; i--)
//         heapify(N, i,color);
//     for (int i = N - 1; i > 0; i--) {
//         swap(color[0], color[i]);
//         heapify(i, 0,color);
//     }
// }
// void Duplicate2(int n,int k, vector<long long> &color)
// { vector<long long> non_duplicate;
//     non_duplicate.push_back(color[0]);
//     for(int i=1;i < n;i++)
//     {
//     	if (color[i] != color[i - 1])
//     	{
//     		non_duplicate.push_back(color[i]);
//     	}
//     }
//     long long count = 1;
//     if (k <= non_duplicate.size())
//     {
//         for (int i = 0; i < k; i++)
//         {
//             cout<<non_duplicate[i]<<' ';
//         }
//     }
//     else
//     {
//         for(auto x : non_duplicate)
//         {
//             cout<<x<<' ';
//         }
//         k -= non_duplicate.size();
//         int index = n-1;
//         while (k > 0)
//         {
//             if (color[index] == color[index-1])
//             {
//                 cout<<color[index]<<" ";
//                 k--;
//             }
//             index--;
//         }
//     }
// }
// int main()
// {
//     long long n,k;
//     cin >> n >> k;
//     vector<long long> color;
//     long long temp;
//     for (long long i = 0; i < n; ++i)
//     {
//         cin>>temp;
//         color.push_back(temp);
//     }
//     heapSort(n,color); 
//     Duplicate2(n,k,color);
//     return 0;
// }
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
        swap(a[k],a[j]);
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
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i< n; i++)
    {
        cin>>a[i];
    }
    HeapSort(a,n);
    int nen[n];
    int j=0;
    nen[j]=a[0];
	for (int i = 1; i < n; i++)
    {
		if (a[i]!=nen[j])
        {
			++j;
            nen[j]=a[i];
		}
    }
    int m=j+1;
    if(k<=m)
    {
        for(int i=0;i<j+1;i++)
        {
            cout<<nen[i]<<" ";
        }
    }
    else
    {
        for(int i=0;i<j+1;i++)
        {
            cout<<nen[i]<<" ";
        }
        k-=m;
        int l=n-1;
        while(k>0)
        {
            if(a[l]==a[l-1])
            {
                cout<<a[l]<<" ";
                k--;
            }
            l--;
        }
    }
return 0;
}

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp >= 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}
void SelectionSort(vector<int>& a, int n)
{
    for (int i=0;i<n-1;i++)
    {
        int max=i;
        for (int j=i+1;j<n;j++)
        {
            if (a[j] > a[max]) max=j;
        }
        cout<<"i="<<i<<": "<<"swap"<<" ("<<a[i]<<"-"<<a[max]<<")"<<endl;
        swap(a[i],a[max]);
    }
}
void Sort(vector<int>A)
{
   SelectionSort(A,A.size());
}





int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
// cau 5
// void Input(vector<vector<int>> &G,int &v,int &e)
// {
//     for (int i=0;i<e;i++)
//     {
//         int u,w;
//         cin>>u>>w;
//         G[u][w]=1;
//     }
//     for (int i=0;i<v;i++)
//     {
//         for (int j=0;j<v;j++)
//         {
//             cout<<G[i][j]<< " ";
//         }
//         cout<<"\n";
//     }
//     cout<<endl;
// }
// int main()
// {
// 	int v,e; //v là số đỉnh, e là số cạnh
// 	cin>>e>>v;
// 	vector<vector<int>> G (v,vector<int>(v,0));
// 	Input(G,v,e);
// 	return 0;
// }
// cau 4
void Input(map<int,set<int>> &number_list,int n)
{
    int x,y;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x>>y;
        number_list[x].insert(y);
    }
    int k;
    cin>>k;
    cout<<number_list[x].size();
    for (map<int,set<int>>::iterator itr=number_list.begin();itr !=number_list.end();itr++)
    {
        cout<<itr->first<< ":";
        for (set<int>::iterator;it=itr->second.begin();it!=itr->second.end();it++)
        {
            cout<<*it<< " ";
        }
        
    }
}
int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
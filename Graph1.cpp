#include <bits/stdc++.h>
using namespace std;
void Input(int v, map<string,int> v_index,int e, vector<vector<int>>G)
{
    for(int i=0;i<v;i++)
    {
        string x;
        cin>>x;
        v_index[x]=i;
    }
    for (int i=0;i<e;i++)
    {
        string m,n;
        cin>>m>>n;
        cin>>G[v_index[m]][v_index[n]];
    }
    int x,dem=0;cin>>x;
    for (int k=0;k<v;k++)
    {
        if (G[v_index[x]][k]!=0)
        {   
            dem++;
            for (map<string,int>::iterator i=v_index.begin();i!=v_index.end();i++)
            {
                cout<<i->first<< " ";
            
            if(k==i->second) cout<<i->first;
            }
        }
    }
    if (dem==0) cout<<"No find";
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>G(v,vector<int>(v,0));
    map<string,int> v_index;
    Input(v,v_index,e,G);
    return 0;
}
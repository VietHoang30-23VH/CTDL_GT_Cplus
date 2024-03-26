// Ma tran ke
// Danh sach canh
// Danh sach ke

#include <bits/stdc++.h>
using namespace std;
int n,m;
/* //  cac canh -> ma tran
int a[1001][1001];
int main()
{
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        cout<<a[i][j]<< " ";

        cout<<endl;
    }
}
5 9 
1 2 
1 3
1 4
2 3
2 4
2 5
3 4
3 5
4 5
*/ 

// // ma tran->in ra so canh ke tuong ung
// vector<int> adj[1001]; 
// int main()
// {
//     cin>>n>>m;
//     for (int i=0;i<m;i++)
//     {
//         int x,y;
//         cin>>x>>y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     for (int i=1;i<=n;i++)
//     {
//         cout<< i << " : ";
//         for (int x:adj[i])
//         {
//             cout<<x<< " ";
//         }
//         cout<<endl;
//     }
// }
// in ra danh sach canh tuong ung
/*input:
5
0 1 1 1 0
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
0 1 1 1 0
output:
1 2
1 3
1 4
2 3
2 4
2 5
3 4
3 5
4 5
*/
//   cap canh -> danh sach ke
// vector <pair<int,int>> edge;
// int a[1001][1001];
// int main()
// {
//     cin>>n;
//     for (int i=1;i<=n;i++)
//     {
//         for (int j=1;j<=n;j++)
//         cin>>a[i][j];
//     }
//     for (int i=1;i<n;i++)
//     {
//         for (int j=1;j<=n;j++)
//         {
//             if (a[i][j] && i<j) edge.push_back({i,j});
//         }
//     }
//     for (auto it:edge)
//     {
//         cout<<it.first<< " " <<it.second<<endl;
//     }
// }
/* ma tran -> in ra danh sach ke tuong ung
// vector <pair<int,int>>edge;
// vector <int> adj[1001];
// int a[1001][1001];
// int main()
// {
//     cin>>n;
//     for (int i=1;i<=n;i++)
//     {
//         for (int j=1;j<=n;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     for (int i=1;i<=n;i++)
//     {
//         for (int j=1;j<=n;j++)
//         {
//             if (a[i][j])
//             {
//                 adj[i].push_back(j);
//             }
//         }
//     }
//     for ( int i=1;i<=n;i++)
//     {   
//         cout<< i << " : ";
//         for (int x: adj[i])
//         {
//             cout<<x << " ";
//         }
//         cout<<endl;
//     }
// }
// 5
// 0 1 1 1 0
// 1 0 1 1 1
// 1 1 0 1 1
// 1 1 1 0 1
// 0 1 1 1 0
// 1 : 2 3 4
// 2 : 1 3 4 5
// 3 : 1 2 4 5
// 4 : 1 2 3 5
// 5 : 2 3 4 
*/
// tu danh sach ke in ra ma tran

// int a[1001][1001];
// int main()
// {
//     cin>>n;
//     cin.ignore();
//     for (int i=1;i<=n;i++)
//     {
//         string s,num;
//         getline(cin, s);
//         stringstream ss(s);
//         while ( ss >> num)
//         {
//             a[i][stoi(num)]=1;
//         }
//     }
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=n;j++)
//         cout<<a[i][j]<< " " ;
//         cout<<endl;
//     }
// }
// Deep first search
vector<int>adj[1001];
bool visited[1001];
void input()
{
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        // neu la co huong thi commment adj[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
}
void DFS(int u)
{
    cout<< u << " ";
    visited[u]=true;
    for(int v:adj[u])
    {
        if (!visited[v]) DFS(v);
    }
}
// Breadth first search
void BFS(int u)
{
    queue<int>q;
    q.push(u);
    visited[u]=true;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        cout<< v << " ";
        for (int x: adj[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
// dem hoac kiem tra thanh phan lien thong
void ConnectedComp()
{
    int ans=0;
    memset(visited,false,sizeof(visited));
    for (int i=0;i<=n;i++)
    {
        if (!visited[i])
        {
            ++ans;
            DFS(i);
            cout<<endl;
        }
    }
    cout<<" so thanh phan lien thong cua do thi:"<<ans;
}
// duong di
void DFS1(int u, int path)
{
    visited[u]=true;
    for (int v:adj[u])
    {
        if (!visited[v])
        {
            if(DFS1(v,u)) return true;
        }
        else if(v!=path) return true;
    }
    return false;
}
int main()
{
    input();
    
    DFS(1);
    BFS(1);
}

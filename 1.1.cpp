#include <iostream>
#include <vector>

using namespace std;

int main() {
    int hang,cot;
    cin>>hang>>cot;
    vector<vector<int>> a(hang, vector<int>(cot));

    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            cin >> a[i][j];
        }
    }
    int min_sum = 99999;

    for (int i = 0; i <= hang - 3; i++) {
        for (int j = 0; j <= cot - 3; j++) {
            int sum = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) 
                   {
                    sum += a[x][y];
                }
            }
            min_sum = min(min_sum, sum);
        }
    }

    cout << min_sum << endl;
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define MAX 100
// int main()
// {
//     int a[MAX][MAX],n,m;
//     cin>>n>>m;
//     for (int i=0;i<n;i++)
//     {
//         for (int j=0;j<m;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     int sum_min=100000;
//     for (int i=0;i<=n-3;i++)
//     {
//         for (int j=0;j<=m-3;j++)
//         {
//             int sum=0;
//             for (int x=i;x<i+3;x++)
//             {
//                 for(int y=j;y<j+3;y++)
//                 {
//                     sum+=a[x][y];
//                 }
//             }
//         sum_min=min(sum_min,sum);
//         }
//     }
//     cout<<sum_min<<endl;
//     return 0;
// }
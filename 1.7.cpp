#include <bits/stdc++.h>
struct diem
{
    int x,y;
};
int ss(diem a,diem b)
{
    if(a.x==b.x)  return a.y>b.y;
    else if(a.x!=b.x) return a.x<b.x;
}
int main()
{
    int n;
    std::cin>>n;
    std::vector<diem> D(n);
    for(int i=0;i<n;i++)
    {
        std::cin>>D[i].x>>D[i].y;
    }
    sort(D.begin(),D.end(),ss);
    for(int i=0;i<n;i++)
    {
        std::cout<<D[i].x<<" "<<D[i].y<<"\n";
    }
    return 0;
}
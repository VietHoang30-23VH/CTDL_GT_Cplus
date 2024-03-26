#include <bits/stdc++.h>
using namespace std;

void Find(string s1, string s2) 
{
    int check=0,j=0,a[100],m=s1.length(),n=s2.length();
    for (int i=0;i<n;i++) 
    {
        if (s2[i] == s1[0]) 
        {
            int count = 0;
            for (int j=0;j<m;j++) 
            {
                if (s2[j+i] == s1[j])
                    count+= 1;
            }
            if (count==m) 
            {
                check+=1;a[j]=i+1;j++;
            }
        }
    }
    if (check==0) 
        cout<<"NO";
    else 
    {
        cout<<"YES"<<endl;
        for(int i=0;i<check;i++)
        {
            cout<<a[i]<<" ";
        }
    }
}
int main()
{
    string S,T;
    cin>>S>>T;
    Find(S,T);
    return 0;
}
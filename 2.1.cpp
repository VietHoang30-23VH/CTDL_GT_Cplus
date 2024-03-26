#include <iostream>
using namespace std;
int main()
{
    int n,k,p,q;
	cin>>n>>k>>p>>q;
	int u=2*(p-1)+q-k,v=2*(p-1)+q+k;
	if(u>0) 
	{
		if (u%2==0) 
            cout<<u/2<<" "<<2;
		else cout<<u/2+1<<" "<<1;
	}
	else if (v<=n) 
	{
		if (v%2==0) 
            cout<<v/2<<" "<<2;
		else cout<<v/2+1<<" "<<1;
	}
	else cout<<-1;
	return 0;
}
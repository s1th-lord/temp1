#include <iostream>
using namespace std;

int main() {
	int n,x;
	cin>>n>>x;
	if(n%2==0)
	{
	    if(x<=(n/2))
	    cout<<(x*2-1);
	    else
	    cout<<((x-(n/2))*2);
	}
	else
	{
	    if(x<=(n/2)+1)
	    cout<<(x*2-1);
	    else
	    cout<<((x-(n/2)-1)*2);
	}
	return 0;
}


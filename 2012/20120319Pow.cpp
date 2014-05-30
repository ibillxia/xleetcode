#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	double pow(double x,int n) {
		double ans=1.0;
		if(!n)return ans;
		int i=1,sgn=0,flag=0;
		if(n==INT_MIN){
			flag=1;
			n=-(n>>1);
			//cout<<n<<endl;
		}
		n>0 ? sgn=1 : n=-n;
		while(n){
			if(n&0x01)ans*=x;
			x*=x;
			n=n>>1;
		}
		if(flag)return 1.0/ans/ans;
		return sgn ? ans : 1.0/ans;
	}
};

int main()
{
	Solution sol;
	double x,ans;
	int n;
	while(cin>>x>>n){
		ans=sol.pow(x,n);
		cout<<ans<<endl;
	}
	return 0;
}


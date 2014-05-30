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
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	int divide(int dividend,int divisor) {
		if(divisor==1)return dividend;
		if(divisor==-1)return -dividend;
		if(dividend>0&&divisor>0)return div(-dividend,-divisor);
		if(dividend>0)return -div(-dividend,divisor);
		if(divisor>0)return -div(dividend,-divisor);
		return div(dividend,divisor);
	}
	int div(int d1,int d2){	
		if(d1>d2) return 0;
		if(d1==d2) return 1;
		int ans=1,td=d2;
		while(d1>>1 < d2) {
			d2=d2<<1;
			ans=ans<<1;
		}
		return ans+div(d1-d2,td);
	}
};

int main()
{
	Solution sol;
	int a,b;
	while(cin>>a>>b){
		cout<<sol.divide(a,b)<<endl;
	}
	return 0;
}


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
	int sqrt(int x) {
		if(x<2)return x;
		int l,m,r;
		l=1;r=x/2;
		while(l<=r){
			m=(l+r)/2;
			if(m>x/m)r=m-1;
			else if(m*m<x) l=m+1;
			else return m;
		}
		return r;
	}
};

int main()
{
	Solution sol;
	int x;
	while(cin>>x)
		cout<<sol.sqrt(x)<<endl;
	return 0;
}


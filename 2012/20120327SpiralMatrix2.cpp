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
	vector<vector<int> > generateMatrix(int n){
		vector<vector<int> > ans(n,vector<int>(n));
		if(!n)return ans;
		int i,k,l,r,t,b;
		k=1;l=0,r=n-1,t=0,b=n-1;
		while(l<=r&&t<=b){
			//cout<<l<<" "<<r<<" "<<t<<" "<<b<<endl;
			for(i=l;i<=r;i++)ans[t][i]=k++;t++;
			for(i=t;i<=b;i++)ans[i][r]=k++;r--;
			for(i=r;i>=l&&t<=b;i--)ans[b][i]=k++;b--;
			for(i=b;i>=t&&l<=r;i--)ans[i][l]=k++;l++;
		}
		return ans;
	}
};

int main()
{
    Solution sol;
	vector<vector<int> > ans = sol.generateMatrix(2);
    FOR(i,ans.size()){
		FOR(j,ans[0].size())cout<<ans[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}

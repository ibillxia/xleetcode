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
	vector<int> vt;
	vector<vector<int> >ans;
	vector<vector<int> > combine(int n, int k) {
		if(k>n || k<1)return ans;
		ans.clear();
		comb(1,n,k);
		return ans;
	}
	void comb(int m,int n,int k){
		if(!k){
			ans.push_back(vt);
			return;
		}
		if(vt.size())m=max(m,vt[vt.size()-1]+1);
		for(int i=m;i<=n-k+1;i++){
			vt.push_back(i);
			comb(m+1,n,k-1);
			i=vt[vt.size()-1];
			vt.pop_back();
		}
	}
};

int main()
{
	Solution sol;
	int n,k;
	while(cin>>n>>k){
		vector<vector<int> > ans = sol.combine(n,k);
		FOR(i,ans.size()){
			FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}


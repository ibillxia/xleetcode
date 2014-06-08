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
	vector<vector<int> > ans;
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vt.clear();
		ans.clear();
		ans.push_back(vt);
		for(int i=1;i<=S.size();i++){
			comb(S,1,S.size(),i);
		}
		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		return ans;
	}
	void comb(vector<int> &S,int m,int n,int k){
		if(!k){
			vector<int> vt2(vt.size());
			for(int i=0;i<vt.size();i++)vt2[i]=S[vt[i]-1];
			sort(vt2.begin(),vt2.end());
			ans.push_back(vt2);
			return;
		}
		if(vt.size())m=max(m,vt[vt.size()-1]+1);
		for(int i=m;i<=n-k+1;i++){
			vt.push_back(i);
			comb(S,m+1,n,k-1);
			i=vt[vt.size()-1];
			vt.pop_back();
		}
	}
};

int main()
{
	Solution sol;
	int n;
	while(cin>>n){
		vector<int> v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		vector<vector<int> >ans = sol.subsetsWithDup(v);
		FOR(i,ans.size()){
			FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}


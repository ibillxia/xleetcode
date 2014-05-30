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
	vector<vector<string> > ans;
	vector<vector<string> > solveNQueens(int n) {
		ans.clear();
		if(n==1){
			vector<string> vc;
			vc.push_back("Q");
			ans.push_back(vc);
			return ans;
		}
		if(n<4)return ans;
		string str(n,'.');
		vector<string> vs;
		for(int i=0;i<n;i++)vs.push_back(str);
		vector<bool> used(n,false); // col used
		vector<bool> uiaj(2*n-1,false); // i+j used
		vector<bool> uiansj(2*n-1,false); //i+(n-1-j) used
		fill(vs,used,uiaj,uiansj,0);
		return ans;
	}
	void fill(vector<string> &vs,vector<bool> &u,vector<bool> &u1,vector<bool> &u2,int n){
		int i,sz=vs[0].size();
		if(n==sz)ans.push_back(vs);
		for(i=0;i<sz;i++){
			if(!u[i]&&!u1[i+n]&&!u2[i+sz-1-n]){
				vs[n][i]='Q';
				u[i]=u1[i+n]=u2[i+sz-1-n]=true;
				fill(vs,u,u1,u2,n+1);
				u[i]=u1[i+n]=u2[i+sz-1-n]=false;
				vs[n][i]='.';
			}
		}
		return;
	}
};

int main()
{
	Solution sol;
	vector<vector<string> > ans;
	int n;
	while(cin>>n){
		ans = sol.solveNQueens(n);
		cout<<ans.size()<<endl;
	}
	return 0;
}


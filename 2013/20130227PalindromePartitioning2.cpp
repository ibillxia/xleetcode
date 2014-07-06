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
//#define DEBUG

class Solution {
public:
	int minCut(string s){ // DP, O(n*n)
		const int sz=s.size();
		int ans=0;
		if(sz<2)return ans;

		int i,j;
		int f[sz+1]; // minCuts of s[i,sz]
		vector<vector<bool> > dp(sz,vector<bool>(sz,false));
		for(i=0;i<=sz;i++)f[i]=sz-i-1;
		for(i=sz-1;i>=0;i--){
			for(j=i;j<sz;j++){
				if(s[i]==s[j] && (j-i<2||dp[i+1][j-1])){
					dp[i][j]=true;
					f[i]=min(f[i],f[j+1]+1);
				}
			}
		}
		return f[0];
	}
	int minCut2(string s) { // TLE, directly modified from problem PalindromePartitioning
		const int sz = s.size();
		int ans=0;
		if(sz<2)return ans;

		int i,j;
		vector<vector<bool> > p(sz,vector<bool>(sz,false)); // s[i,j] is palindrome?
		for(i=sz-1;i>=0;i--){
			for(j=i;j<sz;++j){
				if(s[i]==s[j] && (j-i<2||p[i+1][j-1]) )p[i][j]=true;
			}
		}

		vector<vector<string> > sub_vc[sz]; // sub palindromes of s[i,sz]
		for(i=sz-1;i>=0;--i){
			for(j=i;j<sz;++j){
				if(p[i][j]){
					const string si = s.substr(i,j-i+1);
					if(j<sz-1){
						for(auto it=sub_vc[j+1].begin();it!=sub_vc[j+1].end();it++){
							vector<string> vs(*it);
							vs.insert(vs.begin(),si);
							sub_vc[i].push_back(vs);
						}
					}else{
						vector<string> vs(1,si);
						sub_vc[i].push_back(vs);
					}
					#ifdef DEBUG
					cout<<"DEBUG-"<<i<<" "<<j<<":";
					for(int ii=0;ii<sub_vc[i].size();ii++){
						for(int jj=0;jj<sub_vc[i][ii].size();jj++)cout<<sub_vc[i][ii][jj]<<" ";
						cout<<"|";
					}
					cout<<endl;
					#endif
				}
			}
		}
		ans=sz;
		for(i=0;i<sub_vc[0].size();i++){
			if(sub_vc[0][i].size()<ans)
				ans=sub_vc[0][i].size();
		}
		return ans-1;
	}
};

int main()
{
	Solution sol;
	string s;
	while(cin>>s){
		cout<<sol.minCut(s)<<endl;
	}
	return 0;
}


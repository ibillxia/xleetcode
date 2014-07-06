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
	vector<vector<string> > partition(string s) {
		const int sz = s.size();
		vector<vector<string> > ans;
		if(!sz)return ans;
		if(sz==1){
			vector<string> vs(1,s);
			ans.push_back(vs);
			return ans;
		}

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
		return sub_vc[0];
	}
};

int main()
{
	Solution sol;
	string s;
	while(cin>>s){
		vector<vector<string> > ans=sol.partition(s);
		FOR(i,ans.size()){
			FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}


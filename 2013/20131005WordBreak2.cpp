#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_set>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	vector<string> wordBreak(string s,unordered_set<string> &dict) {
		int sz=s.size();
		vector<bool> f(sz+1,false);
		vector<vector<bool> > wd(sz,vector<bool>(sz,false));
		int i,j;
		f[0]=true;
		for(i=1;i<=sz;i++){
			for(j=i-1;j>=0;j--){
				if(f[j] && dict.find(s.substr(j,i-j))!=dict.end()){
					f[i]=true;
					wd[j][i-1]=true; // s[j,i-1] is in dict
				}
			}
		}
		path.clear();
		ans.clear();
		genPath(s,wd,f,sz-1);
		return ans;
	}
private:
	vector<string> path;
	vector<string> ans;
	void genPath(string s,vector<vector<bool> > &wd,vector<bool> &f,int end){
		int i;
		if(end==-1){
			if(path.empty())return;
			string si;
			for(i=path.size()-1;i>0;i--){
				si+=path[i]+" ";
			}
			si+=path[i];
			ans.push_back(si);
		}
		for(i=end;i>=0;i--){
			if(wd[i][end]){
				path.push_back(s.substr(i,end-i+1));
				genPath(s,wd,f,i-1);
				path.pop_back();
			}
		}
	}
};

int main()
{
	Solution sol;
	int n;
	string s,t;
	while(cin>>s>>n){
		unordered_set<string> dict;
		FOR(i,n){
			cin>>t;
			dict.insert(t);
		}
		vector<string> ans = sol.wordBreak(s,dict);
		FOR(i,ans.size())cout<<ans[i]<<endl;
	}
	return 0;
}


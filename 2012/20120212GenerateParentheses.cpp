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
	vector<string>ans;
	string str;
	vector<string> generateParenthesis(int n) {
		if(!n)return ans;
		gen(n,n);
		return ans;
	}

	void gen(int n,int m){
		if(!n){
			n=m;
			while(m--)str+=')';
			ans.push_back(str);
			str=str.substr(0,str.size()-n);
			return;
		}
		if(n==m){ //m=n>0
			str+='(';
			gen(n-1,m);
			//str.pop_back();
			str=str.substr(0,str.size()-1);
		}else if(n<m){
			str+='(';
			gen(n-1,m);
			//str.pop_back();
			str=str.substr(0,str.size()-1);
			str+=')';
			gen(n,m-1);
			//str.pop_back();
			str=str.substr(0,str.size()-1);
		}
	}
};

int main()
{
	Solution sol;
	int n;
	vector<string> ans;
	while(cin>>n){
		ans=sol.generateParenthesis(n);
		FOR(i,ans.size())cout<<ans[i]<<endl;
		sol.ans.clear();
	}
	return 0;
}


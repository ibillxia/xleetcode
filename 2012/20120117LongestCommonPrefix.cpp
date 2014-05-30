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
	string longestCommonPrefix(vector<string> &strs) {
		string ans;
		if(strs.size()==0)return ans;
		if(strs.size()==1)return strs[0];
		int i,j;
		for(i=0;i<strs[0].size();i++){
			for(j=1;j<strs.size();j++){
				if(strs[j].size()>i&&strs[j][i]==strs[0][i])continue;
				else break;
			}
			if(j==strs.size())ans+=strs[0][i];
			else break;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<string> strs;
	strs.push_back("abcdef");
	strs.push_back("abcfed");
	strs.push_back("abdcfge");
	string ans = sol.longestCommonPrefix(strs);
	cout<<ans<<endl;
	return 0;
}


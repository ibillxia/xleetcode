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
	vector<string> anagrams(vector<string> &strs) {
		vector<string> ans;
		map<string, vector<string> > mp;
		int i;
		for(i=0;i<strs.size();i++){
			string key=strs[i];
			sort(key.begin(),key.end());
			mp[key].push_back(strs[i]);
		}
		for(auto it=mp.begin();it!=mp.end();it++){
			if(it->second.size()>1)
				ans.insert(ans.end(),it->second.begin(),it->second.end());
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<string> strs;
	string s1("tea"),s2("eat"),s3("treat");
	strs.push_back(s1);
	strs.push_back(s2);
	strs.push_back(s3);
	vector<string> ans = sol.anagrams(strs);
	FOR(i,ans.size())cout<<ans[i]<<endl;
	return 0;
}


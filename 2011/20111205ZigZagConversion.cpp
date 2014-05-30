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
	string convert(string s,int nRows) {
		if(nRows<2)return s;
		int i,j;
		string ans;
		vector<string> vs(nRows);
		i=0;j=-2;
		while(1){
			for(j=j+2;j<nRows&&i<s.size();j++,i++){
				vs[j]+=s[i];
			}
			if(i>=s.size())break;
			for(j=j-2;j>=0&&i<s.size();j--,i++){
				vs[j]+=s[i];
			}
			if(i>=s.size())break;
		}
		for(j=0;j<nRows;j++) ans+=vs[j];
		return ans;
	}
};

int main()
{
	Solution sol;
	string str;
	int n;
	while(cin>>str>>n){
		string ans = sol.convert(str,n);
		cout<<ans<<endl;
	}
	return 0;
}


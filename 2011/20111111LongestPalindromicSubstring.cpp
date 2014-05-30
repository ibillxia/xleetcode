#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	string longestPalindrome(string s) {
		int i,j,sz,m,len;
		sz=s.size();
		if(sz<2)return s;
		m=len=0;
		for(i=0;i<sz;i++){
			// even length palindrome
			for(j=0;j<=i&&i+j<sz-1;j++){
				if(s[i-j]!=s[i+j+1])break;
			}
			if(2*j>len)len=2*j,m=i+1-j;
			// odd length plindrome
			for(j=0;j<i&&i+j<sz-1;j++){
				if(s[i-j-1]!=s[i+j+1])break;
			}
			if(2*j+1>len)len=2*j+1,m=i-j;
		}
		string ans = s.substr(m,len);
		return ans;
	}
};

int main()
{
	Solution sol;
	string str = "std::dts j=0;j+i&|&i+j<sz-1;j++){";
	string ans = sol.longestPalindrome(str);
	cout<<ans<<endl;
	cout<<"max length: "<<ans.size()<<endl;
	return 0;
}


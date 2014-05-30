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
	string countAndSay(int n) {
		string ans;
		if(!n)return ans;
		int m=n,i,j,sz;
		string str="1";
		char ch;
		while(--m){
			sz=str.size();
			for(i=0;i<sz;i++){
				j=1;
				while(i+j<sz&&str[i]==str[i+j])j++;
				ch=j+'0';
				ans=ans+ch+str[i];
				i+=j-1;
			}
			str=ans;
			ans.erase(0,ans.size());
		}
		return ans=str;
	}
};

int main()
{
	Solution sol;
	string ans;
	int n;
	while(cin>>n){
		ans = sol.countAndSay(n);
		cout<<ans<<endl;
	}
	return 0;
}


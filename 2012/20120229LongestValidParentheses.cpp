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
	int longestValidParentheses(string s){
		int sz=s.size();
		if(sz<2)return 0;
		int ans=0,i,j;
		stack<int> st;
		for(i=j=0;i<sz;i++){
			if(s[i]=='('){
				st.push(j);
				while(++i<sz&&s[i]=='(')st.push(i);
				if(i==sz)break;
				i--;
			}else if(st.size()){
				j=st.top();
				st.pop();
				if(i-j+1>ans)ans=i-j+1;
			}else { //s[i]=')'&&st.size()=0
				while(i<sz&&s[i]==')')i++;
				if(i==sz)break;
				j=i;
				i--;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	string s;
	int ans;
	while(cin>>s){
		ans=sol.longestValidParentheses(s);
		cout<<ans<<endl;
	}
	return 0;
}


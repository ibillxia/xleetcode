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
	int largestRectangleArea(vector<int> &height) {
		int n = height.size();
		if(!n) return 0;
		if(n==1) return height[0];
		int i,t,len, ans = height[0];
		stack<int> st;
		height.push_back(0);
		for(i=0;i<n+1;){
			if(st.empty() || height[i] > height[st.top()]) st.push(i++);
			else {
				t=st.top();
				st.pop();
				if(st.empty()) len = i;
				else len = i-st.top()-1;
				ans = max(ans,height[t]*len);
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	int n,t;
	vector<int> height;
	while(cin>>n){
		FOR(i,n){
			cin>>t;
			height.push_back(t);
		}
		cout<<sol.largestRectangleArea(height)<<endl;
		height.clear();
	}
	return 0;
}


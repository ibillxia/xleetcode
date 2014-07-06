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
	int candy(vector<int> &rt) {
		int sz=rt.size();
		if(sz<2)return sz;
		vector<int> l(sz,1),r(sz,1);
		int i;
		for(i=1;i<sz;i++){
			if(rt[i]>rt[i-1])l[i]=l[i-1]+1;
		}
		for(i=sz-2;i>=0;i--){
			if(rt[i]>rt[i+1])r[i]=r[i+1]+1;
		}
		int ans=0;
		for(i=0;i<sz;i++){
			ans+=max(l[i],r[i]);
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	int n;
	while(cin>>n){
		vector<int> ratings(n);
		FOR(i,n)cin>>ratings[i];
		cout<<sol.candy(ratings)<<endl;
	}
	return 0;
}


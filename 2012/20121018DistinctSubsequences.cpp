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
	int numDistinct(string S,string T) {
		int sz1,sz2;
		sz1=S.size();
		sz2=T.size();
		if(sz1<sz2)return 0;
		if(S.compare(T)==0)return 1;
		
		int i,j;
		int *dp = new int[sz2+1];
		memset(dp,0,sizeof(int)*(sz2+1));
		dp[0]=1;
		for(i=1;i<=sz1;i++){
			for(j=sz2;j>0;j--){
				if(S[i-1]==T[j-1])dp[j]=dp[j]+dp[j-1];
			}
		}
		return dp[sz2];
	}
};

int main()
{
	Solution sol;
	string S,T;
	while(cin>>S>>T){
		cout<<sol.numDistinct(S,T)<<endl;
	}
	return 0;
}


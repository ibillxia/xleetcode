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
#include<climits>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	int minDistance(string word1,string word2) {
		int i,j,m,n,t;
		m=word1.size();
		n=word2.size();
		int *dp1 = new int[n+1];
		int *dp2 = new int[n+1];
		memset(dp1,0,sizeof(int)*(n+1));
		memset(dp2,0,sizeof(int)*(n+1));
		for(i=0;i<=n;i++)dp1[i]=i;
		for(i=1;i<=m;i++){
			dp2[0]=i;
			for(j=1;j<=n;j++){
				if(word1[i-1]==word2[j-1]){
					dp2[j]=dp1[j-1];
				}else{
					t=min(dp1[j-1],dp1[j]); // replace,delete
					dp2[j]=min(t,dp2[j-1])+1; // insert
				}
			}
			memcpy(dp1,dp2,sizeof(int)*(n+1));
		}
		return dp1[n];
	}
};

int main()
{
	Solution sol;
	string w1,w2;
	while(cin>>w1>>w2){
		cout<<sol.minDistance(w1,w2)<<endl;
	}
	return 0;
}


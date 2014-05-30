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
	int jump(int A[],int n) {
		if(n<2)return 0;
		if(A[0]>=n-1)return 1;
		if(!A[0])return INT_MAX; // can not reach
		int ans,i,j;
		int *mi = new int[n];
		for(i=0;i<n;i++)mi[i]=INT_MAX;
		mi[0]=0;j=1;
		for(i=0;i<n;i++){
			for(;j<=i+A[i];j++){
				if(mi[i]!=INT_MAX)mi[j]=min(mi[j],mi[i]+1);
				//cout<<i<<" "<<j<<" "<<mi[j]<<endl;
				if(j==n-1){
					ans=mi[j];
					delete[] mi;
					return ans;
				}
			}
			j=i+A[i]+1;
		}
		ans=mi[n-1];
		delete[] mi;
		return ans;
	}
};

int main()
{
	Solution sol;
	int n;
	int A[25002];
	while(cin>>n){
		FOR(i,n)cin>>A[i];
		int ans = sol.jump(A,n);
		cout<<ans<<endl;
	}
	return 0;
}


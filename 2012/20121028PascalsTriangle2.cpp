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
	vector<int> getRow(int rowIndex) {
		int n=rowIndex;
		if(n<2){
			vector<int> ans(n+1,1);
			return ans;
		}
		int i,j;
		vector<int> ans(n+1,1);
		for(i=1;i<n;i++){
			for(j=i;j>0;j--){
				ans[j]=ans[j]+ans[j-1];
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	int n;
	vector<int> ans;
	while(cin>>n){
		ans = sol.getRow(n);
		FOR(i,ans.size())cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}


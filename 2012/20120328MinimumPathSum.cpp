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
	int minPathSum(vector<vector<int> > &grid) {
		int i,j,m,n,ms;
		m=grid.size();
		n=grid[0].size();
		vector<int> cnt(m*n,0);
		if(grid[0][0]==INT_MAX)return INT_MAX;
		cnt[0]=grid[0][0];
		j=1;
		for(i=0;i<m;i++){
			ms=INT_MAX;
			for(;j<n;j++){
				if(cnt[i*n+j-1]<INT_MAX-grid[i][j])
					cnt[i*n+j]=grid[i][j]+cnt[i*n+j-1];
				else cnt[i*n+j]=INT_MAX;
				if(i>0&&cnt[i*n-n+j]<INT_MAX-grid[i][j])
					cnt[i*n+j]=min(cnt[i*n+j],cnt[i*n-n+j]+grid[i][j]);
				if(cnt[i*n+j]<=ms)ms=cnt[i*n+j];
			}
			j=0;
			//cout<<i<<endl;
			if(i&&ms==INT_MAX)return ms;
			//cout<<cnt[i*n+m]<<endl;
		}
		return cnt[m*n-1];
	}
};

int main()
{
	Solution sol;
	vector<vector<int> > grid;
	int m,n,t;
	while(cin>>m>>n){
		FOR(i,m){
			vector<int> row;
			FOR(j,n){
				cin>>t;
				row.push_back(t);
			}
			grid.push_back(row);
		}
		cout<<sol.minPathSum(grid)<<endl;
		grid.clear();
	}
	return 0;
}


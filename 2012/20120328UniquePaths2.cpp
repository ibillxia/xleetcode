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
	int uniquePathsWithObstacles(vector<vector<int> > &obg) {
		int i,j,m,n;
		m=obg.size();
		n=obg[0].size();
		int *cnt = new int[m*n];
		memset(cnt,0,sizeof(int)*m*n);
		for(i=0;i<m;i++){
			if(!obg[i][0])cnt[i*n]=1;
			else break;
		}
		for(i=0;i<n;i++){
			if(!obg[0][i])cnt[i]=1;
			else break;
		}
		for(i=1;i<m;i++){
			for(j=1;j<n;j++){
				if(!obg[i][j]){
					if(cnt[i*n+j-1]<INT_MAX-cnt[i*n-n+j])
						cnt[i*n+j]=cnt[i*n+j-1]+cnt[i*n-n+j];
					else cnt[i*n+j]=INT_MAX;
				}
			}
		}
		return cnt[m*n-1];
	}
};

int main()
{
	Solution sol;
	vector<vector<int> > obs;
	int m,n,t;
	while(cin>>m>>n){
		FOR(i,m){
			vector<int> row;
			FOR(j,n){cin>>t;row.push_back(t);}
			obs.push_back(row);
		}
		cout<<sol.uniquePathsWithObstacles(obs)<<endl;
		obs.clear();
	}
	return 0;
}

/* sample input:
3 3
0 0 0
0 1 0
0 0 0
*/

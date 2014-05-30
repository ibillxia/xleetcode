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
	int uniquePaths(int m,int n) {
		if(m<2||n<2)return 1;
		int d[100][100];
		int i,j;
		for(i=0;i<m;i++)d[i][0]=1;
		for(i=0;i<n;i++)d[0][i]=1;
		for(i=1;i<m;i++){
			for(j=1;j<n;j++){
				if(d[i-1][j]<INT_MAX-d[i][j-1])d[i][j]=d[i-1][j]+d[i][j-1];
				else return INT_MAX;
			}
		}
		return d[m-1][n-1];
	}
};

int main()
{
	Solution sol;
	int m,n;
	while(cin>>m>>n){
		cout<<sol.uniquePaths(m,n)<<endl;
	}
	return 0;
}


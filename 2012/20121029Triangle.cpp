#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n=triangle.size();
		if(!n)return 0;
		if(n==1)return triangle[0][0];

		int i,j,ans;
		vector<int> mv(n,0);
		mv[0]=triangle[0][0];
		for(i=1;i<n;i++){
			mv[i]=mv[i-1]+triangle[i][i];
			for(j=i-1;j>0;j--){
				mv[j]=min(mv[j],mv[j-1])+triangle[i][j];
			}
			mv[0]=mv[0]+triangle[i][0];
		}
		ans = mv[0];
		for(i=1;i<n;i++){
			if(mv[i]<ans)ans=mv[i];
		}
		return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    vector<vector<int> > triangle;
	while(cin>>n){
		FOR(i,n){
			vector<int> vi(i+1);
			FOR(j,i+1)cin>>vi[j];
			triangle.push_back(vi);
		}
		cout<<sol.minimumTotal(triangle)<<endl;
		triangle.clear();
	}
    return 0;
}

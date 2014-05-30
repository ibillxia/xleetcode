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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int m,n;
		vector<int> ans;
		m=matrix.size();
		if(!m)return ans;
		n=matrix[0].size();
		int i,l,r,t,b;
		l=0,r=n-1,t=0,b=m-1;
		while(l<=r&&t<=b){
			//cout<<l<<" "<<r<<" "<<t<<" "<<b<<endl;
			for(i=l;i<=r;i++)ans.push_back(matrix[t][i]);t++;
			for(i=t;i<=b;i++)ans.push_back(matrix[i][r]);r--;
			for(i=r;i>=l&&t<=b;i--)ans.push_back(matrix[b][i]);b--;
			for(i=b;i>=t&&l<=r;i--)ans.push_back(matrix[i][l]);l++;
		}
		return ans;
    }
};

int main()
{
    Solution sol;
    int a[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{15,16,17,18,19}
    ,{22,23,24,25,26},{34,35,36,37,38} };
	vector<vector<int> > vc;
	vector<int> v1(a[0],a[0]+5),v2(a[1],a[1]+5),v3(a[2],a[2]+5);
	vector<int> v4(a[3],a[3]+5),v5(a[4],a[4]+5);
	vc.push_back(v1),vc.push_back(v2),vc.push_back(v3);
	vc.push_back(v4);
	//vc.push_back(v5);
	FOR(i,vc.size()){
		FOR(j,vc[0].size())cout<<vc[i][j]<<" ";
		cout<<endl;
	}
	vector<int> ans = sol.spiralOrder(vc);
    FOR(i,ans.size())cout<<ans[i]<<" ";
	cout<<endl;
    return 0;
}

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
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ans;
		sort(num.begin(),num.end());
		do{
			ans.push_back(num);
		}while(next_permutation(num.begin(),num.end()));
		return ans;
    }

};

int main()
{
    Solution sol;
	int a[] = {1,2,3};
	vector<int> v(a,a+3);
    vector<vector<int> > ans = sol.permute(v);
	FOR(i,ans.size()){
		FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}

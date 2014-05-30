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
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i,j,s,t,n;
		n=gas.size();
		for(i=s=t=0,j=-1;i<n;i++){
			s+=gas[i]-cost[i];
			t+=gas[i]-cost[i];
			if(t<0)j=i,t=0;
		}
		if(s>=0)return j+1;
		return -1;
    }
};

int main()
{
    Solution sol;
	int a[]={2,3,6,4,5},b[]={2,4,5,3,7};
	vector<int> gas(a,a+1),cost(b,b+1);
	int ans = sol.canCompleteCircuit(gas,cost);
    cout<<ans<<endl;
    return 0;
}

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
	int maxArea(vector<int> &height) {
		int i,j,t,ans=0;
		if(!height.size())return 0;
		for(i=0,j=height.size()-1;i<j;){
			if(height[i]<height[j]){
				t=(j-i)*height[i];
				i++;
			}else{
				t=(j-i)*height[j];
				j--;
			}
			if(t>ans)ans=t;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	int arr[] = {1,2,4,5,3,6,9,8,7};
	vector<int> ht(arr,arr+9);
	int ans=sol.maxArea(ht);
	cout<<ans<<endl;
	return 0;
}


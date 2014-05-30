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
	int firstMissingPositive(int A[],int n) {
		int ans,i;
		if(!n)return 1;
		for(i=0;i<n;i++){
			if(A[i]>0 && A[i]<n){
				if(A[A[i]-1]!=A[i]){
					swap(A[A[i]-1],A[i]);
					i--;
				}
			}
		}
		for(i=0;i<n;i++)
			if(A[i]!=i+1)break;
		return ans=i+1;
	}
};

int main()
{
	Solution sol;
	int a[] = {3,4,1,5,2};
	int ans = sol.firstMissingPositive(a,5);
	cout<<ans<<endl;
	return 0;
}


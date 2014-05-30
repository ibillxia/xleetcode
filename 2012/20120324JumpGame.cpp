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
	bool canJump(int A[],int n){
		if(n<2)return true;
		if(n==2&&A[0]>0)return true;
		if(A[0]<1)return false;
		if(A[0]>=n-1)return true;
		int i,j;
		char *can = new char[n];
		memset(can,0,n);
		can[0]=1;
		for(i=0;i<n-1;i++){
			if(!can[i])continue;
			if(i+A[i]>n-2)return true;
			memset(can+i+1,1,A[i]);
		}
		delete[] can;
		return false;
	}

	bool canJump2(int A[],int n){ // TLE
		if(n<2)return true;
		if(n==2&&A[0]>0)return true;
		if(A[0]<1)return false;
		if(A[0]>=n-1)return true;
		vector<bool> can(n,false);
		int i,j;
		can[0]=true;
		for(i=0;i<n;i++){
			if(!can[i])continue;
			if(i+A[i]>n-2)return true;
			for(j=A[i];j>0;j--){
				can[i+j]=true;
			}
		}
		return false;
	}

	bool canJump1(int A[],int n) { // TLE
		if(n<2)return true;
		if(n==2&&A[0]>0)return true;
		if(A[0]<1)return false;
		if(A[0]>=n-1)return true;
		int i,j,k=0,t;
		queue<int> q1,q2;
		for(i=1;i<=A[0];i++)q1.push(i);
		while(q1.size()&&k<n){
			while(q1.size()){
				i=q1.front();
				if(i+A[i]>=n-1)return true;
				for(j=1;j<=A[i];j++){
					q2.push(i+j);
				}
				q1.pop();
			}
			swap(q1,q2);
			k++;
		}
		return false;
	}
};

int A[25002];
int main()
{
	Solution sol;
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>A[i];
		bool ans = sol.canJump(A,n);
		cout<<ans<<endl;
	}
	return 0;
}


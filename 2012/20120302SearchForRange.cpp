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
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans(2,-1);
		if(!n)return ans;
		if(A[0]>target||A[n-1]<target)return ans;
		if(n==1&&A[0]!=target)return ans;
		if(n==1&&A[0]==target){ans[0]=ans[1]=0;return ans;}
		if(A[0]==A[n-1]&&A[0]==target){ans[0]=0;ans[1]=n-1;return ans;}
		if(n<10){
			int a=0,b;
			while(A[a]<target)a++;
			if(A[a]>target)return ans;
			b=a;
			while(b<n&&A[b]==target)b++;
			ans[0]=a;
			ans[1]=b-1;
			return ans;
		}
		int l=0,r=n,m;
		while(l<=r){
			m=(l+r)/2;
			if(A[m]>target)r=m-1;
			else if(A[m]<target)l=m+1;
			else break;
		}
		if(A[m]!=target)return ans;
		int lr=m,rl=m,tm;
		while(l<=lr){
			tm=(l+lr)/2;
			if(A[tm]<target)l=tm+1;
			else lr=tm-1;
		}
		while(rl<=r){
			tm=(rl+r)/2;
			if(A[tm]>target)r=tm-1;
			else rl=tm+1;
		}
		ans[0]=lr+1;
		ans[1]=rl-1;
		return ans;
    }

	vector<int> searchRange2(int A[],int n,int target) {  // WA, don't know why, very strange bug, it's OK on my pc, but WA returned from the OJ
		vector<int> ans(2,-1);
		if(!n)return ans;
		if(A[0]>target||A[n-1]<target)return ans;
		if(n==1&&A[0]!=target)return ans;
		if(n==1&&A[0]==target){ans[0]=ans[1]=0;return ans;}
		if(n<10){
			int a=0,b;
			while(A[a]<target)a++;
			if(A[a]>target)return ans;
			b=a;
			while(b<n&&A[b]==target)b++;
			ans[0]=a;
			ans[1]=b-1;
			return ans;
		}
		int l=0,r=n,m;
		while(l<=r){
			m=(l+r)/2;
			if(A[m]>target)r=m-1;
			else if(A[m]<target)l=m+1;
			else break;
		}
		if(A[m]!=target)return ans;
		int lr=m,rl=m,tm;
		while(l<=lr){
			tm=(l+lr)/2;
			if(A[tm]<target)l=tm+1;
			else lr=tm-1;
		}
		while(rl<=r){
			tm=(rl+r)/2;
			if(A[tm]>target)r=tm-1;
			else rl=tm+1;
		}
		ans[0]=lr+1;
		ans[1]=rl-1;
		return ans;
	}
};

int main()
{
	Solution sol;
	int d[]={5,7,7,8,8,8,10};
	vector<int> ans = sol.searchRange(d,7,8);
	cout<<ans[0]<<","<<ans[1]<<endl;
	return 0;
}


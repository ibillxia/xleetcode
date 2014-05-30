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
    int trap(int A[], int n) {
        if(n<3)return 0;
        int i,t,ans=0;
        int *mxl = new int[n];
        int *mxr = new int[n];
        mxl[0]=A[0],mxr[n-1]=A[n-1];
        for(i=1;i<n;i++)mxl[i]=max(A[i-1],mxl[i-1]);
        for(i=n-2;i>=0;i--)mxr[i]=max(A[i+1],mxr[i+1]);
        for(i=1;i<n-1;i++){
            t=min(mxl[i],mxr[i])-A[i];
            if(t>0)ans+=t;
        }
        delete[] mxl;
        delete[] mxr;
        return ans;
    }
};

int main()
{
    Solution sol;
    int a[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = sol.trap(a,12);
	cout<<ans<<endl;
    return 0;
}

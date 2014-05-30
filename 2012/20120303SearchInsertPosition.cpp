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
    int searchInsert(int A[], int n, int target) {
        if(!n)return 0;
        int l,r,m;
        l=0;r=n-1;
        while(l<=r){
            m=(l+r)/2;
            if(A[m]==target)return m;
            else if(A[m]>target)r=m-1;
            else l=m+1;
        }
        if(A[m]>=target)return m;
		else return m+1;
    }
};

int main()
{
    Solution sol;
    int A[]={1,3,5,6};
    int ans = sol.searchInsert(A,4,0);
    cout<<ans<<endl;
    return 0;
}

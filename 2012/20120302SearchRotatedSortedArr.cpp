#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
        if(!n)return -1;
        int l,m,r;
        l=0,r=n-1;
        while(l<r){
            m=(l+r)/2;
            if(target==A[m])return m;
            if(target==A[l])return l;
            if(target==A[r])return r;
            if(A[l]>A[m]){
                if(target>A[m]&&target<A[r])l=m+1;
                else r=m-1;
            }else if(A[r]<A[m]){
                if(target>A[l]&&target<A[m])r=m-1;
                else l=m+1;
            }else{
                if(target>A[m])l=m+1;
                else r=m-1;
            }
        }
        if(target==A[l])return l;
        if(target==A[r])return r;
        return -1;
    }
};

int main()
{
    Solution sol;
    int A[]={4,5,6,7,0,1,2};
    int ans = sol.search(A,7,3);
    cout<<ans<<endl;
    return 0;
}

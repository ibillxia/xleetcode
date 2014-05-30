#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(int A[], int n, int target) {
        if(!n)return false;
        int l,m,r;
        l=0,r=n-1;
        while(l<r){
            m=(l+r)/2;
            if(target==A[m]||target==A[l]||target==A[r])return true;
            if(A[l]>A[m]){
                if(target>A[m]&&target<A[r])l=m+1;
                else r=m-1;
            }else if(A[r]<A[m]){
                if(target>A[l]&&target<A[m])r=m-1;
                else l=m+1;
            }else if(A[l]==A[m]||A[r]==A[m]){
                l++;r--;
            }else{
                if(target>A[m])l=m+1;
                else r=m-1;
            }
        }
        if(target==A[l]||target==A[r])return true;
        return false;
    }
};

int main()
{
    Solution sol;
    int A[]={1,3,1,1,1};
    bool ans = sol.search(A,5,3);
    cout<<ans<<endl;
    return 0;
}

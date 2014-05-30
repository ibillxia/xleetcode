#include<iostream>
class Solution {
public:
    int singleNumber(int A[], int n) {
        int i,ans;
        ans=A[0];
        for(i=1;i<n;i++)ans^=A[i];
        return ans;
    }
};

int main()
{
    int A[]={1,1,2,2,3,3,4};
    Solution sol;
    int ans = sol.singleNumber(A,7);
    std::cout<<ans<<std::endl;
}

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),ans=0;
        if(n<=1) return n;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1) dp[i] = dp[j]+1;
            }
            if(dp[i]>ans) ans = dp[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums={1,3,6,7,9,4,10,5,6};
    Solution sol;
    int ans = sol.lengthOfLIS(nums);
    cout<<ans<<endl;
    return 0;
}
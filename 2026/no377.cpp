#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(target+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++) dp[0][i]=1;
        for(int i=1;i<=target;i++){
            for(int j=1;j<=n;j++){
                if(i>=nums[j-1])dp[i][j]=dp[i-nums[j-1]][j]+dp[i][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[target][n];
    }
};

int main()
{
    vector<int> nums={1,2,3};
    int target=4;
    Solution sol;
    int ans = sol.combinationSum4(nums,target);
    cout<<ans<<endl;
    return 0;
}
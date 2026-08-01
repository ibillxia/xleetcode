#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
private:
    int simulatePlay(vector<int> &nums,int left,int right,int k)
    {
        if(left==right) return nums[left]*k;
        int pickLeft = nums[left]*k + simulatePlay(nums,left+1,right,-k);
        int pickRight = nums[right]*k + simulatePlay(nums,left,right-1,-k);
        return max(pickLeft*k,pickRight*k)*k;
    }
    int dp2d(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)dp[i][i]=nums[i];
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] = max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n%2==0){
            return true;
        }
        if(n==3){
            if(nums[0]+nums[2]>=nums[1]) return true;
            return false;
        }
        //n>=5
        int k=1;
        int diff;
        // diff = simulatePlay(nums,0,n-1,k);
        diff = dp2d(nums);
        if(diff>=0) return true;
        return false;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    bool ans = sol.predictTheWinner(nums);
    if(ans) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>=n || n<=1) return n;
        int ans=0,t=0;
        unordered_map<int,int> f;
        for(int i=0;i<n;i++){
            f[nums[i]]++;
            if(f[nums[i]]<=k){
                t++;
                if(t>ans){
                    ans=t;
                }
            }else{
                for(int j=i-t;j<i;j++){
                    f[nums[j]]--;
                    if(nums[j]==nums[i]){
                        t=i-j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,2,1,2,1,2,1,2};
    int k=1;
    Solution sol;
    int ans = sol.maxSubarrayLength(nums,k);
    cout<<ans<<endl;
    return 0;
}

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt[51]={0};
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        int ans=-1;
        if(k==1){
            for(int i=50;i>-1;i--){
                if(cnt[i]==1) return i;
            }
        }
        if(k==n){
            for(int i=50;i>-1;i--){
                if(cnt[i]>0) return i;
            }
        }
        ans = max(nums[0],nums[n-1]);
        if(cnt[ans]==1) return ans;
        ans = min(nums[0],nums[n-1]);
        if(cnt[ans]==1) return ans;
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums={3,9,7,2,1,7};
    int k=4;
    int ans = sol.largestInteger(nums,k);
    cout<<ans<<endl;
    return 0;
}
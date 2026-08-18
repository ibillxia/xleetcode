#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n,ans,f[51]={0};
        n=nums.size();
        ans=nums[0];
        for(int i=0;i<n;i++){
            f[nums[i]]=1;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                ans+=nums[i];
            }else{
                break;
            }
        }
        for(int i=ans;i<51;i++){
            if(f[i]==1)ans++;
            else break;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums= {37,1,2,9,5,8,5,2,9,4};
    int ans = sol.missingInteger(nums);
    cout<<ans<<endl;
    return 0;
}
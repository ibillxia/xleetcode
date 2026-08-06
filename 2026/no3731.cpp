#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> isExits(101,false);
        int maxi=0,mini=100;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi) maxi=nums[i];
            if(nums[i]<mini) mini=nums[i];
            isExits[nums[i]] = true;
        }
        vector<int> ans;
        for(int i=mini+1;i<maxi;i++){
            if(!isExits[i]) ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums={1,4,2,5};
    Solution sol;
    vector<int> ans=sol.findMissingElements(nums);
    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
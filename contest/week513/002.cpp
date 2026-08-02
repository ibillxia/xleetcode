#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int x=0,y=0;
        int ans=0;
        for(int i=0;i<n;i++){
            x=0,y=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) x++;
                else y++;
                if(y>0 && x/float(y)<=a/float(b))ans++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums={1,2,1,2};
    int a=3,b=2;
    Solution sol;
    int ans=sol.countRatioSubarrays(nums,a,b);
    cout<<ans<<endl;
    return 0;
}
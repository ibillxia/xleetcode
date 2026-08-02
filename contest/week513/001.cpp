#include<iostream>
#include<vector>
#include<numeric>   // require C++17

using namespace std;
#if __cplusplus > 201703L
    // 当前版本大于 C++17（例如 C++20 或更高）
#else
    int gcd(int a,int b){ return b == 0 ? std::abs(a) : gcd(b, a % b); }
#endif

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0,tmp=0;
        int g;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int g=gcd(nums[i],nums[j]);
                tmp = (((long long)nums[i])*nums[j])/(((long long)g)*g);
                if(tmp>ans) ans=tmp;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums={2,3,5};
    Solution sol;
    long long ans=sol.maxPairStrength(nums);
    cout<<ans<<endl;
    return 0;
}
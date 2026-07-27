#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        int m = 1<<(n-1);
        long long tmp,tmp2;
        for(int i=1;i<m;i++){
            tmp=1;
            tmp2=1;
            for(int j=0;j<n;j++){
                if((i&(1<<j))>0){
                    tmp *= (long long)nums[j];
                }else{
                    tmp2 *= (long long)nums[j];
                }
                if(tmp>target || tmp2>target) break;
            }
            if(tmp==target && tmp2==target) return true;
        }
        return false;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    long long t;
    cin>>t;
    Solution sol;
    bool res = sol.checkEqualPartitions(nums,t);
    cout<<res<<endl;
    return 0;
}
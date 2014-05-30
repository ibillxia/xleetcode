#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int i=digits.size()-1;
        while(i>=0&&digits[i]==9){
            digits[i]=0;
            i--;
        }
        if(i>=0){
            digits[i]++;
            return digits;
        }
        vector<int> ans(digits.size()+1,0);
        ans[0]=1;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> vin(0);
    //vin[0]=9,vin[1]=9;
    vector<int> ans = sol.plusOne(vin);
    FOR(i,ans.size())cout<<ans[i];
    cout<<endl;
    return 0;
}

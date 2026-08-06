#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        string ans;
        int *p = stoneValue.data();
        vector<int> d(n+1,0);
        if(n>=1) d[n-1] = p[n-1];
        if(n>=2) d[n-2] = max(p[n-2]-p[n-1],p[n-1]+p[n-2]);
        for(int i=n-3;i>=0;i--){
            d[i] = max(max(p[i]-d[i+1],p[i]+p[i+1]-d[i+2]),p[i]+p[i+1]+p[i+2]-d[i+3]);
        }
        if(d[0]>0){
            ans = "Alice";
        }else if(d[0]==0){
            ans = "Tie";
        }else{
            ans="Bob";
        }
        return ans;
    }
};

int main()
{
    vector<int> sv = {1,2,3,7};
    Solution sol;
    string ans = sol.stoneGameIII(sv);
    cout<<ans<<endl;
    return 0;
}
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
    vector<int> grayCode(int n) {
        int sz = n>0? 1<<n : 1;
        vector<int> ans(sz);
        for(int i=0;i<sz;i++){
            ans[i]=(i>>1)^i;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> ans = sol.grayCode(4);
    FOR(i,ans.size()){
        cout<<ans[i];
        if(i<ans.size()-1)cout<<",";
    }
    cout<<endl;
    return 0;
}

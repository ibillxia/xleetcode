#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans(numRows);
        if(!numRows)return ans;
        int i,j;
        for(i=1;i<=numRows;i++){
            vector<int> v(i);
            v[0]=v[i-1]=1;
            for(j=1;j<i-1;j++){
                v[j]=ans[i-2][j-1]+ans[i-2][j];
            }
            ans[i-1]=v;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > ans = sol.generate(2);
    FOR(i,ans.size()){
        FOR(j,ans[i].size()){
            cout<<ans[i][j];
            if(j<ans[i].size()-1)cout<<",";
        }
        cout<<endl;
    }
    return 0;
}

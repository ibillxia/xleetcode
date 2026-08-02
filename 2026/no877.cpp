#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=piles[i];
            for(int j=i+1;j<n;j++){
                dp[i][j]=max(piles[j]-dp[i][j-1],piles[i]-dp[i+1][j]);
            }
        }
        if(dp[0][n-1]>0) return true;
        return false;
    }
};

int main()
{
    int N;
    Solution sol;
    bool ans;
    cin>>N;
    vector<int> p(N);
    for(int i=0;i<N;i++){
        cin>>p[i];
    }
    ans = sol.stoneGame(p);
    if(ans) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
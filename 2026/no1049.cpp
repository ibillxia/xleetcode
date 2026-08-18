#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

class Solution {
public:
    int lastStoneWeightII2(vector<int>& stones) {
        int n = stones.size();
        if(n==2) return abs(stones[0]-stones[1]);
        int ans=100,tmp=100;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                vector<int> d = stones;
                int x=d[i],y=d[j];
                if(x<=y){
                    d[j] -= x;
                    d[i] = d[n-1];
                    d.pop_back();
                }else{
                    d[i] -= y;
                    d[j] = d[n-1];
                    d.pop_back();
                }
                tmp=lastStoneWeightII(d);
                if(tmp<ans) ans=tmp;
            }
        }
        return ans;
    }
    int lastStoneWeightII(vector<int>& stones){
        int n=stones.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += stones[i];
        }
        int sum2=sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum2+1,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=sum2;j++){
                if(stones[i]<=j){
                    dp[i+1][j]= min(1,max(dp[i][j], dp[i][j-stones[i]]));
                } 
                else dp[i+1][j] = dp[i][j];
            }
        }
        int ans=0;
        for(int i=sum2;i>=0;i--){
            if(dp[n][i]){
                ans = abs(sum-i*2);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> stones = {31,26,33,21,40};
    Solution sol;
    int ans = sol.lastStoneWeightII(stones);
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=books[0][1];
        for(int i=2;i<=n;i++) dp[i]=INT_MAX;
        for(int i=2;i<=n;i++){
            int t=0,h=0;;
            for(int j=i-1;j>=0;j--){
                t+=books[j][0];
                if(t>shelfWidth) break;
                if(books[j][1]>h) h = books[j][1];
                dp[i]=min(dp[i],dp[j]+h);
            }
            dp[i]=min(dp[i],dp[i-1]+books[i-1][1]);
        }
        return dp[n];
    }
};

int main()
{
    // vector<vector<int>> books= {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    // int shelfWidth=4;
    vector<vector<int>> books= {{1,3},{2,4},{3,2}};
    int shelfWidth=6;
    Solution sol;
    int ans = sol.minHeightShelves(books,shelfWidth);
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        int maxHappyGroups(int batchSize, vector<int>& groups) {
            int grpSize = groups.size();
            if(grpSize==1) return 1;
            if(batchSize==1) return grpSize;
            vector<int> cnt(9,0);
            int ans=0,mods=0;
            // 整除的
            for(int i=0;i<grpSize;i++){
                mods = groups[i]%batchSize;
                cnt[mods]++;
            }
            ans = cnt[0];

            // 两组的
            int tmp=0;
            for(int i=1;i<=batchSize/2;i++){
                if(i<batchSize-i)tmp = min(cnt[i],cnt[batchSize-i]);
                else tmp=int(cnt[i]/2);
                ans += tmp;
                cnt[i] -= tmp;
                cnt[batchSize-i] -= tmp;
            }
            // 判断是否结束
            int totalCnt=0,remainCnt=0;
            for(int i=1;i<batchSize;i++){
                totalCnt += cnt[i];
                remainCnt += cnt[i]*i;
            }
            if(totalCnt==0){
                return ans;
            }
            if(remainCnt<batchSize){
                return ans+1;
            }
            // 两个以上的,dfs遍历
            vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>> 
                dp(cnt[1]+1,vector<vector<vector<vector<vector<vector<vector<int>>>>>>>(
                    cnt[2]+1,vector<vector<vector<vector<vector<vector<int>>>>>>(
                        cnt[3]+1,vector<vector<vector<vector<vector<int>>>>>(
                            cnt[4]+1,vector<vector<vector<vector<int>>>>(
                                cnt[5]+1,vector<vector<vector<int>>>(
                                    cnt[6]+1,vector<vector<int>>(
                                        cnt[7]+1,vector<int>(
                                            cnt[8]+1,-1))))))));
            std::function<int(int,int,int,int,int,int,int,int)> dfs = [&dfs,&batchSize,&dp](int i1,int i2,int i3,int i4,int i5,int i6,int i7,int i8) -> int {
                int ret = 0;
                int sum = i1+2*i2+3*i3+4*i4+5*i5+6*i6+7*i7+8*i8;
                if(sum==0) return 0;
                if(dp[i1][i2][i3][i4][i5][i6][i7][i8]!=-1) return dp[i1][i2][i3][i4][i5][i6][i7][i8];
                if(i1) ret = max(ret, dfs(i1-1,i2,i3,i4,i5,i6,i7,i8)+((sum-1)%batchSize==0?1:0));
                if(i2) ret = max(ret, dfs(i1,i2-1,i3,i4,i5,i6,i7,i8)+((sum-2)%batchSize==0?1:0));
                if(i3) ret = max(ret, dfs(i1,i2,i3-1,i4,i5,i6,i7,i8)+((sum-3)%batchSize==0?1:0));
                if(i4) ret = max(ret, dfs(i1,i2,i3,i4-1,i5,i6,i7,i8)+((sum-4)%batchSize==0?1:0));
                if(i5) ret = max(ret, dfs(i1,i2,i3,i4,i5-1,i6,i7,i8)+((sum-5)%batchSize==0?1:0));
                if(i6) ret = max(ret, dfs(i1,i2,i3,i4,i5,i6-1,i7,i8)+((sum-6)%batchSize==0?1:0));
                if(i7) ret = max(ret, dfs(i1,i2,i3,i4,i5,i6,i7-1,i8)+((sum-7)%batchSize==0?1:0));
                if(i8) ret = max(ret, dfs(i1,i2,i3,i4,i5,i6,i7,i8-1)+((sum-8)%batchSize==0?1:0));
                dp[i1][i2][i3][i4][i5][i6][i7][i8]=ret;
                return ret;
            };
            return ans+dfs(cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],cnt[6],cnt[7],cnt[8]);
        }
    };

int main()
{
    int batch,grpSize;
    cin>>batch>>grpSize;
    vector<int> groups(grpSize);
    for(int i=0;i<grpSize;i++){
        cin>>groups[i];
    }
    Solution sol;
    int res = sol.maxHappyGroups(batch,groups);
    cout<<res<<endl;
    return 0;
}
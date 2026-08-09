#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> t(n,vector<int>());
        for(int i=1;i<n;i++){
            t[parent[i]].push_back(i);
        }
        
        vector<int> depth(n,0);
        queue<int> que;
        depth[0]=1;
        int height=1;
        que.push(0);
        while(que.size()>0){
            int i = que.front();
            for(int j=0;j<t[i].size();j++){
                depth[t[i][j]] = depth[i]+1;
                if(depth[t[i][j]]>height) height=depth[t[i][j]];
                que.push(t[i][j]);
            }
            que.pop();
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            ans += ((long long)nums[i])*(height-depth[i]+1);
        }
        return ans;
    }
};
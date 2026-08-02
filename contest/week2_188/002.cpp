#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // TLE了
    int maximumWidth_v1(vector<int>& planks) {
        int n=planks.size();
        if(n==1) return 1;
        sort(planks.begin(),planks.end());
        if(planks[0]==planks[n-1]) return n;
        unordered_set<int> dist;
        for(int i=0;i<n;i++){
            dist.insert(planks[i]);
            for(int j=i+1;j<n;j++){
                dist.insert(planks[i]+planks[j]);
            }
        }
        int l,r;
        int ans=1,tmp=0;
        for(int H : dist){
            l=0;
            r=n-1;
            tmp=0;
            while(l<=r){
                if(planks[r]==H){
                    tmp++;
                    r--;
                }
                else if(planks[l]==H){
                    tmp++;
                    l++;
                }
                else if(l!=r && planks[l]+planks[r]==H) {
                    tmp++;
                    l++;
                    r--;
                }
                else if(l!=r && planks[l]+planks[r]>H) {
                    r--;
                } 
                else {
                    l++;
                }
            }
            if(tmp>ans) ans = tmp;
        }
        return ans;
    }

    int maximumWidth(vector<int>& planks) {
        int n = planks.size(),ans=0;
        if(n<=1) return n;
        unordered_map<int,int> pcnt;
        for(int x: planks){
            pcnt[x]++;
        }
        unordered_map<int,int> hcnt;
        for(auto p: pcnt) {
            hcnt[p.first] += p.second;
            hcnt[p.first*2] += p.second/2;
            for(auto p2: pcnt) {
                if(p.first<p2.first) {
                    hcnt[p.first+p2.first] += min(p.second,p2.second);
                }
            }
        }
        for(auto h: hcnt){
            if(h.second>ans) ans=h.second;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> planks = {1,3,2,5,7,5,4,2,1};
    int ans = sol.maximumWidth(planks);
    cout<<ans<<endl;
    return 0;
}
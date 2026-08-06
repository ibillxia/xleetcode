#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods_v1(int n, int k, vector<vector<int>>& invocations) {
        int m = invocations.size();
        vector<vector<int>> grp(n);
        for(int i=0;i<m;i++){
            grp[invocations[i][0]].push_back(invocations[i][1]);
        }
        unordered_set<int> bug,bugfree;
        bug.insert(k);
        while(1){
            int t1=bug.size();
            unordered_set<int> bug2;
            for(int i: bug){
                for(int j: grp[i])
                    bug2.insert(j);
            }
            for(int i:bug2){
                bug.insert(i);
            }
            int t2=bug.size();
            if(t1==t2){
                break;
            }
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(bug.find(i)==bug.end()){
                for(int j: grp[i]){
                    if(bug.find(j)!=bug.end()){
                        flag=1;
                        break;
                    }
                }
                if(flag==1) break;
                else bugfree.insert(i);
            }
        }
        vector<int> ans;
        if(flag==0){
            for(int i: bugfree){
                ans.push_back(i);
            }
        }else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> grp1(n);
        vector<vector<int>> grp2(n);
        int m = invocations.size();
        for(int i=0;i<m;i++){
            int a=invocations[i][0],b=invocations[i][1];
            grp1[a].push_back(b);
            grp2[b].push_back(a);
        }

        vector<int> is_bug(n,0);
        queue<int> bug;
        bug.push(k);
        while(!bug.empty()){
            int t = bug.front();
            bug.pop();
            if(!is_bug[t]){ // 已经判断过的，不需要重复入队列
                is_bug[t]=1;
                for(int i: grp1[t]){
                    bug.push(i);
                }
            }
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(!is_bug[i]){
                for(int j: grp2[i]){
                    if(is_bug[j]) {
                        flag=1;
                        break;
                    }
                }
                if(flag==1) break;
            }
        }
        vector<int> ans;
        if(flag==1){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }else {
            for(int i=0;i<n;i++){
                if(!is_bug[i]) ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    int n=4,k=1;
    vector<vector<int>> invocations={{1,2},{0,1},{3,2}};
    Solution sol;
    vector<int> ans = sol.remainingMethods(n,k,invocations);
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[ans.size()-1]<<endl;
    return 0;
}
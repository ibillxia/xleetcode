#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
    // TLE: 超出时间限制
    vector<int> countTasks_v1(vector<int>& tasks, vector<int>& shifts) {
        int __debug__ = 0;
        int n = tasks.size();
        int m = shifts.size();
        vector<int> ans(m,0);
        vector<int> task2(n,0);
        long long total=0;
        for(int ii=0;ii<n;ii++){
            task2[ii] = tasks[ii];
            total += (long long)tasks[ii];
        }
        for(int i=0,j=0;i<n && j<m;i++){
            if(__debug__)printf("L%03d | Debug: i=%d,j=%d,shifts[j]=%d\n",__LINE__,i,j,shifts[j]);
            if(shifts[j]>=total){
                ans[j]=0;
                j++;
                i=-1;
            }
            while(j<m && task2[i]>shifts[j]){
                task2[i] -= shifts[j];
                ans[j]= n-i;
                if(__debug__)printf("L%03d | Debug: i=%d,j=%d,ans[j]=%d\n",__LINE__,i,j,ans[j]);
                j++;
            }
            if(j>=m) {
                break;
            }
            if(__debug__)printf("L%03d | Debug: i=%d,j=%d,ans[j]=%d,shifts[j]=%d\n",__LINE__,i,j,ans[j],shifts[j]);
            while(i<n && shifts[j]>=task2[i]){
                shifts[j] -= task2[i];
                ans[j] = n-i-1;
                i++;
            }
            if(i==n){
                ans[j]=0;
                if(__debug__)printf("L%03d | Debug: i=%d,j=%d,ans[j]=%d\n",__LINE__,i,j,ans[j]);
                i=-1;
                j++;
                for(int ii=0;ii<n;ii++){
                    task2[ii] = tasks[ii];
                }
            }else{
                task2[i] -= shifts[j];
                j++;
                i--;
            }
            if(__debug__)printf("L%03d | Debug: i=%d,j=%d,ans[j]=%d\n",__LINE__,i,j,ans[j]);
        }
        return ans;
    }
    // 前缀和、二分查找
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int __debug__ = 0;
        int n = tasks.size();
        int m = shifts.size();
        vector<int> ans(m,0);
        vector<long long> pre_sum(n,0);
        long long total=0;
        for(int ii=0;ii<n;ii++){
            total += (long long)tasks[ii];
            pre_sum[ii]=total;
        }
        int l=0,r=n-1,j=0;
        total=0;
        for(int i=0;i<m;i++){
            total+=shifts[i];
            // if(__debug__)printf("L%03d | Debug: i=%d,j=%d,total=%lld\n",__LINE__,i,j,total);
            if(total>=pre_sum[n-1]){
                total=0;
                ans[i]=0;
                continue;
            }
            l=0,r=n-1;
            while(l<r){
                j=(l+r)/2;
                if(pre_sum[j]<total) l=j+1;
                else r=j;
                if(__debug__)printf("L%03d | find j: l=%d,r=%d,j=%d,presum[j]=%lld,total=%lld-----\n",__LINE__,l,r,j,pre_sum[j],total);
            }
            if(__debug__)printf("L%03d | Debug: l=%d,r=%d,j=%d,presum[j]=%lld,total=%lld\n",__LINE__,l,r,j,pre_sum[j],total);
            j=(l+r)/2;
            ans[i]= n-j;
            if(pre_sum[j]==total) ans[i]--;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> tasks,shifts,ans;
    tasks = {1,4,4};
    shifts = {9,1,4};
    ans = sol.countTasks(tasks,shifts);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    tasks = {2,3,4};
    shifts = {20,4,5};
    ans = sol.countTasks(tasks,shifts);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    tasks = {4,2};
    shifts = {3,6,1};
    ans = sol.countTasks(tasks,shifts);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    tasks = {1,1,3,3,8};
    shifts = {2,9,5,3,9};
    ans = sol.countTasks(tasks,shifts);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
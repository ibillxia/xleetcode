#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        map<pair<int,int>,int> mp;
        vector<vector<int> > ans;
        if(num.size()<3||num[0]>0||num[num.size()-1]<0)return ans;
        int i,j,t,l,r,m;
        for(i=0;i<num.size()-2&&num.at(i)<1;i++){
            for(j=i+1;j<num.size()-1;j++){
                if(mp.count(make_pair(num.at(i),num.at(j))))continue;
                t=-num.at(i)-num.at(j);
                if(num[j+1]-t>0)break;
                if(num[num.size()-1]-t<0)continue;
                l=j+1,r=num.size()-1,m=(l+r)/2;
                while(l<=r){
                    m=(l+r)/2;
                    if(num.at(m)==t)break;
                    if((num.at(m)-t)>0)r=m-1;
                    else l=m+1;
                }
                if(num.at(m)==t){
                    vector<int> vk(3);
                    vk[0]=num.at(i),vk[1]=num.at(j),vk[2]=num.at(m);
                    ans.push_back(vk);
                    mp[make_pair(num.at(i),num.at(j))]=1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v(6); //{-1 0 1 2 -1 -4}
    v[0]=-1,v[1]=0,v[2]=1,v[3]=2,v[4]=-1,v[5]=-4;
    vector<vector<int> > ans = sol.threeSum(v);
    cout<<ans.size()<<endl;
    return 0;
}

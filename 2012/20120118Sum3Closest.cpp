#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int i,j,t,tmin,l,r,m,ans;
        tmin=abs(num.at(0)+num.at(1)+num.at(2)-target);
        ans=num.at(0)+num.at(1)+num.at(2);
        for(i=0;i<num.size()-2;i++){
            for(j=i+1;j<num.size()-1;j++){
                t=num.at(i)+num.at(j);
                l=j+1,r=num.size()-1,m=(l+r)/2;
                while(l<=r){
                    m=(l+r)/2;
                    if(num.at(m)+t==target)return target;
                    if((num.at(m)+t)>target)r=m-1;
                    else l=m+1;
                }
                if(num.at(m)+t==target)return target;
                if(abs(num.at(m)+t-target)<tmin){
                    tmin=abs(num.at(m)+t-target);
                    ans=num.at(m)+t;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v(4); //{-1 0 1 2 -1 -4}
    v[0]=1,v[1]=1,v[2]=1,v[3]=0;
    int ans = sol.threeSumClosest(v,100);
    cout<<ans<<endl;
    return 0;
}

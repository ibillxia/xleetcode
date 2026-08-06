#include<iostream>

using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans,m=1,i=n,j=1;
        while(1){
            j=i;
            while(j){
                m *= j%10;
                j /= 10;
                if(m==0) break;
            }
            if(m==0 || m%t==0){
                ans=i;
                break;
            }else{
                m=1;
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    int n,t;
    cin>>n>>t;
    Solution sol;
    int ans = sol.smallestNumber(n,t);
    cout<<ans<<endl;
    return 0;
}
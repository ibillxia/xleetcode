#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        static bool cmp(int a,int b){
            return a>b;
        }
        double minPrice(vector<int>& prices, vector<int>& discounts) {
            sort(prices.begin(),prices.end(),cmp);
            sort(discounts.begin(),discounts.end(),[](int a,int b){return a>b;});
            int n1=prices.size(),n2=discounts.size();
            double ans=0.0;
            for(int i=0;i<n1;i++){
                if(i<n2){
                    ans+=prices[i]*(100-discounts[i])/100.0;
                }else{
                    ans+=prices[i]*1.0;
                }
            }
            return ans;
        }
    };

int main()
{
    vector<int> prices = {10,30,21};
    vector<int> discounts = {50,60};
    Solution sol;
    double ans = sol.minPrice(prices,discounts);
    cout<<ans<<endl;
    return 0;
}

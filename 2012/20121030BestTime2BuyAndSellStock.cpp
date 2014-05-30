#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int i,j;
		//for(i=j=0;i<prices.size();i++){
		//	if(prices[i])prices[j++]=prices[i];
		//}
		j=prices.size();
        if(j<2)return 0;
        if(j==2)return prices[0]>prices[1]? 0: prices[1]-prices[0];
        int mi,ans=0;
        mi=0;i=1;
        while(i<j){
            if(prices[i]<prices[mi])mi=i;
            else if(prices[i]-prices[mi]>ans)ans=prices[i]-prices[mi];
			i++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    //vector<int> v(10);
    //v[0]=v[1]=3;
    //v[2]=v[3]=5;
    //v[4]=v[5]=1;
    //v[6]=v[7]=4;
    //v[8]=v[9]=2;
	int a[]={6,1,3,2,4,7};
	vector<int> v(a,a+6);
	//v[0]=v[4]=2,v[1]=v[3]=0,v[2]=1;
    int ans = sol.maxProfit(v);
    cout<<ans<<endl;
    return 0;
}

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
	int maxProfit(vector<int> &prices){
		int i,sz;
		sz = prices.size();
		if(sz<2)return 0;
		if(sz==2) return prices[0]>prices[1] ? 0 : prices[1]-prices[0];

		int *f = new int[sz];
		int *g = new int[sz];
		memset(f,0,sizeof(int)*sz);
		memset(g,0,sizeof(int)*sz);
		int mi,mx;
		for(i=1,mi=prices[0];i<sz;i++){
			if(prices[i]<mi)mi=prices[i];
			f[i]=max(f[i-1],prices[i]-mi);
		}
		for(i=sz-2,mx=prices[sz-1];i>=0;i--){
			if(prices[i]>mx)mx=prices[i];
			g[i]=max(g[i],mx-prices[i]);
		}

		int ans=0;
		for(i=0;i<sz;i++){
			ans = max(ans,f[i]+g[i]);
		}
		return ans;
	}

    int maxProfit2(vector<int> &prices) { // TLE
		int i,j;
		j=prices.size();
        if(j<2)return 0;
        if(j==2)return prices[0]>prices[1]? 0: prices[1]-prices[0];
        
		int ma,mb,ans=0;
        i=0;
        while(i<j-1){
			if(prices[i]>prices[i+1]){
				ma = maxProfit(prices,0,i+1);
				mb = maxProfit(prices,i+1,j);
        	    if(ma+mb>ans)ans=ma+mb;
			}
			i++;
        }
        return ans;
    }
private:
	int maxProfit(vector<int> &prices,int start,int end){
		if(start>=end)return 0;
		int i=start+1,mi=start,mx=start+1,ans=0;
		while(i<end){
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
	int a[]={1,2,4,2,5,7,2,4,9,0};
	vector<int> v(a,a+10);
	//v[0]=v[4]=2,v[1]=v[3]=0,v[2]=1;
    int ans = sol.maxProfit(v);
    cout<<ans<<endl;
    return 0;
}

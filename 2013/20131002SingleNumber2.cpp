#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	int singleNumber(int A[], int n) {
        if(!n)return 0;
		if(n==1)return A[0];
		int i,j,cnt[32],ans;
		unsigned int t;
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<n;i++){
			t=(unsigned int)A[i];
			j=0;
			while(t){
				if(t&0x1)cnt[j]++;
				t>>=1,j++;
			}
		}
		ans=0;
		for(i=0;i<32;i++){
			if(cnt[i]%3)ans+=1<<i;
		}
		return ans;
    }
};

int main()
{
    Solution sol;
	int a[]={-2,-2,1,1,-3,1,-3,-3,-4,-2};
	int ans = sol.singleNumber(a,10);
    cout<<ans<<endl;
    return 0;
}

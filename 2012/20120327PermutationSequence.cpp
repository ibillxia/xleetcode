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
    string getPermutation(int n, int k) {
		vector<int> num(n);
		string ans;
		char c;
		int i;
		if(n<7){
			for(i=0;i<n;i++)num[i]=i+1;
		}else{
			int fn =1;
			for(i=2;i<n;i++)fn*=i;
			i=1;
			while(k>fn)k-=fn,i++;
			num[0]=i;
			for(int j=1;j<n;j++){
				if(j<i)num[j]=j;
				else if(j>=i) num[j]=j+1;
			}
		}
		i=1;
		while(i<k){
			next_permutation(num.begin(),num.end());
			i++;
		}
		for(i=0;i<n;i++){
			c=num[i]+'0';
			ans+=c;
		}
		return ans;
    }

};

int main()
{
    Solution sol;
    string ans = sol.getPermutation(8,31492);
	cout<<ans<<endl;
    return 0;
}

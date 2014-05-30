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
	bool isPalindrome(int x) {
		if(x<0)return false;
		if(!x) return true;
		int i,t,n;
		t=x/10,n=1;
		while(t)n*=10,t/=10;
		t=x;
		while(t){
			if(t/n!=t%10)break;
			t%=n;
			t/=10;
			n/=100;
		}
		if(t)return false;
		return true;
	}
};

int main()
{
	Solution sol;
	int x;
	while(cin>>x){
		bool ans=sol.isPalindrome(x);
		cout<<ans<<endl;
	}
	return 0;
}


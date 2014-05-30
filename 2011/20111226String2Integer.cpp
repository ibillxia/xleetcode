#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	int atoi(const char *str) {
		int ans=0,i=0,sgn=1;
		while(str[i]==' ')i++;
		if(str[i]=='-')sgn=-1,i++;
		if(str[i]=='+')i++;
		while(str[i]>='0'&&str[i]<='9'){
			if(sgn==1){
				if((INT_MAX-str[i]+'0')/10<ans)return INT_MAX;
				ans=ans*10-'0'+str[i];
			}else{
				if((INT_MIN+str[i]-'0')/10>ans)return INT_MIN;
				ans=ans*10-str[i]+'0';
			}
			i++;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	char str[32]; //=" -2147483648 ";
	while(cin>>str){
	int ans = sol.atoi(str);
	int ans_inner = atoi(str);
	cout<<ans<<","<<ans_inner<<endl;
	}
	return 0;
}


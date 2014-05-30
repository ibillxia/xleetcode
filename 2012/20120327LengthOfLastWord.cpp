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
	int lengthOfLastWord(const char *s) {
		int sz=strlen(s);
		int i=sz-1,ans=0;
		while(i>=0&&s[i]==' ')i--;
		while(i>=0&&s[i]!=' '){
			i--;
			ans++;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	char *s = new char[2048];
	while(gets(s)){
		cout<<sol.lengthOfLastWord(s)<<endl;
	}
	return 0;
}


#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	bool isNumber(const char *s) {
		char *ss;
		double lf=strtod(s,&ss);
		if(ss==s)return false;
		while(*ss!='\0'){
			if(*ss!=' ')return false;
			ss++;
		}
		return true;
	}
};

int main()
{
	Solution sol;
	char s[256];
	while(cin.getline(s,256)){
		cout<<sol.isNumber(s)<<endl;
	}
	return 0;
}


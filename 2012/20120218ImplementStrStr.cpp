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
	char *strStr(char *haystack, char *needle) {
		char *p;
		int sl1,sl2;
		sl1 = strlen(haystack);
		sl2 = strlen(needle);
		if(sl1<sl2)return NULL;
		p=haystack;
		while(p-haystack<=sl1-sl2){
			if(!strncmp(p,needle,sl2))return p;
			p++;
		}
		return NULL;
	}
};

int main()
{
	Solution sol;
	char str1[] = "char *strStr(char *haystack, char *needle)";
	char str2[] = "char *n";
	char *ans = sol.strStr(str1,str2);
	cout<<ans<<endl;
	return 0;
}


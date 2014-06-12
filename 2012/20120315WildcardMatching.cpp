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
	bool isMatch(const char *s,const char *p){
		bool b = false;
		const char *x,*y;
		for(x=s,y=p; *x != '\0'; x++,y++){
			if(*y=='?'){
				continue;
			}else if(*y=='*'){
				b=true;
				s=x,p=y;
				while(*p=='*')p++;
				if(*p=='\0') return true;
				x=s-1,y=p-1;
			}else{
				if(*x != *y){
					if(!b)return false;
					s++;
					x=s-1,y=p-1;
				}
			}
		}
		while(*y=='*')y++;
		return (*y=='\0');
	}
	bool isMatch2(const char *s,const char *p) { // TLE
		if(*p=='\0'&&*s=='\0')return true;
		if(*p=='\0'&&*s!='\0')return false;
		#ifdef DEBUG
		cout<<"DEBUG:"<<s<<"|"<<p<<endl;
		#endif
		if(*p!='*'){
			if((*p=='?' && *s!='\0')||(*s==*p))return isMatch(s+1,p+1);
			return false;
		}else{ // *p = '*'
			while(*(p+1)=='*')p++;
			if(*(p+1)==*s && isMatch(s+1,p+2))return true;
			if(*s!='\0' && isMatch(s+1,p))return true;
			return isMatch(s,p+1);
		}
		//return false;
	}
};

int main()
{
	Solution sol;
	char s[128],p[128];
	while(cin>>s>>p){
		cout<<sol.isMatch(s,p)<<endl;
	}
	return 0;
}


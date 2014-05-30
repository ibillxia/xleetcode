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
#define DEBUG

class Solution {
public:
	bool isMatch(const char *s, const char *p){
		if(*p=='\0'&&*s=='\0')return true;
		if(*p=='\0'&&*s!='\0')return false;
		#ifdef DEBUG
		cout<<"DEBUG:"<<s<<"|"<<p<<endl;
		#endif
		if(*(p+1)!='*'){
			if((*p=='.' && *s!='\0')||(*s==*p))return isMatch(s+1,p+1);
			return false;
		}else{
			while((*p=='.' && *s!='\0')||(*s==*p)){
				if(isMatch(s,p+2))return true;
				s++;
			}
			return isMatch(s,p+2);
		}
		//return false;
	}

	bool isMatch2(const char *s, const char *p) { // not completed, too complex
		int i,j,k,ls,lp;
		ls = strlen(s);
		lp = strlen(p);
		if(!ls&&!lp)return true;
		i=j=0;
		while(i<ls&&j<lp){
			if(j+1<lp){
				if(p[j+1]=='*'){
					if(p[j]!='.'){
						if(s[i]!=p[j]){ // '*' = 0*p[j]
							j+=2;
							continue;
						}
						// s[i] = p[j]
						k=j+2;
						while(i<ls&&k<lp&&s[i]==p[k])i++,k++; // match s[i] and s[i]=p[k](after '*' in p)
						while(i<ls&&k<lp&&s[i]==p[j])i++; // match remaining s[i]=p[j],'*'=N*p[j]
						if(i==ls){
							if(k==lp)return true;
							while(j+1<lp&&p[j+1]=='*')j+=2;
						}else{
							j+=2;
						}
					}else { // p[j]='.'
					
					}
				}else if(p[j]==s[i]||p[j]=='.'){ // p[j+1]!='*'
					i++;
					j++;
				}else return false;
			}else { // j=lp-1
				if(i==ls-1&&(s[i]==p[j]||p[j]=='.'))return true;
				return false;
			}
		}
		if(i<ls)return false;
		// i=ls,j<=lp
		while(j+1<lp&&p[j+1]=='*')j+=2;
		if(j+1<=lp)return false;
		return true;
	}
};

int main()
{
	Solution sol;
	char s[128];//="aaaaaa";
	char p[128];//="a*aab*a*aa*c*a*a*aa*a*a";
	while(cin>>s>>p){
		cout<<s<<" "<<p<<endl;
		bool ans=sol.isMatch(s,p);
		cout<<ans<<endl;
	}
	return 0;
}


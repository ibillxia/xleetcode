#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) { // DP
		int x,y,z;
		x=s1.size();
		y=s2.size();
		z=s3.size();
		if(x+y!=z)return false;

		if(x>y){
			swap(s1,s2);
			swap(x,y);
		}
		vector<bool> dp(x+1,true);
		int i,j;
		for(i=1;i<=x;i++){
			if(s1[i-1]==s3[i-1] && dp[i-1])dp[i]=true;
			else dp[i]=false;
		}
		for(i=1;i<=y;i++){
			if(s2[i-1]==s3[i-1] && dp[0])dp[0]=true;
			else dp[0]=false;
			for(j=1;j<=x;j++){
				if((s2[i-1]==s3[i+j-1] && dp[j])||
					(s1[j-1]==s3[i+j-1] && dp[j-1]))dp[j]=true;
				else dp[j]=false;
			}
		}
		return dp[x];
	}
    bool isInterleave2(string s1, string s2, string s3) {
        int x,y,z;
		x=s1.size();
		y=s2.size();
		z=s3.size();
		if(x+y!=z)return false;
		char *p1=new char[x+1];
		char *p2=new char[y+1];
		char *p3=new char[z+1];
		strcpy(p1,s1.c_str());
		strcpy(p2,s2.c_str());
		strcpy(p3,s3.c_str());
		return isInterleave(p1,p2,p3);
    }
private:
	bool isInterleave(char *p1,char *p2,char *p3){ // TLE
		if(*p1=='\0' && *p2=='\0' && *p3=='\0')return true;
		if(*p1!='\0' && *p2!='\0' && *p1==*p3 && *p2==*p3)
			return isInterleave(p1+1,p2,p3+1) || isInterleave(p1,p2+1,p3+1);
		if(*p1!='\0' && *p1 == *p3 && isInterleave(p1+1,p2,p3+1))return true;
		if(*p2!='\0' && *p2 == *p3 && isInterleave(p1,p2+1,p3+1))return true;
		return false;
	}
};

int main()
{
    Solution sol;
    string s1,s2,s3;
	while(cin>>s1>>s2>>s3){
		cout<<sol.isInterleave(s1,s2,s3)<<endl;
	}
    return 0;
}
/*demo input:
aabcc
dbbca
aadbbcbcac
aabcc
dbbca
aadbbbaccc
bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa
babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab
babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab
*/

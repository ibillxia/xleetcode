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
	void reverseWords(string &s) {
        int i,j,k,t,n;
		string s2=s;
		n=s2.size();
		s.clear();
		//for(i=0;i<n;i++)s[i]='\0';
		for(i=n-1,k=0;i>=0;i--){
			while(i>=0&&s2[i]==' ')i--;
			if(i<0)break;
			j=i;
			while(j>=0&&s2[j]!=' ')j--;
			if(k)s+=' ';
			for(t=j+1;t<=i;t++)s+=s2[t];
			i=j;
			k=1;
		}
    }
};

int main()
{
    Solution sol;
	string s = "  the sky is blue  ";  // "   " , "  a  "
	sol.reverseWords(s);
    cout<<s<<endl;
	cout<<s.size()<<endl;
    return 0;
}

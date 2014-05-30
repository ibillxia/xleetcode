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
	bool isValid(string s) {
		int sz=s.size(),i,len;
		if(!sz)return true;
		if(sz%2==1)return false;
		string ss(s);
		while(ss.length()){
			len=ss.length();
			for(i=0;i<len-1;i++){
				if((ss[i]=='('&&ss[i+1]==')')||(ss[i]=='['&&ss[i+1]==']')||(ss[i]=='{'&&ss[i+1]=='}')){
					ss.erase(i,2);
					break;
				}
			}
			if(i==len-1)return false;
		}
		return true;
	}
};

int main()
{
	Solution sol;
	string s;
	//s="()[]{}";
	while(cin>>s){
		bool ans = sol.isValid(s);
		cout<<ans<<endl;
	}
	return 0;
}


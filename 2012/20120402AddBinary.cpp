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
	string addBinary(string a,string b) {
		if(!a.size())return b;
		if(!b.size())return a;
		int i,m,n,c,s;
		m=a.size();
		n=b.size();
		reverse(a);
		reverse(b);
		string ans;
		i=c=0;
		while(i<m||i<n){
			s=c;
			if(i<m)s+=a[i];
			if(i<n)s+=b[i];
			if(i<m&&i<n)s-='0';
			if(s>'1'){
				c=1;
				ans+=char(s-2);
			}else{
				c=0;
				ans+=char(s);
			}
			i++;
		}
		if(c)ans+='1';
		reverse(ans);
		return ans;
	}
	void reverse(string &s){
		int i,n;
		n=s.size();
		if(n<2)return;
		for(i=0;i<n/2;i++){
			swap(s[i],s[n-1-i]);
		}
		return;
	}
};

int main()
{
	Solution sol;
	string a,b;
	while(cin>>a>>b){
		cout<<sol.addBinary(a,b)<<endl;
	}
	return 0;
}


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
    int numDecodings(string s) {
		int i,n;
		n=s.size();
		if(!n)return 0;
		if(s[0]<'1')return 0;
		if(n==1)return 1;

		int t;
		int *f = new int[n];
		memset(f,0,sizeof(int)*n);
		if(s[n-1]<'1')f[n-1]=0;
		else f[n-1]=1;

		t=(s[n-2]-'0')*10+s[n-1]-'0';
		if(t<1)return 0;
		if(t<10)f[n-2]=1;
		else if(t==10||t==20)f[n-2]=1;
		else if(t<27)f[n-2]=2;
		else if(t%10)f[n-2]=1;
		else return 0;
		for(i=n-3;i>=0;i--){
			t=(s[i]-'0')*10+s[i+1]-'0';
			if(t<1)return 0;
			else if(t<10)f[i]=f[i+1];
			else if(t==10||t==20) f[i]=f[i+2];
			else if(t<27){
				if(i<n-2&&s[i+2]<'1') f[i]=f[i+1];
				else f[i]=f[i+1]+f[i+2];
			}
			else if(t%10)f[i]=f[i+1];
			else return 0;
		}
		return f[0];
    }
};

int main()
{
    Solution sol;
    string str;
	while(cin>>str){
		cout<<sol.numDecodings(str)<<endl;
	}
    return 0;
}

/* demo input:
0  // 0
10 // 1
20 // 1
30 // 0
110// 1
120// 1
1212//5
121212//13
*/

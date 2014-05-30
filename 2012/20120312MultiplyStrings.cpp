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
//#define DEBUG

class Solution {
public:
	string multiply(string num1, string num2) {
		int i,j;
		int ln1 = num1.size();
		int ln2 = num2.size();
		char cj;
		int carry,ni,nj;
		string ans;
		reverse(num1.begin(),num1.end());
		reverse(num2.begin(),num2.end());
		for(i=0;i<ln1;i++){
			string si(i,'0');
			carry=0;
			for(j=0;j<ln2;j++){
				ni=num1[i]-'0';
				nj=num2[j]-'0';
				cj='0'+(carry+ni*nj)%10;
				carry=(carry+ni*nj)/10;
				si+=cj;
			}
			#ifdef DEBUG
			cout<<"DEBUG: "<<i<<" "<<si<<endl;
			#endif
			if(carry)si+=(carry+'0');
			if(!ans.size())ans=si;
			else{
				j=carry=0;
				while(carry||j<si.size()||j<ans.size()){
					if(j<si.size()) carry += si[j]-'0';
					if(j<ans.size()) carry += ans[j]-'0';
					if(j<ans.size()) ans[j]=carry%10+'0';
					else ans+= (carry%10+'0');
					carry = carry/10;
					j++;
				}
			}
			#ifdef DEBUG
			cout<<"DEBUG: "<<ans<<endl;
			#endif
		}
		reverse(ans.begin(),ans.end());
		if(ans[0]=='0')return string("0");
		return ans;
	}
};

int main()
{
	Solution sol;
	//string num1("1234567890");
	//string num2("20");
	string num1,num2;
	while(cin>>num1>>num2){
		string ans = sol.multiply(num1,num2);
		cout<<ans<<endl;
	}
	return 0;
}


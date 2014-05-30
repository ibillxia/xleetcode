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
	vector<string>ans;
	string str;
	vector<string> letterCombinations(string digits) {
		if(!digits.size()){
			ans.push_back("");
			return ans;
		}
		gen(&digits[0],0);
		return ans;
	}

	void gen(char *d,int n){
		static const char dict[][8]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		static const int len[10]={0,0,3,3,3,3,3,4,3,4};
		int i;
		if(n==strlen(d)){
			ans.push_back(str);
			return;
		}
		for(i=0;i<len[d[n]-'0'];i++){
			str+=dict[d[n]-'0'][i];
			gen(d,n+1);
			//str.pop_back();
			str=str.substr(0,str.size()-1);
		}
	}
};

int main()
{
	Solution sol;
	char str[] = "";
	string digits(str);
	cout<<digits.size()<<endl;
	vector<string> ans = sol.letterCombinations(digits);
	FOR(i,ans.size()){
		cout<<ans[i]<<endl;
	}
	cout<<ans.size()<<endl;
	return 0;
}


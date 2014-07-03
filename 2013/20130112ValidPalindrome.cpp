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
	bool isPalindrome(string s) {
		int sz=s.size();
		if(sz<2)return true;
		
		int i;
		vector<char> vc;
		for(i=0;i<sz;i++){
			if(s[i]>='A'&&s[i]<='Z'){
				vc.push_back(s[i]-'A'+'a');
			}else if(s[i]>='a'&&s[i]<='z'){
				vc.push_back(s[i]);
			}else if(s[i]>='0'&&s[i]<='9'){
				vc.push_back(s[i]);
			}
		}
		sz=vc.size();
		for(i=0;i<sz;i++){
			if(vc[i]!=vc[sz-i-1])return false;
		}
		return true;
	}
};

int main()
{
	Solution sol;
	string s;
	while(getline(std::cin,s)){
		cout<<sol.isPalindrome(s)<<endl;
	}
	return 0;
}


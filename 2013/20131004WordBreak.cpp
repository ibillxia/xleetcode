#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_set>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		int sz=s.size();
		int i,j;
		vector<bool> f(sz+1,false);
		f[0]=true;
		for(i=1;i<=sz;i++){
			for(j=i-1;j>=0;j--){
				if(f[j] && dict.find(s.substr(j,i-j))!=dict.end()){
					f[i]=true;
					break;
				}
			}
		}
		return f[sz];
	}
};

int main()
{
	Solution sol;
	string s,t;
	int n;
	while(cin>>s>>n){
		unordered_set<string> dict;
		FOR(i,n){
			cin>>t;
			dict.insert(t);
		}
		cout<<sol.wordBreak(s,dict)<<endl;
	}
	return 0;
}


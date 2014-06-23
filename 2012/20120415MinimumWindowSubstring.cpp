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
#include<climits>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
	string minWindow(string S,string T) {
		int m,n;
		m = S.size();
		n = T.size();
		if(m<n)return "";
		if(m==n && S.compare(T)==0)return S;

		int i,wini=0,mi,mw=INT_MAX;
		int cnt=0,cnt1[256],cnt2[256];
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(i=0;i<n;i++)cnt1[T[i]]++;
		for(i=0;i<m;i++){
			if(cnt1[S[i]]){
				cnt2[S[i]]++;
				if(cnt2[S[i]] <= cnt1[S[i]])cnt++;
			}
			if(cnt==n){
				while(cnt2[S[wini]]>cnt1[S[wini]] || cnt1[S[wini]]==0){
					cnt2[S[wini]]--;
					wini++;
				}
				if(mw>(i-wini+1)){
					mw = i-wini+1;
					mi = wini;
				}
			}
		}
		if(mw==INT_MAX)return "";
		return S.substr(mi,mw);
	}
};

int main()
{
	Solution sol;
	string S,T;
	while(cin>>S>>T){
		cout<<sol.minWindow(S,T)<<endl;
	}
	return 0;
}


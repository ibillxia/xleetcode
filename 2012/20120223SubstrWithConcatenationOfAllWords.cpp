#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
//#define DEBUG

class Solution {
public:
	vector<int> findSubstring(string S,vector<string> &L) { // AC
		vector<int> ans;
		int i,j,k,szs,szl,szli,sz;
		szs=S.size();
		szl=L.size();
		szli=L[0].size();
		sz=szl*szli;
		if(szs<sz)return ans;
		#ifdef DEBUG
		cout<<"DEBUG:"<<szs<<" "<<szl<<" "<<szli<<endl;
		#endif

		// convert L to map
		map<string,int> mp;
		for(i=0;i<szl;i++){
			if(mp.find(L[i])==mp.end()){
				mp.insert(make_pair(L[i],1));
			}else {
				mp[L[i]]++;
			}
		}
		
		for(i=0;i<=szs-sz;i++){
			map<string,int> mp2(mp);
			for(j=k=0;j<szl;j++){ // check if strings in L apear once
				string st(&S[i+k],szli);
				if(mp2[st]){
					mp2[st]--;
					k+=szli;
					#ifdef DEBUG
					cout<<"DEBUG:"<<j<<" "<<st<<endl;
					#endif
				}else break;
			}
			if(j==szl){
				ans.push_back(i);
			}
		}
		return ans;
	}

	vector<int> findSubstring2(string S, vector<string> &L) {  // TLE
		vector<int> ans;
		int i,j,k,t,szs,szl,szli,sz;
		szs=S.size();
		szl=L.size();
		szli=L[0].size();
		sz=szl*szli;
		vector<bool> used(szl);
		for(i=0;i<szs-sz;i++){
			fill(used.begin(),used.end(),false);
			k=t=0;
			for(j=0;j<szl;j++){ // check if strings in L apear once
				if(i+k+szli<szs && !used[j] && !strncmp(&S[i+k],&L[j][0],szli)){
					used[j]=true;
					k+=szli;
					t++;
					j=-1;
				}
				if(t==szl)break;
			}
			if(t==szl){
				ans.push_back(i);
				//i+=k-1;
			}
		}
		return ans;
    }
};

int main()
{
	Solution sol;
	string s;
	vector<string> L;
	string str;// = "barfoothefoobarman";
	//L.push_back("bar");
	//L.push_back("foo");
	cin>>str;
	while(cin>>s){
		L.push_back(s);
	}
	cout<<"read input done!"<<endl;

	vector<int> ans = sol.findSubstring(str,L);

	cout<<"size of ans: "<<ans.size()<<endl;
	FOR(i,ans.size())cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}


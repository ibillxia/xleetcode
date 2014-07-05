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
	vector<vector<string> > findLadders(string start,string end,unordered_set<string> &dict){
		unordered_set<string> visited;
		unordered_set<string> s1,s2;
		vector<vector<string> > ans;
		map<string,vector<string> > mp;
		int i,sz;
		char c;
		bool find=false;
		sz=start.size();
		string key,val;
		s1.insert(start);
		while(!s1.empty() && !find){ // BFS
			for(auto it=s1.begin();it!=s1.end();it++){
				visited.insert(*it);
			}
			for(auto it=s1.begin();it!=s1.end();it++){
				key=val=*it;
				for(i=0;i<sz;i++){
					for(c='a';c<='z';c++){
						if(key[i]==c) continue;
						swap(key[i],c);
						if(key==end){
							find = true;
							mp[key].push_back(val);
						}else if(dict.count(key) && !visited.count(key)){ 
							//visited.insert(key+str);
							s2.insert(key);
							mp[key].push_back(val);
						}
						swap(key[i],c);
					} // end for(c)
				} // end for(i)
			} // end for(auto it)
			s1.clear();
			swap(s1,s2);
		} // end while
		paths.clear();
		if(!find)return ans;
		//mp.insert(make_pair(end,""));
		genPaths(mp,start,end);
		//sort(paths.begin(),paths.end());
		//paths.erase(unique(paths.begin(),paths.end()),paths.end());
		return paths;
	}
private:
	vector<string> path;
	vector<vector<string> >paths;
	void genPaths(map<string,vector<string> > &mp,string start,string end){ // DFS
		path.push_back(end);
		if(start==end){
			paths.push_back(path);
			reverse(paths.back().begin(),paths.back().end());
		}else{
			for(auto it=mp[end].begin();it!=mp[end].end();it++)
				genPaths(mp,start,*it);
		}
		path.pop_back();
	}
};

int main()
{
	Solution sol;
	int n;
	string start,end,str;
	unordered_set<string> dict;
	vector<vector<string> > ans;
	while(cin>>start>>end>>n){ 
		FOR(i,n){
			cin>>str;
			dict.insert(str);
		}
		ans = sol.findLadders(start,end,dict);
		FOR(i,ans.size()){
			FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
			cout<<endl;
		}
		dict.clear();
	}
	return 0;
}

/* demo input:
hit
cog
5
hot
dot
dog
lot
log
red
tax
8
ted
tex
red
tax
tad
den
rex
pee
*/

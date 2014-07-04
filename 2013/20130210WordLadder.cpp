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
	int ladderLength(string start,string end,unordered_set<string> &dict){
		if(!start.compare(end))return 1;
		if(start.size()==1)return 2;
		
		unordered_set<string> visited;
		queue<string> q1,q2;
		int ans=1,i,sz;
		char c;
		sz=start.size();
		string str;
		q1.push(start);
		while(q1.size()){ // BFS
			while(q1.size()){
				str=q1.front();
				q1.pop();
				for(i=0;i<sz;i++){
					for(c='a';c<='z';c++){
						if(str[i]!=c){
							swap(str[i],c);
							if(!str.compare(end))return ans+1;
							if(dict.count(str) && !visited.count(str)){
								visited.insert(str);
								q2.push(str);
							}
							swap(str[i],c);
						}
					} // end for(c)
				} // end for(i)
			} // end while
			swap(q1,q2);
			ans++;
		} // end while
		return 0;
	}
};

int main()
{
	Solution sol;
	int n;
	string start,end,str;
	unordered_set<string> dict;
	while(cin>>start>>end>>n){ 
		FOR(i,n){
			cin>>str;
			dict.insert(str);
		}
		cout<<sol.ladderLength(start,end,dict)<<endl;
		dict.clear();
	}
	return 0;
}


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

struct Interval{
	int start;
	int end;
	Interval(): start(0),end(0) {}
	Interval(int s,int e): start(s),end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &in,Interval ini) {
		vector<Interval> ans;
		int sz=in.size();
		if(!sz){
			ans.push_back(ini);
			return ans;
		}
		if(in[sz-1].end<ini.start){
			ans=in;
			ans.push_back(ini);
			return ans;
		}
		if(in[0].start>ini.end){
			ans.push_back(ini);
			ans.insert(ans.end(),in.begin(),in.end());
			return ans;
		}
		int i,l,r,m;
		l=0,r=sz;
		while(l<=r){
			m=(l+r)/2;
			if(in[m].start>ini.start)r=m-1;
			else if(in[m].start==ini.start)break;
			else l=m+1;
		}
		l=r;
		if(in[m].start==ini.start)l=m;
		if(l<0)l=0;
		if(l==sz)l=sz-1;
		for(i=0;i<l;i++)ans.push_back(in[i]);
		Interval ti;
		if(in[l].end<ini.start){
			ans.push_back(in[l]);
			ti = ini;
		}else{
			ti.start = min(in[l].start,ini.start);
			ti.end = max(in[l].end,ini.end);
		}
		l++;
		while(l<sz && ti.end>=in[l].start){
			ti.end=max(ti.end,in[l].end);
			l++;
		}
		ans.push_back(ti);
		while(l<sz)ans.push_back(in[l++]);
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<Interval> intervals,ans;
	int n,s,e;
	while(cin>>n){
		FOR(i,n){
			cin>>s>>e;
			intervals.push_back(Interval(s,e));
		}
		cin>>s>>e;
		Interval ini(s,e);
		ans = sol.insert(intervals,ini);
		FOR(i,ans.size())cout<<ans[i].start<<" "<<ans[i].end<<endl;
		intervals.clear();
	}
	return 0;
}


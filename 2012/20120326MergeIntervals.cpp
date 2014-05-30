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
struct cmp{
	bool operator() (Interval a,Interval b){
		return a.start<b.start;
	}
}cmp;
public:
	vector<Interval> merge(vector<Interval> &in) {
		vector<Interval> ans;
		int sz=in.size();
		if(!sz)return ans;
		int i,j;
		sort(in.begin(),in.end(),cmp);
		for(i=0;i<sz;i++){
			if(i+1==sz){
				ans.push_back(in[i]);
				break;
			}
			if(in[i].end<in[i+1].start)ans.push_back(in[i]);
			else {
				Interval ti=in[i];
				i++;
				while(i<sz && in[i].start<=ti.end){
					ti.end=max(in[i].end,ti.end);
					i++;
				}
				ans.push_back(ti);
				i--;
			}
		}
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
		ans = sol.merge(intervals);
		FOR(i,ans.size())cout<<ans[i].start<<" "<<ans[i].end<<endl;
		intervals.clear();
	}
	return 0;
}


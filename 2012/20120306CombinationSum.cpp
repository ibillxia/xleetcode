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
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > ans;
		if(!candidates.size())return ans;
		sort(candidates.begin(),candidates.end());
		if(candidates[0]>target)return ans;
		vector<int> vct;
		stack<int> st;
		int i=0,t=0,sz=candidates.size();
		while(1){
			for(;i<sz;i++){
				st.push(i);
				t+=candidates[i];
				vct.push_back(candidates[i]);
				if(t<target){
					i--;
					continue;
				}else{ // t>=target
					if(t==target)ans.push_back(vct);
					if(vct[0]>=target)return ans; // candidates[sz-1]>=target
					if(vct[0]==candidates[sz-1])return ans; // candidates[sz-1]<target
					t-=candidates[i];
					vct.pop_back();
					st.pop();
					if(st.size()){
						i=st.top();
						st.pop();
						t-=candidates[i];
						vct.pop_back();
						continue;
					}else return ans;
				}
			}
			if(i==sz&&st.size()){
				i=st.top();
				st.pop();
				t-=candidates[i];
				vct.pop_back();
				i++;
			}else break;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	int a[] = {1,2};
	vector<int> vc(a,a+2);
	vector<vector<int> > ans = sol.combinationSum(vc,9);
	FOR(i,ans.size()){
		FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}


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
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int> > ans;
		if(!num.size())return ans;
		sort(num.begin(),num.end());
		if(num[0]>target)return ans;
		vector<int> vct;
		stack<int> st;
		int i=0,t=0,sz=num.size();
		while(1){
			for(;i<sz;i++){
				st.push(i);
				t+=num[i];
				vct.push_back(num[i]);
				if(t<target){
					continue;
				}else{ // t>=target
					if(t==target)ans.push_back(vct);
					if(vct[0]>=target)goto LABEL; // num[sz-1]>=target
					if(vct[0]==num[sz-1])goto LABEL; // num[sz-1]<target
					t-=num[i];
					vct.pop_back();
					st.pop();
					if(st.size()){
						i=st.top();
						st.pop();
						t-=num[i];
						vct.pop_back();
						continue;
					}else goto LABEL;
				}
			}
			if(i==sz&&st.size()){
				i=st.top();
				st.pop();
				t-=num[i];
				vct.pop_back();
				i++;
			}else break;
		}
LABEL:
		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		return ans;
	}
};

int main()
{
	Solution sol;
	int a[] = {10,1,2,7,6,1,5};
	vector<int> vc(a,a+7);
	vector<vector<int> > ans = sol.combinationSum2(vc,8);
	FOR(i,ans.size()){
		FOR(j,ans[i].size())cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}


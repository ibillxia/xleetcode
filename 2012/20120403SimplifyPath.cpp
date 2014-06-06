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
	string simplifyPath(string path) {
		string ans=path;
		if(path.size()<2)return ans;
		int i,j;
		for(i=0;i<ans.size()-1;i++){
			if(ans[i]=='/' && ans[i+1]=='/'){ // remove one '/' in continus two '/'
				ans.erase(i,1);
				i--;
			}
			if(i<ans.size()-2 && ans[i]=='/' && ans[i+1]=='.' && ans[i+2]=='/'){ // remove './' in '/./'
				ans.erase(i,2);
				i--;
			}
		}
		//cout<<ans<<endl;
		for(i=0;i<ans.size();i++){ // in '../' case, cd to upper directory
			if(i<ans.size()-3 && ans[i]=='/' && ans[i+1]=='.' && ans[i+2]=='.' && ans[i+3]=='/'){
				if(!i){
					ans.erase(i+1,3);
					i--;
				} else {
					j=i-1;
					while(j&&ans[j]!='/')j--;
					ans.erase(j,i-j+3);
					i=j-1;
					//cout<<ans<<endl;
				}
			}
		}
		i=ans.size()-1;
		if(i>1&&ans[i-2]=='/'&&ans[i-1]=='.'&&ans[i]=='.'){
			j=i-3;
			if(j<1){
				ans.erase(i-1,2);
				return ans;
			} else {
				while(j&&ans[j]!='/')j--;
				ans.erase(j+1,i-j);
			}
		}
		if(i>0&&ans[i-1]=='/'&&ans[i]=='.')ans.erase(i,1);
		i=ans.size()-1;
		if(i&&ans[i]=='/')ans.erase(i,1);
		return ans;
	}
};

int main()
{
	Solution sol;
	string path;
	while(cin>>path){
		cout<<sol.simplifyPath(path)<<endl;
	}
	return 0;
}

/* test cases:
/.		// output: '/'
/..		// output: '/'
/home/of/foo/../../bar/../../is/./here/.		// output: '/is/here'
///eHx/..		// output: '/'
*/

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
	int evalRPN(vector<string> &tk) {
		if(tk.empty())return 0;
		int i,x,y,sz=tk.size();
		stack<int> st;
		vector<int> vc(128,0);
		vc['+']=1,vc['-']=2,vc['*']=3,vc['/']=4;
		for(i=0;i<sz;i++){
			if(tk[i].size()==1 && vc[tk[i][0]]){ // operator
				x=st.top();st.pop();
				y=st.top();st.pop();
				switch(tk[i][0]){
					case '+':
						st.push(y+x);
						break;
					case '-':
						st.push(y-x);
						break;
					case '*':
						st.push(y*x);
						break;
					case '/':
						st.push(y/x);
						break;
				}
			}else{ // number
				x=atoi(tk[i].c_str());
				st.push(x);
			}
		}
		return st.top();
	}
};

int main()
{
	Solution sol;
	int n;
	while(cin>>n){
		vector<string> tokens(n);
		FOR(i,n)cin>>tokens[i];
		cout<<sol.evalRPN(tokens)<<endl;
	}
	return 0;
}


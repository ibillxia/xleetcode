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
	void solve(vector<vector<char> > &board) {
		if(board.empty())return;
		int i,j,m,n;
		m=board.size();
		n=board[0].size();
		if(m<3 || n<3)return;
		for(i=0;i<m;i++){
			if(board[i][0]=='O')floodFill(board,i,0);
			if(board[i][n-1]=='O')floodFill(board,i,n-1);
		}
		for(i=1;i<n-1;i++){
			if(board[0][i]=='O')floodFill(board,0,i);
			if(board[m-1][i]=='O')floodFill(board,m-1,i);
		}
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				if(board[i][j]=='T')board[i][j]='O';
				else board[i][j]='X';
		}
		return;
	}
private:
	void floodFill(vector<vector<char> > &bd,int i,int j){ // DFS
		int m,n,t,x,y;
		m=bd.size();n=bd[0].size();
		stack<int> st;
		st.push(i*n+j);
		while(!st.empty()){
			t=st.top();
			st.pop();
			x=t/n;y=t%n;
			bd[x][y]='T'; // true
			if(x>0&&bd[x-1][y]=='O')st.push(x*n-n+y); // up
			if(x<m-1&&bd[x+1][y]=='O')st.push(x*n+n+y); // down
			if(y>0&&bd[x][y-1]=='O')st.push(x*n+y-1); // left
			if(y<n-1&&bd[x][y+1]=='O')st.push(x*n+y+1); // right
		}
	}
};

int main()
{
	Solution sol;
	int m,n;
	vector<vector<char> > board;
	while(cin>>m>>n){
		FOR(i,m){ // input
			vector<char> line(n);
			FOR(j,n)cin>>line[j];
			board.push_back(line);
		}
		sol.solve(board);
		cout<<"results:"<<endl;
		FOR(i,m){ // output
			FOR(j,n)cout<<board[i][j];
			cout<<endl;
		}
		board.clear();
	}
	return 0;
}


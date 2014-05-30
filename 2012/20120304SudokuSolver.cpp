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
	void solveSudoku(vector<vector<char> > &board) {
		fill(board,0);
		return;
	}

	bool fill(vector<vector<char> > &board, int k){
		if(k==81)return true;
		int i,j,ii,x,y;
		i=k/9,j=k%9;
		vector<bool> used(9,false);
		vector<char> vc;
		for(;i<9;i++){
			for(;j<9;j++){
				if(board[i][j]=='.'){
					for(ii=0;ii<9;ii++){ // row
						if(board[i][ii]!='.')used[board[i][ii]-'1']=true;
					}
					for(ii=0;ii<9;ii++){ // col
						if(board[ii][j]!='.')used[board[ii][j]-'1']=true;
					}
					for(ii=0;ii<9;ii++){ // 3x3 cell
						x=(i-i%3)+ii/3,y=(j-j%3)+ii%3;
						if(board[x][y]!='.')used[board[x][y]-'1']=true;
					}
					for(ii=0;ii<9;ii++){
						if(!used[ii])vc.push_back(char(ii+'1'));
					}
					if(vc.size()==0){
						return 0;
					}else{
						for(ii=0;ii<vc.size();ii++){
							board[i][j]=vc[ii];
							if(fill(board,k+1))return true;
							board[i][j]='.';
						}
						return false;
					}
				}
				k++;
			}
			j=0;
		}
		return true;
	}
};

int main()
{
	Solution sol;
	vector<vector<char> > board(9);
	int i,j;
	char ch;
	while(1){
		cout<<"input(input 0 to exit):"<<endl;
		for(i=0;i<9;i++){
			board[i].clear();
			for(j=0;j<9;j++){
				cin>>ch;
				if(ch=='0')return 0;
				board[i].push_back(ch);
			}
		}
		sol.solveSudoku(board);
		cout<<"solve:"<<endl;
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				cout<<board[i][j];
			cout<<endl;
		}
	}
	return 0;
}


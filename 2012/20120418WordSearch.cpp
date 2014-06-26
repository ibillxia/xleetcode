#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int i,j,rows,cols;
        rows = board.size();
        cols = board[0].size();
		if(rows*cols<word.size())return false;
        vector<vector<bool> > visited(rows,vector<bool>(cols,false));
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(dfs(board,word,0,i,j,visited))return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char> > &board, string &word, int n, int i, int j, vector<vector<bool> > &visited){
        if(n==word.size())return true;
        int rows,cols;
        rows = board.size();
        cols = board[0].size();
        if(word[n]==board[i][j]){
            visited[i][j]=true;
			if(n+1 == word.size())return true;
            if(i>0 && !visited[i-1][j] && dfs(board,word,n+1,i-1,j,visited))return true;
            if(i<rows-1 && !visited[i+1][j] && dfs(board,word,n+1,i+1,j,visited))return true;
            if(j>0 && !visited[i][j-1] && dfs(board,word,n+1,i,j-1,visited))return true;
            if(j<cols-1 && !visited[i][j+1] && dfs(board,word,n+1,i,j+1,visited))return true;
            visited[i][j]=false;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char> > board;
    string word;
    int m,n;
    while(cin>>m>>n){
        while(m--){
            vector<char> vc(n);
            FOR(i,n)cin>>vc[i];
            board.push_back(vc);
        }
        cin>>n;
        while(n--){
            cin>>word;
            cout<<sol.exist(board,word)<<endl;
        }
		board.clear();
    }
    return 0;
}
/* demo input:
3 4
ABCE
SFCS
ADEE
3
ABCCED
SEE
ABCB
30 30
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaab
1
baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/

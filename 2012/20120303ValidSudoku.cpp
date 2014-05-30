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
    bool isValidSudoku(vector<vector<char> > &board) {
        bool used[9];
        int i,j,k,t;
        for(i=0;i<9;i++){
            fill(used,used+9,false);
            for(j=0;j<9;j++){ // check row
                if(board[i][j]!='.'){
                    if(!used[board[i][j]-'1'])used[board[i][j]-'1']=true;
                    else return false;
                }
            }
            fill(used,used+9,false);
            for(j=0;j<9;j++){ // check col
                if(board[j][i]!='.'){
                    if(!used[board[j][i]-'1'])used[board[j][i]-'1']=true;
                    else return false;
                }
            }
        }
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                fill(used,used+9,false);
                for(k=i*3;k<i*3+3;k++){
                    for(t=j*3;t<j*3+3;t++){
                        if(board[k][t]!='.'){
                            if(!used[board[k][t]-'1'])used[board[k][t]-'1']=true;
                            else return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
	char a[9][10] = {{"..92..67."},{"41.6....."},{".7.35.9.2"},
        {"..5..6.89"},{"1..7.8..3"},{"96.1..4.."},
        {"5.7.42.1."},{".....3.58"},{".83..72.."}
	};
	vector<vector<char> > vc;
	vector<char> v1(a[0],a[0]+9),v2(a[1],a[1]+9),v3(a[2],a[2]+9),
	v4(a[3],a[3]+9),v5(a[4],a[4]+9),v6(a[5],a[5]+9),
	v7(a[6],a[6]+9),v8(a[7],a[7]+9),v9(a[8],a[8]+9);
	vc.push_back(v1),vc.push_back(v2),vc.push_back(v3),
	vc.push_back(v4),vc.push_back(v5),vc.push_back(v6),
	vc.push_back(v7),vc.push_back(v8),vc.push_back(v9);
    bool ans = sol.isValidSudoku(vc);
	cout<<ans<<endl;
    return 0;
}

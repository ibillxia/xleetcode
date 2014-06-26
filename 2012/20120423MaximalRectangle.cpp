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
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        int i,j,rows,cols;
        rows = matrix.size();
        cols = matrix[0].size();

        vector<int> vL(cols,0);
        vector<int> vH(cols,0);
        vector<int> vR(cols,cols);
        int left,right,ans=0;
        for(i=0;i<rows;i++){
            left=0,right=cols;
            for(j=0;j<cols;j++){ // collect vL[j], from left to right
                if(matrix[i][j]=='1'){
                    vL[j]=max(vL[j],left);
                    vH[j]++;
                }else{
                    left=j+1;
                    vL[j]=0,vH[j]=0,vR[j]=cols;
                }
            }
            for(j=cols-1;j>=0;j--){ // collect vR[j], from right to left
                if(matrix[i][j]=='1'){
                    vR[j]=min(vR[j],right);
                    ans = max(ans,vH[j]*(vR[j]-vL[j]));
                }else{
                    right=j;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int m,n;
    vector<vector<char> > matrix;
	while(cin>>m>>n){
        while(m--){
            vector<char> vc(n);
            FOR(i,n)cin>>vc[i];
            matrix.push_back(vc);
        }
        cout<<sol.maximalRectangle(matrix)<<endl;
        matrix.clear();
	}
    return 0;
}

/* demp input:
5 5
10110
10110
11011
11001
3 3
101
110
011
*/

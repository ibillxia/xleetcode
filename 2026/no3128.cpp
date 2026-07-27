#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long count = 0;
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count += (rowCount[i]-1)*(colCount[j]-1);
                }
            }
        }
        return count;
    }
};

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m,vector<int>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>grid[i][j];
        }
    }
    Solution sol;
    long long result = sol.numberOfRightTriangles(grid);
    cout<<result<<endl;
    return 0;
}
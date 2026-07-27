#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<cstdio>

using namespace std;

class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m,n;
        m = image.size();
        n = image[0].size();
        vector<vector<int>> area(m-2,vector<int>(n-2));
        vector<vector<int>> res(m,vector<int>(n));
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                if( abs(image[i][j]-image[i][j+1]) <= threshold 
                    && abs(image[i][j+1]-image[i][j+2]) <= threshold
                    && abs(image[i+1][j]-image[i+1][j+1]) <= threshold 
                    && abs(image[i+1][j+1]-image[i+1][j+2]) <= threshold
                    && abs(image[i+2][j]-image[i+2][j+1]) <= threshold 
                    && abs(image[i+2][j+1]-image[i+2][j+2]) <= threshold
                    && abs(image[i][j]-image[i+1][j]) <= threshold
                    && abs(image[i+1][j]-image[i+2][j]) <= threshold
                    && abs(image[i][j+1]-image[i+1][j+1]) <= threshold
                    && abs(image[i+1][j+1]-image[i+2][j+1]) <= threshold
                    && abs(image[i][j+2]-image[i+1][j+2]) <= threshold
                    && abs(image[i+1][j+2]-image[i+2][j+2]) <= threshold
                ) {
                    area[i][j] = floor((image[i][j]+image[i][j+1]+image[i][j+2]
                            +image[i+1][j]+image[i+1][j+1]+image[i+1][j+2]
                            +image[i+2][j]+image[i+2][j+1]+image[i+2][j+2]
                        )/9.0);
                } else {
                    area[i][j] = -1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j] = 0;
                int cnt=0,sum=0;
                if(i<m-2 && j<n-2 && area[i][j]>=0){
                    sum+=area[i][j];
                    cnt++;
                }
                if(i<m-2 && j-1<n-2 && j-1>=0 && area[i][j-1]>=0){
                    sum+=area[i][j-1];
                    cnt++;
                }
                if(i<m-2 && j-2<n-2 && j-2>=0 && area[i][j-2]>=0){
                    sum+=area[i][j-2];
                    cnt++;
                }
                if(i-1>=0 && i-1<m-2 && j<n-2 && area[i-1][j]>=0){
                    sum+=area[i-1][j];
                    cnt++;
                }
                if(i-1>=0 && i-1<m-2 && j-1>=0 && j-1<n-2 && area[i-1][j-1]>=0){
                    sum+=area[i-1][j-1];
                    cnt++;
                }
                if(i-1>=0 && i-1<m-2 && j-2>=0 && j-2<n-2 && area[i-1][j-2]>=0){
                    sum+=area[i-1][j-2];
                    cnt++;
                }
                if(i-2>=0 && i-2<m-2 && j<n-2 && area[i-2][j]>=0){
                    sum+=area[i-2][j];
                    cnt++;
                }
                if(i-2>=0 && i-2<m-2 && j-1>=0 && j-1<n-2 && area[i-2][j-1]>=0){
                    sum+=area[i-2][j-1];
                    cnt++;
                }
                if(i-2>=0 && i-2<m-2 && j-2>=0 && j-2<n-2 && area[i-2][j-2]>=0){
                    sum+=area[i-2][j-2];
                    cnt++;
                }
                if(cnt>0){
                    res[i][j]=floor(sum/cnt);
                }else{
                    res[i][j] = image[i][j];
                }
            }
        }
        return res;
    }
};

int main() {
    int m,n,thres;
    cin>>m>>n>>thres;
    vector<vector<int>> img(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>img[i][j];
        }
    }

    Solution sol;
    vector<vector<int>> res = sol.resultGrid(img,thres);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
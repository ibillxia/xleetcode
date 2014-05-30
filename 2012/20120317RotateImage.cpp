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
    void rotate(vector<vector<int> > &matrix) {
        int i,j,t,n,c,r;
		if(matrix.size()<2)return;
        n=matrix.size();
		if(n&0x1)c=n/2,r=n/2+1;
		else c=r=n/2;
        for(i=0;i<c;i++){
            for(j=0;j<r;j++){
				t=matrix[i][j];
				matrix[i][j]=matrix[n-j-1][i];
				matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
				matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
				matrix[j][n-i-1]=t;
            }
        }
    }
};

int main()
{
    Solution sol;
	char a[5][5] = {{1,2,3,4,5},{3,4,5,6,7},
        {5,6,7,8,9},{2,3,4,5,6},{4,5,6,7,8}	};
	vector<vector<int> > vc;
	vector<int> v1(a[0],a[0]+4),v2(a[1],a[1]+4),v3(a[2],a[2]+4),
	v4(a[3],a[3]+4);//,v5(a[4],a[4]+5);
	vc.push_back(v1),vc.push_back(v2),vc.push_back(v3),
	vc.push_back(v4);//,vc.push_back(v5);
	cout<<"before rotate:"<<endl;
	FOR(i,vc.size()){
		FOR(j,vc[i].size())
			cout<<vc[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
    sol.rotate(vc);
	cout<<"after rotate:"<<endl;
	FOR(i,vc.size()){
		FOR(j,vc[i].size())
			cout<<vc[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
    return 0;
}

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

// definition for a point
struct Point{
	int x,y;
	Point(): x(0),y(0) {}
	Point(int a,int b): x(a),y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &p) {
		int i,j,k,t,sz,ans;
		double xx,yy;
		sz=p.size();
		if(sz<3)return sz;

		// count repeated points
		vector<int> cnt;
		vector<Point> p2(p);
		for(i=0;i<p2.size();i++){
			cnt.push_back(1);
			for(j=i+1;j<p2.size();j++){
				if(p2[j].x==p2[i].x&&p2[j].y==p2[i].y){
					swap(*(p2.begin()+j),p2.back());
					p2.pop_back();
					cnt[i]++;
					j--;
				}
			}
		}
		if(p2.size()<3)return sz;
		ans=0;
		sz=p2.size();
		for(i=0;i<sz;i++){
			for(j=i+1;j<sz;j++){
				t=cnt[i]+cnt[j];
				for(k=0;k<sz;k++){
					if(i!=k && j!=k){
						xx=((double)p2[i].x-p2[k].x)*((double)p2[j].y-p2[k].y);
						yy=((double)p2[j].x-p2[k].x)*((double)p2[i].y-p2[k].y);
						if(fabs(xx-yy)<1e-8)t+=cnt[k];
					}
				}
				if(t>ans)ans=t;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	int n;
	while(cin>>n){
		vector<Point> pt(n);
		FOR(i,n)cin>>pt[i].x>>pt[i].y;
		cout<<sol.maxPoints(pt)<<endl;
	}
	return 0;
}

/* demo input:
9
84 250
0 0
1 0
0 -70
0 -70
1 -1
21 10
42 90
-42 -230
*/

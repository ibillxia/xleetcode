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
    bool isScramble(string s1, string s2) {
		const int sz=s1.size();
		const int sz2=s2.size();
		if(sz != sz2)return false;
        if(!sz)return true;

		int i,j,k,t;
		bool f[sz+1][sz][sz];
		memset(f,0,(sz+1)*sz*sz);
		for(i=0;i<sz;i++){
			for(j=0;j<sz;j++) f[1][i][j]= (s1[i]==s2[j]);
		}

		for(t=2;t<=sz;t++){
			for(i=0;i+t<=sz;i++){
				for(j=0;j+t<=sz;j++){
					for(k=1;k<t;k++){
						if( (f[k][i][j] && f[t-k][i+k][j+k]) ||
							(f[k][i][j+t-k] && f[t-k][i+k][j]) ){
							f[t][i][j]=true;
							break;
						}
					}
				}
			}
		}
		return f[sz][0][0];
    }
};

int main()
{
    Solution sol;
    string s1,s2;
	while(cin>>s1>>s2){
		cout<<sol.isScramble(s1,s2)<<endl;
	}
    return 0;
}

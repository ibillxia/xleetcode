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
    int lengthOfLongestSubstring(string s) {
        #define uci unsigned int)(unsigned char
        if(s.size()<2)return s.size();
        unsigned int i,j,t,ans=0;
        int d[256];
        memset(d,0,sizeof(d));
		t=0;
        for(i=0;i<s.size();i++){
            if(!d[(uci)s[i]])d[(uci)s[i]]=i+1,t++;
            else {
                t=i+1-d[(uci)s[i]];
                for(j=0;j<256;j++)
                    if(d[j]<d[(uci)s[i]])d[j]=0;
                d[(uci)s[i]]=i+1;
				//cout<<i<<":"<<s[i]<<endl;
            }
            if(t>ans)ans=t;
			//cout<<i<<"-:"<<t<<", "<<ans<<endl;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s="#define FOR(i,n) for(int i=0;i<n;i++)";
    int ans = sol.lengthOfLongestSubstring(s);
    cout<<ans<<endl;
	return 0;
}

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
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int sz = s.size();
        if(sz<4 || sz>12)return ans;

        int i1,i2,i3,i4,t[4];
        for(i1=1;i1<4;i1++){
            for(i2=1;i2<4;i2++){
                if(i1+i2>sz-2)break;
                for(i3=1;i3<4;i3++){
                    if(i1+i2+i3>=sz)break;
                    i4=sz-i1-i2-i3;
                    if(i4<1)break;
                    if(i4>3)continue;
                    t[0]=str2num(s.substr(0,i1));
					if(s[0]=='0'&&i1>1)continue;
                    t[1]=str2num(s.substr(i1,i2));
					if(s[i1]=='0'&&i2>1)continue;
                    t[2]=str2num(s.substr(i1+i2,i3));
					if(s[i1+i2]=='0'&&i3>1)continue;
                    t[3]=str2num(s.substr(i1+i2+i3,i4));
					if(s[i1+i2+i3]=='0'&&i4>1)continue;
                    if(t[0]<256&&t[1]<256&&t[2]<256&&t[3]<256){
                        string str(s);
                        str.insert(i1+i2+i3,".");
                        str.insert(i1+i2,".");
                        str.insert(i1,".");
                        ans.push_back(str);
                    }
                }
            }
        }
        return ans;
    }
private:
    int str2num(string str){
        int i,sz,n;
        sz=str.size();
        n=0;
        for(i=0;i<sz;i++) n = n*10+str[i]-'0';
        return n;
    }
};

int main()
{
    Solution sol;
    string s;
    vector<string> ans;
	while(cin>>s){
		ans = sol.restoreIpAddresses(s);
		FOR(i,ans.size())cout<<ans[i]<<endl;
		ans.clear();
	}
    return 0;
}
/* demo input:
25525511135
010010
101023
*/

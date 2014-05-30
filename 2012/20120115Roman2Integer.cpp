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
    int romanToInt(string s) {
        if(!s.size())return 0;
        int i,ans=0;
        for(i=0;i<s.size();i++){
            switch(s[i]){
                case 'I':
                    if(i+1<s.size()){
                        if(s[i+1]=='V')ans+=4,i++;
                        else if(s[i+1]=='X')ans+=9,i++;
                        else ans++;
                    }else ans++;
                    break;
                case 'V':
                    ans+=5;
                    break;
                case 'X':
                    if(i+1<s.size()){
                        if(s[i+1]=='L')ans+=40,i++;
                        else if(s[i+1]=='C')ans+=90,i++;
                        else ans+=10;
                    }else ans+=10;
                    break;
                case 'L':
                    ans+=50;
                    break;
                case 'C':
                    if(i+1<s.size()){
                        if(s[i+1]=='D')ans+=400,i++;
                        else if(s[i+1]=='M')ans+=900,i++;
                        else ans+=100;
                    }else ans+=100;
                    break;
                case 'D':
                    ans+=500;
                    break;
                case 'M':
                    ans+=1000;
                    break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int ans = sol.romanToInt("MMXIV");
    cout<<ans<<endl;
    return 0;
}

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();
        int cnt0=0,cnt1=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')cnt0++;
            else cnt1++;
            if(abs(cnt0-cnt1)<=1) ans++;
        }
        return ans;
    }
};

int main()
{
    string s;
    int ans;
    cin>>s;
    Solution sol;
    ans = sol.countValidPrefixes(s);
    cout<<ans<<endl;
    return 0;
}
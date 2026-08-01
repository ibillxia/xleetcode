#include<iostream>
#include<string>


using namespace std;

class Solution {
    public:
        string smallestPalindrome(string s) {
            int sz = s.size();
            if(sz==1) return s;
            int cnt[26] = {};
            string res(sz,'a');
            int t = 0;
            for(int i=0;i<sz;i++){
                t = int(s[i]-'a');
                cnt[t]++;
            }
            int i=0;
            for(int j=0;j<26;j++){
                for(int k=0;k<cnt[j]/2;k++){
                    res[i+k] = char('a'+j);
                    res[sz-1-i-k] = char('a'+j);
                }
                if(cnt[j]%2>0){
                    res[sz/2] = char('a'+j);
                }
                i=i+cnt[j]/2;
            }
            return res;
        }
};

int main()
{
    string s;
    cin>>s;
    Solution sol;
    string s2 = sol.smallestPalindrome(s);
    cout<<s2<<endl;
    return 0;
}

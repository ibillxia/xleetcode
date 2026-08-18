#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int cnt[26]={0};
        int ans=0,t=0,k;
        for(int i=0;i<n;i++){
            k=s[i]-'a';
            cnt[k]++;
            t++;
            if(cnt[k]>2){
                for(int j=i+1-t;j<i;j++){
                    cnt[s[j]-'a']--;
                    if(s[j]==s[i]){
                        t=i-j;
                        break;
                    }
                }
            }
            if(t>ans) ans = t;
        }
        return ans;
    }
};

int main()
{
    string s="bcbbbcba";
    Solution sol;
    int ans = sol.maximumLengthSubstring(s);
    cout<<ans<<endl;
    return 0;
}
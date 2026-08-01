#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int cnt[26]={0};
        int n = word.size(),ans=0;
        int i;
        for(i=0;i<n;i++){
            cnt[word[i]-'a']++;
        }
        sort(cnt,cnt+26);
        for(i=25;i>=0;i--){
            if(cnt[i]==0)break;
            if(i>17) ans += cnt[i];
            else if(i>9) ans += cnt[i]*2;
            else if(i>1) ans += cnt[i]*3;
            else ans += cnt[i]*4;
        }
        return ans;
    }
};

int main ()
{
    string word;
    cin>>word;
    Solution sol;
    int ans = sol.minimumPushes(word);
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        vector<int> validSequence(string word1, string word2) {
            int n1 = word1.size(),n2 = word2.size();
            vector<int> d(n1+1,0);
            int i,j;
            d[n1] = n2;
            for(i=n1-1,j=n2-1;i>=0 && j>=0;i--){
                if(word1[i]==word2[j]){
                    j--;
                }
                d[i]=j+1;
            }
    
            vector<int> ans(n2);
            bool flag=false;
            for(i=0,j=0;i<n1 && j<n2;i++){
                if(word1[i]==word2[j] || (!flag && d[i+1]<=j+1)){
                    if(word1[i]!=word2[j]) flag=true;
                    ans[j]=i;
                    j++;
                    if(j==n2) return ans;
                }
            }
            return {};
        }
    };

int main()
{
    return 0;
}
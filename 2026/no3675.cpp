#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int res=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='a' && int('z'-s[i])+1>res){
                res = int('z'-s[i])+1;
            }
        }
        return res;
    }
};

int main () {
    string s;
    cin>>s;
    Solution sol;
    int m = sol.minOperations(s);
    cout<<m<<endl;
    return 0;
}
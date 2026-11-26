#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
            int l=0,r=0,ans=0;
        map<char,int>m;
        while(r<s.size()){
            m[s[r]]++;
            while(m.size()>k){
              m[s[l]]--;
              if(m[s[l]]==0){
                m.erase(s[l]);
              }l++;
            }ans=max(ans,r-l+1);
            r++;
        } return ans;
    }
};
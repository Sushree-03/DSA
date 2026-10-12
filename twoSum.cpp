#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        } sort(v.begin(),v.end());
         int start=0,end=v.size()-1;
         while(start<end){
            int s=v[start].first+v[end].first;
            if(s==target)
            return {v[start].second,v[end].second};
            else if(s<target)
            start++;
            else 
            end--;
         } return {};
    }
};
int main() {
    Solution sol;
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> target;
    vector<int> ans = sol.twoSum(nums, target);
    if (!ans.empty()) {
        cout << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }
    return 0;
}
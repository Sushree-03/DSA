#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n=nums.size();
        int c=0,i=0;
        while(i<n-1){
            if(nums[i]==nums[i+1]) {
                c++;
                i++;
            }else{
                i++;
            }
        } return c;
    } 
};
int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.minDeletions(nums) << endl;

    return 0;
}
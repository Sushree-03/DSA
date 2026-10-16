#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0) st.push_back(asteroids[i]);
            else{
                while(!st.empty() && st.back()>0 && abs(asteroids[i])>st.back())
                st.pop_back();
                if(!st.empty() && st.back()>0 && abs(st.back()) == abs(asteroids[i])) 
                st.pop_back();
                else{
                    if(st.empty() ||st.back()<0)
                    st.push_back(asteroids[i]);
                }
            }
        } return st;
    }
};
int main() {
    Solution sol;

    vector<int> asteroids = {5, 10, -5};

    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Remaining asteroids: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
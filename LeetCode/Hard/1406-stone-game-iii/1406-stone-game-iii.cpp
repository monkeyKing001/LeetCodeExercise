#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int stoneGame(vector <int>& stoneValue, int i, vector<int> &dp)
    {
        int n = stoneValue.size();
        if (i >= n)
            return (0);
        int other_score = dp[i + 1];
        if (other_score == INT_MIN)
            other_score = stoneGame(stoneValue, i + 1, dp);
        int takeOne = stoneValue[i] - other_score;
        int takeTwo = INT_MIN;
        if (i + 1 < n)
        {
            int other_score = INT_MIN;
            if (i + 2 < n && dp[i + 2] != INT_MIN)
                other_score = dp[i + 2];
            else
                other_score = stoneGame(stoneValue, i + 2, dp);
            takeTwo = stoneValue[i] + stoneValue[i + 1] - other_score;
        }
        int takeThr = INT_MIN;
        if (i + 2 < n)
        {
            int other_score = INT_MIN;
            if (i + 3 < n && dp[i + 3] != INT_MIN)
                other_score = dp[i + 3];
            else
                other_score = stoneGame(stoneValue, i + 3, dp);
            takeThr = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - other_score;
        }
        return (dp[i] = max(takeOne, max(takeTwo, takeThr)));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(50001, INT_MIN);
        int sol = stoneGame(stoneValue, 0, dp); 
        if (sol > 0)
            return ("Alice"); 
        else if (sol < 0)
            return ("Bob"); 
        else
            return ("Tie");
    }
};
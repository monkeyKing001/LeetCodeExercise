#define ll long long
class Solution {
public:
  long long minCost(int n, vector<vector<int>>& cost) {
    ll ans = 1e12 + 1;
    ll max_cost = ans;
    int nn = n / 2;
    vector<vector<vector<ll>>> best(nn, vector<vector<ll>> (3, vector<ll>(3, max_cost)));
    vector<vector<vector<ll>>> dp(nn, vector<vector<ll>> (3, vector<ll>(3, max_cost)));
    for (int i = 0 ; i < nn; i++){
      int ri = n - 1 - i;
      for (int ci = 0; ci < 3; ci++){
        int cur_cost = cost[i][ci];
        for (int rci = 0; rci < 3; rci++){
          if (rci == ci)
            continue;
          best[i][ci][rci] = cur_cost + cost[ri][rci];
        }
      }
    }
    dp[0][0][0] = best[0][0][0], dp[0][0][1] = best[0][0][1], dp[0][0][2] = best[0][0][2];
    dp[0][1][0] = best[0][1][0], dp[0][1][1] = best[0][1][1], dp[0][1][2] = best[0][1][2];
    dp[0][2][0] = best[0][2][0], dp[0][2][1] = best[0][2][1], dp[0][2][2] = best[0][2][2];
    for (int i = 1; i < nn; i++){
      for (int ci = 0; ci < 3; ci++){
        for (int rci = 0; rci < 3; rci++){
          if (rci == ci) continue;
          int cur_cost = best[i][ci][rci];
          for (int pci = 0; pci < 3; pci++){
            if (pci == ci) continue;
            for (int prci = 0; prci < 3; prci++){
              if (prci == rci) continue; 
              dp[i][ci][rci] = min(dp[i][ci][rci], dp[i - 1][pci][prci] + cur_cost);
            }
          }
        }
      }
    }
    for (int ci = 0; ci < 3; ci++){
      for (int rci = 0; rci < 3; rci++){
        ans = min(ans, dp[nn - 1][ci][rci]);
      }
    }
    return (ans);
  }
};
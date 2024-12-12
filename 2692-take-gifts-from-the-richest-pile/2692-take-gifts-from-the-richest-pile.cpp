#define ll long long
class Solution {
public:
  long long pickGifts(vector<int>& gifts, int k) {
    ll ans = 0;
    priority_queue<int> pq(gifts.begin(), gifts.end());
    while (k-- > 0){
      int next_num = sqrt(pq.top());
      pq.pop();
      pq.push(next_num);
    }
    while (pq.size() != 0) ans+= pq.top(), pq.pop();
    return (ans);
  }
};
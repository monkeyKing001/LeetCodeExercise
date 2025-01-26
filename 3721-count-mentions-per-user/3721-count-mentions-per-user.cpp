#define M "MESSAGE"
#define O "OFFLINE"
#define A "ALL"
#define H "HERE"
class Solution {
public:
  int n;
  vector<int> online_time;
  vector<int> ans;
  vector<string> split(string str){
    vector<string> ret;
    string buf;
    stringstream ss(str);
    while (ss >> buf)
      ret.push_back(buf);
    return(ret);
  }

  int idstr_to_id(string idstr){
    //idstring lookslike id<number>
    string numstr = idstr.substr(2);
    return (stoi(numstr));
  }

  void handleMessage(int time, string target){
    if (target == A){
      for (int i = 0 ; i < n ; i++)
        ans[i]++;
    }
    else if (target == H){
      for (int i = 0 ; i < n ; i++)
        if (online_time[i] <= time) ans[i]++;
    }
    //parsing ids.
    else{
      vector<string> ids = split(target);
      for (auto idstr : ids){
        int id = idstr_to_id(idstr);
        ans[id]++;
      }
    }
  }

  void handleOffline(int time, string target){
    int id = stoi(target);
    online_time[id] = time + 60;
    return ;
  }

  static bool cmp(vector<string> ev1, vector<string> ev2){
    int time1 = stoi(ev1[1]);
    int time2 = stoi(ev2[1]);
    if (time1 == time2) return (ev1[0] > ev2[0]);//handle status first before msg
    return (time1 < time2);
  }

  vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    n = numberOfUsers;
    online_time.resize(n, 0);
    ans.resize(n, 0);
    sort(events.begin(), events.end(), cmp);
    for (auto e : events){
      string ev = e[0];
      int time = stoi(e[1]);
      string target = e[2];
      if (ev == M)
        handleMessage(time, target);
      else if (ev == O)
        handleOffline(time, target);
    }
    return (ans);
  }
};
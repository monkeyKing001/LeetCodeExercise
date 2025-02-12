class Solution {
public:
  string removeOccurrences(string s, string part) {
    vector<char> buf;
    for (auto c : s){
      buf.push_back(c);
      //check
      if (buf.back() == part.back()){
        bool pop = true;
        while (pop){
          for (int i = 0; i < part.size() && pop; i++){
            //unable check
            if ((int)buf.size() - 1 - i < 0) pop = false;
            if (pop && buf[buf.size() - 1 - i] != part[part.size() - 1 - i]) pop = false;
          }
          if (pop) for (int i = 0; i < part.size(); i++) buf.pop_back();
        }
      }
    }
    string ret = "";
    ret.reserve(buf.size());
    if (buf.size()) ret.assign(buf.begin(), buf.end());
    return (ret);
  }
};
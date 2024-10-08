class Solution {
public:
    string intToRoman(int num) {
      unordered_map<int, string> m;
      string sol = "";
      m = {
        {1, "I"},
        {2, "II"},
        {3, "III"},
        {4, "IV"},
        {5, "V"},
        {6, "VI"},
        {7, "VII"},
        {8, "VIII"},
        {9, "IX"},
        {10, "X"},
        {20, "XX"},
        {30, "XXX"},
        {40, "XL"},
        {50, "L"},
        {60, "LX"},
        {70, "LXX"},
        {80, "LXXX"},
        {90, "XC"},
        {100, "C"},
        {200, "CC"},
        {300, "CCC"},
        {400, "CD"},
        {500, "D"},
        {600, "DC"},
        {700, "DCC"},
        {800, "DCCC"},
        {900, "CM"},
        {1000, "M"},
        {2000, "MM"},
        {3000, "MMM"}
      };
      stack<string> s;
      int dec = 1;
      while (num != 0){
        int digit = num % 10;
        int curNum = digit * dec;
        string rom_num = m[curNum];
        s.push(rom_num);
        num /= 10;
        dec *= 10;
      }
      while (s.size() != 0){
        sol.append(s.top());
        s.pop();
      }
      return (sol);
    }
};
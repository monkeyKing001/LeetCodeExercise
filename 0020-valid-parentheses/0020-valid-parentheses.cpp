class Solution {
public:
    bool isValid(string s) {
       stack<char> stc; 
       for (int i = 0; i < s.size(); i++){
        char chr = s[i];
        if (chr == '(' || chr == '{' || chr == '[')
          stc.push(chr);
        else if (chr == ')'){
          if (stc.size() != 0 && stc.top() == '(')
            stc.pop();
          else
            return false;
        }
        else if (chr == '}'){
          if (stc.size() != 0 && stc.top() == '{')
            stc.pop();
          else
            return false;
        }
        else if (chr == ']'){
          if (stc.size() != 0 && stc.top() == '[')
            stc.pop();
          else
            return false;
        }
       }
       if (stc.size() != 0)
        return false;
       return (true);
    }
};
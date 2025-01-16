class Solution {
public:
    int minimizeXor(unsigned num1, unsigned num2) {
      int num2_count = popcount(num2);
      bitset<31> num1_bit(num1), ans;
      for (int i = 30; i >= 0 && num2_count > 0; i--){
        //cout << i << " : "<< num1_bit[i] << "\n";
        if (num1_bit[i])
          num2_count -= ans[i] = 1;
      }
      //exhaust rest 1 bit
      for (int i = 0; i < 31 & num2_count > 0; i++){
        if(!ans[i])
          num2_count -= ans[i] = 1;
      }
      return (ans.to_ulong());
    }
};
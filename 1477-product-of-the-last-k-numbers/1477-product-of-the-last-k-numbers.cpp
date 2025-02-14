class ProductOfNumbers {
private:
  vector<int> prefix_x;
public:
    ProductOfNumbers() {
      prefix_x.resize(1, 1);
    }
    
    void add(int num) {
      if (num) prefix_x.push_back(prefix_x.back() * num);
      else prefix_x.resize(1, 1);
    }
    
    int getProduct(int k) {
      if (k >= prefix_x.size() || prefix_x.size() == 1) return (0);
      else return (prefix_x.back() / prefix_x[prefix_x.size() - k - 1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
class ProductOfNumbers {
public:
    vector<int> prefix_product;
    set<int> zero_idx;

    ProductOfNumbers() {
      prefix_product.resize(0, 0);
    }
    
    void add(int num) {
      prefix_product.push_back(num);
      if (num){
        if (prefix_product.size() >= 2 && \
            prefix_product[prefix_product.size() - 2]){
            prefix_product[prefix_product.size() - 1] *= prefix_product[prefix_product.size() - 2];
        }
      }
      else zero_idx.insert(prefix_product.size() - 1);
    }
    
    int getProduct(int k) {
      //for (int i = 0; i < prefix_product.size(); i++){
      //  cout << prefix_product[i] << " ";
      //}
      //cout << "\n";
      int last_idx = prefix_product.size() - 1;
      int exclude_idx = last_idx - k;
      auto zero_it = zero_idx.upper_bound(exclude_idx);
      if (zero_it == zero_idx.end() || *zero_it > last_idx){
        if (exclude_idx == -1 || !prefix_product[exclude_idx]) 
          return (prefix_product[last_idx]);
        else
          return (prefix_product[last_idx] / prefix_product[exclude_idx]);
      }
      else{
        //cout
        //  << "exclude idx, zero_idx  : "
        //  << exclude_idx
        //  << ", "
        //  << *zero_it << "\n";
        return (0);
      }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
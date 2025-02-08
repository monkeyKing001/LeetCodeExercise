class NumberContainers {
public:
    unordered_map<int, int> idx_info;
    unordered_map<int, set<int>> value_info;
    
    NumberContainers() {
        idx_info.clear();
        value_info.clear();
    }
    
    void change(int index, int number) {
        //remove prev_infomation.
        if (idx_info.contains(index)) value_info[idx_info[index]].erase(index);  
        idx_info[index] = number;
        value_info[number].insert(index);
    }
    
    int find(int number) {
        int ret = -1;
        if (value_info.contains(number) && value_info[number].size()) ret = *(value_info[number].begin());
        return (ret);
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
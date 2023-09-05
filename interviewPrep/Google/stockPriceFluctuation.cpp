// https://leetcode.com/problems/stock-price-fluctuation/description/
class StockPrice {
public:
    map <int,int> orignal;
    map <int,int> val;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(orignal.find(timestamp)!=orignal.end()){
            int temp = orignal[timestamp];
            val[temp]--;
            if(val[temp]<=0)
                val.erase(temp);
        }
        orignal[timestamp] = price;
        val[price]++;
        
    }
    
    int current() {
        return orignal.rbegin()->second;
    }
    
    int maximum() {
        return val.rbegin()->first;
    }
    
    int minimum() {
        return val.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
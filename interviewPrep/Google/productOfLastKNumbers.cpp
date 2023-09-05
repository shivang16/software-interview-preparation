// https://leetcode.com/problems/product-of-the-last-k-numbers/description/
class ProductOfNumbers {
public:
    vector <int> products; 
    ProductOfNumbers() {
        products.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            products.clear();
            products.push_back(1);
        }
        else
            products.push_back(products.back()*num);
    }
    
    int getProduct(int k) {
        int crntInd = products.size()-1;
        int reqInd = crntInd-k;
        if(reqInd<0) return 0;
        return products[crntInd]/products[reqInd];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
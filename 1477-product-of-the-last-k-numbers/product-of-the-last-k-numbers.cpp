class ProductOfNumbers {
public:
    vector<int>prod;
    ProductOfNumbers() {
        prod.push_back(1);
    }
    
    void add(int num) {
        if(num!=0){
            prod.push_back(num*prod[prod.size()-1]);
        }
        else{
            prod.clear();
            prod.push_back(1);
        }
    }
    
    int getProduct(int k) {
        int i=prod.size();
        if(i-k-1<0)return 0;
        else{
            return prod[i-1]/prod[i-k-1];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
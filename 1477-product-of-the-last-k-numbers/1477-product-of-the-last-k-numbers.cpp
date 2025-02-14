class ProductOfNumbers {
private:
    vector<int> prefixProduct; 
public:
    ProductOfNumbers() {
        prefixProduct.clear();
        prefixProduct.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1);
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = prefixProduct.size();
        if (k >= size) return 0;
        return prefixProduct[size - 1] / prefixProduct[size - k - 1];
    }
};

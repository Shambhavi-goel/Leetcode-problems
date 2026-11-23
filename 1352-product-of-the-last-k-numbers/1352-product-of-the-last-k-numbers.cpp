
class ProductOfNumbers {
public:
    vector<int> pref;

    ProductOfNumbers() {
        
    }

    void add(int num) {
        if(num == 0) {
            pref.clear();
        }
        else {
            int product = num;

            if(!pref.empty()) {
                product *= pref.back();
            }

            pref.push_back(product);
        }
    }

    int getProduct(int k) {
        if(k > pref.size()) {
            return 0;
        }

        if(k == pref.size()) {
            return pref.back();
        }

        return pref.back() / pref[pref.size() - k - 1];
    }
};

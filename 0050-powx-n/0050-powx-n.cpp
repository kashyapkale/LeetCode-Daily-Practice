class Solution {
private:
    double myPowUtil(double x, int n){
        if(n == 1){
            return x;
        } else if(n == 0) {
            return 1;
        }

        if(n % 2 == 0){
            double current_x = myPowUtil(x, n/2);
            return current_x * current_x;
        }

        double current_x = myPowUtil(x, (n-1)/2);
        return current_x * current_x * x;
    }
public:
    double myPow(double x, int n) {
        if(x == 1){
            return 1;
        }
        if(n < 0 && n > INT_MIN){
            x = 1/x;
            n = n * -1;
        } else if(n == INT_MIN){
            return myPowUtil(1/x, (n + 1)*-1) * (1/x);
        }

        return myPowUtil(x, n);
    }
};
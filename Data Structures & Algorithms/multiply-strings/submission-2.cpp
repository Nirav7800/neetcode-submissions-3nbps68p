class Solution {
public:
    string sumString(string &ans, string& curr) {
        if(ans == "") return curr;

        int n1 = ans.size();
        int n2 = curr.size();
        string sum = "";
        int carry = 0;

        while(n1 > 0 || n2 > 0) {
            int d = carry;

            if(n1 > 0) d += (ans[--n1] - '0');
            if(n2 > 0) d += (curr[--n2] - '0');

            sum.push_back((d % 10) + '0');
            carry = d / 10;
        }

        if(carry) sum.push_back(carry + '0');

        reverse(sum.begin(), sum.end());
        return sum;
    }

    string multiply(string num1, string num2) {
        if(num1.size() < num2.size()) {
            swap(num1, num2);
        }

        if(num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        string ans = "";

        for(int i = m - 1; i >= 0; i--) {
            string curr = "";
            int carry = 0;

            for(int j = n - 1; j >= 0; j--) {
                int mul = (num2[i] - '0') * (num1[j] - '0');
                int digit = (mul + carry) % 10;
                carry = (mul + carry) / 10;

                curr.push_back(digit + '0');
            }

            if(carry) curr.push_back(carry + '0');

            reverse(curr.begin(), curr.end());

            int zerocount = m - 1 - i;
            while(zerocount--) {
                curr.push_back('0');
            }

            ans = sumString(ans, curr);
        }

        return ans;
    }
};
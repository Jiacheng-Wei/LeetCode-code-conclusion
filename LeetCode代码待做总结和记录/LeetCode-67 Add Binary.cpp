//简单方法，方法是不存在这个数就当'0'来处理，然后直接加到头 
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;//这里要注意要判断 
    }
};
//常规方法，先把两个字符串补成一样长，然后在计算
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int na = a.size();
        int nb = b.size();
        int n = max(na, nb);
        bool carry = false;
        if (na > nb) {
            for (int i = 0; i < na - nb; ++i) b.insert(b.begin(), '0');
        }
        else if (na < nb) {
            for (int i = 0; i < nb - na; ++i) a.insert(a.begin(), '0');
        }
        for (int i = n - 1; i >= 0; --i) {
            int tmp = 0;
            if (carry) tmp = (a[i] - '0') + (b[i] - '0') + 1;
            else tmp = (a[i] - '0') + (b[i] - '0');
            if (tmp == 0) {
                res.insert(res.begin(), '0');
                carry = false;
            }
            else if (tmp == 1) {
                res.insert(res.begin(), '1');
                carry = false;
            }
            else if (tmp == 2) {
                res.insert(res.begin(), '0');
                carry = true;
            }
            else if (tmp == 3) {
                res.insert(res.begin(), '1');
                carry = true;
            }
        }
        if (carry) res.insert(res.begin(), '1');
        return res;
    }
}; 

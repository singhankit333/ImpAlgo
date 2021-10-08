/////multiply two strings

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int n1=num1.size(), n2=num2.size();
        vector<int> v(n1+n2-1, 0);
        for(int i=n1-1; i>=0; i--) {
            int temp1 = num1[i]-'0';
            for(int j=n2-1; j>=0; j--) {
                int temp2 = num2[j]-'0';
                v[i+j] += temp1*temp2;
            }
        }
        string ans;
        int carry=0;
        for(int i=n1+n2-2; i>=0; i--) {
            int temp = v[i] + carry;
            carry = temp/10;
            ans += '0' + (temp%10);
        }
        while(carry) {
            ans += '0' + (carry%10);
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         if(num1=="0" || num2=="0") return "0";
//         int n1=num1.size(), n2=num2.size();
//         string ans(n1+n2, '0');
//         reverse(num1.begin(), num1.end());
//         reverse(num2.begin(), num2.end());
//         for(int i=0; i<n1; i++){
//             int m = num1[i]-'0', carry=0, temp, j=0;
//             for(; j<n2; j++){
//                 temp = (num2[j]-'0')*m + carry + ans[i+j]-'0';
//                 carry = temp/10;
//                 ans[i+j] = '0' + (temp % 10);
//             }
//             while(carry){
//                 temp = ans[i+j] - '0' + carry;
//                 carry = temp / 10;
//                 ans[i+j] = '0' + (temp % 10);
//                 j++;
//             } 
//         }
//         while(ans.back()=='0') ans.pop_back();
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

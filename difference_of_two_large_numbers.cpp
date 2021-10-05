//// given two very large numbers in string format find their difference after handling bad test cases.

#include <bits/stdc++.h>
using namespace std;

void preprocessing(string &str1, string &str2) {
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    while(str1.size()>1 && str1.back()=='0') str1.pop_back();
    while(str2.size()>1 && str2.back()=='0') str2.pop_back();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
}

bool compareStr(string &str1, string &str2) {
    if(str1.size() < str2.size()) return 1;
    if(str1.size() > str2.size()) return 0;
    for(int i=0; i<str1.size(); i++) {
        if(str1[i] < str2[i]) return 1;
        if(str1[i] > str2[i]) return 0;
    }
    return 0;
}

string findDifference(string &str1, string &str2) {
    preprocessing(str1, str2);
    if(compareStr(str1, str2)) return findDifference(str2, str1);
    
    ///////////Now str1 is larger number
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    string ans;
    for(int i=0; i<str2.size(); i++) {
        int temp = str1[i]-str2[i]-carry;
        if(temp < 0) {
            temp += 10;
            carry = 1;
        }
        else carry = 0;
        ans.push_back('0'+temp);
    }
    for(int i=str2.size(); i<str1.size(); i++) {
        int temp = str1[i]-'0'-carry;
        if(temp < 0) {
            temp += 10;
            carry = 1;
        }
        else carry = 0;
        ans.push_back('0'+temp);
    }
    while(ans.size()>1 && ans.back()=='0') ans.pop_back();
    return ans;
}

int main() {
    string str1, str2;
    cin>> str1 >> str2;
    cout<< findDifference(str1, str2) <<endl;
    return 0;
}

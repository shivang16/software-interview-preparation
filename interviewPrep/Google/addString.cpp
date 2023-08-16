class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string add = "";
        int carry = 0;
        if(num2.size()>num1.size())
            swap(num2,num1);
        for(int i=0;i<num2.size();i++){
            int c1 = num2[i]-'0';
            int c2 = num1[i]-'0';
            int sum = c1+c2+carry;
            int temp = sum%10;
            add += to_string(temp);
            carry = sum/10;
        }

        for(int i=num2.size();i<num1.size();i++){
            int c1 = num1[i]-'0';
            int sum = c1+carry;
            int temp = sum%10;
            add += to_string(temp);
            carry = sum/10;
        }
        if(carry)
            add += to_string(carry);
        reverse(add.begin(),add.end());
        return add;

    }
};
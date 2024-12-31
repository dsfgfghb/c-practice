#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

struct BigNum{      // 大整数类型
    int digit[1000];
    int len;
    BigNum(){
        len = 0;
        memset(digit, 0, sizeof(digit));
    }
};

BigNum change(char str[]){      //将字符串的内容转化成BigNum类型
    BigNum num;
    num.len = strlen(str);
    for(int i = 0; i < num.len; i++){
        num.digit[i] = str[num.len - 1 - i] - '0';      //要逆着赋值
    }
    return num;
}

int compare(BigNum a, BigNum b){        //比较两个大整数的大小
    if(a.len > b.len) return 1;     //a大
    else if(a.len < b.len) return -1;    //a小
    else{
        for(int i = a.len - 1; i >= 0; i--){
            if(a.digit[i] > b.digit[i]) return 1;       //只要有一位大,则a大
            else if(a.digit[i] < b.digit[i]) return -1;     //只要有一位小,则a小
        }
        return 0;           //相等
    }
}

BigNum add(BigNum a, BigNum b){         //高精度加法
    BigNum c;
    int carry = 0;          //进位
    for(int i = 0; i < a.len || i < b.len; i++){
        int temp = a.digit[i] + b.digit[i] + carry;     //加上进位
        c.digit[c.len++] = temp % 10;
        carry = temp /10;
    }
    if(carry){              //有进位
        c.digit[c.len++] = carry;       
    }
    return c;
}

BigNum sub(BigNum a, BigNum b){         //高精度减法        适合a > b
    BigNum c;
    for(int i = 0; i < a.len || i < b.len; i++){
        if(a.digit[i] < b.digit[i]){
            a.digit[i] += 10;           //借位  
            a.digit[i + 1]--;           //被借位减一
        }
        c.digit[c.len++] = a.digit[i] - b.digit[i];     //相减
        
        
    }
    while(c.len > 1 && c.digit[c.len - 1] == 0){        //去掉末尾的0
        c.len--;
    }
    return c;
}

BigNum mul(BigNum a, int b){            //高精度乘法
    BigNum c;
    int carry = 0;
    for(int i = 0; i < a.len; i++){
        int temp = a.digit[i] * b + carry;
        c.digit[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry){
        c.digit[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

BigNum div(BigNum a, int b, int &r /*余数*/){            //高精度除法
    BigNum c;
    c.len = a.len;
    r=0;
    for(int i = a.len - 1; i >= 0; i--){
        r = r * 10 + a.digit[i];
        if(r < a.digit[i]) c.digit[i] = 0;
        if(r >= b){
            c.digit[i] = r / b;
            r %= b;
        }
    }
    while(c.len > 1 && c.digit[c.len - 1] == 0){
        c.len--;
    }
    return c;
}



void print(BigNum a){
    for(int i = a.len - 1; i >= 0; i--){
        printf("%d", a.digit[i]);
    }
}

int main(){
    BigNum a, b;
    char str1[1000], str2[1000];
    int r;
    while(scanf("%s%s", str1, str2) != EOF){
        a = change(str1);
        b = change(str2);
        cout<<a.len << " " << b.len << endl;
        if(compare(a, b) == 1){
            cout << "a > b" << endl;
        }
        else if(compare(a, b) == -1){
            cout << "a < b" << endl;
        }
        else{
            cout << "a = b" << endl;
        }
        cout << "a + b = ";
        BigNum d = div(a,2000,r);
        print(d);
        cout<<"\n" << r << endl;
    }
    return 0;
}
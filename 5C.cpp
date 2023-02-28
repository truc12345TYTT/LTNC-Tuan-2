#include <iostream>

using namespace std;

string read[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","night"};
string ten[10] = {"ten", "eleven", "thirteen", "fourteen", "fifteen", "fiveteen", "sixteen", "seventeen", "eighteen", "nighteen"};
string under100[10] = {"" ,"ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "nighty"};
string temp[3] = {"hundred", "million", "hundred"} ;

string readNumber(int n){
    string readNum = "";
    int N = abs(n);
    if (N < 10){
        if (n < 0) readNum = "negative " + read[-n];
        else readNum = read[n];
        return readNum;
    }
    if (N < 100){
        int chuc = N/10;
        int donvi = N%10;
        if (N < 20) readNum = ten[donvi];
        if (N >= 20){

            if (donvi) readNum = under100[chuc] + "-" + read[donvi];
            else readNum = under100[chuc];
        }
        if (n < 0) readNum = "negative " + readNum;
        return readNum;
    }
    int scs[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(N){
        for(int i = 1; i <= 9; i ++){
            scs[i] = N%10;
            N /= 10;
        }
    }
    int tmp = abs(n);
    int i = 9;
    while(scs[i] == 0) i --;
    if (i == 4) readNum += read[scs[i]];
    for (; i >= 0; i --){
            if (i%3 == 0 && scs[i]) readNum += read[scs[i]] + " " + "hundred " ;
            if ( i%3 == 2 && scs[i] != 0){
                readNum += readNumber(scs[i]*10 + scs[i - 1]) + " ";
                i --;
           }
           if (i > 6) readNum += "million ";
           if (i <= 5 && n >= 4 && scs[i + 1] != 0) readNum += "thousand ";
    }
    if (n < 0) readNum = "negative " + readNum;
    return readNum;
}

int main(){
    int n;
    cin >> n;
    cout << readNumber(n);
    return 0;
}

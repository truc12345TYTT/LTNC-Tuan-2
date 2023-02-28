#include<iostream>

using namespace std;

int sqrt(int n){
    for (int i = 0; i < n; i ++){
        if (i*i > n) return i - 1;
    }
    return 0;
}
bool checkPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i ++){
        if (n%i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    if (checkPrime(n)) cout << "yes\n";
    else cout << "no\n";
    return 0;
}


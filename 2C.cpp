#include <iostream>

using namespace std;

void drawTriangle(int n){
    for (int i = n; i > 0; i --){
        for (int j = n; j > 0; j --)
            if (i >= j) cout << "*";
            else cout << " ";
        cout << endl;
    }
}
int main(){
    int n;
    cin >> n;
    drawTriangle(n);
    return 0;
}


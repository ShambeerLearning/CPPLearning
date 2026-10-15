#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int a[10000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int Chis = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[Chis]) {
            Chis++;
            a[Chis] = a[i];
        }
    }
    
    cout << Chis + 1 << endl;
    
    return 0;
}
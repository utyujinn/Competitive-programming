#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    long n, s;
    cin >> n >> s;
    vector<long> a(n), b(n);
    
    cin >> a[0];
    b[0] = a[0];
    
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    
    s %= b[n - 1];

    unordered_set<long> seen; 
    seen.insert(0); 

    for (int i = 0; i < n; i++) {
        
        if (seen.count(b[i] - s)) {
            cout << "Yes" << endl;
            return 0;
        }
        seen.insert(b[i]); 
    }
    
    cout << "No" << endl;
    return 0;
}

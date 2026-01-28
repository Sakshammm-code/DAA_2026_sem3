#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll n, h, w;
    cout << "Enter n, h, and w: ";
    if (!(cin >> n >> h >> w)) return;


    ll side = max(h, w);

    while (true) {
        ll horizontal = side / w;
        ll vertical = side / h;
        if (horizontal >= n || vertical >= n || (horizontal * vertical >= n)) {
            cout << side << endl;
            break;
        }
        
        side++;
    }
}

int main() {
    
    solve();
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vlli;
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
	IOS
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll ans = 0;
		for (int i = n - 3; i >= 1; i--) {

			ans ^= i;
			cout << i << " ";
		}
		ans ^= 536870912;
		ans ^= 1073741824;
		cout << ans << " " << 1073741824 << " " << 536870912 << " " << endl;
		
	}
	return 0;
}

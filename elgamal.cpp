#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int mod_pow(int base, int exp, int mod) {
int result = 1;
base %= mod;
while (exp > 0) {
if (exp & 1) result = (result * base) % mod;
base = (base * base) % mod;
exp >>= 1;
}
return result;
}
bool is_prime(int n) {
if (n <= 1) return false;
if (n <= 3) return true;
if (n % 2 == 0 || n % 3 == 0) return false;
for (int i = 5; i * i <= n; i += 6) {
if (n % i == 0 || n % (i + 2) == 0) return false;
}
return true;
}
int find_primitive_root(int p) {
int phi = p - 1;
int factors[phi], count = 0;
int n = phi;
for (int i = 2; i * i <= n; i++) {
if (n % i == 0) {
factors[count++] = i;
while (n % i == 0) {
n /= i;
}
}
}
if (n > 1) {
factors[count++] = n;
}
for (int res = 2; res <= p; res++) {
bool ok = true;
for (int i = 0; i < count && ok; i++) {
ok &= mod_pow(res, phi / factors[i], p) != 1;
}
if (ok) {
return res;
}
}
return -1;
}
int main() {
srand(time(NULL));
int p, e1, x, k;
cout << "Enter prime p: ";
cin >> p;
while (!is_prime(p)) {
cout << "p is not prime, please enter a prime number: ";
cin >> p;
}
e1 = find_primitive_root(p);
cout << "Primitive root= " << e1 << endl;
cout << "Enter d= ";
cin >> x;
while (x < 1 || x > p - 2) {
cout << "Invalid x, please enter a value between 1 and p-2: ";
cin >> x;
}
int y = mod_pow(e1, x, p);
cout << "Public key = " << y << endl;
cout << "Enter a message= ";
int m;
cin >> m;
while (m >= p) {
cout << "Invalid message, please enter a value less than p: ";
cin >> m;
}
cout<<"enter r=";
//k = rand() % (p - 2) + 1;
cin>>k;
int a = mod_pow(e1, k, p);
int b = (mod_pow(y, k, p) * m) % p;
cout << "Encrypted message: (" << a << ", " << b << ")" << endl;
int m_prime = (b * mod_pow(a, p - 1 - x, p)) % p;
cout << "Decrypted message: " << m_prime << endl;
return 0;
}
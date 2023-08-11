#include <iostream>
#include <cmath>
using namespace std;
int encrypt(int message, int e, int n) {
    int j=message;
    for(int i=1;i<e;i++){
        j*=message;
    }
    
    return static_cast<int>(j) % n;
}
int decrypt(int message, int d, int n) {
    return static_cast<int>(pow(message, d)) % n;
}
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
void generate_keys(int& e, int& d, int& n) { 
    int p, q;
    cout << "Enter a prime number p= ";
    cin >> p;
while (!is_prime(p)) {
cout << "Invalid ";
cin >> p;
}
cout << "Enter another prime number (q): ";
cin >> q;
while (!is_prime(q)) {
cout << "Invalid input! Please enter a prime number (q): ";
cin >> q;
}
n = p * q;
int phi_n = (p - 1) * (q - 1);
cout << "phi_n: " << phi_n << endl;
cout << "Enter a number for the public key (e): ";
cin >> e;
while (e < 2 || e >= phi_n || gcd(e, phi_n) != 1) {
cout << "Invalid input! Please enter a number for the public key (e): ";
cin >> e;
}
int k = 1;
while ((k * phi_n + 1) % e != 0) {
k++;
}
d = (k * phi_n + 1) / e;
}
int main() {
    int e, d, n;
    generate_keys(e, d, n);
    cout << "Public key =" << e << ", " << n << endl;
     cout << "Private key =" << d << ", " << n << endl;
     int message;
     cout << "message=";
     cin >> message;
     int encrypted_message = encrypt(message, e, n);
     cout << "Encrypted=" << encrypted_message << endl;
     int decrypted_message = decrypt(encrypted_message, d, n);
     cout << "Decrypted= " << decrypted_message << endl;
     return 0;
}
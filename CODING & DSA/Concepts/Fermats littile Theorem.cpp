
If we know m is prime, then we can also use Fermats's little theorem to find the inverse.

a^m-1 ≡ 1 (mod m)
If we multiply both sides with a-1, we get

a^-1 ≡ a m-2 (mod m)
Below is the Implementation of above
a^p-1 ≡ 1 (mod p)
OR
a^p-1 % p = 1
Here a is not divisible by p.

// C++ program to find modular inverse of a 
// under modulo m using Fermat's little theorem. 
// This program works only if m is prime. 
#include <bits/stdc++.h> 
using namespace std; 

// To compute x raised to power y under modulo m 
int power(int x, unsigned int y, unsigned int m); 

// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
void modInverse(int a, int m) 
{ 
  if (__gcd(a, m) != 1) 
    cout << "Inverse doesn't exist"; 

  else { 

    // If a and m are relatively prime, then 
    // modulo inverse is a^(m-2) mode m 
    cout << "Modular multiplicative inverse is "
      << power(a, m - 2, m); 
  } 
} 

// To compute x^y under modulo m 
int power(int x, unsigned int y, unsigned int m) 
{ 
  if (y == 0) 
    return 1; 
  int p = power(x, y / 2, m) % m; 
  p = (p * p) % m; 

  return (y % 2 == 0) ? p : (x * p) % m; 
} 

// Driver Program 
int main() 
{ 
  int a = 3, m = 11; 
  modInverse(a, m); 
  return 0; 
}


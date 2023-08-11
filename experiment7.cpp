#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned long long int modExp(unsigned long long int base, unsigned long long int exp, unsigned long long int mod) {
int result = 1;
base = base % mod;
while (exp > 0) {
if (exp % 2 == 1)
result = (result * base) % mod;
exp = exp >> 1;
base = (base * base) % mod;
}
return result;
}
int main() {
unsigned long long int p,q,n,phi,e,d,m;
printf("Enter prime number p: ");
scanf("%llu", &p);
printf("Enter prime number q: ");
scanf("%llu", &q);
n = p * q;
phi = (p - 1) * (q - 1);
printf("Enter public exponent e: ");
scanf("%llu", &e);
printf("Enter the value of m:");
scanf("%llu", &m);
for (d = 1; d < phi; d++) {
if ((e * d) % phi == 1)
break;
}
printf("Public Key (n, e): (%llu, %llu)\n", e,n);
printf("Private Key (n, d): (%llu, %llu)\n", d,n);
unsigned long long int encrypted = modExp(m, e, n);
printf("Encrypted: %llu\n", encrypted);
unsigned long long int decrypted = modExp(encrypted, d, n);
printf("Decrypted: %llu\n", decrypted);
return 0;
}

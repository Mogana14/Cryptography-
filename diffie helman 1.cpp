#include <stdio.h>
#include <math.h>

int mod_exp(int a, int b, int n) {
int result = 1;
a = a % n;
while (b > 0) {
if (b & 1) {
result = (result * a) % n;
}
b = b >> 1;
a = (a * a) % n;
}
return result;
}
int main() {
int p, g;
int a, b;
int A, B;
int s;
printf("Enter the public parameters p and g:\n");
scanf("%d %d", &p, &g);
printf("Enter the private keys a and b:\n");
scanf("%d %d", &a, &b);
A = mod_exp(g, a, p);
B = mod_exp(g, b, p);
s = mod_exp(B, a, p);
s = mod_exp(A, b, p);
printf("The public keys are:\n");
printf("A = %d\n", A);
printf("B = %d\n", B);
printf("The shared secret key is:\n");
printf("s = %d\n", s);
return 0;
}

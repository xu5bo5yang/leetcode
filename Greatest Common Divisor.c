#include <stdio.h>

int gcd (int a, int b) {
	if (a==0) return b;
	printf("%d(b) mod %d(a) = %d\n", b, a, b%a);
	return gcd(b%a, a);
}

int main(){
	int a, b;
	printf("Please input number:\n");
	scanf("%d %d", &a, &b);
	printf("GCD is: %d\n", gcd(a, b));
	return 0;
}
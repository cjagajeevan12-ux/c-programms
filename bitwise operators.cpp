#include<stdio.h>
#include<conio.h>
int main(){
	int a,b;
	printf("Enter two numbers:");
	scanf("%d %d",&a,&b);
	printf("\nBitwise AND (a&b)=%d",a&b);
	printf("\nBitwise OR (A|B)=%d",a|b);
	printf("\nBitwise XOR(a^b)=%d",a^b);
	printf("\nBitwise NOT of a (-a)=%d",~a);
	printf("\nLeft Shift(a<<1)=%d",a<<1);
	printf("\nRight shift(a>>1)=%d",a>>1);
	getch();
	return 0;
}

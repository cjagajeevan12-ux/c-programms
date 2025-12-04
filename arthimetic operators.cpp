#include<stdio.h>
#include<conio.h>
int main(){
	int a,b;
	printf("Enter two numbers:");
	scanf("%d %d",a,b);
	printf("addition=%d\n",a+b);
	printf("subtraction=%d\n",a-b);
	printf("Mutiplication=%d\n",a*b);
	printf("division=%d\n",a/b);//b should not be zero
	printf("modulus = %d\n",a%b);
	getch();
	return 0;
}


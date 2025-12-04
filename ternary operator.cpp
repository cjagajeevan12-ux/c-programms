#include<stdio.h>
#include<conio.h>
int main(){
	int a,b,largest;
	printf("Enter two numbers:");
	scanf("%d %d",&a,&b);
	largest=(a>b)?a:b;
	printf("Largest number=%d",largest);
	getch();
	return 0;
}

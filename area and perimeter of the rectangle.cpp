#include<stdio.h>
#include<conio.h>
int main(){
	int l,b,area,peri;
	printf("Enter the length and breadth of the rectangle:");
	scanf("%d %d",l,b);
	area=l*b;
	peri=2*(l+b);
	printf("Area of the rectangle=%d",area);
	printf("perimeter of the rectangle=%d",peri);
	getch();
	return 0;
}

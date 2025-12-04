#include<stdio.h>
#include<conio.h>
int main(){
	float r,area,peri;
	printf("Enter thr radius of the circle:");
	scanf("%f",&r);
	area=3.14*r*r;
	peri=2*3.14*r;
	printf("Area of circle=%.2f\n",area);
	printf("perimeter of circle=%.2f\n",peri);
	getch();
	return 0;
}

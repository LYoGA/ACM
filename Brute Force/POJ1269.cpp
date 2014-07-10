#include<stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	double x, y;
};

Point p1,p2,p3,p4;

double Direction(Point p1, Point p2, Point p3) {
	return (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);
}

void DealPoint() {
	if (Direction(p1,p2,p3) == 0 && Direction(p1,p2,p4) == 0) {
		printf("LINE\n");
	}
	else if ((p2.x - p1.x) * (p4.y - p3.y) == (p4.x - p3.x) * (p2.y - p1.y)) 	{
		printf("NONE\n");
	}
	else {
		double a1 = p1.y - p2.y;
		double b1 = p2.x - p1.x;
		double c1 = p1.x*p2.y - p2.x*p1.y;
		double a2 = p3.y - p4.y;
		double b2 = p4.x - p3.x;
		double c2 = p3.x*p4.y - p4.x*p3.y;
		double x = (b1*c2 - b2*c1)/(a1*b2 - a2*b1);
		double y = (a2*c1 - a1*c2)/(a1*b2 - a2*b1);
		printf("POINT %.2lf %.2lf\n", x, y);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);
		DealPoint();
	}
	printf("END OF OUTPUT\n");
	return 0; 
}


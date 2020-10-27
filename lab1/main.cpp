#include <cstdio>
#include "cmath"
#include <cstring>
#include "c_right_lines.h"
#include "cpp_right_lines.h"

const int size_mass = 100;
const int code_sign_minus = 45;
const int code_digit_0 = 48;
const int code_digit_9 = 57;


double determinate_num(const char* ptr) {
	size_t length_str = strlen(ptr) - 1;
	for (int i = 0; i < length_str; i++)
	{
		if (ptr[i] > code_digit_9 || ptr[i] < code_digit_0 && ptr[0]!= code_sign_minus)
			return nan("1");
	}
	return strtod(ptr, NULL);
}
double input_num() {
	char mass[size_mass] = "0";
	double num = 0;
	do {
		memset(mass, 0, sizeof(char) * size_mass);
		fgets(mass, size_mass, stdin);
		num = determinate_num(mass);
		if (num != num)
			printf("Number is uncorrect. Try again: ");
		else
			break;
	} while (true);
	return num;

}
void c_realization(double A1, double B1, double C1, double A2, double B2, double C2, double x1, double y1, double x2, double y2) {
	using namespace c;
	printf("C realization:\n");
	RightLine first_line = {A1,B1,C1};
	RightLine second_line = { A2,B2,C2 };
	RightLine abscissa = { 0,0,0 };
	Point first_point = { x1,y1 };
	Point second_point = { x2,y2 };
	printf("Angle between abscissa and first line :%lf\n", calculate_angle(abscissa, first_line));
	printf("Angle between abscissa and second line :%lf\n", calculate_angle(abscissa, second_line));
	printf("Angle between lines :%lf\n",calculate_angle(first_line, second_line));
	if (points_on_defferent_sides(first_line, first_point, second_point) == true)
		printf("Points on defferent sides\n");
	else 
		printf("Points on one sides\n");
	printf("Lines decussation in point ");
	print_point(decussation_lines(first_line,second_line));
}
void cpp_realiztaion(double A1, double B1, double C1, double A2, double B2, double C2, double x1, double y1, double x2, double y2) {
	using namespace cpp;
	printf("CPP realization:\n");
	RightLine first_line(A1, B1, C1);
	RightLine second_line(A2, B2, C2);
	RightLine abscissa(0, 0, 0);
	Point first_point(x1, y1);
	Point second_point(x2, y2);
	printf("Angle between abscissa and first line :%lf\n", abscissa.calculate_angle(first_line));
	printf("Angle between abscissa and second line :%lf\n", abscissa.calculate_angle(second_line));
	printf("Angle between lines :%lf\n",first_line.calculate_angle(second_line));
	if (points_on_defferent_sides(first_line, first_point, second_point) == true)
		printf("Points on defferent sides\n");
	else
		printf("Points on one sides\n");
	printf("Lines decussation in point ");
	decussation_lines(first_line, second_line).print_point();
}
void input_data(double* A1, double* B1, double* C1, double* A2, double* B2, double* C2, double* x1, double* y1, double* x2, double* y2) {
	printf("Enter data first right line :\nEnter A1 : ");
	*A1 = input_num();
	printf("Enter B1 : ");
	*B1 = input_num();
	printf("Enter C1 : ");
	*C1 = input_num();
	printf("Enter data second right line :\nEnter A2 : ");
	*A2 = input_num();
	printf("Enter B2 : ");
	*B2 = input_num();
	printf("Enter C2 : ");
	*C2 = input_num();
	printf("Enter data first point :\nEnter x1 : ");
	*x1 = input_num();
	printf("Enter y1 : ");
	*y1 = input_num();
	printf("Enter data second point :\nEnter x2 : ");
	*x2 = input_num();
	printf("Enter y2 : ");
	*y2 = input_num();
}


int main(void) {
	double A1, B1, C1, A2, B2, C2, x1, y1, x2, y2 = 0;
	input_data(&A1, &B1, &C1, &A2, &B2, &C2, &x1, &y1, &x2, &y2);
	c_realization(A1, B1, C1, A2, B2, C2, x1, y1, x2, y2);
	cpp_realiztaion(A1, B1, C1, A2, B2, C2, x1, y1, x2, y2);

}

#include<stdio.h>
#include<string.h>
struct Student{
	char name[20];
	char Phone[12];
	char Email[40];
};
int main(){
	struct Student std1;
	strcpy(std1.name, "Nguyen Van Hung");
	strcpy(std1.Phone, "03555555555");
	strcpy(std1.Email, "Hunglum@gmail.com");
	printf("Name: %s\nPhone: %s\nEmail: %s\n", std1.name, std1.Phone, std1.Email);
}

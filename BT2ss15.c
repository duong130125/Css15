#include<stdio.h>
#include<string.h>
struct Student{
	char name[20];
	int age;
	char phone[12];
	char Email[20];
};
void dislayStudent(struct Student Data);
int main(){
	struct Student sv1;
	printf("Nhap vao Ten cua sinh vien: ");
	gets(sv1.name);
	printf("Nhap vao Tuoi cua sinh vien: ");
	scanf("%d", &sv1.age);
	fflush(stdin);
	printf("Nhap vao So Dien Thoai cua sinh vien: ");
	gets(sv1.phone);
	printf("Nhap vao Email cua sinh vien: ");
	gets(sv1.Email);
	dislayStudent(sv1);
	return 0;
}

void dislayStudent(struct Student Data){
	printf("\nThong tin ve sinh vien vua nhap vao:\n");
	printf("Name: %s\n", Data.name);
	printf("Age: %d\n", Data.age);
	printf("Phone: %s\n", Data.phone);
	printf("Email: %s", Data.Email);
}

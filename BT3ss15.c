#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[50];
    int age;
	char phone[12];
    char email[100];
};
typedef struct student std;
void input(std *temp){
    printf("Nhap ten sinh vien: ");
    getchar();
    gets(temp->name);
    printf("Nhap tuoi: ");
    scanf("%d",&temp->age);
    printf("Nhap SDT: ");
    getchar();
    gets(temp->phone);
    printf("nhap email: ");
    getchar();
    gets(temp->email);
}  
void output( std *temp){
    printf("Ten: %s, Tuoi: %d, SDT: %s, Email: %s\n",temp->name, temp->age, temp->phone, temp->email);
}
int main(){
    int n;
    std temp[100];
    int index;
    int add;
    int change_index;
    int delete_index;
    int choice;
    do {
    	printf("*************MENU*************\n");
        printf("1. Nhap vao danh sach sinh vien.\n");
        printf("2. Them sinh vien vao danh sach.\n");
        printf("3. Sua sinh vien o vi tri chi dinh.\n");
        printf("4. Xoa sinh vien o vi tri chi dinh.\n");
        printf("5. In ra danh sach sinh vien.\n");
        printf("6. Thoat.\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                printf("Nhap vao so luong sinh vien:");
                scanf("%d",&n);
                for (int i=0; i<n; i++)
                    input(&temp[i]);
                break;
            case 2:
                printf("Nhap so sinh vien can them vao: ");
                scanf("%d",&add);
                index = 0;
                index += n + add;
                for (int i=n; i<index; i++)
                    input(&temp[i]);
                break;
            case 3:
                printf("Nhap vao vi tri muon sua: ");
                scanf("%d",&change_index);
                input(&temp[change_index]);
                break;
            case 4:
                printf("Nhap vi tri can xoa:");
                scanf("%d",&delete_index);
                for (int i=delete_index; i<index-1; i++)
                    temp[i] = temp[i+1];
                index--;
                break;
            case 5:
                for (int i=0; i<index; i++){
                    printf("sinh vien thu %d: ",i+1);
                    output(&temp[i]);   
                }
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice !=6);
}

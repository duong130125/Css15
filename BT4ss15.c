#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
struct Books {
    int book_id;
    char book_name[100];
    char author[100];
    long price;
    char category[100]; 
};
typedef struct Books book;
void input(book *temp){
    printf("Nhap ma sach:");
    scanf("%d",&temp->book_id);
    printf("Nhap ten sach:");
    getchar();
    gets(temp->book_name);
    printf("Nhap tac gia:");
    getchar();
    gets(temp->author);
    printf("Nhap gia:");
    scanf("%d",&temp->price);
    printf("Nhap the loai:");
    getchar();
    gets(temp->category);
}
void output( book *temp){
    printf("Ma sach: %d, Ten sach: %s, Tac gia: %s, Gia tien: %d, The loai: %s\n",temp->book_id, temp->book_name, temp->author, temp->price, temp->category);
}
void price_sort_increase(book temp[], int index){
    for (int i=0;i<index-1;i++){
        for (int j=i+1;j<index;j++) {
            if (temp[i].price > temp[j].price){
                book t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
}
void price_sort_decrease(book temp[], int index){
    for (int i=0;i<index-1;i++){
        for (int j=i+1;j<index;j++) {
            if (temp[i].price < temp[j].price){
                book t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
}
int main(){
    book temp[100];
    int n,i;
    int choice;
    int index;
    int add_index;
    int delete_id;
    int find_id;
    int sort_choice;
    char find_name[10];
    int first_price,last_price;
    do {
    	printf("************MENU*************\n");
        printf("1. nhap vao danh sach sach.\n");
        printf("2. Hien thi tong tin sach.\n");
        printf("3. Them sach vao vi tri.\n");
        printf("4. Xoa sach theo id.\n");
        printf("5. Cap nhat thong tin sach theo ma sach.\n");
        printf("6. Sap xep theo gia.\n");
        printf("7. Tim kiem theo ten sach.\n");
        printf("8. Tim kiem theo khoang gia.\n");
        printf("9. Thoat.\n");
        printf("Lua chon cua ban: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
        	case 1:
			    printf("Nhap vao so luong sach can quan ly: ");
				scanf("%d", &n); 
                for (int i=0; i<n; i++)
                    input(&temp[i]);
                index = n;
                printf("\n"); 
                break;
            case 2:
                for(i=0;i<index;i++) {
                    printf("Cuon sach thu %d:",i+1);
                    output(&temp[i]);
                }
                printf("\n"); 
                break;
            case 3:
                printf("Nhap vi tri can them thong tin:");
                scanf("%d",&add_index);
                for (i=index; i>=add_index; i--){
                    temp[i] = temp[i-1];
                    if (i == add_index)
                        input(&temp[i]);
                }
                index++;
                printf("\n"); 
                break;
            case 4:
                printf("Nhap vao id can xoa:");
                scanf("%d",&delete_id);
                for (i=0; i<index; i++) {
                    if (temp[i].book_id == delete_id)
                    for (int j=i;j<index-1;j++)
                    temp[i] = temp [i+1];
                }
                index--;
                printf("\n"); 
                break;
            case 5:
                printf("nhap vao id can cap nhat:");
                scanf("%d",&find_id);
                for (i=0; i<index; i++) {
                    if (temp[i].book_id == find_id)
                        input(&temp[i]);
                }
                printf("\n"); 
                break;
            case 6:
                printf("lua chon cach sap xep:\n");
                printf("1.tang dan\n");
                printf("2.giam dan\n");
                scanf("%d",&sort_choice);
                switch(sort_choice){
                    case 1:
                        price_sort_increase(temp,index);
                        break;
                    case 2:
                        price_sort_decrease(temp,index);
                        break;
                    default:
                        printf("khong hop le");
                        break;                   
                }
                printf("\n"); 
                break;
            case 7:
                printf("nhap vao ten can tim:");
                fgets(find_name,10,stdin);
                for (i=0; i<index; i++) {
                    if ( strcmp(temp[i].book_name,find_name) )  
                        output(&temp[i]);
                }
                printf("\n"); 
                break;
            case 8:
                printf("nhap vao gia tri dau tien:");
                scanf("%d",&first_price);
                printf("nhap vao gia tri dau cuoi:");
                scanf("%d",&last_price);
                for (i=0; i<index; i++) {
                    if ( (temp[i].price > first_price) && (temp[i].price < last_price))
                        output(&temp[i]);
                }
                printf("\n"); 
                break;
            case 9:
                exit(0); 
                break;
            default:
                printf("Lua chon cua ban khong hop le.\n");
                break;
        }
    } while (choice != 9);
}

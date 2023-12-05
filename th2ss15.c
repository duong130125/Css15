#include<stdio.h>

struct DiemThi {
    int maSV;
    float diemToan;
    float diemVan;
};

int main() {
	int size = 100;
	printf("Nhap phan tu gia tri muon quan ly sinh vien: ");
	scanf("%d", &size);
    struct DiemThi dsDiemThi[size];

    for (int i = 0; i < size; i++) {
        printf("Nhap ma sinh vien: ");
        scanf("%d", &dsDiemThi[i].maSV);
        printf("Nhap diem toan: ");
        scanf("%f", &dsDiemThi[i].diemToan);
        printf("Nhap diem van: ");
        scanf("%f", &dsDiemThi[i].diemVan);
    }

    printf("\nDanh sach ma sinh vien va diem thi:\n");
    for (int i = 0; i < size; i++) {
        printf("Ma sinh vien: %d, Diem toan: %.1f, Diem van: %.1f\n", dsDiemThi[i].maSV, dsDiemThi[i].diemToan, dsDiemThi[i].diemVan);
    }

    return 0;
}

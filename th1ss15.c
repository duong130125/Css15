#include <stdio.h>
#include <string.h>

struct SinhVien {
    char name[50];
    int maSV;
    float diemTB;
};

int main() {
    struct SinhVien sv1;
    strcpy(sv1.name, "Nguyen Dinh Duong");
    sv1.maSV = 12805;
    sv1.diemTB = 8.5;

    printf("Thong tin sinh vien:\n");
    printf("Ten: %s\n", sv1.name);
    printf("Ma sinh vien: %d\n", sv1.maSV);
    printf("Diem trung binh: %.1f\n", sv1.diemTB);

    return 0;
}

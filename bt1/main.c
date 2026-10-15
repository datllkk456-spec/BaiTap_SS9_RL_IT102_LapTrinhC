#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    struct VeMayBay danhSachVe[50];
    int n, i;
    char pnrCanTim[10];
    int foundIndex = -1;
    float trongLuongMoi;

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");
    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);
        if (n < 1 || n > 50) {
            printf("So luong ve khong hop le! Vui long nhap lai.\n");
        }
    } while (n < 1 || n > 50);

    while (getchar() != '\n');

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Nhap ma PNR: ");
        fgets(danhSachVe[i].maPNR, sizeof(danhSachVe[i].maPNR), stdin);
        danhSachVe[i].maPNR[strcspn(danhSachVe[i].maPNR, "\n")] = 0;

        printf("Nhap ho ten hanh khach: ");
        fgets(danhSachVe[i].tenHanhKhach, sizeof(danhSachVe[i].tenHanhKhach), stdin);
        danhSachVe[i].tenHanhKhach[strcspn(danhSachVe[i].tenHanhKhach, "\n")] = 0;

        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(danhSachVe[i].hangVe, sizeof(danhSachVe[i].hangVe), stdin);
        danhSachVe[i].hangVe[strcspn(danhSachVe[i].hangVe, "\n")] = 0;

        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &danhSachVe[i].trongLuongHanhLy);
        while (getchar() != '\n');

        if (danhSachVe[i].trongLuongHanhLy > 7.0f) {
            danhSachVe[i].phiPhuThu = (long)((danhSachVe[i].trongLuongHanhLy - 7.0f) * 50000);
        } else {
            danhSachVe[i].phiPhuThu = 0;
        }
    }

    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-25s %-15s %-15s %-15s\n", 
           "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
    printf("-----------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-15s %-15.1f %-15ld\n",
               i + 1,
               danhSachVe[i].maPNR,
               danhSachVe[i].tenHanhKhach,
               danhSachVe[i].hangVe,
               danhSachVe[i].trongLuongHanhLy,
               danhSachVe[i].phiPhuThu);
    }
    printf("-----------------------------------------------------------------------------------------\n");

    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");
    fgets(pnrCanTim, sizeof(pnrCanTim), stdin);
    pnrCanTim[strcspn(pnrCanTim, "\n")] = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(danhSachVe[i].maPNR, pnrCanTim) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Tim thay ve cua hanh khach: %s\n", danhSachVe[foundIndex].tenHanhKhach);
        printf("Nhap trong luong hanh ly moi (kg): ");
        scanf("%f", &trongLuongMoi);

        danhSachVe[foundIndex].trongLuongHanhLy = trongLuongMoi;
        if (trongLuongMoi > 7.0f) {
            danhSachVe[foundIndex].phiPhuThu = (long)((trongLuongMoi - 7.0f) * 50000);
        } else {
            danhSachVe[foundIndex].phiPhuThu = 0;
        }

        printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n", danhSachVe[foundIndex].phiPhuThu);

        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("-----------------------------------------------------------------------------------------\n");
        printf("%-5s %-10s %-25s %-15s %-15s %-15s\n", 
               "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
        printf("-----------------------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-15s %-15.1f %-15ld\n",
                   i + 1,
                   danhSachVe[i].maPNR,
                   danhSachVe[i].tenHanhKhach,
                   danhSachVe[i].hangVe,
                   danhSachVe[i].trongLuongHanhLy,
                   danhSachVe[i].phiPhuThu);
        }
        printf("-----------------------------------------------------------------------------------------\n");
    } else {
        printf("Khong tim thay ma PNR hop le trong he thong!\n");
    }

    return 0;
}
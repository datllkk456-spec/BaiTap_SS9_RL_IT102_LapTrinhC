#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maVe[15];
    char tenHanhKhach[50];
    char hangVe[20];
    float canNangHanhLy;
    double cuocHanhLy;
};

int main() {
    struct VeMayBay danhSachVe[100];
    int n, i;
    double tongCuoc = 0;
    int maxIndex = 0;
    char pnrTim[15];
    int foundIndex = -1;

    printf("Nhap so luong ve may bay: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("So luong ve khong hop le!\n");
        return 0;
    }

    while (getchar() != '\n');

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Ma ve PNR: ");
        fgets(danhSachVe[i].maVe, sizeof(danhSachVe[i].maVe), stdin);
        danhSachVe[i].maVe[strcspn(danhSachVe[i].maVe, "\n")] = 0;

        printf("Ho ten hanh khach: ");
        fgets(danhSachVe[i].tenHanhKhach, sizeof(danhSachVe[i].tenHanhKhach), stdin);
        danhSachVe[i].tenHanhKhach[strcspn(danhSachVe[i].tenHanhKhach, "\n")] = 0;

        printf("Hang ve (Business/Deluxe/Eco): ");
        fgets(danhSachVe[i].hangVe, sizeof(danhSachVe[i].hangVe), stdin);
        danhSachVe[i].hangVe[strcspn(danhSachVe[i].hangVe, "\n")] = 0;

        do {
            printf("Khoi luong hanh ly ky gui (kg): ");
            scanf("%f", &danhSachVe[i].canNangHanhLy);
            if (danhSachVe[i].canNangHanhLy < 0) {
                printf("Khoi luong hanh ly khong duoc am! Nhap lai.\n");
            }
        } while (danhSachVe[i].canNangHanhLy < 0);

        while (getchar() != '\n');

        if (strcmp(danhSachVe[i].hangVe, "Business") == 0) {
            if (danhSachVe[i].canNangHanhLy > 20.0f) {
                danhSachVe[i].cuocHanhLy = (danhSachVe[i].canNangHanhLy - 20.0f) * 50000;
            } else {
                danhSachVe[i].cuocHanhLy = 0;
            }
        } else {
            danhSachVe[i].cuocHanhLy = danhSachVe[i].canNangHanhLy * 50000;
        }

        tongCuoc += danhSachVe[i].cuocHanhLy;

        if (danhSachVe[i].canNangHanhLy > danhSachVe[maxIndex].canNangHanhLy) {
            maxIndex = i;
        }
    }

    printf("\n================================== DANH SACH VE MAY BAY CHUYEN BAY ==================================\n");
    printf("%-5s %-12s %-25s %-12s %12s %15s\n", 
           "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE", "HANH LY (KG)", "CUOC PHI (VND)");
    printf("----------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-12s %-25s %-12s %12.1f %15.0f\n",
               i + 1,
               danhSachVe[i].maVe,
               danhSachVe[i].tenHanhKhach,
               danhSachVe[i].hangVe,
               danhSachVe[i].canNangHanhLy,
               danhSachVe[i].cuocHanhLy);
    }
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Tong tien cuoc hanh ly toan chuyen: %.0f VND\n", tongCuoc);
    printf("Ve co hanh ly ky gui nang nhat: %s - %s (%.1f kg)\n", 
           danhSachVe[maxIndex].maVe, danhSachVe[maxIndex].tenHanhKhach, danhSachVe[maxIndex].canNangHanhLy);

    printf("\n--- CAP NHAT THONG TIN HANH LY ---\n");
    printf("Nhap ma ve PNR can cap nhat hanh ly: ");
    fgets(pnrTim, sizeof(pnrTim), stdin);
    pnrTim[strcspn(pnrTim, "\n")] = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(danhSachVe[i].maVe, pnrTim) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        do {
            printf("Nhap can nang hanh ly ky gui moi (kg): ");
            scanf("%f", &danhSachVe[foundIndex].canNangHanhLy);
            if (danhSachVe[foundIndex].canNangHanhLy < 0) {
                printf("Khoi luong hanh ly khong duoc am! Nhap lai.\n");
            }
        } while (danhSachVe[foundIndex].canNangHanhLy < 0);

        if (strcmp(danhSachVe[foundIndex].hangVe, "Business") == 0) {
            if (danhSachVe[foundIndex].canNangHanhLy > 20.0f) {
                danhSachVe[foundIndex].cuocHanhLy = (danhSachVe[foundIndex].canNangHanhLy - 20.0f) * 50000;
            } else {
                danhSachVe[foundIndex].cuocHanhLy = 0;
            }
        } else {
            danhSachVe[foundIndex].cuocHanhLy = danhSachVe[foundIndex].canNangHanhLy * 50000;
        }

        printf("Tim thay ma ve %s. Da cap nhat cuoc hanh ly moi: %.0f VND.\n", 
               danhSachVe[foundIndex].maVe, danhSachVe[foundIndex].cuocHanhLy);

        printf("\n================================ DANH SACH VE MAY BAY SAU CAP NHAT ================================\n");
        printf("%-5s %-12s %-25s %-12s %12s %15s\n", 
               "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE", "HANH LY (KG)", "CUOC PHI (VND)");
        printf("----------------------------------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++) {
            printf("%-5d %-12s %-25s %-12s %12.1f %15.0f\n",
                   i + 1,
                   danhSachVe[i].maVe,
                   danhSachVe[i].tenHanhKhach,
                   danhSachVe[i].hangVe,
                   danhSachVe[i].canNangHanhLy,
                   danhSachVe[i].cuocHanhLy);
        }
        printf("----------------------------------------------------------------------------------------------------\n");
    } else {
        printf("Khong tim thay ma ve PNR nay trong he thong!\n");
    }

    return 0;
}
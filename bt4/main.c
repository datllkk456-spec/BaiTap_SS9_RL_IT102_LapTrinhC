#include <stdio.h>
#include <string.h>

struct HanhKhach {
    char maPNR[15];
    char hoTen[50];
    char hangVe[15];
    float canNangHanhLy;
    float phiHanhLy;
};

int main() {
    struct HanhKhach danhSach[100];
    int soLuong = 0;
    int luaChon;
    int i;
    char pnrTim[15];
    int foundIndex;
    float kgMienPhi, kgVuot;

    do {
        printf("\n=== HE THONG CHECK-IN HANG KHONG ===\n");
        printf("1. Them hanh khach check-in\n");
        printf("2. Hien thi danh sach hanh khach\n");
        printf("3. Cap nhat hanh ly theo ma PNR\n");
        printf("4. Thong ke chuyen bay\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                if (soLuong >= 100) {
                    printf("Bo nho day, khong the them hanh khach!\n");
                    break;
                }

                while (getchar() != '\n');

                printf("\nNhap ma PNR: ");
                fgets(danhSach[soLuong].maPNR, sizeof(danhSach[soLuong].maPNR), stdin);
                danhSach[soLuong].maPNR[strcspn(danhSach[soLuong].maPNR, "\n")] = 0;

                printf("Nhap ho ten: ");
                fgets(danhSach[soLuong].hoTen, sizeof(danhSach[soLuong].hoTen), stdin);
                danhSach[soLuong].hoTen[strcspn(danhSach[soLuong].hoTen, "\n")] = 0;

                printf("Nhap hang ve (Business/Deluxe/Eco): ");
                fgets(danhSach[soLuong].hangVe, sizeof(danhSach[soLuong].hangVe), stdin);
                danhSach[soLuong].hangVe[strcspn(danhSach[soLuong].hangVe, "\n")] = 0;

                do {
                    printf("Nhap so kg hanh ly ky gui: ");
                    scanf("%f", &danhSach[soLuong].canNangHanhLy);
                    if (danhSach[soLuong].canNangHanhLy < 0) {
                        printf("So kg hanh ly khong duoc am! Nhap lai.\n");
                    }
                } while (danhSach[soLuong].canNangHanhLy < 0);

                if (strcmp(danhSach[soLuong].hangVe, "Business") == 0) {
                    kgMienPhi = 30.0f;
                } else if (strcmp(danhSach[soLuong].hangVe, "Deluxe") == 0) {
                    kgMienPhi = 20.0f;
                } else {
                    kgMienPhi = 0.0f;
                }

                if (danhSach[soLuong].canNangHanhLy > kgMienPhi) {
                    kgVuot = danhSach[soLuong].canNangHanhLy - kgMienPhi;
                } else {
                    kgVuot = 0.0f;
                }

                danhSach[soLuong].phiHanhLy = kgVuot * 50000.0f;

                printf("Them hanh khach thanh cong! Phi hanh ly qua cuoc: %.0f VND\n", danhSach[soLuong].phiHanhLy);
                soLuong++;
                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                printf("\n-----------------------------------------------------------------------------------------\n");
                printf("| %-5s | %-10s | %-25s | %-12s | %-14s | %-18s |\n", 
                       "STT", "Ma PNR", "Ho va Ten", "Hang ve", "Hanh ly (kg)", "Phi Qua Cuoc (VND)");
                printf("-----------------------------------------------------------------------------------------\n");

                for (i = 0; i < soLuong; i++) {
                    printf("| %-5d | %-10s | %-25s | %-12s | %-14.1f | %-18.0f |\n",
                           i + 1,
                           danhSach[i].maPNR,
                           danhSach[i].hoTen,
                           danhSach[i].hangVe,
                           danhSach[i].canNangHanhLy,
                           danhSach[i].phiHanhLy);
                }
                printf("-----------------------------------------------------------------------------------------\n");
                break;

            case 3:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                while (getchar() != '\n');
                printf("\nNhap ma PNR can cap nhat: ");
                fgets(pnrTim, sizeof(pnrTim), stdin);
                pnrTim[strcspn(pnrTim, "\n")] = 0;

                foundIndex = -1;
                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].maPNR, pnrTim) == 0) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    printf("Tim thay hanh khach: %s\n", danhSach[foundIndex].hoTen);

                    do {
                        printf("Nhap so kg hanh ly ky gui moi: ");
                        scanf("%f", &danhSach[foundIndex].canNangHanhLy);
                        if (danhSach[foundIndex].canNangHanhLy < 0) {
                            printf("So kg hanh ly khong duoc am! Nhap lai.\n");
                        }
                    } while (danhSach[foundIndex].canNangHanhLy < 0);

                    if (strcmp(danhSach[foundIndex].hangVe, "Business") == 0) {
                        kgMienPhi = 30.0f;
                    } else if (strcmp(danhSach[foundIndex].hangVe, "Deluxe") == 0) {
                        kgMienPhi = 20.0f;
                    } else {
                        kgMienPhi = 0.0f;
                    }

                    if (danhSach[foundIndex].canNangHanhLy > kgMienPhi) {
                        kgVuot = danhSach[foundIndex].canNangHanhLy - kgMienPhi;
                    } else {
                        kgVuot = 0.0f;
                    }

                    danhSach[foundIndex].phiHanhLy = kgVuot * 50000.0f;

                    printf("Cap nhat thanh cong! Phi hanh ly moi: %.0f VND\n", danhSach[foundIndex].phiHanhLy);
                } else {
                    printf("Ma PNR khong ton tai trong he thong!\n");
                }
                break;

            case 4:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                {
                    int demBusiness = 0;
                    float tongPhi = 0.0f;

                    for (i = 0; i < soLuong; i++) {
                        if (strcmp(danhSach[i].hangVe, "Business") == 0) {
                            demBusiness++;
                        }
                        tongPhi += danhSach[i].phiHanhLy;
                    }

                    printf("\n=== THONG KE CHUYEN BAY ===\n");
                    printf("- Tong so hanh khach check-in             : %d\n", soLuong);
                    printf("- So luong hanh khach hang Business       : %d\n", demBusiness);
                    printf("- Tong tien phi hanh ly qua cuoc da thu   : %.0f VND\n", tongPhi);
                }
                break;

            case 5:
                printf("Cam on ban da su dung he thong. Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon tu 1 den 5.\n");
                break;
        }

    } while (luaChon != 5);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Hienthitencot();

struct Tensp {
	char Tensp[20];
};

struct Sanpham {
	int Masp;
	struct Tensp Tensp;
	int Soluong;
};

struct Ngaysanxuat {
    int tm_mday; // ngay trong thang 
    int tm_year; // nam 
};

struct Hansudung {
    int tm_mday; // ngay trong thang 
    int tm_year; // nam 
};

////Ðinh nghia cau truc du lieu cho Quy trinh san xuat
//typedef struct Quytrinhsx {
//	int Masp;
//	char Tensp[20];
//	struct Ngaysanxuat ngaysanxuat;
//	struct Hansudung hansudung; 
//}Quytrinhsx;
//
////Ðinh nghia cau truc du lieu cho Don vi giao hang
//typedef struct Donvigiaohang {
//	int Masp;
//	char Tensp[20];
//	char Thongtinlienlac[50]; 
//}Donvigiaohang;
//
////Ðinh nghia cau truc du lieu cho Kho hang 
//typedef struct Khohang {
//	int Masp;
//	char Diachi[20];
//	int Tongsoluong; 
//}Khohang;

void Nhaptensp(struct Tensp* Tensp) {
	printf("Ten san pham: ");
	scanf("%s", Tensp->Tensp);
}

struct Sanpham Nhapsp() {
	struct Sanpham sp;
	printf("Nhap ma san pham: ");
	scanf("%d", &sp.Masp);
	Nhaptensp(&sp.Tensp);
	printf("So luong san pham: ");
	scanf("%d", &sp.Soluong);
	return sp;
}

void HienthiTTSP(struct Sanpham sp) {
	printf("%-10d %-20s %-20d\n", sp.Masp, sp.Tensp.Tensp, sp.Soluong);
}

//void Xoasp(struct Sanpham* ds, int slsp, int id, int n) {
//    int found = 0;
//    for(int i = 0; i < n; i++) {
//        if ([i].Masp = id) {
//            found = 1;
//            printf(40);
//            for (int j = i; j < n; j++) {
//                a[j] = a[j+1];
//            }
//            printf("\n Da xoa sap pham co ma la:  ", id);
//            printf(40);
//            break;
//        }
//    }
//    if (found == 0) {
//        printf("\n San pham co ID = %d khong ton tai.", id);
//        return 0;
//    } else {
//        return 1;
//    }
//}

// void Xoasp(Sanpham** head, int id) {
//     Sanpham* temp = *head;
//     Sanpham* prev = NULL;

//     if (temp != NULL && temp-> Masp == id) {
//         *head = temp-> Xoasp;
//         free(temp);
//         return;
//     }
//     while (temp != NULL && temp-> Masp != id) {
//         prev = temp;
//         temp = temp->next;
//     }
//     if (temp == NULL) {
//         return;
//     }
//     prev->next = temp->next;
//     free(temp);
// }


void Timsp(struct Sanpham* ds, int slsp) {
	char Tensp[20];
	printf("San pham ban can tim kiem la: ");
	scanf("%s", Tensp);
	
	Hienthitencot();
	
	int i, timsp = 0;
	for(i = 0; i < slsp; i++) {
		if(strcmp(Tensp, ds[i].Tensp.Tensp) == 0) {
			HienthiTTSP(ds[i]);
			timsp = 1;
		}
	}
	if(timsp == 0) {
		printf("Khong co san pham %s trong danh sach!\n", Tensp);
	}
}

void Ghifile(struct Sanpham* ds, int slsp) {
	FILE* fOut = fopen("Danh sach san pham.txt", "a");
	int i;
	for(i = 0; i < slsp; i++) {
		struct Sanpham sp = ds[i];
		fprintf(fOut, "%-10d %-20s %-20d\n", sp.Masp, sp.Tensp.Tensp, sp.Soluong);
	}
	fclose(fOut);
}

void Hienthitencot() {
	printf("%-10s %-20s %-20s\n", "Ma san pham", "Ten san pham", "So luong");
}

int main() {
	struct Sanpham dssp[100];
	int slsp = 0;
	int Luachon;
	
	do {
	    printf("Danh sach lien ket trong bai toan quan li san pham");
	    printf("\nLop: DA21TTC         MSSV: 110121188");
		printf("\n=============== MENU ===============");
		printf("\n1. Them San pham vao danh sach.");
		printf("\n2. Hien thi danh sach san pham.");
		printf("\n3. Xoa san pham.");
		printf("\n4. Tim san pham.");
		printf("\n5. Ghi thong tin san pham ra file.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nLua chon cua ban la ? ");
		
		scanf("%d", &Luachon);
		struct Sanpham sp;
		int i;
		switch(Luachon) {
			case 0:
				break;
				
			case 1:
				sp = Nhapsp();
				dssp[slsp++] = sp;
				break;
				
			case 2:
				Hienthitencot();
				for(i = 0; i < slsp; i++) {
					HienthiTTSP(dssp[i]);
				}
				break;
				
// 			case 3:
// 				if(slsp > 0) {
//                    int id;
//                    printf ("\n3. Xoa san pham.");
//                    printf ("\n Nhap ID: ", id);
//                    if (xoaTheoID(arraySANPHAM, id, slsp == 1) {
//                        printf("\nSan pham co id = %d da bi xoa.", &id);
//                        slsp--;
//                    }
//                }else{
//                    prinft ("\nDanh sach san pham trong!");
//                }
//                pressAnyKey();
//                break;
				
			case 4:
				Timsp(dssp, slsp);
				break;
				
			case 5:
				Ghifile(dssp, slsp);
				break;
				
//			case 6:
//				Khohang kho1;
//    			printf("Nhap ma san pham: ");
//    			scanf("%d", &kho1.Masp);
//    			printf("Nhap dia chi: ");
//    			scanf("%s", kho1.Diachi);
//    			printf("Nhap tong so luong: ");
//    			scanf("%d", &kho1.Tongsoluong);
//    			printf("Ma san pham: %d\n", kho1.Masp);
//    			printf("Dia chi: %s\n", kho1.Diachi);
//    			printf("Tong so luong: %d\n", kho1.Tongsoluong);
//				break;

//			case 7:
//				Quytrinhsx quytrinh1;
//    			printf("Nhap ma san pham: ");
//    			scanf("%d", &quytrinh1.Masp);
//    			printf("Nhap ten san pham: ");
//    			scanf("%s", quytrinh1.Tensp);
//    			printf("Nhap ngay san xuat (ngay trong thang): ");
//    			scanf("%d", &quytrinh1.ngaysanxuat.tm_mday);
//    			printf("Nhap nam san xuat: ");
//    			scanf("%d", &quytrinh1.ngaysanxuat.tm_year);
//    			printf("Nhap ngay het han (ngay trong thang): ");
//    			scanf("%d", &quytrinh1.hansudung.tm_mday);
//    			printf("Nhap nam het han: ");
//    			scanf("%d", &quytrinh1.hansudung.tm_year);
//
//    			printf("\nThong tin Quy trinh san xuat:\n");
//    			printf("Ma san pham: %d\n", quytrinh1.Masp);
//    			printf("Ten san pham: %s\n", quytrinh1.Tensp);
//    			printf("Ngay san xuat: %d/%d\n", quytrinh1.ngaysanxuat.tm_mday, quytrinh1.ngaysanxuat.tm_year);
//    			printf("Ngay het han: %d/%d\n", quytrinh1.hansudung.tm_mday, quytrinh1.hansudung.tm_year);
// 				break;
				
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
		
	} while(Luachon);
	
	
	
	return 0;
}



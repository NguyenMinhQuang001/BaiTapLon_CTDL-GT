#include "stdio.h"
#include "string.h"
#include "time.h"
#include "conio.h"
#include "stdlib.h"
#include <ctime>

struct NGAYTHANG{
	int ngay;
	int thang;
	int nam;
};

struct BENHNHAN{
	int STT;
	char hoten[30];
	char diachi[255];
	char sdt[12];
	char BHYT[12];;
	NGAYTHANG ngaykham;
	char trangthai[255];
};

typedef struct BENHNHAN BN;

struct node{
    BENHNHAN data;
    node * next;
};

typedef struct node NODE;

struct list{
    NODE *pHead;
    NODE *pTail;
};

typedef struct list LIST;

void KhoiTao(LIST &ds){
    ds.pHead = NULL;
    ds.pTail = NULL;
}

int KiemTraRong(LIST ds){
    if (ds.pHead == NULL){
        return 1;
    }
    return 0;
}

NODE* TaoNode(BN x) {
    NODE *p;
    p = new NODE;
    if (p==NULL) {
        printf ("KHONG DU BO NHO");
        return NULL;
    }
    p->data=x;
    p->next=NULL;
    return p;
}

void ChenCuoi (LIST &ds, NODE *p){
    if (ds.pHead==NULL) {
        ds.pHead=p;
        ds.pTail=p;
    }
    else {
        ds.pTail->next=p;
        ds.pTail=p;
    }
}

int DemBenhNhan(LIST ds){
	int dem=0;
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        dem++;
    }
    return dem;
}

void XuatTuFile(LIST ds);

void Nhap(LIST &ds, int n){
	int stt = DemBenhNhan(ds);
	BN bn;
    printf("NHAP THONG TIN BENH NHAN\n");
    for(int i = 0; i < n; i++){
    	bn.STT = stt+1;
		
		printf("Nhap ho ten: ");fflush(stdin);
		gets(bn.hoten);
		
		char diaChi[255];
		int input;
		printf("+------------------------------------------------------------------------------------------------------------------+\n");
		printf("|\t\t\t\tDanh sach cac quan, huyen thuoc Thanh pho Ho Chi Minh\t\t\t\t   |\n");
		printf("+------------------------------------------------------------------------------------------------------------------+\n");
		printf("|1. Quan 1\t\t\t2. Quan 2\t\t\t3. Quan 3\t\t\t4. Quan 4\t   |\n");
		printf("|5. Quan 5\t\t\t6. Quan 6\t\t\t7. Quan 7\t\t\t8. Quan 8\t   |\n");
		printf("|9. Quan 9\t\t\t10. Quan 10\t\t\t11. Quan 11\t\t\t12. Quan 12\t   |\n");
		printf("|13. Quan Tan Binh\t\t14. Quan Phu Nhuan\t\t15. Quan Go Vap\t\t\t16. Quan Binh Thanh|\n");
		printf("|17. Quan Binh Tan\t\t18. Quan Tan Phu\t\t19. Quan Thu Duc\t\t20. Huyen Hoc Mon  |\n");
		printf("|21. Huyen Cu Chi\t\t22. Huyen Nha Be\t\t23. Huyen Binh Chanh\t\t24. Huyen Can Gio  |\n");
		printf("+------------------------------------------------------------------------------------------------------------------+\n");
		printf("Chon dia chi Benh nhan muon tim: ");
		scanf("%d",&input);
		
		if(input == 1){
			strcpy(diaChi,"Quan1");
		}else if(input == 2){
			strcpy(diaChi,"Quan2");
		}else if(input == 3){
			strcpy(diaChi,"Quan3");
		}else if(input == 4){
			strcpy(diaChi,"Quan4");
		}else if(input == 5){
			strcpy(diaChi,"Quan5");
		}else if(input == 6){
			strcpy(diaChi,"Quan6");
		}else if(input == 7){
			strcpy(diaChi,"Quan7");
		}else if(input == 8){
			strcpy(diaChi,"Quan8");
		}else if(input == 9){
			strcpy(diaChi,"Quan9");
		}else if(input == 10){
			strcpy(diaChi,"Quan10");
		}else if(input == 11){
			strcpy(diaChi,"Quan11");
		}else if(input == 12){
			strcpy(diaChi,"Quan12");
		}else if(input == 13){
			strcpy(diaChi,"TanBinh");
		}else if(input == 14){
			strcpy(diaChi,"PhuNhuan");
		}else if(input == 15){
			strcpy(diaChi,"GoVap");
		}else if(input == 16){
			strcpy(diaChi,"BinhThanh");
		}else if(input == 17){
			strcpy(diaChi,"BinhTan");
		}else if(input == 18){
			strcpy(diaChi,"TanPhu");
		}else if(input == 19){
			strcpy(diaChi,"ThuDuc");
		}else if(input == 20){
			strcpy(diaChi,"HocMon");
		}else if(input == 21){
			strcpy(diaChi,"CuChi");
		}else if(input == 22){
			strcpy(diaChi,"NhaBe");
		}else if(input == 23){
			strcpy(diaChi,"BinhChanh");
		}else{
			strcpy(diaChi,"CanGio");
		}
		strcpy(bn.diachi,diaChi);
		printf("Dia chi Benh nhan: %s\n",bn.diachi);
		
		printf("Nhap so dien thoai: ");fflush(stdin);
		gets(bn.sdt);
		
		printf("Nhap BHYT: ");fflush(stdin);
		gets(bn.BHYT);
		
		time_t now = time(0);
   		tm *ltm = localtime(&now);
   
 		int day = ltm->tm_mday;
  		int month = 1 + ltm->tm_mon;
   		int year = 1900 + ltm->tm_year;
   		
   		int chonNgay;
   		printf("Chon ngay kham (1-Lay ngay hien tai | 2-Nhap thu cong): ");
   		scanf("%d",&chonNgay);
   		if(chonNgay == 1){
   			bn.ngaykham.ngay = day;
   			bn.ngaykham.thang = month;
   			bn.ngaykham.nam = year;
   			printf("Ngay kham: %d/%d/%d\n",bn.ngaykham.ngay,bn.ngaykham.thang,bn.ngaykham.nam);	
		}else{
			printf("Nhap thoi gian kham:\n");fflush(stdin);
			printf("	Ngay: ");
			scanf("%d", &bn.ngaykham.ngay);fflush(stdin);
			printf("	Thang: ");
			scanf("%d", &bn.ngaykham.thang);fflush(stdin);
			printf("	Nam: ");
			scanf("%d", &bn.ngaykham.nam);fflush(stdin);
		}
   		
		int choose;
		printf("Chon trang thai Benh nhan ( 1-Cho kham | 2-Noi tru | 3-Ngoai tru ): ");
		scanf("%d",&choose);
		if(choose == 1){
			strcpy(bn.trangthai,"Chokham");
		}else if(choose == 2){
			strcpy(bn.trangthai,"Noitru");
		}else {
			strcpy(bn.trangthai,"Ngoaitru");
		}
		
		printf ("--------------------------------------\n");
        NODE *p = new NODE;
        p = TaoNode(bn);
        ChenCuoi(ds,p);
        XuatTuFile(ds);
        stt++;
    }
}

void Xuat(LIST ds){
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        printf("%3d",p->data.STT);
		printf("%25s",p->data.hoten);
		printf("%12s",p->data.diachi);
		printf("%22s",p->data.sdt);
		printf("%15s",p->data.BHYT);
		if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang > 9){
			printf("%7d/%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);	
		}else if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang <= 9){
			printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
		}else if(p->data.ngaykham.ngay <= 9 && p->data.ngaykham.thang > 9){
			printf("%7d/%d/%d", p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
		}else{
			printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
		}
		printf("%15s\n",p->data.trangthai);
    }
}

void Xuat1BenhNhan(NODE* p){
        printf("%3d",p->data.STT);
		printf("%25s",p->data.hoten);
		printf("%12s",p->data.diachi);
		printf("%22s",p->data.sdt);
		printf("%15s",p->data.BHYT);
		if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang > 9){
			printf("%7d/%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);	
		}else if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang <= 9){
			printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
		}else if(p->data.ngaykham.ngay <= 9 && p->data.ngaykham.thang > 9){
			printf("%7d/%d/%d", p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
		}else{
			printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
		}
		printf("%15s\n",p->data.trangthai);
}

void NhapTuFile(LIST &ds){
	FILE *fp;
	int n;// so benh nhan
	BN bn;
	fp = fopen("DataBenhNhan.txt","r");
	//kiem tra file
    if(fp==NULL){
        printf("Loi file!");
        return;
    }
    
    //doc du lieu tu file gan vao n
    fscanf(fp,"%d",&n);
//    printf("So benh nhan la: %d\n",n);
    //doc du lieu tu file gan vao tung benh nhan thi i
    for(int i=0; i<n; i++){
        fscanf(fp,"%d%s%s%s%s%d%d%d%s",&bn.STT,&bn.hoten,&bn.diachi,&bn.sdt,&bn.BHYT,&bn.ngaykham.ngay,&bn.ngaykham.thang,&bn.ngaykham.nam,&bn.trangthai);
        NODE *p = new NODE;
        p = TaoNode(bn);
        ChenCuoi(ds,p);
	}
    
//    Xuat(ds);
	printf("\nDoc file thanh cong!\n");
    //dong file
    fclose(fp);
}

void XuatTuFile(LIST ds){
	FILE *fp;
	//mo file o che do w
    fp = fopen("DataBenhNhan.txt","w");
    //kiem tra file
    if(fp==NULL){
        printf("Loi file!");
        return;
    }
    fprintf(fp,"%d\n",DemBenhNhan(ds));
	for(NODE *p = ds.pHead; p!= NULL; p=p->next){
    	fprintf(fp,"%d \t %s \t %s \t %s \t %s \t %d \t %d \t %d \t %s \n",p->data.STT,p->data.hoten,p->data.diachi,p->data.sdt,p->data.BHYT,p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam,p->data.trangthai);
    }
    //dong file
    fclose(fp);
}

void TimBNtheoSDT(LIST ds, char sdt[12]){
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.sdt, sdt)==0){
	        printf("%3d",p->data.STT);
			printf("%25s",p->data.hoten);
			printf("%12s",p->data.diachi);
			printf("%22s",p->data.sdt);
			printf("%15s",p->data.BHYT);
			if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);	
			}else if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang <= 9){
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else if(p->data.ngaykham.ngay <= 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d", p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else{
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}
			printf("%15s\n",p->data.trangthai);
        }
    }
}

void TimBNtheoTrangThai(LIST ds, char trangthai[255]){
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.trangthai, trangthai)==0){
	        printf("%3d",p->data.STT);
			printf("%25s",p->data.hoten);
			printf("%12s",p->data.diachi);
			printf("%22s",p->data.sdt);
			printf("%15s",p->data.BHYT);
			if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);	
			}else if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang <= 9){
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else if(p->data.ngaykham.ngay <= 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d", p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else{
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}
			printf("%15s\n",p->data.trangthai);
        }
    }
}

void TimBNtheoName(LIST ds, char hoten[30]){
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.hoten, hoten)==0){
	        printf("%3d",p->data.STT);
			printf("%25s",p->data.hoten);
			printf("%12s",p->data.diachi);
			printf("%22s",p->data.sdt);
			printf("%15s",p->data.BHYT);
			if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);	
			}else if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang <= 9){
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else if(p->data.ngaykham.ngay <= 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d", p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else{
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}
			printf("%15s\n",p->data.trangthai);
        }
    }
}

void TimBNtheoNameVsSDT(LIST ds, char hoten[30], char sdt[12]){
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.hoten, hoten)==0){
	        if(strcmp(p->data.sdt, sdt)==0){
		        printf("%3d",p->data.STT);
				printf("%25s",p->data.hoten);
				printf("%12s",p->data.diachi);
				printf("%22s",p->data.sdt);
				printf("%15s",p->data.BHYT);
				if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang > 9){
					printf("%7d/%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);	
				}else if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang <= 9){
					printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
				}else if(p->data.ngaykham.ngay <= 9 && p->data.ngaykham.thang > 9){
					printf("%7d/%d/%d", p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
				}else{
					printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
				}
				printf("%15s\n",p->data.trangthai);
	        }
        }
    }
}

void TimBNtheoNgayKham(LIST ds, NGAYTHANG nk){
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        if(p->data.ngaykham.ngay == nk.ngay && p->data.ngaykham.thang == nk.thang && p->data.ngaykham.nam == nk.nam){
	        printf("%3d",p->data.STT);
			printf("%25s",p->data.hoten);
			printf("%12s",p->data.diachi);
			printf("%22s",p->data.sdt);
			printf("%15s",p->data.BHYT);
			if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);	
			}else if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang <= 9){
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else if(p->data.ngaykham.ngay <= 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d", p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else{
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}
			printf("%15s\n",p->data.trangthai);
        }
    }
}

void TimBNtheoDiaChi(LIST ds, char diaChi[255]){
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
    for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.diachi, diaChi)==0){
	        printf("%3d",p->data.STT);
			printf("%25s",p->data.hoten);
			printf("%12s",p->data.diachi);
			printf("%22s",p->data.sdt);
			printf("%15s",p->data.BHYT);
			if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);	
			}else if(p->data.ngaykham.ngay > 9 && p->data.ngaykham.thang <= 9){
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else if(p->data.ngaykham.ngay <= 9 && p->data.ngaykham.thang > 9){
				printf("%7d/%d/%d", p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}else{
				printf("%7d/0%d/%d",p->data.ngaykham.ngay,p->data.ngaykham.thang,p->data.ngaykham.nam);
			}
			printf("%15s\n",p->data.trangthai);
        }
    }
}

void TimBN(LIST ds){
	int kt=1;
	int chon;
	while(kt){
		printf("\n1. Tim BN theo so dien thoai");
		printf("\n2. Tim BN theo ho ten");
		printf("\n3. Tim BN theo trang thai");
		printf("\n4. Tim BN theo ho ten & SDT");
		printf("\n5. Tim BN theo ngay kham");
		printf("\n6. Tim BN theo dia chi");
		printf("\nGo so tuong ung chuc nang can chon ( 7-Thoat ):");
		scanf("%d",&chon);
		switch(chon){
			case 1:{
				char sdt[12];
				printf("Nhap so dien thoai BN can tim: ");fflush(stdin);
				gets(sdt);
				TimBNtheoSDT(ds,sdt);
				break;
			}
			case 2:{
				char hoten[30];
				printf("Nhap so Ho ten BN can tim: ");fflush(stdin);
				gets(hoten);
				TimBNtheoName(ds, hoten);
				break;
			}			
			case 3:{
				char trangthai[255];
				int input;
				printf("Chon trang thai BN can tim ( 1-Cho kham | 2-Noi tru | 3-Ngoai tru ): ");
				scanf("%d",&input);
				if(input == 1){
					strcpy(trangthai,"Chokham");
				}else if(input == 2){
					strcpy(trangthai,"Noitru");
				}else {
					strcpy(trangthai,"Ngoaitru");
				}
				TimBNtheoTrangThai(ds, trangthai);
				break;
			}
			case 4:{
				char sdt[12];
				printf("Nhap so dien thoai BN can tim: ");fflush(stdin);
				gets(sdt);
				char hoten[30];
				printf("Nhap so Ho ten BN can tim: ");fflush(stdin);
				gets(hoten);
				TimBNtheoNameVsSDT(ds, hoten, sdt);
				break;
			}
			case 5:{
				NGAYTHANG nk;
				time_t now = time(0);
				tm *ltm = localtime(&now);
			
				int day = ltm->tm_mday;
				int month = 1 + ltm->tm_mon;
				int year = 1900 + ltm->tm_year;
				
				int chonNgay;
				printf("Chon ngay kham (1-Lay ngay hien tai | 2-Nhap thu cong): ");
				scanf("%d",&chonNgay);
				if(chonNgay == 1){
					nk.ngay = day;
					nk.thang = month;
					nk.nam = year;
				}else{
					printf("Nhap thoi gian kham:\n");fflush(stdin);
					printf("	Ngay: ");
					scanf("%d", &nk.ngay);fflush(stdin);
					printf("	Thang: ");
					scanf("%d", &nk.thang);fflush(stdin);
					printf("	Nam: ");
					scanf("%d", &nk.nam);fflush(stdin);
				}
				
				TimBNtheoNgayKham(ds,nk);
				break;
			}
			case 6:{
				char diaChi[255];
				int input;
				printf("+------------------------------------------------------------------------------------------------------------------+\n");
				printf("|\t\t\t\tDanh sach cac quan, huyen thuoc Thanh pho Ho Chi Minh\t\t\t\t   |\n");
				printf("+------------------------------------------------------------------------------------------------------------------+\n");
				printf("|1. Quan 1\t\t\t2. Quan 2\t\t\t3. Quan 3\t\t\t4. Quan 4\t   |\n");
				printf("|5. Quan 5\t\t\t6. Quan 6\t\t\t7. Quan 7\t\t\t8. Quan 8\t   |\n");
				printf("|9. Quan 9\t\t\t10. Quan 10\t\t\t11. Quan 11\t\t\t12. Quan 12\t   |\n");
				printf("|13. Quan Tan Binh\t\t14. Quan Phu Nhuan\t\t15. Quan Go Vap\t\t\t16. Quan Binh Thanh|\n");
				printf("|17. Quan Binh Tan\t\t18. Quan Tan Phu\t\t19. Quan Thu Duc\t\t20. Huyen Hoc Mon  |\n");
				printf("|21. Huyen Cu Chi\t\t22. Huyen Nha Be\t\t23. Huyen Binh Chanh\t\t24. Huyen Can Gio  |\n");
				printf("+------------------------------------------------------------------------------------------------------------------+\n");
				printf("Chon dia chi Benh nhan muon tim: ");
				scanf("%d",&input);
				
				if(input == 1){
					strcpy(diaChi,"Quan1");
				}else if(input == 2){
					strcpy(diaChi,"Quan2");
				}else if(input == 3){
					strcpy(diaChi,"Quan3");
				}else if(input == 4){
					strcpy(diaChi,"Quan4");
				}else if(input == 5){
					strcpy(diaChi,"Quan5");
				}else if(input == 6){
					strcpy(diaChi,"Quan6");
				}else if(input == 7){
					strcpy(diaChi,"Quan7");
				}else if(input == 8){
					strcpy(diaChi,"Quan8");
				}else if(input == 9){
					strcpy(diaChi,"Quan9");
				}else if(input == 10){
					strcpy(diaChi,"Quan10");
				}else if(input == 11){
					strcpy(diaChi,"Quan11");
				}else if(input == 12){
					strcpy(diaChi,"Quan12");
				}else if(input == 13){
					strcpy(diaChi,"TanBinh");
				}else if(input == 14){
					strcpy(diaChi,"PhuNhuan");
				}else if(input == 15){
					strcpy(diaChi,"GoVap");
				}else if(input == 16){
					strcpy(diaChi,"BinhThanh");
				}else if(input == 17){
					strcpy(diaChi,"BinhTan");
				}else if(input == 18){
					strcpy(diaChi,"TanPhu");
				}else if(input == 19){
					strcpy(diaChi,"ThuDuc");
				}else if(input == 20){
					strcpy(diaChi,"HocMon");
				}else if(input == 21){
					strcpy(diaChi,"CuChi");
				}else if(input == 22){
					strcpy(diaChi,"NhaBe");
				}else if(input == 23){
					strcpy(diaChi,"BinhChanh");
				}else{
					strcpy(diaChi,"CanGio");
				}
				
				TimBNtheoDiaChi(ds,diaChi);
				break;
			}			
			case 7:	kt=0;			
		}
	}
}

void CapNhapBN(LIST &ds){
	char sdt[12];
	printf("\nNhap so dien thoai Benh nhan can cap nhat: ");fflush(stdin);
	gets(sdt);
	int count = 0;
	printf("\nDanh sach BN co SDT:%s chua duoc cap nhat\n",sdt);
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
	for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.sdt, sdt)==0){
        	Xuat1BenhNhan(p);
        	count++;
        }
    }
    
    if(count==1){
		int kt=1;
		int chon;
		printf("\nCap nhat thong tin BN:");
		while(kt){
			printf("\n1. Ho ten");
			printf("\n2. Dia chi");
			printf("\n3. So dien thoai");
			printf("\n4. So BHYT");
			printf("\n5. Ngay kham");
			printf("\n6. Trang thai");
			printf("\n7. Xem thong tin sau khi cap nhat");
			printf("\nChon thong tin muon cap nhat (Nhap 8 de thoat!): ");
			scanf("%d",&chon);
			switch(chon){
				case 1:
						char hoten[30];
						printf("Nhap ho ten:");fflush(stdin);
						gets(hoten);	
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.sdt, sdt)==0){
								strcpy(p->data.hoten,hoten);
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoSDT(ds,sdt);
						XuatTuFile(ds);
						break;
				case 2:
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.sdt, sdt)==0){
								char diaChi[255];
								int input;
								printf("+------------------------------------------------------------------------------------------------------------------+\n");
								printf("|\t\t\t\tDanh sach cac quan, huyen thuoc Thanh pho Ho Chi Minh\t\t\t\t   |\n");
								printf("+------------------------------------------------------------------------------------------------------------------+\n");
								printf("|1. Quan 1\t\t\t2. Quan 2\t\t\t3. Quan 3\t\t\t4. Quan 4\t   |\n");
								printf("|5. Quan 5\t\t\t6. Quan 6\t\t\t7. Quan 7\t\t\t8. Quan 8\t   |\n");
								printf("|9. Quan 9\t\t\t10. Quan 10\t\t\t11. Quan 11\t\t\t12. Quan 12\t   |\n");
								printf("|13. Quan Tan Binh\t\t14. Quan Phu Nhuan\t\t15. Quan Go Vap\t\t\t16. Quan Binh Thanh|\n");
								printf("|17. Quan Binh Tan\t\t18. Quan Tan Phu\t\t19. Quan Thu Duc\t\t20. Huyen Hoc Mon  |\n");
								printf("|21. Huyen Cu Chi\t\t22. Huyen Nha Be\t\t23. Huyen Binh Chanh\t\t24. Huyen Can Gio  |\n");
								printf("+------------------------------------------------------------------------------------------------------------------+\n");
								printf("Chon dia chi Benh nhan muon cap nhat: ");
								scanf("%d",&input);
								
								if(input == 1){
									strcpy(diaChi,"Quan1");
								}else if(input == 2){
									strcpy(diaChi,"Quan2");
								}else if(input == 3){
									strcpy(diaChi,"Quan3");
								}else if(input == 4){
									strcpy(diaChi,"Quan4");
								}else if(input == 5){
									strcpy(diaChi,"Quan5");
								}else if(input == 6){
									strcpy(diaChi,"Quan6");
								}else if(input == 7){
									strcpy(diaChi,"Quan7");
								}else if(input == 8){
									strcpy(diaChi,"Quan8");
								}else if(input == 9){
									strcpy(diaChi,"Quan9");
								}else if(input == 10){
									strcpy(diaChi,"Quan10");
								}else if(input == 11){
									strcpy(diaChi,"Quan11");
								}else if(input == 12){
									strcpy(diaChi,"Quan12");
								}else if(input == 13){
									strcpy(diaChi,"TanBinh");
								}else if(input == 14){
									strcpy(diaChi,"PhuNhuan");
								}else if(input == 15){
									strcpy(diaChi,"GoVap");
								}else if(input == 16){
									strcpy(diaChi,"BinhThanh");
								}else if(input == 17){
									strcpy(diaChi,"BinhTan");
								}else if(input == 18){
									strcpy(diaChi,"TanPhu");
								}else if(input == 19){
									strcpy(diaChi,"ThuDuc");
								}else if(input == 20){
									strcpy(diaChi,"HocMon");
								}else if(input == 21){
									strcpy(diaChi,"CuChi");
								}else if(input == 22){
									strcpy(diaChi,"NhaBe");
								}else if(input == 23){
									strcpy(diaChi,"BinhChanh");
								}else{
									strcpy(diaChi,"CanGio");
								}
								strcpy(p->data.diachi,diaChi);
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoSDT(ds,sdt);
						XuatTuFile(ds);
						break;
				case 3:
						char newSDT[12];
						printf("Nhap so dien thoai:");fflush(stdin);
						gets(newSDT);	
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.sdt, sdt)==0){
								strcpy(p->data.sdt,newSDT);
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoSDT(ds,newSDT);
						XuatTuFile(ds);
						break;
				case 4:
						char BHYT[12];
						printf("Nhap so BHYT:");fflush(stdin);
						gets(BHYT);	
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.sdt, sdt)==0){
								strcpy(p->data.BHYT,BHYT);
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoSDT(ds,sdt);
						XuatTuFile(ds);
						break;
				case 5:
						NGAYTHANG ngaykham;
						printf("Nhap thoi gian kham:\n");fflush(stdin);
						printf("	Ngay: ");
						scanf("%d", &ngaykham.ngay);fflush(stdin);
						printf("	Thang: ");
						scanf("%d", &ngaykham.thang);fflush(stdin);
						printf("	Nam: ");
						scanf("%d", &ngaykham.nam);fflush(stdin);
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.sdt, sdt)==0){
								p->data.ngaykham.ngay=ngaykham.ngay;
								p->data.ngaykham.thang=ngaykham.thang;
								p->data.ngaykham.nam=ngaykham.nam;
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoSDT(ds,sdt);
						XuatTuFile(ds);
						break;
				case 6:{
						int input = 0;
						printf("Chon trang thai ( 1-Cho kham | 2-Noi tru | 3-Ngoai tru ): ");
						scanf("%d",&input);
						char trangthai[255];
						if(input == 1){
							strcpy(trangthai,"Chokham");
						}else if(input == 2){
							strcpy(trangthai,"Noitru");
						}else {
							strcpy(trangthai,"Ngoaitru");
						}
						
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.sdt, sdt)==0){
								strcpy(p->data.trangthai,trangthai);
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoSDT(ds,sdt);
						XuatTuFile(ds);					
						break;
					}
				case 7:
						TimBNtheoSDT(ds,sdt);
						break;
				case 8: 	kt=0;				
			}
		}
	}else{
		char hoten[30];
		printf("Nhap ho ten can tim: ");fflush(stdin);
		gets(hoten);
		printf("\nDanh sach BN co SDT:%s va ten:%s chua duoc cap nhat\n",sdt,hoten);
		TimBNtheoNameVsSDT(ds,hoten,sdt);
		
		int kt=1;
		int chon;
		printf("\nCap nhat thong tin BN:");
		while(kt){
			printf("\n1. Ho ten");
			printf("\n2. Dia chi");
			printf("\n3. So dien thoai");
			printf("\n4. So BHYT");
			printf("\n5. Ngay kham");
			printf("\n6. Trang thai");
			printf("\n7. Xem thong tin sau khi cap nhat");
			printf("\nChon thong tin muon cap nhat (Nhap 8 de thoat!): ");
			scanf("%d",&chon);
			switch(chon){
				case 1:
						char newHoten[30];
						printf("Nhap ho ten:");fflush(stdin);
						gets(newHoten);	
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.hoten, newHoten)==0){
								if(strcmp(p->data.sdt, sdt)==0){		
									strcpy(p->data.hoten,newHoten);
								}
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoNameVsSDT(ds,newHoten,sdt);
						XuatTuFile(ds);
						break;
				case 2:
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.hoten, hoten)==0){
								if(strcmp(p->data.sdt, sdt)==0){		
									char diaChi[255];
									int input;
									printf("+------------------------------------------------------------------------------------------------------------------+\n");
									printf("|\t\t\t\tDanh sach cac quan, huyen thuoc Thanh pho Ho Chi Minh\t\t\t\t   |\n");
									printf("+------------------------------------------------------------------------------------------------------------------+\n");
									printf("|1. Quan 1\t\t\t2. Quan 2\t\t\t3. Quan 3\t\t\t4. Quan 4\t   |\n");
									printf("|5. Quan 5\t\t\t6. Quan 6\t\t\t7. Quan 7\t\t\t8. Quan 8\t   |\n");
									printf("|9. Quan 9\t\t\t10. Quan 10\t\t\t11. Quan 11\t\t\t12. Quan 12\t   |\n");
									printf("|13. Quan Tan Binh\t\t14. Quan Phu Nhuan\t\t15. Quan Go Vap\t\t\t16. Quan Binh Thanh|\n");
									printf("|17. Quan Binh Tan\t\t18. Quan Tan Phu\t\t19. Quan Thu Duc\t\t20. Huyen Hoc Mon  |\n");
									printf("|21. Huyen Cu Chi\t\t22. Huyen Nha Be\t\t23. Huyen Binh Chanh\t\t24. Huyen Can Gio  |\n");
									printf("+------------------------------------------------------------------------------------------------------------------+\n");
									printf("Chon dia chi Benh nhan muon cap nhat: ");
									scanf("%d",&input);
									
									if(input == 1){
										strcpy(diaChi,"Quan1");
									}else if(input == 2){
										strcpy(diaChi,"Quan2");
									}else if(input == 3){
										strcpy(diaChi,"Quan3");
									}else if(input == 4){
										strcpy(diaChi,"Quan4");
									}else if(input == 5){
										strcpy(diaChi,"Quan5");
									}else if(input == 6){
										strcpy(diaChi,"Quan6");
									}else if(input == 7){
										strcpy(diaChi,"Quan7");
									}else if(input == 8){
										strcpy(diaChi,"Quan8");
									}else if(input == 9){
										strcpy(diaChi,"Quan9");
									}else if(input == 10){
										strcpy(diaChi,"Quan10");
									}else if(input == 11){
										strcpy(diaChi,"Quan11");
									}else if(input == 12){
										strcpy(diaChi,"Quan12");
									}else if(input == 13){
										strcpy(diaChi,"TanBinh");
									}else if(input == 14){
										strcpy(diaChi,"PhuNhuan");
									}else if(input == 15){
										strcpy(diaChi,"GoVap");
									}else if(input == 16){
										strcpy(diaChi,"BinhThanh");
									}else if(input == 17){
										strcpy(diaChi,"BinhTan");
									}else if(input == 18){
										strcpy(diaChi,"TanPhu");
									}else if(input == 19){
										strcpy(diaChi,"ThuDuc");
									}else if(input == 20){
										strcpy(diaChi,"HocMon");
									}else if(input == 21){
										strcpy(diaChi,"CuChi");
									}else if(input == 22){
										strcpy(diaChi,"NhaBe");
									}else if(input == 23){
										strcpy(diaChi,"BinhChanh");
									}else{
										strcpy(diaChi,"CanGio");
									}
									
									strcpy(p->data.diachi,diaChi);
								}
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoNameVsSDT(ds,hoten,sdt);
						XuatTuFile(ds);
						break;
				case 3:
						char newSDT[12];
						printf("Nhap so dien thoai:");fflush(stdin);
						gets(newSDT);	
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.hoten, hoten)==0){
								if(strcmp(p->data.sdt, sdt)==0){		
									strcpy(p->data.sdt,newSDT);
								}
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoNameVsSDT(ds,hoten,newSDT);
						XuatTuFile(ds);
						break;
				case 4:
						char BHYT[12];
						printf("Nhap so BHYT:");fflush(stdin);
						gets(BHYT);	
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.hoten, hoten)==0){
								if(strcmp(p->data.sdt, sdt)==0){		
									strcpy(p->data.BHYT,BHYT);
								}
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoNameVsSDT(ds,hoten,sdt);
						XuatTuFile(ds);
						break;
				case 5:
						NGAYTHANG ngaykham;
						printf("Nhap thoi gian kham:\n");fflush(stdin);
						printf("	Ngay: ");
						scanf("%d", &ngaykham.ngay);fflush(stdin);
						printf("	Thang: ");
						scanf("%d", &ngaykham.thang);fflush(stdin);
						printf("	Nam: ");
						scanf("%d", &ngaykham.nam);fflush(stdin);
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.hoten, hoten)==0){
								if(strcmp(p->data.sdt, sdt)==0){		
									p->data.ngaykham.ngay=ngaykham.ngay;
									p->data.ngaykham.thang=ngaykham.thang;
									p->data.ngaykham.nam=ngaykham.nam;
								}
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoNameVsSDT(ds,hoten,sdt);
						XuatTuFile(ds);
						break;
				case 6:{
						int input = 0;
						printf("Chon trang thai ( 1-Cho kham | 2-Noi tru | 3-Ngoai tru ): ");
						scanf("%d",&input);
						char trangthai[255];
						if(input == 1){
							strcpy(trangthai,"Chokham");
						}else if(input == 2){
							strcpy(trangthai,"Noitru");
						}else {
							strcpy(trangthai,"Ngoaitru");
						}
						
						for(NODE *p = ds.pHead; p!= NULL; p=p->next){
							if(strcmp(p->data.hoten, hoten)==0){
								if(strcmp(p->data.sdt, sdt)==0){		
									strcpy(p->data.trangthai,trangthai);
								}
							}
						}
						printf("\nThong tin BN sau khi cap nhat\n");
						TimBNtheoNameVsSDT(ds,hoten,sdt);
						XuatTuFile(ds);					
						break;
					}
				case 7:
						TimBNtheoNameVsSDT(ds,hoten,sdt);
						break;
				case 8: 	kt=0;				
			}
		}
	}
}

//void SapXep(LIST &ds){
//    NODE *p, *q;
//    for(p = ds.pHead; p != ds.pTail; p=p->next){
//        for(q = p->next; q != NULL; q = q->next){
//            if(p->data.masv > q->data.masv){
//                SV x = p->data;
//                p->data = q->data;
//                q->data = x; 
//            }
//        }
//    }
//    Xuat(ds);
//}

void XoaBN(LIST &ds){
	NODE *p = new NODE;
//	Tim SDT Can xoa
	char sdt[12];
	printf("\nNhap so dien thoai can tim: ");fflush(stdin);
	gets(sdt);
	int count = 0;
	printf("\nDanh sach BN co SDT:%s chua duoc Xoa\n",sdt);
	printf("-----------------------------------------------------------------------------------------------------------");
	printf("\n|STT|\t\tHo ten\t    |\tDia chi\t|\tSo dien thoai|\t\tBHYT  |\tNgay kham\t|Trangthai|\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
	for(NODE *p = ds.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.sdt, sdt)==0){
        	Xuat1BenhNhan(p);
        	count++;
        }
    }
	
	if(count == 1){
		int chon;
		printf("Ban co chac chan xoa Benh nhan co SDT: %s ? ( 1-YES | 2-NO ): ",sdt);
		scanf("%d",&chon);
		if(chon==1){
		    //duyet qua cac phan tu co trong danh sach
		    for(NODE *k = ds.pHead; k != NULL; k=k->next){
		        //neu tim thay data trung voi k->data dang duyet
		        if(strcmp(k->data.sdt, sdt)==0){
		            //gan con tro next cua node p bang con tro next cua node k
		            p->next = k->next;
		            //xoa di node k
		            delete k;
		        }
		        //gan node p bang node k de node p luon la node dung truoc node k
		        p = k;
		    }
			
//			Cap nhat lai so thu tu DS
			int stt = 1;
			for(NODE *f = ds.pHead; f!= NULL; f=f->next){
				f->data.STT = stt;
				stt++;
			}
			
//			Cap nhat lai File
			XuatTuFile(ds);
			printf("Xoa BN thanh cong!");
			return;	
		}else{
			printf("Xoa BN khong thanh cong!");
			return;
		}	
	}else{
		char hoten[30];
		printf("Nhap ho ten can xoa: ");fflush(stdin);
		gets(hoten);
		printf("\nDanh sach BN co SDT:%s va ten:%s chua duoc cap nhat\n",sdt,hoten);
		TimBNtheoNameVsSDT(ds,hoten,sdt);
		
		int chon;
		printf("Ban co chac chan xoa Benh nhan co SDT: %s ? ( 1-YES | 2-NO ): ",sdt);
		scanf("%d",&chon);
		if(chon==1){
		    //duyet qua cac phan tu co trong danh sach
		    for(NODE *k = ds.pHead; k != NULL; k=k->next){
		        //neu tim thay data trung voi k->data dang duyet
		        if(strcmp(k->data.hoten, hoten)==0){
			        if(strcmp(k->data.sdt, sdt)==0){
			            //gan con tro next cua node p bang con tro next cua node k
			            p->next = k->next;
			            //xoa di node k
			            delete k;
			        }
		    	}
		        //gan node p bang node k de node p luon la node dung truoc node k
		        p = k;
		    }
			
//			Cap nhat lai so thu tu DS
			int stt = 1;
			for(NODE *f = ds.pHead; f!= NULL; f=f->next){
				f->data.STT = stt;
				stt++;
			}
			
//			Cap nhat lai File
			XuatTuFile(ds);
			printf("Xoa BN thanh cong!");
			return;	
		}else{
			printf("Xoa BN khong thanh cong!");
			return;
		}
	}
	
	
}

int main(){
    LIST ds;
    int n;
	int kt=1;
	int chon;
	while(kt){
		printf("\n<------------------------------------>");
		printf("\n|      DANH SACH LIEN KET DON        |");
		printf("\n|      QUAN LY KHAM CHUA BENH        |");
		printf("\n<------------------------------------>");
		printf("\n|1. Them Benh nhan vao Danh sach     |");
		printf("\n|2. Xem toan bo Danh sach Benh nhan  |");
		printf("\n|3. Tim / Xem Danh sach Benh nhan    |");
		printf("\n|4. Nhap danh sach Benh nhan tu file |");
		printf("\n|5. Xuat danh sach Benh nhan vao file|");
		printf("\n|6. Cap nhat thong tin Benh nhan     |");
		printf("\n|7. Xoa Benh nhan khoi danh sach     |");
		printf("\n|8. Thoat!                           |");
		printf("\n<------------------------------------>");
		printf("\nGo so tuong ung chuc nang can chon:");
		scanf("%d",&chon);
		printf("--------------------------------------");
		switch(chon)
		{
			case 1:
					if(KiemTraRong(ds) == 1){
						KhoiTao(ds);
						NhapTuFile(ds);
					}
					printf("\nNhap so luong Benh nhan muon them: ");
    				scanf("%d",&n);
    				Nhap(ds,n);
					break;
			case 2:
					printf("\nDANH SACH BENH NHAN\n");
    				Xuat(ds);
					break;
			case 3:
					TimBN(ds);
					break;
			case 4:
					KhoiTao(ds);
					NhapTuFile(ds);
					break;
			case 5:
					XuatTuFile(ds);
					break;
			case 6:
					CapNhapBN(ds);
					break;
			case 7:
					XoaBN(ds);		
					break;
					
			case 8:	kt=0;															
		}
	}
}

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Book{
	char ISBN[8];
	char name[25];
	char tacgia[25];
	int namXuatBan;
	int soTrang,giaTien,soLuotban;

};

// Ham loai bo ky tu xuong dong cuoi cung neu co
void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}
//viet hoa
void vietHoa(char *str) {
    while (*str != '\0') { // lam den khi nao ket thuc
        *str = toupper(*str);
        str++;// tro den vi tri tiep theo
    }
}

void nhapSach(Book &b){
	printf("\nISBN: "); fflush(stdin); fgets(b.ISBN, sizeof(b.ISBN), stdin); xoaXuongDong(b.ISBN);
	printf("\nTen Truyen: "); fflush(stdin); fgets(b.name, sizeof(b.name), stdin); xoaXuongDong(b.name);vietHoa(b.name);
	//ham fgets de doc mot chuoi ky tu tu dau vao tieu chuan (stdin) và luu tri no vao truong Ten cua bien sv
	printf("\nTen Tac Gia: "); fflush(stdin); fgets(b.tacgia, sizeof(b.tacgia), stdin); xoaXuongDong(b.tacgia);vietHoa(b.tacgia);
	printf("\nNam Xuan Ban: "); scanf("%d", &b.namXuatBan);getchar();
	printf("\nSo Trang: "); scanf("%d", &b.soTrang);getchar();
	printf("\nGia Tien: "); scanf("%d", &b.giaTien);getchar();
	printf("\nSo luot Ban: "); scanf("%d", &b.soLuotban);getchar();
}

void capNhatbook(Book &b){
	nhapSach(b);
}
//xuat sach
void inASach(Book b){
	printf("| %-8s | %-20s | %-20s | %-8d     | %-8d | %-25d | %-25d |", b.ISBN, b.name, b.tacgia, b.namXuatBan, b.soTrang, b.giaTien, b.soLuotban);
}
//them vao sach
void nhaplistbook(Book b[], int &n){
	do{
		printf("\nNhap vao so quan truyen muon nhap: ");// so sach muon nhap
		scanf("%d",&n);
	}while(n <= 0);
	
	for(int i =0;i<n;i++){
		printf("\nNhap vao quan truyen thu %d: ",i+1);
		capNhatbook(b[i]);
	}
}

//print list co san
void xuatListbook(Book b[], int n){
	printf("| %-8s | %-20s | %-20s | %-8s | %-8s | %-25s | %-25s |","ISBN", "Ten Truyen", "Ten Tac Gia", "Nam Xuat Ban", "So Trang", "Gia Tien", "So Luot Da Ban");
		for(int i = 0;i<n;i++){
			printf("\n");
			inASach(b[i]);
		}
}
//add them sach
void themSach(Book b[], int &n) {
    printf("\nNhap thong tin cho truyen muon them:");
    capNhatbook(b[n]); 
    n++; //tang n len 1 de luu 
}
//cap nhat thong tin cho truyen
void updateSach(Book b[], int n,  char isbn[]){
	printf("\nNhap ISBN truyen muon UPDATE:");
	fflush(stdin); 
	fgets(isbn,sizeof(isbn),stdin);
	xoaXuongDong(isbn);
    int found = 0; // ktra xem co cuon sach nao dc xoa hay khong
    for (int i = 0; i < n; i++) {
        if (strstr(b[i].ISBN, isbn) != NULL) {
            found = 1; // da tim thay cuon sach can xoa
        	printf("\nISBN: "); fflush(stdin); fgets(b[i].ISBN, sizeof(b[i].ISBN), stdin); xoaXuongDong(b[i].ISBN);
			printf("\nTen Truyen: "); fflush(stdin); fgets(b[i].name, sizeof(b[i].name), stdin); xoaXuongDong(b[i].name);vietHoa(b[i].name);
			printf("\nTen Tac Gia: "); fflush(stdin); fgets(b[i].tacgia, sizeof(b[i].tacgia), stdin); xoaXuongDong(b[i].tacgia);vietHoa(b[i].tacgia);
			printf("\nNam Xuan Ban: "); scanf("%d", &b[i].namXuatBan);
			printf("\nSo Trang: "); scanf("%d%",&b[i].soTrang);
			printf("\nGia Tien: "); scanf("%d", &b[i].giaTien);
			printf("\nSo luot Ban: "); scanf("%d", &b[i].soLuotban);	
		}
	}
	if(!found){
	printf("\nKhong tim thay sach co ISBN: %s\n", isbn);
}
}

//xoa sach theo ISBN
void removeSach(Book b[], int &n, char is[]) {
    int found = 0; // ktra xem co cuon sach nao dc xoa hay khong
    for (int i = 0; i < n; i++) {
        if (strstr(b[i].ISBN, is) != NULL) {
            found = 1; // da tim thay cuon sach can xoa
            // dich chuyen cac cuon sach trong mang b sang ben trai 1 don vi
            for (int j = i; j < n - 1; j++) {
                b[j] = b[j + 1];
            }
            // giam so luong sach di 1
            n--;
            i--; // giam gia tri i di 1 sau moi lan xoa
        }
    }
    if (!found) { // neu khong tim thay sach found van se giu gia tri 0
        printf("\nKhong co cuon truyen co %s trong danh sach\n", is);
    }
}


//hoan doi vi tri
void swap(Book& a, Book& b) {
    Book temp = a;
    a = b;
    b = temp;
}

void sortbyprice(Book x[], int n){
    for (int i = 0; i < n - 1; ++i) {// duyen qua cac phan tu
        for (int j = 0; j < n - i - 1; ++j) {//so sanh va hoan doi
            if (x[j].giaTien >x[j + 1].giaTien) {
                swap(x[j], x[j + 1]);
            }
        }
    }
    printf("\nDanh sach sau khi sap xep:\n");
    printf("| %-8s | %-20s | %-20s | %-8s | %-8s | %-25s | %-25s |\n","ISBN", "Ten Truyen", "Ten Tac Gia", "Nam Xuat Ban", "So Trang", "Gia Tien", "So Luot Da Ban");
    for(int i=0;i<n;i++){
    printf("| %-8s | %-20s | %-20s | %-8d     | %-8d | %-25d | %-25d |\n", x[i].ISBN, x[i].name, x[i].tacgia, x[i].namXuatBan, x[i].soTrang, x[i].giaTien, x[i].soLuotban);
	}
}
//tim kiem theo ten
void searchbyNamebook(Book b[], int n, char Nb[]) {
    int found = 0; // bien kiem tra
    printf("\nKet qua tim kiem:\n");
    printf("| %-8s | %-20s | %-20s | %-8s     | %-8s | %-25s | %-25s |\n","ISBN", "Ten Truyen", "Ten Tac Gia", "Nam Xuat Ban", "So Trang", "Gia Tien", "So Luot Da Ban");
    for (int i = 0; i < n; i++) {
        if (strstr(b[i].name, Nb) != NULL) { // kiem tra cac phan tu trong mang
            printf("| %-8s | %-20s | %-20s | %-8d | %-8d | %-25d | %-25d |\n", b[i].ISBN, b[i].name, b[i].tacgia, b[i].namXuatBan, b[i].soTrang, b[i].giaTien, b[i].soLuotban);
            found = 1; // danh dau tim thay
        }
    }
    if (!found) { // neu khong tim thay sach
        printf("Khong co truyen ten %s trong danh sach\n", Nb);
    }
}


//xuat 3 cuon ban nhieu nhat
void inTop3booksell(Book x[], int n){
	for (int i = 0; i < n - 1; ++i) {//duyet qua cac phan tu trong mang
        for (int j = 0; j < n - i - 1; ++j) {//so sach roi hoan doi
            if (x[j].giaTien >x[j + 1].giaTien) {
                swap(x[j], x[j + 1]);
			}
		}
	}
	
	printf("\nTop 3 quan truyen ban chay nhat la:\n");
	printf("| %-8s | %-20s | %-20s | %-8s | %-8s | %-25s | %-25s |\n","ISBN", "Ten Truyen", "Ten Tac Gia", "Nam Xuat Ban", "So Trang", "Gia Tien", "So Luot Da Ban");
	for(int i=0;i<3;i++){
		printf("| %-8s | %-20s | %-20s | %-8d     | %-8d | %-25d | %-25d |\n", x[i].ISBN, x[i].name, x[i].tacgia, x[i].namXuatBan, x[i].soTrang, x[i].giaTien, x[i].soLuotban);
	}
}
//luu du lieu vao file
void chuyenDuLieuSangFile(Book b[], int n){
    char tenFile[100];
    printf("\nNhap vao ten file: ");
    fflush(stdin); 
    //Nhan ten cua file ma nguoi dung nhap tu ban phim va luu vao mang tenFile
    fgets(tenFile, sizeof(tenFile), stdin); 
    xoaXuongDong(tenFile);
    FILE *f;
    f = fopen(tenFile, "w");
    if(f == NULL){
        printf("\nLoi mo file de ghi!");
        return;
    }
   fscanf(f, "%d\n", &n);
   fprintf(f, "| %-8s | %-20s | %-20s | %-8s | %-8s | %-25s | %-25s |", "ISBN", "Ten Truyen", "Ten Tac Gia", "Nam Xuat Ban", "So Trang", "Gia Tien", "So Luot Da Ban");
    for(int i = 0; i < n; i++){
    	fprintf(f,"\n");
        fprintf(f, "%s ", b[i].ISBN);
        fprintf(f, " \t%s ", b[i].name);
        fprintf(f, " \t%s", b[i].tacgia);
        fprintf(f, " \t%d", b[i].namXuatBan);
        fprintf(f, " \t%d", b[i].soTrang);
        fprintf(f, " \t%d", b[i].giaTien);
        fprintf(f, " \t%d", b[i].soLuotban);
    }
    fclose(f);//dong tep
}
//doc du lieu tu file ra roi in
void docDuLieuTuFile(Book b[], int &n){
    char tenFile[100];//luu ten tep
    printf("\nNhap vao ten file: ");
    fflush(stdin); 
    fgets(tenFile, sizeof(tenFile), stdin); 
    xoaXuongDong(tenFile);
    FILE *f;// con tro tep
    f = fopen(tenFile, "r");
    if(f == NULL){
        printf("\nLoi mo file de doc!");
        return;//ket thuc neu ko mo dc tep
    }

    // doc so luong sach tu dong dau
	fscanf(f, "%d\n", &n);
	char line[256];
	//doc dong tieu de
    fgets(line, sizeof(line), f);
    printf("| %-8s | %-20s | %-20s | %-8s | %-8s | %-25s | %-25s |\n","ISBN", "Ten Truyen", "Ten Tac Gia", "Nam Xuat Ban", "So Trang", "Gia Tien", "So Luot Da Ban");
    
    for(int i = 0; i < n; i++){
    	//doc thong tin roi lu vao mang b
        fscanf(f, "%s %s %s %d %d %d %d", b[i].ISBN, b[i].name, b[i].tacgia, &b[i].namXuatBan, &b[i].soTrang, &b[i].giaTien, &b[i].soLuotban);
        printf("| %-8s | %-20s | %-20s | %-8d     | %-8d | %-25d | %-25d |\n", b[i].ISBN, b[i].name, b[i].tacgia, b[i].namXuatBan, b[i].soTrang, b[i].giaTien, b[i].soLuotban);
    }
    fclose(f);//dong tep
}


int main(int argc, char** argv) {
	Book b[100];
	int n=0;
	int key=0;
	
	
	do{
		
		printf("\n--------------------MENU--------------------\n");
		printf("\n1- Nhap danh sach truyen						");
		printf("\n2-  Xuat danh sach truyen						");
		printf("\n3-  Xuat danh sach truyen ban nhieu nhat		");
		printf("\n4-  Sap xep theo gia tien						");
		printf("\n5-  Them truyen								");
		printf("\n6-  Cap nhat truyen tim theo ISBN				");
		printf("\n7-  Tim truyen theo ten						");
		printf("\n8-  Xoa truyen theo ISBM						");
		printf("\n9-  Luu danh sach truyen vao file				");
		printf("\n10- Doc danh sach truyen tu file				");
		printf("\n0- Quit										");
		printf("\n----------------------------------------------");
		printf("\nLua Chon Cua Ban: ");
		scanf("%d", &key);
		switch(key){
			case 1:
				nhaplistbook(b,n);
				printf("\nNhan Enter To Continue!");
				break;
			
			case 2:
				xuatListbook(b,n);
				printf("\nNhan Enter To Continue!");
				break;
			case 3:
				inTop3booksell(b, n);
				printf("\nNhan Enter To Continue!");
				break;
			case 4:
				sortbyprice(b,n);
				printf("\nNhan Enter To Continue!");
				break;
			case 5:
				themSach(b,n);
				printf("\nNhan Enter To Continue!");
				break;
			case 6:
				char isbN[20];
				updateSach(b,n,isbN);
				printf("\nNhan Enter To Continue!");
				break;
			case 7:
				char nB[20];
				printf("\nNhap ten truyen muon tim:");
				fflush(stdin); 
				fgets(nB,sizeof(nB),stdin);
				xoaXuongDong(nB);
				vietHoa(nB);
				searchbyNamebook(b,n,nB);
				printf("\nNhan Enter To Continue!");
				break;
			case 8:
				char Is[20];
				xuatListbook(b,n);
				printf("\nNhap ISBN truyen muon tim:");
				fflush(stdin); 
				fgets(Is,sizeof(Is),stdin);
				xoaXuongDong(Is);
				removeSach(b,n,Is);
				xuatListbook(b,n);
				printf("\nNhan Enter To Continue!");
				break;
			case 9:
				chuyenDuLieuSangFile(b,n);
				printf("\nNhan Enter To Continue!");
				break;
			case 10:
				docDuLieuTuFile(b,n);
				printf("\nNhan Enter To Continue!");
				break;
			default:
				break;
		}
		
	}while(key>0 && key<11);
	
	
	return 0;
}

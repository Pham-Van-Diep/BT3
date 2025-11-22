#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char day[3];
	char month[3];
	char year[5];	
}DOB;

typedef struct{
	char id[50];
	char fullName[50];
	DOB birthday;
	char address[100];
	char phoneNumber[15];
}Student;

void enterStudent(Student *students, int *length){
	int size;
	printf("Nhap vao so luong sinh vien muon them: ");
	scanf("%d",&size);
	getchar();
	
	for(int i=0; i<size; i++){
		Student student;
		
		printf("Nhap ma sinh vien: ");
		fgets(student.id,sizeof(student.id),stdin);
		student.id[strcspn(student.id,"\n")]=0;
		
		printf("Nhap ho va ten: ");
		fgets(student.fullName,sizeof(student.fullName),stdin);
		student.fullName[strcspn(student.fullName,"\n")]=0;
		
		printf("Nhap ngay/thang/nam sinh: ");
		scanf("%2s/%2s/%4s",&student.birthday.day,&student.birthday.month,&student.birthday.year);
		getchar();
		
		printf("Nhap dia chi: ");
		fgets(student.address,sizeof(student.address),stdin);
		student.address[strcspn(student.address,"\n")]=0;
		
		printf("Nhap SDT: ");
		fgets(student.phoneNumber,sizeof(student.phoneNumber),stdin);
		student.phoneNumber[strcspn(student.phoneNumber,"\n")]=0;
		
		students[*length+i]=student;
	}
	*length+=size;
	printf("Nhap thanh cong!!!");
}

void displayStudent(Student *students, int length){
	if(length<=0){
		printf("Danh sach trong\n");
		return;
	}
	printf("________DANH SACH SINH VIEN___________\n");
	for(int i=0; i<length; i++){
		printf("ID: %s\nFULLNAME: %s\nBIRTHDAY: %s/%s/%s\nADDRESS: %s\nPHONENUMBER: %s\n",
		students[i].id,
		students[i].fullName,
		students[i].birthday.day,
		students[i].birthday.month,
		students[i].birthday.year,
		students[i].address,
		students[i].phoneNumber);
	}
	printf("\n");
}

void addLastStudent(Student *students, int *length){
    Student student;

    printf("Nhap ma sinh vien: ");
    fgets(student.id, sizeof(student.id), stdin);
    student.id[strcspn(student.id,"\n")] = 0;

    printf("Nhap ho va ten: ");
    fgets(student.fullName, sizeof(student.fullName), stdin);
    student.fullName[strcspn(student.fullName,"\n")] = 0;

    printf("Nhap ngay/thang/nam sinh (dd/mm/yyyy): ");
    scanf("%2s/%2s/%4s",student.birthday.day,student.birthday.month,student.birthday.year);
    getchar();

    printf("Nhap dia chi: ");
    fgets(student.address, sizeof(student.address),stdin);
    student.address[strcspn(student.address,"\n")] = 0;

    printf("Nhap SDT: ");
    fgets(student.phoneNumber,sizeof(student.phoneNumber),stdin);
    student.phoneNumber[strcspn(student.phoneNumber,"\n")] = 0;

    students[*length] = student;
    (*length)++;

    printf("Them thanh cong!\n");
}

void deleteStudent(Student *students, int *length){
	char id[50];
	printf("Nhap ID cua sinh vien can xoa: ");
	fgets(id,sizeof(id),stdin);
	id[strcspn(id,"\n")]=0;
	
	int pos=-1;
	for(int i=0; i<*length; i++){
		if(strcmp(students[i].id,id)==0){
		pos=i;
		break;
		}
	}
	if(pos==-1){
		printf("Khong tim thay sinh vien co %s nay\n",id);
		return;
	}
	for(int i=pos; i<*length-1; i++){
		students[i]=students[i+1];
	}
	(*length)--;
	printf("Xoa thanh cong!\n");
}

void updateStudent(Student *students, int length){
	char id[50];
	printf("Nhap vao ID can cap nhap: ");
	fgets(id,sizeof(id),stdin);
	id[strcspn(id,"\n")]=0;
	
	int pos=-1;
	for(int i=0; i<length; i++){
		if(strcmp(students[i].id,id)==0){
		pos=i;
		break;
		}
	}
	if(pos==-1){
		printf("Khong tim thay sinh vien co %s nay",id);
		return;
	}
	
	printf("=== Cap nhat thong tin moi ===\n");

    printf("Nhap ho va ten moi: ");
    fgets(students[pos].fullName, sizeof(students[pos].fullName), stdin);
    students[pos].fullName[strcspn(students[pos].fullName, "\n")] = 0;

    printf("Nhap ngay/thang/nam sinh moi: ");
    scanf("%2s/%2s/%4s",students[pos].birthday.day,students[pos].birthday.month,students[pos].birthday.year);
    getchar();

    printf("Nhap dia chi moi: ");
    fgets(students[pos].address, sizeof(students[pos].address), stdin);
    students[pos].address[strcspn(students[pos].address, "\n")] = 0;

    printf("Nhap so dien thoai moi: ");
    fgets(students[pos].phoneNumber, sizeof(students[pos].phoneNumber), stdin);
    students[pos].phoneNumber[strcspn(students[pos].phoneNumber, "\n")] = 0;

    printf("Cap nhat thanh cong!\n");
}

void arrangeStudent(Student *students, int length){
	if(length<=0){
		printf("Danh sach trong");
		return;
	}
	for(int i=0; i<length-1; i++){
		for(int j=i+1; j<length; j++){
			if(strcmp(students[i].fullName,students[j].fullName)>0){
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
	printf("Mang da duoc sap xep theo ten(A-Z)!\n");
}

void searchStudent(Student *students, int length){
	char id[50];
	printf("Nhap vao ID sinh vien muon tim: ");
	fgets(id,sizeof(id),stdin);
	id[strcspn(id,"\n")]=0;
	
	int pos=-1;
	printf("___KET QUA TIM KIEM_____\n");
	for(int i=0; i<length; i++){
		if(strcmp(students[i].id, id)==0){
			printf("ID: %s\nFULLNAME: %s\nBIRTHDAY: %s/%s/%s\nADDRESS: %s\nPHONENUMBER: %s\n",
                students[i].id,
                students[i].fullName,
                students[i].birthday.day,
                students[i].birthday.month,
                students[i].birthday.year,
                students[i].address,
                students[i].phoneNumber);
            pos=0;
            break;
		}
	}
	if(pos==-1){
		printf("Khong tim thay sinh vien co %s nay",id);
}


int main(){
	int choice=0, length=0;
	Student students[100];
	
	do{
		printf("\n************MENU**************\n");
		printf("1.Nhap thong tin sinh vien\n");
		printf("2.Hien thi thong tin sinh vien\n");
		printf("3.Them sinh vien vao cuoi danh sach\n");
		printf("4.Xoa sinh vien theo ma sinh vien\n");
		printf("5.Cap nhap thong tin theo ma sinh vien\n");
		printf("6.Sap xep sinh vien theo ho ten(A-Z)\n");
		printf("7.Tim kiem sinh vien theo ma sinh vien\n");
		printf("8.Thoat\n");
		printf("Vui long nhap vao lua chon cua ban: ");
		scanf("%d",&choice);
		getchar();
		
		switch(choice){
			case 1:{
				enterStudent(students,&length);
				break;
			}
			case 2:{
				displayStudent(students,length);
				break;
			}
			case 3:{
				addLastStudent(students,&length);
				break;
			}
			case 4:{
				deleteStudent(students,&length);
				break;
			}
			case 5:{
				updateStudent(students,length);
				break;
			}
			case 6:{
				arrangeStudent(students,length);
				break;
			}
			case 7:{
				searchStudent(students,length);
				break;
			}
			case 8:{
				printf("TAM BIET !!!!!!!!!");
				break;
			}
			default:{
				printf("VUI LONG CHON LAI !!!!!!!");
				break;
			}
		}
	}while(choice!=8);
	
}
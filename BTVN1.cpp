#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char name[50];
	int age;
	float grade;
}Student;

void enterStudent(Student *students, int *length){
	int size;
	
	printf("Nhap vao so luong hoc sinh: ");
		scanf("%d",&size);
		getchar();
		
	for(int i=0; i<size; i++){
		Student student;
		
		printf("Nhap ten hoc sinh: ");
		fgets(student.name,sizeof(student.name),stdin);
		student.name[strcspn(student.name,"\n")]=0;
		
		printf("Nhap tuoi cua hoc sinh: ");
		scanf("%d",&student.age);
		
		printf("Nhap diem cua hoc sinh: ");
		scanf("%f",&student.grade);
		getchar();
		
		students[i]=student;
	}
	*length=size;
	printf("Nhap thanh cong");
}

void displayStudent(Student *students, int length){
	if(length <= 0 ){
		printf("Danh sach hoc sinh trong \n");
		return ;
	}
	printf("______________Danh sach hoc sinh________________\n");
	for(int i = 0 ; i < length ; i++){
		printf("NAME: %s | AGE: %d | GARDE: %.2f\n",students[i].name,students[i].age,students[i].grade);
	}
	printf("\n");
}

void averageStudent(Student *students, int length){
	int sum=0;
	for(int i=0; i<length; i++){
		sum+=students[i].grade;
	}
	float average = (float)sum / length;
	printf("Trung binh tat cac hoc sinh la: %.2f",average);
}

int main(){
	int choice=0, length=0;
	Student students[100];
	do{
		printf("\n_________MENU____________\n");
		printf("1.Nhap thong tin hoc sinh\n");
		printf("2.Hien thi thong tin hoc sinh\n");
		printf("3.Tinh diem trung binh cua tat ca hoc sinh\n");
		printf("4.Thoat\n");
		printf("Vui long chon cac chuc nang 1->4: ");
		scanf("%d",&choice);
		
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
				averageStudent(students,length);
				break;
			}
			case 4:{
				printf("Tam biet!!!!");
				break;
			}
			default:{
				printf("Vui long chon lai tu 1->4!!! ");
				break;
			}
		}
	}while(choice!=4);
}
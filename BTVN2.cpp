#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char name[50];
	char phoneNumber[15];
	char email[50];
}Contact;

void enterContact(Contact *contacts, int *length){
	int size;
	printf("Nhap vao so luong muon them: ");
	scanf("%d",&size);
	getchar();
	
	for(int i=0; i<size; i++){
		Contact contact;
		
		printf("Nhap ten: ");
		fgets(contact.name,sizeof(contact.name),stdin);
		contact.name[strcspn(contact.name,"\n")]=0;
		
		printf("Nhap SDT: ");
		fgets(contact.phoneNumber,sizeof(contact.phoneNumber),stdin);
		contact.phoneNumber[strcspn(contact.phoneNumber,"\n")]=0;
		
		printf("Nhap EMAIL: ");
		fgets(contact.email,sizeof(contact.email),stdin);
		contact.email[strcspn(contact.email,"\n")]=0;
		
		contacts[*length+i]=contact;
	} 
	*length+=size;
	printf("Nhap thanh cong!");
}

void displayContact(Contact *contacts, int length){
	if(length<=0){
		printf("Trong\n");
		return;
	}
	printf("_______DANH SACH LIEN HE________\n");
	for(int i=0; i<length; i++){
		printf("NAME: %s | SDT: %s | EMAIL: %s\n",contacts[i].name,contacts[i].phoneNumber,contacts[i].email);
	}
	printf("\n");
}

void searchContact(Contact *contacts, int length){
	while(getchar()!='\n');
	char name[50];
	printf("Nhap ten muon tim: ");
	fgets(name,sizeof(name),stdin);
	name[strcspn(name,"\n")]=0;
	
	for(int i=0; i<length; i++){
		if(strcmp(contacts[i].name,name)==0){
			printf("Tim thay ten: \n");
			printf("NAME: %s | SDT: %s | EMAIL: %s\n",contacts[i].name,contacts[i].phoneNumber,contacts[i].email);
			return;
		}
	}
	printf("Khong tim thay ten: %s",name);
}

void deleteContact(Contact *contacts, int *length){
	getchar();
	char name[50];
	printf("Nhap ten muon xoa: ");
	fgets(name,sizeof(name),stdin);
	name[strcspn(name,"\n")]=0;
	
	for(int i=0; i<*length; i++){
		if(strcmp(contacts[i].name,name)==0){
			for(int j=i; j<*length-1;j++){
				contacts[j]=contacts[j+1];
			}
			(*length)--;
		}
		printf("Da xoa thanh cong!");
		return;
	}
	printf("Khong tim thay ten: %s",name);
}

int main(){
	int length=0, choice=0;
	Contact contacts[100];
	do{
		printf("\n_________MENU__________\n");
		printf("1.Them lien he moi\n");
		printf("2.Hien thi tat ca lien he\n");
		printf("3.Tim kiem theo ten\n");
		printf("4.Xoa lien he theo ten\n");
		printf("5.Thoat\n");
		printf("Vui long chon tu 1->5: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:{
				enterContact(contacts,&length);
				break;
			}
			case 2:{
				displayContact(contacts,length);
				break;
			}
			case 3:{
				searchContact(contacts,length);
				break;
			}
			case 4:{
				deleteContact(contacts,&length);
				break;
			}
			case 5:{
				printf("Tam biet!!!");
				break;
			}
			default:{
				printf("Vui long chon lai!!!!!");
				break;
			}
		}
	}while(choice!=5);
}
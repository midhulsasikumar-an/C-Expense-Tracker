#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct expense{
	char item[50];
	float amount;
};

void add_Expense(struct expense e){
	FILE *fp;
	fp = fopen("ExpenseTracker.txt","a");
	
	if(fp == NULL){
		printf("File Not Found\n");
		return;
	}
	printf("Enter the Item and Expense :");
	scanf(" %s %f",e.item,&e.amount);
	
	fprintf(fp, "%s %.2f\n", e.item, e.amount);
    fclose(fp);
	printf("Expense added successfully!\n");
}

void show_Expense(struct expense e){
	FILE *fp = fopen("ExpenseTracker.txt","r");
	
	if(fp == NULL){
		printf("No Expenses Recorded\n");
		return;
	}
	printf("----- All Expenses -----\n");
	while(fscanf(fp, "%s %f", e.item, &e.amount) != EOF) {
        printf("%s - %.2f\n", e.item, e.amount);
    }
    printf("-------------------------\n");
	fclose(fp);
}

void total_Expense(struct expense e){
	FILE *fp = fopen("ExpenseTracker.txt","r");
	float total_amount = 0;
	if(fp == NULL){
		printf("No Expenses Recorded\n");
		return;
	}
	printf("----- Total Expense -----\n");
	while(fscanf(fp, "%s %f", e.item, &e.amount) != EOF) {
        total_amount+=e.amount;
    }
    printf("Toatal Expense : %.2f\n",total_amount);
    printf("-------------------------\n");
	fclose(fp);
}

void modify_Expense(struct expense e){
	FILE *fp = fopen("ExpenseTracker.txt","r");
	FILE *tp = fopen("temp.txt","w");
	int choice;
	
	if(fp == NULL){
		printf("No Expenses Recorded\n");
		return;
	}
	printf("1.Delete\n2.Modify\n");
	printf("Enter your choice :");
	scanf("%d",&choice);
	
    int found = 0;
    char del_item[50] , old_item[50] , new_item[50];
    float new_price;
    switch(choice){
		case 1:
		    printf("Enter the item to delete :");
		    scanf("%s",del_item);
			while(fscanf(fp, "%s %f", e.item, &e.amount) != EOF) {
				if(strcmp(e.item,del_item)==0){
					found++;continue;
				}
		        fprintf(tp,"%s %.2f\n", e.item, e.amount);
		    }
		    break;
		    
		case 2:
		    printf("Enter the item to update :");
		    scanf("%s",old_item);
		    printf("Enter the new Item and Price :");
		    scanf(" %s %f",new_item,&new_price);
		    while(fscanf(fp, "%s %f", e.item, &e.amount) != EOF) {
		    	if(strcmp(e.item,old_item)==0){
					fprintf(tp,"%s %.2f\n", new_item, new_price);
					found++;continue;
				}
		        fprintf(tp,"%s %.2f\n", e.item, e.amount);
		    }
		    break;
		    
		default:
			printf("Invalid Choice");
	}
    fclose(fp);
    fclose(tp);
    if(found>0){
    	remove("ExpenseTracker.txt");
    	rename("temp.txt","ExpenseTracker.txt");
    	printf("Expense Modified\n");
	}
	else{
		printf("Item not found.Expense Not Modified\n");
	}
    
}

int main(){
	int choice;
	struct expense e;
	printf("\n----- Expense Tracker -----\n");
	do{
		printf("1.Add Expenses\n");
		printf("2.Show Expenses\n");
		printf("3.Total Expenses\n");
		printf("4.Delete or Update Expense\n");
		printf("5.Exit\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				add_Expense(e);
				break;
				
			case 2:
				show_Expense(e);
				break;
				
			case 3:
				total_Expense(e);
				break;
				
			case 4:
				modify_Expense(e);
				break;
				
			case 5:
				printf("Exiting....Thankyou for using");
				break;
			
			default:
				printf("Invalid Choice\n");
				break;
		}
	}
	while(choice!=5);
	return 0;
}

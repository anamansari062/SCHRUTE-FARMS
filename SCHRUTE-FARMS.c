#include<stdio.h>
#include<stdlib.h>

void add_item();
void option();
void title_add_item();
void product_list();
void bill();
int final_total= 0;   //This variable stores final total of cart


void menu()  //This is the main menu of system
{
	system("clear");
	printf("-------------------------------------------\n");
	printf("\tWelcome To Schrute Farms\n");
	printf("\t  By Dwight Schrute\n");
    printf("-------------------------------------------\n\n");
	printf("Menu \n1. Press A to place an order \n2. Press P to see products list \n3. Press E to exit \n");
	option();
}
	
void option()  //This function executes options selected in menu and product list
{
	char opt;
	scanf("%s", &opt);
	switch (opt){
		case 'E':
		case 'e':
			{system("clear");
			break;}
		case 'P':
		case 'p':
			{product_list();
			break;}
		case 'A':
		case 'a':
			{title_add_item();
			break;}
		default:
		    {
			char buf;
			printf("Enter valid options \nPress any key to start again\n");
			scanf("%c",&buf);
			menu();
			break;}
		}
}

void title_add_item()  //This function prints Title of cart and triggers add_item() function
{	
	system("clear");
	printf("1. Press C to print bill \n2. Press P to display product list \n3. Press E to exit \n");
	printf("----------------------------------------------------- \n");
	printf("                    SCHRUTE FARMS                         ");
	printf("\n----------------------------------------------------- \n");
	printf("ITEM NO     PRODUCT NAME      RATE    Quantity  Total\n ");
	add_item();
}

void add_item()  //This function adds items to the cart and prints total of each item
{
	int a,b,rate, qt, total;
   char  n, prod[20], line[30];
    scanf("%s",&n);
    switch(n){
	    case 'C':
	    case 'c': 
			bill();
			break;
		case 'P':
		case 'p':
			product_list();
			break;
		case 'E':
		case 'e':
			system("clear");
			break;
		}
	FILE *fp;
	fp = fopen("/home/anam/Documents/STUDY/PPS/IA/PPS_PROJECT/Shop_data", "r");
	while(fscanf(fp,"%d;%d;%s", &a,&rate,prod)){
		b= n- '0';
		if (a==b)
		{
			printf("\r%20s %12d\t",prod,rate);
		    scanf("%d",&qt);
	        total= qt*rate;
	        final_total = final_total + total;
	        printf("-->%50d\n", total);
		    add_item();
		}
	}
}

void product_list()  //This function displays product list
{
	system("clear");
	char ch;
   FILE *fp;


   fp = fopen("/home/anam/Documents/STUDY/PPS/IA/PPS_PROJECT/Product_list", "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

 
   while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

   fclose(fp);
   printf("\n1. Press A to place an order \n2. Press E to exit\n");
   option();
   
}

void bill()  //This function prints bill
{   
	printf("----------------------------------------------------- \n");
	printf("\a%53d\n", final_total);
	printf("----------------------------------------------------- \n");
	printf("\nTHANK YOU FOR SHOPPING WITH US!!\n");
	printf("PLEASE COME BACK SOON!!\n");
	return;
}


int main()
{
	menu();
	return 0;
}
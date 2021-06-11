#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct employee
{
     int id;
	int age;
    char address[10];
    char name[40];
    
    float salary;
};
    struct employee s;
    
    
    void display_record();
    void insert_record();
    void search_record();
    void del_record();
    void update_record();
    void loginCheck();
    void empmgmt();
    
    
     int main(){
    	loginCheck();
    	return;
	}
    
    
    
    
    void loginCheck(){
	char name[20], ch, password[15], i = 0;
	int t, h, k;
	puts("\n \t \t\t Log In");
	puts("\n Enter Employee ID:");
	scanf("%s", &name);

	puts("\n");
	puts("Enter password:");

	while (ch != 13)
	{
		ch = getch();
		if (ch != 13 && ch != 8)
		{
			putch('*');
			password[i] = ch;
			i++;
		}
	}

	password[i] = '\0';

	//Comparing password
	if (strcmp(password, "pass123") == 0 && strcmp(name, "Admin") == 0){
		empmgmt();
	}
    else
    printf("Incorrect Password");
}
    

void empmgmt()
{	system("cls");
	int ch;
    while(ch!=7)
    {
    	//
    printf("\t***********************************************\n");
    printf("\t\tWELCOME TO employee MANAGEMENT PROGRAM\n");
    printf("\t***********************************************\n\n\n");

        printf("\t**** AVAILABLE FUNCTIONALITIES ****\n\n\n");
        printf("\t\t1: Insert employee record\n");
        printf("\t\t2: Display employee record\n");
        printf("\t\t3: Search employee record\n");
        printf("\t\t4: Delete employee record\n");
        printf("\t\t5: Update employee record\n");
        printf("\t\t:6 Exit\n\n");
        printf("\t\tEnter your choice : ");
        scanf("%d",&ch);
    	 switch(ch)
        {
            case 1:
            	system("cls");
                insert_record();
                break;
            case 2:
            	system("cls");
            display_record();
                break;

            case 3:
            	system("cls");
            search_record();
                break;
            case 4:
            	system("cls");
            del_record();
                break;
            case 5:
            	system("cls");
            update_record();
                break;
            
            case 6: exit(0);
            default:
                printf("\n\t\tWrong choice Entered");
        }
        printf("\n\t\tPress any key to continue ");
        getch();
    }  
}

void display_record()
{
    FILE *fp;
    fp=fopen("stu.txt","rb");

    if(fp==NULL)
    {
        printf("\n\t\tError : Cannot open the File !!!");
        return;
    }

    printf("\n\n\t **** Students Details Are As Follows ****\n");
   // printf("\nID.No\tName of employee\tAddress\t\tAge\t\tSalary\n\n"); 
	printf("\nID\t\t Name of employee\t\t Adress\t\t  Age\t\t Salary\n\n");
    //printf("a.students roll number\t b.employee name\t c.employee section\t d.employee marks\t e.employee grade");
    while(fread(&s,sizeof(s),1,fp)>0)
    {
    	 //printf("%d\t%s\t%s  \t\t%d\t\t%.2f\n",s.id,s.name,s.address,s.age,s.salary);
    	  printf("\n %d\t\t %s\t\t\t %s\t\t %d\t\t %.2f\n ",s.id,s.name,s.address,s.age,s.salary);
    }
    fclose(fp);
}

void insert_record()
{
	
    FILE *fp;

    fp=fopen("stu.txt","ab+");

    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    //printf("\t **** Previous Stored Data ****");
    //display_record();
    printf("\n\n\t**** ENTER NEW employee DATA ****\n\n");
    printf("\n\t\tEnter employee ID Number: ");
    scanf("%d",&s.id);
    fflush(stdin);
    printf("\n\t\tEnter employee Name: ");
    gets(s.name);
    printf("\n\t\tEnter employee Address: ");
    gets(s.address);
    printf("\n\t\tEnter employee Age: ");
    scanf("%d",&s.age);
    printf("\n\t\tEnter employee Salary: ");
    scanf("%f",&s.salary);
    fwrite(&s,sizeof(s),1,fp);

    {
        printf("\n\n\t !!! employee Record Inserted Sucessfully\n");
    }
    fclose(fp);
    //printf("\n\t\t Updated Record !!\n");
   // display_record();
}

void search_record()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter employee ID Number Which You Want To Search: ");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0)
    {
        if(s.id==ro)
        {
       
        printf("\n\n\tSearch Sucessfull And employee Records Is as Follows: \n\n");
        printf("\nID.No\tName of employee\tAddress\t\tAge\t\tSalary\n\n");
       printf("%d\t%s\t%s  \t\t%d\t\t%f\n",s.id,s.name,s.address,s.age,s.salary);
        return;
        }
    }
    if(flag==0)
    {
    printf("\n\n\t\tNo Such Record Found !!!!!\n");
    }
fclose(fp);
}

void del_record()
{
    int ro,flag=0;
    FILE *fp,*ft;
    fp=fopen("stu.txt","rb");
    ft=fopen("stu1.txt","ab+");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\t **** Previous Stored Data ****");
    display_record();
    printf("\n\n\tEnter employee ID Which You Want to Delete ");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0)
    {
        if(s.id==ro)
        {
        
        printf("\n\t\tRecord Deleted Sucessfully \n");
        
        }
        else
        {
        fwrite(&s,sizeof(s),1,ft);
        }
    }
    if(flag==0)
    {
    printf("\n\n\t\tNo Such Record Found !!!");
    }
    fclose(fp);
    fclose(ft);
    remove("stu.txt");
    rename("stu1.txt","stu.txt");
    //printf("\n\t\t Updated Record !!\n");
   // display_record();
}

void update_record()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","rb+");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open the File!!!");
        return;
    }
    printf("\n\n\tEnter Roll Number of employee Whose Record You Want To Update: ");
    scanf("%d",&ro);
    //printf("\n\t\t*** Previously Stored Record Of Given Roll Number ***");

    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.id==ro)
        {
        flag=1;
        //printf("\nRoll.No\tName of employee\tSection\t\tMarks\t\tGrade\n\n");
       // printf("%d\t%s\t%s  \t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
        printf("\n\t\t*** Now Enter the New Record ***\n\n");

         printf("\n\t\tEnter updated employee ID Number: ");
    scanf("%d",&s.id);
    fflush(stdin);
    printf("\n\t\tEnter updated employee Name: ");
    gets(s.name);
    printf("\n\t\tEnter updated employee Address: ");
    gets(s.address);
    printf("\n\t\tEnter updated employee Age: ");
    scanf("%d",&s.age);
    printf("\n\t\tEnter updated employee Salary: ");
    scanf("%f",&s.salary);
        fseek(fp,-(long)sizeof(s),1);
        fwrite(&s,sizeof(s),1,fp);
        printf("\n\n\t\tRecord Updated Successfully Check The Display Section!!\n\t\t");
        }
    }
    if(flag==0)
    {
        printf("\n\t\tError : Something went wrong!!!");
    }
fclose(fp);
}
/*
void sort_record()
{
    struct employee temp;
    struct employee arr[50];

    int i,j,k=0;
    FILE *fp;
    fp=fopen("stu.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\tError: Cannot Open File !!!\n");
    }
    i=0;

    while(fread(&arr[i],sizeof(arr[i]),1,fp)==1)
    {
         i++;k++;
    }

    for(i=0;i<k;i++)
        {
        for(j=0;j<k-i-1;j++)
         {
            if(arr[j].roll>arr[j+1].roll)
             {
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
             }
          }
        }
        printf("\n\t\tAfter Sorting employee Details !!\n\n");
        for(i=0;i<k;i++)
        {
           printf("%d\t\t%s\t\t%s\t\t%d\t\t%f\n",arr[i].roll,arr[i].name,arr[i].sec,
           arr[i].marks,arr[i].grade);
        }
    fclose(fp);
}*/

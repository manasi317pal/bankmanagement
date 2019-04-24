#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int i,j;
int exit_menu;
void menu();

struct date{
    int day, month, year;
};
struct {
    char name[30];
    int age, acc_number;
    char acc_type[10];
    char citizenship[20];
    char address[30];
    float amount;
    double phone;
    struct date dob;
    struct date deposit;
    struct date withdraw;
}add, upd, check, rem, transaction;

float interest(float t, float p, int r)
{
    float SI;
    SI=(p*r*t)/100;
    return SI;
}

void fordelay(int i)
{
    int j;
    for(j=0;j<i;j++);
}

void close(void)
{
    printf("\n\n\n\nDo visit again\a\n");
}
void new_account()
{
    int choice;
    FILE *ptr;

    ptr=fopen("file1.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_number);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_number==add.acc_number)
            {
                printf("Entered account no. already in use! \a");
                fordelay(100000000);
                goto account_no;

            }
    }
    add.acc_number=check.acc_number;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:Rs.");
    scanf("%f",&add.amount);
    printf("\nType of account:\n\t-Saving\n\t-Current\n\t-Fixed1(for 1 year)\n\t-Fixed2(for 2 years)\n\t-Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\nAccount created successfully!");
    invalid_entry:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&exit_menu);
    system("cls");
    if (exit_menu==1)
            menu();
    else if(exit_menu==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto invalid_entry;
        }
}
void view_details()
{
    FILE *view;
    view=fopen("file1.dat","r");
    int test=0;
    system("cls");
    printf("\nACC.NO.\t\t\tNAME\t\t\tADDRESS\t\t\tPHONE\t\t\tCitizenship\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_number,add.name,add.address,add.phone,add.citizenship);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS IN THE FILE!!\a\n");}

    invalid_view:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_menu);
        system("cls");
        if (exit_menu==1)
            menu();
        else if(exit_menu==0)
            close();
        else
        {
            printf("\nInvalid Entry!\a");
            goto invalid_view;
        }
}

void edit_details(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("file1.dat","r");
    newrec=fopen("file2.dat","w");

    printf("\nEnter the account no. of the customer:");
    scanf("%d",&upd.acc_number);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_number==upd.acc_number)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice:");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved successfullu!\a");
                }
            else if(choice==2)
                {
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved successfully!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("file1.dat");
    rename("file2.dat","file1.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            invalid_input:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&exit_menu);
              system("cls");
                 if (exit_menu==1)
                    menu();
                else if (exit_menu==2)
                    close();
                else if(exit_menu==0)
                    edit_details();
                else
                    {printf("\nInvalid!\a");
                    goto invalid_input;}
        }
else
        {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_menu);
        system("cls");
        if (exit_menu==1)
            menu();
        else
            close();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("file1.dat","r");
    newrec=fopen("file2.dat","w");
    printf("Enter the account no.:");
    scanf("%d",&transaction.acc_number);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_number==transaction.acc_number)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nWhat do you want to do? \n1.Deposit\n2.Withdraw?\n\nEnter your choice:");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:Rs.");
                    scanf("%f",&transaction.amount);
                    add.amount+=transaction.amount;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!\a");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:Rs. ");
                    scanf("%f",&transaction.amount);
                    add.amount-=transaction.amount;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!\a");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("file1.dat");
   rename("file2.dat","file2.dat");
   if(test!=1)
   {
      printf("\n\nRecord not found!!\a");
      invalid_transcation:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&exit_menu);
      system("cls");
      if (exit_menu==0)
        transact();
    else if (exit_menu==1)
        menu();
    else if (exit_menu==2)
        close();
    else
    {
        printf("\nInvalid!\a");
        goto invalid_transcation;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_menu);
        system("cls");
        if (exit_menu==1)
            menu();
        else
            close();
   }

}
void remove_acc(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("file1.dat","r");
    newrec=fopen("file2.dat","w");
    printf("Enter the account no. of the customer:");
    scanf("%d",&rem.acc_number);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_number!=rem.acc_number)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {
            test++;
            printf("\nRecord deleted successfully!\a\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("file1.dat");
   rename("file2.dat","file1.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&exit_menu);

                 if (exit_menu==1)
                    menu();
                else if (exit_menu==2)
                    close();
                else if(exit_menu==0)
                    remove_acc();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_menu);
        system("cls");
        if (exit_menu==1)
            menu();
        else
            close();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("file1.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\n Enter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_number);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_number==check.acc_number)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_number,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amount,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_number,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amount,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                    }

            }
        }
    }
    fclose(ptr);
    if(test!=1)
    {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            invalid_search:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&exit_menu);
              system("cls");
                 if (exit_menu==1)
                    menu();
                else if (exit_menu==2)
                    close();
                else if(exit_menu==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto invalid_search;
                    }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_menu);
        if (exit_menu==1)
        {
            system("cls");
            menu();
        }

        else
           {
            system("cls");
            close();
           }
    }
}

void menu(void)
{   int choice;
    system("cls");
    system("color 79");
    printf("\n\n\t\t\tBANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\tEnter your choice\n");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update address/phone_no of an existing account\n\t\t3.Do transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's details\n\t\t7.Exit\n\t\t");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_account();
        break;
        case 2:edit_details();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:remove_acc();
        break;
        case 6:view_details();
        break;
        case 7:close();
        break;

    }
}

int main()
{
    char pass[10],password[10]="manasi";
    int i=0;
    printf("\n\nEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            try_again:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&exit_menu);
            if (exit_menu==1)
                    {

                        system("cls");
                        main();
                    }

            else if (exit_menu==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto try_again;}

        }
        return 0;
}

//______________________________________________________________________________________________________
//______________________________________________________________________________________________________
//Header files used in our project
//______________________________________________________________________________________________________

#include<iostream>
#include<cstdio>
#include <fstream>
#include<stdlib.h>
#include<simplecpp>
#include<cmath>

//______________________________________________________________________________________________________
//open variables
//______________________________________________________________________________________________________

using namespace std;

int count;
FILE * fp;//declaring a pointer to a file

//______________________________________________________________________________________________________



//______________________________________________________________________________________________________
//Structure used in our project
//______________________________________________________________________________________________________
struct customer
{
    int Account_num;
    int PIN;
    float Balance;
    char Name[50];
    char DOB[11];//dd/mm/yyyy
    char Address[70];//Maximum 70 characters


    void create_account()
    {
            cout<<"Please fill the following form:"<<endl;//storing information filled by customer in a temporary object c

            cout<<"Enter your name(Upto maximum 50 characters): "<<endl;
            cin.clear();
            cin.sync();
            cin.getline(Name,50);
TryAgain19:
            cout<<"Enter date of birth(dd/mm/yyyy format): "<<endl;
            cin.clear();
            cin.sync();
            cin.getline(DOB,11);

            if((DOB[2]!='/')||(DOB[5]!='/'))
            {
                cout<<"You have not entered date of birth in the given format"<<endl;
                cout<<"Please re-enter it in the given format "<<endl;

                system("pause");
                system("cls");

                goto TryAgain19;

            }

            cout<<"Enter complete residential address(Upto maximum 70 characters in a single line): ";
            cin.clear();
            cin.sync();
            cin.getline(Address,70);

TryAgain3://label
            cout<<"Enter a new PIN(4 digits) for your account"<<endl;
            cin>>PIN;

            if((PIN>9999)||(PIN<1000))//Invalid input
            {
                system("cls");
                cout<<"Invalid input"<<endl;
                goto TryAgain3;//Re-enter a new PIN
            }
            system("cls");

            cout<<"Re-Enter PIN:"<<endl;
            int p;
            cin>>p;

            if(p!=PIN)//Invalid re-entering
            {
                system("cls");
                cout<<"The two PINs entered by you don't match"<<endl;
                cout<<"Please try again "<<endl;
                goto TryAgain3;//Try entering new PIN again
            }
TryAgain12:
            cout<<"Enter Initial balance in the account: "<<endl;
            cin>>Balance;

            if(Balance<1000)
            {
                cout<<"Any Account must have a minimum balance of 1000"<<endl;
                system("pause");
                system("cls");
                goto TryAgain12;
            }

            Account_num=count+1000;

            system("cls");

            cout<<"Account created successfully "<<endl;


            Text t(175,200," Your account number is ");
            Text t1(175,290,Account_num);



            Rectangle button(175,400,150,50);
            Text t2(175,400," OK ");
            button.setFill(true);
            button.setColor(COLOR(255,255,153));


TryAgain30:

            int clickpos = getClick();
            int cx = clickpos/65536;
            int cy = clickpos%65536;




            if((cx>=100)&&(cx<=250)&&(cy>=375)&&(cy<=425))
            {
                button.setFill(true);
                button.setColor(COLOR("red"));
                wait(0.25);
                button.setColor(COLOR(255,255,153));
                wait(0.25);

                system("cls");

                return;


            }

            else
            {
                goto TryAgain30;
            }





    }//end of create_account

    void deposit_account()
    {
        float amount;
        system("cls");
        cout<<"Enter the amount to be deposited"<<endl;
        cin>>amount;

        Balance=Balance+amount;
    }//end of deposit_account()

    void withdrawal_account()
    {
        float amount;
TryAgain13:
        system("cls");
        cout<<"Enter the amount to withdraw"<<endl;
        cin>>amount;

        if((Balance-amount)<1000)
            {
                cout<<"Any Account must have a minimum balance of 1000"<<endl;
                system("pause");
                system("cls");
                goto TryAgain13;
            }

        Balance=Balance-amount;
    }//end of withdrawal_account()

    void view_account()
    {
        cout<<"Name\t:\t"<<Name<<endl;
        cout<<"Date of birth\t:\t"<<DOB<<endl;
        cout<<"Residential address\t:\t"<<Address<<endl;
        cout<<"Current balance\t:\t"<<Balance<<endl<<endl<<endl;
    }//end of view_account()

    void modify_account()
    {

TryAgain8 :

    system("cls");

    Rectangle button(175,81,150,70);
        Text t(175,81," Name ");
        button.setFill(true);
        button.setColor(COLOR(255,255,153));

        Rectangle button1(175,187,150,70);
        Text t1(175,187," Date of birth ");
        button1.setFill(true);
        button1.setColor(COLOR(255,255,153));

        Rectangle button2(175,293,150,70);
        Text t2(175,293," Residential Address ");
        button2.setFill(true);
        button2.setColor(COLOR(255,255,153));

         Rectangle button3(175,399,150,70);
        Text t3(175,399," PIN ");
        button3.setFill(true);
        button3.setColor(COLOR(255,255,153));

        int clickpos = getClick();
    int cx = clickpos/65536;
    int cy = clickpos%65536;




        if((cx>=100)&&(cx<=250)&&(cy>=46)&&(cy<=106))
        {
        button.setFill(true);
        button.setColor(COLOR("red"));
        wait(0.25);
        button.setColor(COLOR(255,255,153));
        wait(0.25);

        Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));


        cout<<"Enter your new name(Upto maximum 50 characters): "<<endl;
        cin.clear();
        cin.sync();

        cin.getline(Name,50);

        return;

        }



        if((cx>=100)&&(cx<=250)&&(cy>=152)&&(cy<=222))
        {
        button1.setFill(true);
        button1.setColor(COLOR("red"));
        wait(0.25);
        button1.setColor(COLOR(255,255,153));
        wait(0.25);

        Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));


       TryAgain20:
            cout<<"Enter new date of birth(dd/mm/yyyy format): "<<endl;
            cin.clear();
            cin.sync();
            cin.getline(DOB,11);

             if((DOB[2]!='/')||(DOB[5]!='/'))
            {
                cout<<"You have not entered date of birth in the given format"<<endl;
                cout<<"Please re-enter it in the given format "<<endl;

                system("pause");
                system("cls");

                goto TryAgain20;

            }

             return;

        }



        if((cx>=100)&&(cx<=250)&&(cy>=258)&&(cy<=328))
        {
        button2.setFill(true);
        button2.setColor(COLOR("red"));
        wait(0.25);
        button2.setColor(COLOR(255,255,153));
        wait(0.25);

        Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));


        cout<<"Enter new complete residential address(Upto maximum 70 characters in a single line): ";
        cin.clear();
        cin.sync();
        cin.getline(Address,70);

         return;

        }



        if((cx>=100)&&(cx<=250)&&(cy>=364)&&(cy<=434))
        {
        button3.setFill(true);
        button3.setColor(COLOR("red"));
        wait(0.25);
        button3.setColor(COLOR(255,255,153));
        wait(0.25);

        Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));


        TryAgain6 :
            int pin;
            cout<<"Enter current PIN : "<<endl;
            cin>>pin;

            if(PIN!=pin)
            {
                cout<<"You have entered incorrect PIN"<<endl;
                cout<<"Please try again"<<endl;
                system("pause");
                system("cls");
                goto TryAgain6;
            }
TryAgain7://label
            system("cls");
            cout<<"Enter a new PIN(4 digits) for your account"<<endl;
            cin>>PIN;

            if((PIN>9999)||(PIN<1000))//Invalid input
            {
                system("cls");
                cout<<"Invalid input"<<endl;
                goto TryAgain7;//Re-enter a new PIN
            }
            system("cls");

            cout<<"Re-Enter PIN:"<<endl;
            int p;
            cin>>p;

            if(p!=PIN)//Invalid re-entering
            {
                system("cls");
                cout<<"The two PINs entered by you don't match"<<endl;
                cout<<"Please try again "<<endl;
                goto TryAgain7;//Try entering new PIN again
            }

             return;


        }

        else
        {
           goto  TryAgain8;
        }

    }//End of modify_account()

    void delete_account()
    {

        Text t(175,81," Name ");

        Name[0]='-';Name[1]='\0';
        DOB[0]='-';DOB[1]='\0';
        Address[0]='-';Address[1]='\0';

        PIN =0;
        Balance=0;

    }//end of delete_account()

    void loan_account()
    {
        int year;float principal,amount;



        cout<<"Enter the amount to be taken as loan "<<endl;
        cin>>principal;

        cout<<"Enter the time in years to take the loan "<<endl;
        cout<<"(You can take only for integral number of years"<<endl;
        cout<<"Our interest rate is only 10% per annum )"<<endl;
        cin>>year;

        amount=principal*(pow(1.1,year));

        system("cls");

        Text t(175,55," You will have to repay ");
        Text t3(75,115,amount);
        Text t4(150,115," after ");
        Text t5(225,115,year);
        Text t6(300,115," years ");
        Text t7(175,225," Confirm ? ");

        Rectangle button1(175,315,150,70);
        Text t1(175,315," Yes ");
        button1.setFill(true);
        button1.setColor(COLOR(255,255,153));

        Rectangle button2(175,425,150,70);
        Text t2(175,425," No ");
        button2.setFill(true);
        button2.setColor(COLOR(255,255,153));
TryAgain31:
        int clickpos = getClick();
        int cx = clickpos/65536;
        int cy = clickpos%65536;

    if((cx>=100)&&(cx<=250)&&(cy>=280)&&(cy<=350))//yes
    {

    button1.setFill(true);
    button1.setColor(COLOR("red"));
    wait(0.25);
    button1.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));

    Balance=Balance+principal;

    system("cls");

    cout<<"Loan received successfully "<<endl;

    return;

    }

    if((cx>=100)&&(cx<=250)&&(cy>=390)&&(cy<=460))//no
    {
    button2.setFill(true);
    button2.setColor(COLOR("red"));
    wait(0.25);
    button2.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));

    return;

    }

    else
    {
        goto TryAgain31;
    }


    }//end of loan_account()

    void fixeddeposit_account()
    {
        int year;float principal,amount;


TryAgain18:
        cout<<"Enter the amount to be given as fixed deposit "<<endl;
        cin>>principal;

        cout<<"Enter the time in years to keep fixed deposit "<<endl;
        cout<<"(You can take only for integral number of years"<<endl;
        cout<<"You will get profit of 8% per annum )"<<endl;
        cin>>year;

        amount=principal*(pow(1.08,year));

         system("cls");

        Text t(175,55," You will get ");
        Text t3(75,115,amount);
        Text t4(150,115," after ");
        Text t5(225,115,year);
        Text t6(300,115," years ");
        Text t7(175,225," Confirm ? ");

        Rectangle button1(175,315,150,70);
        Text t1(175,315," Yes ");
        button1.setFill(true);
        button1.setColor(COLOR(255,255,153));

        Rectangle button2(175,425,150,70);
        Text t2(175,425," No ");
        button2.setFill(true);
        button2.setColor(COLOR(255,255,153));
TryAgain32:
        int clickpos = getClick();
        int cx = clickpos/65536;
        int cy = clickpos%65536;

    if((cx>=100)&&(cx<=250)&&(cy>=280)&&(cy<=350))//yes
    {

    button1.setFill(true);
    button1.setColor(COLOR("red"));
    wait(0.25);
    button1.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));

    if((Balance-principal)<1000)
            {
                cout<<"Any Account must have a minimum balance of 1000"<<endl;
                system("pause");
                system("cls");
                goto TryAgain18;
            }
            Balance=Balance-principal;

            system("cls");

            cout<<"Fixed deposit created successfully "<<endl;

    return;

    }

    if((cx>=100)&&(cx<=250)&&(cy>=390)&&(cy<=460))//no
    {
    button2.setFill(true);
    button2.setColor(COLOR("red"));
    wait(0.25);
    button2.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));

    return;

    }

    else
    {
        goto TryAgain32;
    }


        cout<<amount<<"will be deposited in your account after "<<year<<" years "<<endl;
        cout<<"Enter Y/y to proceed or enter N/n  to go back "<<endl;
        char w;

        cin>>w;

        if((w=='Y')||(w=='y'))
        {
            if((Balance-principal)<1000)
            {
                cout<<"Any Account must have a minimum balance of 1000"<<endl;
                system("pause");
                system("cls");
                goto TryAgain18;
            }
            Balance=Balance-principal;

            system("cls");

            cout<<"Fixed deposit created successfully "<<endl;
        }


        else
        {
            return;
        }

    }//end of fixeddeposit_account()


};//end of structure customer

//______________________________________________________________________________________________________



//______________________________________________________________________________________________________
//Open functions and some more variables
//______________________________________________________________________________________________________
customer c;

int rec_size=sizeof(struct customer);//getting size of above structure

void create_acc()
{
     fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    long POS;//to denote position in the current file

     fseek ( fp , 0 , SEEK_END );//Set cursor to the end of the file
     POS=ftell(fp);
     count=POS/rec_size;

     c.create_account();

     fseek ( fp , 0 , SEEK_END );
     fwrite(&c,rec_size,1,fp);

     fclose(fp);
     return;
}//end of create_acc

void deposit_acc(long POS)
{
    fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    fseek(fp,POS,SEEK_SET);
    fread(&c,rec_size,1,fp);//reading record into c

    c.deposit_account();


    fseek(fp,POS,SEEK_SET);//taking back to same position for update of record
    fwrite(&c,rec_size,1,fp);//updating record

    system("cls");

    cout<<"Your account was credited successfully."<<endl;
    fclose(fp);

}//end of deposit_acc

void withdrawal_acc(long POS)
{
    fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    fseek(fp,POS,SEEK_SET);
    fread(&c,rec_size,1,fp);//reading record into c

    c.withdrawal_account();


    fseek(fp,POS,SEEK_SET);//taking back to same position for update of record
    fwrite(&c,rec_size,1,fp);//updating record

    system("cls");

    cout<<"Your account was debited successfully."<<endl;
    fclose(fp);

}//end of withdrawal_acc()

void view_acc(long POS)
{
    fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    fseek(fp,POS,SEEK_SET);
    fread(&c,rec_size,1,fp);//reading record into c

    c.view_account();

    fclose(fp);
}//end of view_acc

void modify_acc(long POS)

{

    fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    fseek(fp,POS,SEEK_SET);
    fread(&c,rec_size,1,fp);//reading record into c

    c.modify_account();

    fseek(fp,POS,SEEK_SET);//taking back to same position for update of record
    fwrite(&c,rec_size,1,fp);//updating record

    system("cls");

    cout<<"Your account was modified successfully."<<endl;
    fclose(fp);
}//end of modify_acc()

void delete_acc(long POS)
{
    fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    fseek(fp,POS,SEEK_SET);
    fread(&c,rec_size,1,fp);//reading record into c

    c.delete_account();

    fseek(fp,POS,SEEK_SET);//taking back to same position for update of record
    fwrite(&c,rec_size,1,fp);//updating record

    system("cls");

    cout<<"Your account was deleted successfully."<<endl;
    fclose(fp);
}//end of delete_acc()

void transfer_acc(long POS)
{
    long pos;
    fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    fseek(fp,POS,SEEK_SET);
    fread(&c,rec_size,1,fp);//reading record into c

    int amount,acc_no1;
TryAgain21:
    system("cls");

    cout<<"Enter the account number of the account to which money is to be transferred"<<endl;
    cin>>acc_no1;

    if(acc_no1==(1000+POS/rec_size))
    {
        cout<<"You cant enter your own account number for transfer "<<endl;
        cout<<"Please enter correct information "<<endl;

        system("pause");
        goto TryAgain21;
    }


    fseek ( fp , 0 , SEEK_END );//Set cursor to the end of the file
    pos=ftell(fp);
    count=pos/rec_size;

    if((acc_no1>(count+1000))||(acc_no1<1000))
    {
        cout<<"You have entered incorrect account number"<<endl;
        cout<<"Please try again"<<endl;

        system("pause");
        goto TryAgain21;
    }



TryAgain15:
    cout<<"Enter the amount to be transferred :"<<endl;
    cin>>amount;

    if((c.Balance-amount)<1000)
    {
            cout<<"Any Account must have a minimum balance of 1000"<<endl;
            system("pause");
            system("cls");
            goto TryAgain15;
    }


    c.Balance=c.Balance-amount;

    fseek(fp,POS,SEEK_SET);//taking back to same position for update of record
    fwrite(&c,rec_size,1,fp);//updating record

    customer c1;

    long POS1;//to store position of the record of account to which transfer is being done

    POS1=(acc_no1-1000)*rec_size;

    fseek(fp,POS1,SEEK_SET);
    fread(&c1,rec_size,1,fp);//reading record into c1

    c1.Balance=c1.Balance+amount;

    fseek(fp,POS1,SEEK_SET);
    fwrite(&c1,rec_size,1,fp);

    system("cls");
    cout<<"Your transfer was done successfully."<<endl;
    fclose(fp);
}//end of transfer_acc()

void loan_acc(long POS)
{
    system("cls");
    fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    fseek(fp,POS,SEEK_SET);
    fread(&c,rec_size,1,fp);//reading record into c

    c.loan_account();


    fseek(fp,POS,SEEK_SET);//taking back to same position for update of record
    fwrite(&c,rec_size,1,fp);//updating record

    fclose(fp);

}//end of loan_acc()

void fixeddeposit_acc(long POS)
{
     system("cls");
    fp=fopen("customers_data.txt","rb+");

     if(fp==NULL)//Unable to open the file
    {
        cout<<"Could not open database file"<<endl;
        return;
    }//end of if

    fseek(fp,POS,SEEK_SET);
    fread(&c,rec_size,1,fp);//reading record into c

    c.fixeddeposit_account();


    fseek(fp,POS,SEEK_SET);//taking back to same position for update of record
    fwrite(&c,rec_size,1,fp);//updating record


    fclose(fp);

}//end of fixeddeposit_acc()

//______________________________________________________________________________________________________


//______________________________________________________________________________________________________
//main function of our program
//______________________________________________________________________________________________________
main_program
{


   initCanvas("Controller",350,510);

   Rectangle Erase1(175,255,350,510);
    Erase1.setFill(true);
   Erase1.setColor(COLOR(255,255,153));


   Text t7(175,175,"WELCOME");
   Text t8(175,250,"TO   THE");
   Text t9(175,325,"BANK      MANAGEMENT     SYSTEM");

   wait(3);

   Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));



TryAgain10:

    Rectangle button(175,125,150,50);
    Text t(175,125," Log In ");
    button.setFill(true);
    button.setColor(COLOR(255,255,153));

    Rectangle button1(175,275,150,50);
    Text t1(175,275," Create New Account ");
    button1.setFill(true);
    button1.setColor(COLOR(255,255,153));

    Rectangle button2(175,425,150,50);
    Text t2(175,425," View all accounts ");
    button2.setFill(true);
    button2.setColor(COLOR(255,255,153));

    int clickpos = getClick();
    int cx = clickpos/65536;
    int cy = clickpos%65536;

    system("cls");

    if((cx>=100)&&(cx<=250)&&(cy>=100)&&(cy<=150))//log in
    {
    button.setFill(true);
    button.setColor(COLOR("red"));
    wait(0.25);
    button.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
   Erase.setColor(COLOR(255,178,102));


    int acc_no,pin;

TryAgain4:
        system("cls");
        cout<<"Enter account no. :"<<endl;
        cin.clear();
        cin.sync();
        cin>>acc_no;




        cout<<"Enter PIN :"<<endl;
        cin.clear();
        cin.sync();
        cin>>pin;

        fp=fopen("customers_data.txt","rb+");

        if(fp==NULL)//Unable to open the file
        {
            cout<<"Could not open database file"<<endl;
            return -1;
        }//end of if

        struct customer c;
        int n;
        long POS;//to denote position in the current file
        POS=(acc_no-1000)*rec_size;
        fseek(fp,POS,SEEK_SET);
        fread(&c,rec_size,1,fp);

        if (c.PIN!=pin)
        {
            cout<<"You have provided a wrong information"<<endl;
            cout<<"Please try again"<<endl;
            system("pause");
            system("cls");
            goto TryAgain4;

        }

        //log in successfull
        system("cls");

TryAgain11:

    Rectangle button(100,65,100,70);
    Text t(100,65," Deposit ");
    button.setFill(true);
   button.setColor(COLOR(255,255,153));

    Rectangle button1(100,165,100,70);
    Text t1(100,165," Withdrawal ");
    button1.setFill(true);
    button1.setColor(COLOR(255,255,153));

    Rectangle button2(100,265,100,70);
    Text t2(100,265," Transfer ");
    button2.setFill(true);
    button2.setColor(COLOR(255,255,153));

    Rectangle button3(100,365,100,70);
    Text t3(100,365," View ");
    button3.setFill(true);
   button3.setColor(COLOR(255,255,153));

    Rectangle button4(250,265,100,70);
    Text t4(250,265," Modify ");
    button4.setFill(true);
    button4.setColor(COLOR(255,255,153));

    Rectangle button5(250,365,100,70);
    Text t5(250,365," Delete ");
    button5.setFill(true);
    button5.setColor(COLOR(255,255,153));

    Rectangle button6(175,460,150,60);
    Text t6(175,460," Log Out ");
    button6.setFill(true);
    button6.setColor(COLOR(255,255,153));

    Rectangle button10(250,65,100,70);
    Text t10(250,65," Loan ");
    button10.setFill(true);
    button10.setColor(COLOR(255,255,153));

    Rectangle button11(250,165,100,70);
    Text t11(250,165," Fixed Deposit ");
    button11.setFill(true);
    button11.setColor(COLOR(255,255,153));

    int clickpos = getClick();
    int cx = clickpos/65536;
    int cy = clickpos%65536;

    if((cx>=50)&&(cx<=150)&&(cy>=30)&&(cy<=100))//deposit
    { button.setFill(true);
    button.setColor(COLOR("red"));
    wait(0.25);
    button.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));

    deposit_acc(POS);

    goto TryAgain11;


    }
    if((cx>=50)&&(cx<=150)&&(cy>=130)&&(cy<=200))//withdrawal
    { button1.setFill(true);
    button1.setColor(COLOR("red"));
    wait(0.25);
    button1.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
   Erase.setColor(COLOR(255,178,102));

    withdrawal_acc(POS);

    goto TryAgain11;


    }
    if((cx>=50)&&(cx<=150)&&(cy>=230)&&(cy<=300))//Transfer
    { button2.setFill(true);
    button2.setColor(COLOR("red"));
    wait(0.25);
    button2.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));

    transfer_acc(POS);

    goto TryAgain11;


    }
    if((cx>=50)&&(cx<=150)&&(cy>=330)&&(cy<=400))//View
    { button3.setFill(true);
    button3.setColor(COLOR("red"));
    wait(0.25);
    button3.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
   Erase.setColor(COLOR(255,178,102));

    view_acc(POS);

    goto TryAgain11;



    }
    if((cx>=200)&&(cx<=300)&&(cy>=230)&&(cy<=300))//Modify
    {
    button4.setFill(true);
    button4.setColor(COLOR("red"));
    wait(0.25);
    button4.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
     Erase.setColor(COLOR(255,178,102));
    modify_acc(POS);

    goto TryAgain11;


    }

    if((cx>=200)&&(cx<=300)&&(cy>=30)&&(cy<=100))//Loan
    {
    button10.setFill(true);
    button10.setColor(COLOR("red"));
    wait(0.25);
    button10.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
   Erase.setColor(COLOR(255,178,102));

    loan_acc(POS);

    goto TryAgain11;


    }

    if((cx>=200)&&(cx<=300)&&(cy>=130)&&(cy<=200))//FD
    {
    button11.setFill(true);
    button11.setColor(COLOR("red"));
    wait(0.25);
    button11.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
   Erase.setColor(COLOR(255,178,102));

    fixeddeposit_acc(POS);

    goto TryAgain11;


    }
    if((cx>=200)&&(cx<=300)&&(cy>=330)&&(cy<=400))//Delete
    {
    button5.setFill(true);
    button5.setColor(COLOR("red"));
    wait(0.25);
    button5.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
   Erase.setColor(COLOR(255,178,102));
TryAgain16:
    system("cls");

        Text t(175,150," Confirm deletion ");

        Rectangle button1(175,285,150,70);
    Text t1(175,285," Yes ");
    button1.setFill(true);
    button1.setColor(COLOR(255,255,153));

    Rectangle button2(175,415,150,70);
    Text t2(175,415," No ");
    button2.setFill(true);
    button2.setColor(COLOR(255,255,153));

    int clickpos = getClick();
    int cx = clickpos/65536;
    int cy = clickpos%65536;

    if((cx>=100)&&(cx<=250)&&(cy>=250)&&(cy<=320))//yes
    {
    button1.setFill(true);
    button1.setColor(COLOR("red"));
    wait(0.25);
    button1.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));

    delete_acc(POS);
    goto TryAgain10;

    }

    if((cx>=100)&&(cx<=250)&&(cy>=380)&&(cy<=450))//no
    {
    button2.setFill(true);
    button2.setColor(COLOR("red"));
    wait(0.25);
    button2.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
    Erase.setColor(COLOR(255,178,102));

    goto TryAgain11;

    }

    else
    {
        goto TryAgain16;
    }









    }//end of delete


    if((cx>=100)&&(cx<=250)&&(cy>=430)&&(cy<=490))//Logout
    {
    button6.setFill(true);
    button6.setColor(COLOR("red"));
    wait(0.25);
    button6.setColor(COLOR(255,255,153));
    wait(0.25);

    Rectangle Erase(175,255,350,510);
    Erase.setFill(true);
       Erase.setColor(COLOR(255,178,102));

    system("cls");

    goto TryAgain10;
    }

    else
    {
        goto TryAgain11;
    }



    }//end of log in button



    if((cx>=100)&&(cx<=250)&&(cy>=250)&&(cy<=300))//create new account button pressed
    {
         button1.setFill(true);
        button1.setColor(COLOR("red"));
        wait(0.25);
        button1.setColor(COLOR(255,255,153));
        wait(0.25);

            Rectangle Erase(175,255,350,510);
            Erase.setFill(true);
               Erase.setColor(COLOR(255,178,102));

            create_acc();

            system("cls");

            goto TryAgain10;
    }//end of button create new account

    if((cx>=100)&&(cx<=250)&&(cy>=400)&&(cy<=450))//view all accounts
    {
        button2.setFill(true);
        button2.setColor(COLOR("red"));
        wait(0.25);
        button1.setColor(COLOR(255,255,153));

        wait(0.25);
        Rectangle Erase(175,255,350,510);
        Erase.setFill(true);
          Erase.setColor(COLOR(255,178,102));

        fp=fopen("customers_data.txt","rb+");

        if(fp==NULL)//Unable to open the file
        {
            cout<<"Could not open database file"<<endl;
            return 0;
        }//end of if

        long POS;//to denote position in the current file

        fseek ( fp , 0 , SEEK_END );//Set cursor to the end of the file
        POS=ftell(fp);
        count=POS/rec_size;
        int i;

        for(i=0;i<count;i++)
        {
            POS=i*rec_size;
            fseek(fp,POS,SEEK_SET);
            fread(&c,rec_size,1,fp);

            cout<<endl<<endl<<"Account number : "<<(1000+i)<<endl;

            view_acc(POS);


        }

        goto TryAgain10;


    }//end of view all accounts

    else
    {
        goto TryAgain10;
    }

}//end of main

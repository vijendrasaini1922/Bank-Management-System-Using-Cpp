// Bank Management system

#include <iostream>
#include <cstdio>
//#include <stdbool.h>

using namespace std;
// Global declarations
int I = 0;

struct node
{
    int account_no;
    char name[20];
    char age[20];
    char mobile_no[13];
    char email[20];
    char address[20];
    int current_balance;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

// function prototype
void starSeparator();
void dotSeparator();
bool inputAccountNo(char operation);
struct node *searchAccount(int key);
void newAccount();
void accountInfo(int key);
void currentBalance(int key);
void cashWithdrawl(int key);
void addMoney(int key);
void editAccountDetails(int key);
void deleteAccount(int key);
void display_list();

//***Main Function***
int main()
{
    starSeparator();
    printf("ACCESS KEYS FOR SERVICES\n");
    dotSeparator();
    printf("Q : Exit\n");
    printf("N : Open New Account\n");
    printf("I : Search your account details\n");
    printf("B : Current Balance\n");
    printf("C : Cash Withdrawl\n");
    printf("A : Add Money\n");
    printf("E : Edit Account Details\n");
    printf("R : Delete Account\n");
    printf("D : Account Details List\n");

    char operation('0');
    while (operation != 'Q')
    {
        starSeparator();
        int key(0);
        cout << " Enter the operation: ";
        cin >> operation;
        dotSeparator();

        if (inputAccountNo(operation) == true)
        {
            cout << "Enter your account number: ";
            cin >> key;
        }

        // Switch loop for all operation
        switch (operation)
        {
        case 'Q':
            return 0;
        case 'N':
            newAccount();
            break;
        case 'I':
            accountInfo(key);
            break;
        case 'B':
            currentBalance(key);
            break;
        case 'C':
            cashWithdrawl(key);
            break;
        case 'A':
            addMoney(key);
            break;
        case 'E':
            editAccountDetails(key);
            break;
        case 'R':
            deleteAccount(key);
            break;
        case 'D':
            display_list();
            break;
        default:
            cout << "!!!Enter the correct operation!!!" << endl;
            cin.ignore(operation, '\n');
            break;
        }
    }
    return 0;
}

//**********************Function definitions****************************
void display_list()
{
    if (head == NULL)
    {
        cout << "!!!There is no account in Bank!!!\n";
        return;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    int sno = 0;
    cout << "************************Account Details*****************************\n";
    // cout << "\t\tS.No.\tAcc. No.\tFirst Name\tBalance\n";
    cout << "     S.No.     Acc. No.     First Name       Balance\n";

    while (temp != NULL)
    {
        // cout << "\t\t" << ++sno << "\t" << temp->account_no << "\t\t" << temp->name << "\t\t" << temp->current_balance << endl;
        printf("     %.5d     %.8d     ", ++sno, temp->account_no);

        int i{0};
        for (i; i < 12; i++)
        {
            if (temp->name[i] == '\0')
                break;
            printf("%c", temp->name[i]);
        }
        for (i; i < 12; i++)
        {
            printf(" ");
        }
        printf("     %d\n", temp->current_balance);
        temp = temp->next;
    }
}

bool inputAccountNo(char operation)
{
    if (operation == 'I' || operation == 'B' || operation == 'C' ||
        operation == 'A' || operation == 'E' || operation == 'R')
    {
        return true;
    }
    return false;
}

void starSeparator()
{
    printf("\n\n********************************************************************\n");
}

void dotSeparator()
{
    cout << "........................................\n";
}

struct node *searchAccount(int key)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while (temp)
    {
        if (key == temp->account_no)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void newAccount()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;

    // user input for account details
    newNode->account_no = 111110 + I++;
    cout << " Enter First Name    : ";
    cin >> newNode->name;
    cout << " Enter age           : ";
    cin >> newNode->age;
    cout << " Mobile No           : ";
    cin >> newNode->mobile_no;
    cout << " Email-id            : ";
    cin >> newNode->email;
    cout << " Enter your city     : ";
    cin >> newNode->address;
    cout << " Enter amount adding : ";
    cin >> newNode->current_balance;

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        cout << "\n!!!Hurray!!!\nNow you are member of our bank!!\n";
        return;
    }
    tail->next = newNode;
    tail = newNode;
    cout << "\n!!!Hurray!!!\nNow you are member of our bank!!\n";
}

void accountInfo(int key)
{
    struct node *account_info_node = NULL;
    account_info_node = searchAccount(key);

    if (account_info_node == NULL)
    {
        cout << "!!! OOPS !!! \nNo account exist with account number :" << key << endl;
        return;
    }

    cout << "\n***********************Account Details***************************\n";
    cout << "Name             : " << account_info_node->name << endl;
    cout << "Age              : " << account_info_node->age << endl;
    cout << "Mobile No        : " << account_info_node->mobile_no << endl;
    cout << "Email            : " << account_info_node->email << endl;
    cout << "Address          : " << account_info_node->address << endl;
    cout << "Current Balance  : " << account_info_node->current_balance << endl;
}

void currentBalance(int key)
{
    struct node *temp = NULL;
    temp = searchAccount(key);

    if (temp == NULL)
    {
        cout << "!!! OOPS !!!\n No Data found for Account No : " << key << endl;
    }
    cout << "Name             : " << temp->name << endl;
    cout << "Current Balance  : " << temp->current_balance << endl;
}

void cashWithdrawl(int key)
{
    struct node *temp = NULL;
    int curr_balance(0);

    temp = searchAccount(key);
    if (temp == NULL)
    {
        cout << "!!! OOPS !!! \nNo account exist with Account No. : " << key << endl;
        return;
    }

    cout << "Name                 : " << temp->name << endl;
    cout << "Current Balance      : " << temp->current_balance << endl;

    int cash_withdraw(0);
    cout << "Enter Withdrawl Money : ";
    cin >> cash_withdraw;

    curr_balance = temp->current_balance - cash_withdraw;
    temp->current_balance = curr_balance;
    cout << "Current Balance      : " << temp->current_balance << endl;
    cout << "!!! Money Withdrawl Successfully Completed !!!\n";
    cout << "!!! Thank you !!! for using our system !!\n";
}

void addMoney(int key)
{
    struct node *temp = NULL;
    temp = searchAccount(key);
    if (temp == NULL)
    {
        cout << "!!! OOPS !!! \nNo data found for Account No. : " << key << endl;
        return;
    }

    cout << "Name                 : " << temp->name << endl;
    cout << "Current Balance      : " << temp->current_balance << endl;

    int add_money(0);
    cout << "Enter Amount  Adding : ";
    cin >> add_money;
    temp->current_balance += add_money;
    cout << "Current Balance      : " << temp->current_balance << endl;
    cout << "!!! Amount Added Successfully !!!\n";
}

void editAccountDetails(int key)
{
    struct node *temp = NULL;
    temp = searchAccount(key);

    if (temp == NULL)
    {
        cout << "!!! OOPS !!! \nNo Data found for Account No. :" << key << endl;
        return;
    }

    cout << "For Edit details following option are here:\n";
    cout << "1 : Name\n2 : Age\n3 : Mobile No.\n4 : Email-Id\n5 : Address\n6 : Quit\n";

    int oper;
    while (oper != 6)
    {
        cout << "Enter the operation for Edit details: ";
        cin >> oper;
        dotSeparator();
        switch (oper)
        {
        case 1:
            cout << "Enter New Name       : ";
            cin >> temp->name;
            break;
        case 2:
            cout << "Enter New Age        : ";
            cin >> temp->age;
            break;
        case 3:
            cout << "Enter New Mobile No  :";
            cin >> temp->mobile_no;
            break;
        case 4:
            cout << "Enter New Email      : ";
            cin >> temp->email;
            break;
        case 5:
            cout << "Enter New Address    : ";
            cin >> temp->address;
            break;
        case 6:
            return;
        default:
            cout << "!!Enter the correct operation!!" << endl;
            return;
        }
    }
    cout << "!! Account Details Successfully Updated !!\n";
}

void deleteAccount(int key)
{
    struct node *temp, *temp2, *temp3;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    temp2 = searchAccount(key);
    temp3 = NULL;

    if (temp2 == NULL)
    {
        cout << "No account exist with Account No. : " << key << endl;
        return;
    }

    if (temp2 == head)
    {
        head = temp2->next;
    }
    else
    {
        while (temp != temp2)
        {
            temp3 = temp;
            temp = temp->next;
        }
        temp3->next = temp->next;
    }
    cout << "Your account deleted successfully!!\n";
}
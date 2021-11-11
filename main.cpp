// Bank Management system

#include <iostream>
#include <cstdio>
//#include <stdbool.h>

using namespace std;

// Global declarations
int I {0};

// Structure for an Account
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

// Function Prototypes
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

/***MAIN FUNCTION***/
int main()
{
    starSeparator();
    printf(" ACCESS KEYS FOR SERVICES\n");
    dotSeparator();
    printf(" Q : Exit\n");
    printf(" N : Open New Account\n");
    printf(" I : Search your account details\n");
    printf(" B : Current Balance\n");
    printf(" C : Cash Withdrawl\n");
    printf(" A : Add Money\n");
    printf(" E : Edit Account Details\n");
    printf(" R : Delete Account\n");
    printf(" D : Account Details List\n");
    starSeparator();

    char operation{'0'};
    while (operation != 'Q')
    {
        int key {0};
        cout << " Enter the operation: ";
        cin >> operation;
        starSeparator();

        if (inputAccountNo(operation) == true)
        {
            cout << " Enter your account number: ";
            cin >> key;
        }

        // Switch loop for all operation
        switch (operation)
        {
        case 'Q': // Quit
            return 0;
        case 'N': // New Account
            newAccount();
            starSeparator();
            break;
        case 'I': // Display Account Information
            accountInfo(key);
            starSeparator();
            break;
        case 'B': // Display Current Balance
            currentBalance(key);
            starSeparator();
            break;
        case 'C': // Cash Withdraw
            cashWithdrawl(key);
            starSeparator();
            break;
        case 'A': // Add Money
            addMoney(key);
            starSeparator();
            break;
        case 'E': // Edit Account Details
            editAccountDetails(key);
            starSeparator();
            break;
        case 'R': // Delete Account
            deleteAccount(key);
            starSeparator();
            break;
        case 'D': // Display Accounts List
            display_list();
            starSeparator();
            break;
        default:
            cout << " !!!Enter the correct operation!!!" << endl;
            cin.ignore(operation, '\n');
            break;
        }
    }
    return 0;
}

//**********************Function definitions****************************

// Display list of all accounts
void display_list()
{
    if (head == NULL)
    {
        cout << " !!!There is no account in Bank!!!\n";
        return;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    int sno {0};
    cout << "********************* -- Account  Details -- *********************\n\n";
    cout << "     S.No.     Acc. No.     First Name       Balance\n";

    while (temp != NULL)
    {
        printf("     %.5d     %.8d     ", ++sno, temp->account_no);

        int i{0};
        for (; i < 12; i++)
        {
            if (temp->name[i] == '\0')
                break;
            printf("%c", temp->name[i]);
        }
        for (; i < 12; i++)
        {
            printf(" ");
        }
        printf("     %d\n", temp->current_balance);
        temp = temp->next;
    }
}

// Switch Account Number Input
bool inputAccountNo(char operation)
{
    if (operation == 'I' || operation == 'B' || operation == 'C' ||
        operation == 'A' || operation == 'E' || operation == 'R')
    {
        return true;
    }
    return false;
}

// Seaparate a section with a '*' line
// 70 '*' count
void starSeparator()
{
    printf("\n******************************************************************\n\n");
}

// Seaparate a sub section with a '.' line
// 50 '.' count
void dotSeparator()
{
    cout << "................................................\n";
}

// Search Account
// returns NULL if not found
struct node *searchAccount(int key)
{
    struct node *temp;
    temp = head;
    while (temp)
    {
        if (key == temp->account_no)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Create an Account
void newAccount()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;

    // user input for account details
    newNode->account_no = 729780 + I++;
    cout << " Enter First Name         : ";
    cin >> newNode->name;
    cout << " Enter age                : ";
    cin >> newNode->age;
    cout << " Mobile No                : ";
    cin >> newNode->mobile_no;
    cout << " Email-id                 : ";
    cin >> newNode->email;
    cout << " Enter your city          : ";
    cin >> newNode->address;
    cout << " Enter amount to be added : ";
    cin >> newNode->current_balance;

    if (tail == NULL) // First account in the bank
    {
        head = newNode;
        tail = newNode;

        dotSeparator();
        cout << "Name                      : " << newNode->name << "\n";
        cout << " Your New Account No. is  : " << newNode->account_no << "\n";
        dotSeparator();

        cout << "\n !!! Hurray !!!\n Now you are member of our bank!!\n";
        return;
    }
    tail->next = newNode;
    tail = newNode;

    dotSeparator();
    cout << " Name                      : " << newNode->name << "\n";
    cout << " Your New Account No. is  : " << newNode->account_no << "\n";
    dotSeparator();
    cout << "\n !!! Hurray !!!\n Now you are member of our bank!!\n";
}

// Display an Account
void accountInfo(int key)
{
    struct node *account_info_node = NULL;
    account_info_node = searchAccount(key);

    if (account_info_node == NULL)
    {
        cout << "!!! OOPS !!! \nNo account exist with account number :" << key << endl;
        return;
    }

    cout << "\n********************* -- Account  Details -- *********************\n\n";
    cout << "Name             : " << account_info_node->name << endl;
    cout << "Age              : " << account_info_node->age << endl;
    cout << "Mobile No        : " << account_info_node->mobile_no << endl;
    cout << "Email            : " << account_info_node->email << endl;
    cout << "Address          : " << account_info_node->address << endl;
    cout << "Current Balance  : " << account_info_node->current_balance << endl;
}

// Display Current Balance
void currentBalance(int key)
{
    struct node *temp = NULL;
    temp = searchAccount(key);

    if (temp == NULL) // Account doesn't exist
    { 
        cout << " !!! OOPS !!!\n No Data found for Account No : " << key << "\n";
    }
    cout << " Name             : " << temp->name << endl;
    cout << " Current Balance  : " << temp->current_balance << endl;
}

// Withdraw Cash from account
void cashWithdrawl(int key)
{
    struct node *temp = NULL;

    temp = searchAccount(key);
    if (temp == NULL) // Account doesn't exist
    {
        cout << " !!! OOPS !!! \nNo account exist with Account No. : " << key << endl;
        return;
    }

    cout << " Name                 : " << temp->name << "\n";
    cout << " Current Balance      : " << temp->current_balance << "\n";

    int cash_withdraw {0};
    cout << "\n Enter Withdrawl Money : ";
    cin >> cash_withdraw;

    temp->current_balance -= cash_withdraw;
    cout << "!!! Money Withdrawl Successfully Completed !!!\n";
    cout << "!!! Thank you !!! for using our system !!!\n";
}

// Add Money to account
void addMoney(int key)
{
    struct node *temp = NULL;
    temp = searchAccount(key);
    if (temp == NULL) // Account does NOT exist
    {
        cout << " !!! OOPS !!! \nNo data found for Account No. : " << key << "\n";
        return;
    }

    cout << " Name                 : " << temp->name << "\n";
    cout << " Current Balance      : " << temp->current_balance << "\n";

    int add_money{0};
    cout << " Enter Amount to be Added : ";
    cin >> add_money;
    temp->current_balance += add_money;
    cout << " !!! Amount Added Successfully !!!\n";
    cout << " !!! Thank you !!! for using our system !!!\n";
}

// Edit Account Details
void editAccountDetails(int key)
{
    struct node *temp = NULL;
    temp = searchAccount(key);

    if (temp == NULL) // Account does NOT exist
    {
        cout << " !!! OOPS !!! \nNo Data found for Account No. :" << key << endl;
        return;
    }

    cout << " Access keys to edit details :\n";
    cout << " 1 : Name\n 2 : Age\n 3 : Mobile No.\n 4 : Email-Id\n 5 : Address\n 6 : Quit\n";

    int oper {0};
    while (oper != 6)
    {
        cout << "\n";
        dotSeparator();
        cout << " Enter an operation to Edit : ";
        cin >> oper;
        dotSeparator();
        cout << "\n";

        switch (oper)
        {
        case 1:
            cout << " Enter New Name       : ";
            cin >> temp->name;
            break;
        case 2:
            cout << " Enter New Age        : ";
            cin >> temp->age;
            break;
        case 3:
            cout << " Enter New Mobile No  :";
            cin >> temp->mobile_no;
            break;
        case 4:
            cout << " Enter New Email      : ";
            cin >> temp->email;
            break;
        case 5:
            cout << "Enter New Address    : ";
            cin >> temp->address;
            break;
        case 6:
            break;
        default:
            cout << " !!Enter the correct operation!!" << "\n";
        }
    }
    cout << " !! Account Details Successfully Updated !!\n";
}

// Delete Account
void deleteAccount(int key)
{
    struct node *temp, *temp2;
    temp = head;
    temp2 = searchAccount(key);

    if (temp2 == NULL) // Account does NOT exist
    {
        cout << " No account exist with Account No. : " << key << endl;
        return;
    }

    if (temp2 == head)
    {
        head = temp2->next;
        free(temp2);
    }
    else
    {
        while (temp->next != temp2)
        {
            temp = temp->next;
        }
        temp->next = temp2->next;
        free(temp2);
    }
    cout << " Your account deleted successfully!!\n";
}
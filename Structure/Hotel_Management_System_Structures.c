#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 2

// Defining a structure for Inventry
struct inventry
{
    char item_name[30];
    char user[30];
    int rooms;
};

struct cust_data
{
    unsigned int room_no;
    char name[50];
    char package_chosen[30];
} Customer[4][7];

struct Employee
{
    char name[50];
    int empID;
    int salary;
    char designation[50];
};

struct food{
    char dish[max];
    int p[max];
}f1,f2,f3,f4;

struct fdbck
{
    char fb[100];
    int star, flg;
} feed[4][7];

// initialization of Structure for inventry
struct inventry l[100];
char ar_nm[30], item_nm[30];
int i = 0;
int keepcount = 0;

// All the function created
void inPut() {
    printf("Enter item name = ");
    scanf("%s", l[i].item_name);

    printf("Enter user name = ");
    scanf("%s", l[i].user);

    printf("Enter rooms = ");
    scanf("%d", &l[i].rooms);

    printf("Please verify the input");

    keepcount++;
}

int write()
{
    int f, r, op;
    printf("Enter guest's floor number: ");
    scanf("%d", &f);
    printf("Enter guest's room number: ");
    scanf("%d", &r);
    if (f > 3 || r > 6)
    {
        printf("\n\tInvalid floor or room number!");
        return 0;
    }
    if (feed[r][f].flg == 1)
    {
        printf("\nReview already taken!");
        printf("\nDo you wish to rewrite? ");
        printf("\nEnter '0' for YES '1' for NO: ");
        scanf("%d", &op);
        if (op == 1)  
            return 0;
    }
    printf("Please enter rating out of 5: ");
    scanf("%d", &feed[f][r].star);
    if (feed[f][r].star < 0 || feed[f][r].star > 5)
    {
        printf("\n\tInvalid rating!");
        return 0;
    }
    printf("Please write a review: ");
    scanf("%s", feed[f][r].fb);
    feed[f][r].flg = 1;
    return 0;
}

int view()
{
    int i, j, k, cnt = 0;
    printf("\nFloor\t\tRoom\t\tReview\t\tRating");
    for (i = 0; i < 4; i++)
        for (j = 0; j < 7; j++)
            if (feed[i][j].flg == 1)
            {
                cnt++;
                printf("\n%d\t\t%d\t\t%s\t\t", i, j, feed[i][j].fb);
                for (k = 0; k < feed[i][j].star; k++)
                    printf("%c", '*');
            }
    if (cnt == 0)
        printf("\nNO Reviews received yet!");
    return 0;
}

void feedback()
{
    int ch = 0, f, r, i, j;

    while (ch != 3)
    {
        printf("\n\tFEEDBACK...");
        printf("\n1. Write");
        printf("\n2. View");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            write();
            ch = 0;
            break;

        case 2:
            view();
            ch = 0;
            break;

        default:
            printf("\n\tINVALID!");
        }
    }
}

void AddData(int i, int j, int rn, char name[], char package_chosen[])
{
    if(Customer[i][j].room_no == 0){
        Customer[i][j].room_no = rn;
        strcpy(Customer[i][j].name, name);
        strcpy(Customer[i][j].package_chosen, package_chosen);
        printf("\nName:%s\nPackage:%s\nRoom Number:%d",Customer[i][j].name,Customer[i][j].package_chosen,Customer[i][j].room_no);
        printf("\nChecked In!!\n\n");
    }
    else
    {
        printf("Room is currently occupied by %s\n",Customer[i][j].name);
    }
}

void InsertData(int room_no, char name[], char package_chosen[])
{
    if(package_chosen == "Deluxe")
    {
        if(room_no-100<=7 && room_no-100>0)
        {
            AddData(0, room_no - 101, room_no, name, "Deluxe");
        }
        else
        {
            printf("No room number with Entry %d\n",room_no);
        }
    }
    else if(package_chosen == "Premium")
    {
        if(room_no-200<=7 && room_no-200>0)
        {
            AddData(1, room_no - 201, room_no, name, "Premium");
        }
        else
        {
            printf("No room number with Entry %d\n",room_no);
        }
    }
    else if(package_chosen == "Regular")
    {
        if(room_no-300<=7 && room_no-300>0)
        {
            AddData(2, room_no - 301, room_no, name, "Regular");
        }
        else
        {
            printf("No room number with Entry %d\n",room_no);
        }
    }
    else if(package_chosen == "Regular with A\\C")
    {
        if(room_no-400<=7 && room_no-400>0)
        {
            AddData(3, room_no - 401, room_no, name, "Regular with A\\C");
        }
        else
        {
            printf("No room number with Entry %d\n",room_no);
        }
    }
}

struct cust_data DefaultStructures(struct cust_data customer)
{
    customer.room_no = 0;
    strcpy(customer.name, "NotSet");
    strcpy(customer.package_chosen, "Default");
    return customer;
}

void Display() {
    printf("you have entered the following information\n");
    printf("----------------------------------------------\n");
    printf("item name \tuser name \troom No.\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < keepcount; i++)
    {
        printf("%s", l[i].item_name);
        printf("\t\t %s", l[i].user);
        printf("\t\t %d", l[i].rooms);
        printf("\n");
    }
}

void itemOfUser() {
    printf("Enter user name : ");
    scanf("%s", ar_nm);
    printf("\nFollowing information found\n");
    printf("----------------------------------------------\n");
    printf("item name \tuser name \troom No.\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < keepcount; i++)
    {
        if (strcmp(ar_nm, l[i].user) == 0)                  // strcmp is used for comparing strings 
            printf("%s \t\t %s\t\t%d\n", l[i].item_name, l[i].user, l[i].rooms);
    }
}

void itemInfo() {
    printf("Enter item name : ");
    scanf("%s", item_nm);
    printf("----------------------------------------------\n");
    printf("item name \tuser name \troom No.\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < keepcount; i++)
    {
        if (strcmp(item_nm, l[i].item_name) == 0)
            printf("%s \t\t %s\t\t%d\n", l[i].item_name, l[i].user, l[i].rooms);
    }
}

void itemInUse() {
    printf("\n Number of items out of inventry : %d", keepcount);
}

void car()
{
    int v,t,f,p,ti;
    while(v!=4)
    {
        printf("\n Type of vehicle \n 1. Two wheeler \n 2. Four wheeler \n 3. Bus \n 4. Exit \n");
        printf("\nWhat type of vehicle do you want:");
        scanf("%d", &v);
        switch(v)
        {
            case 1:
                printf("\n Types of two wheelers. \n 1. Bike \n 2. Activa \n ");
                printf("What type of vehicle do you want:");
                scanf("%d", &t);
                printf("\nYou can collect your keys from front desk.\n");
                break;
                
            case 2:
                printf("\n Types of four wheelers. \n 1. SUV \n 2. Sedan \n 3. Hatchback \n 4. Jeep \n");
                printf("What type of vehicle do you want:");
                scanf("%d", &f);
                printf("\nYou can collect your keys from front desk.\n");
                break;
                
            case 3:
                printf("\n Total number of passengers:");
                scanf("%d", &p);
                printf("\n At what time you want this facility:");
                scanf("%f", &ti);
                break;
                
            case 4:
                break;
                
            default:
                printf("Pressed invalid key\n");
                exit;
                
        }
    }
}

void food()
{
    int fo=0,amount=0,d,q;
    while (fo!=5)
    {
        printf("\n");
        printf(" -------------------------------\n");
        printf("|\t       MENU            \t|\n");
        printf("|\t1. South Indian Food   \t|\n");
        printf("|\t2. Gujarati Food       \t|\n");
        printf("|\t3. Maxican food        \t|\n");
        printf("|\t4. Italian food        \t|\n");
        printf("|\t5. Exit                \t|\n");
        printf(" -------------------------------\n");
        printf("\n Select the type of food: ");
        scanf("%d", &fo);
    
        if(fo==1)
        {
            
            f1.dish[0]="Dosa";
            f1.p[0]=150;
            f1.dish[1]= "Idli";
            f1.p[1]= 100;
            while(d!=2)
            {
                printf(" -------------------------------\n");
                printf("|\t South Indian Food    \t|\n");
                printf("|\t0. Dosa               \t|\n");
                printf("|\t1. Idli               \t|\n");
                printf("|\t2. Exit               \t|\n");
                printf(" -------------------------------\n");
                printf("\nSelect the type of dish: ");
                scanf("%d", &d);
                if(d==0)
                {
                    printf("\nPrice:%d \n", f1.p[d]);
                    printf("Quantity of Dosa:");
                    scanf("%d", &q);
                    amount += (q)*(f1.p[d]);
                    q=0;
                }
                    
                else if(d==1)
                {  
                    printf("\nPrice:%d \n", f1.p[d]);
                    printf("Quantity of Idli:");
                    scanf("%d", &q);
                    amount += (q)*(f1.p[d]);
                    q=0;
                }
                  
                else if(d==2)
                {
                    exit;
                }
                    
                else
                {
                    printf("Pressed invalid key");
                }
            }
        }
        
        
        if(fo==2)
        {
            
            f2.dish[0]="Gujarati Thali";
            f2.p[0]=200;
            f2.dish[1]= "Khaman";
            f2.p[1]= 100;
            while(d!=2)
            {
                printf(" -------------------------------\n");
                printf("|\t Gujarati Food        \t|\n");
                printf("|\t0. Gujarati Thali     \t|\n");
                printf("|\t1. Khaman             \t|\n");
                printf("|\t2. Exit               \t|\n");
                printf(" -------------------------------\n");
                printf("\nSelect the type of dish: ");
                scanf("%d", &d);
                if(d==0)
                {
                    printf("\nPrice:%d \n", f2.p[d]);
                    printf("Quantity of Gujarati Thali:");
                    scanf("%d", &q);
                    amount += (q)*(f2.p[d]);
                    q=0;
                }
                    
                else if(d==1)
                {  
                    printf("\nPrice:%d \n", f2.p[d]);
                    printf("Quantity of Khaman:");
                    scanf("%d", &q);
                    amount += (q)*(f2.p[d]);
                    q=0;
                }
                  
                else if(d==2)
                {
                    exit;
                }
                    
                else
                {
                    printf("Pressed invalid key");
                }
            }
        }
        
        
        if(fo==3)
        {
            
            f3.dish[0]="Cheese Nachos";
            f3.p[0]=200;
            f3.dish[1]= "Mexican Tacos";
            f3.p[1]= 150;
            while(d!=2)
            {
                printf(" -------------------------------\n");
                printf("|\t Mexican food         \t|\n");
                printf("|\t0. Cheese Nachos      \t|\n");
                printf("|\t1. Maxican Tacos      \t|\n");
                printf("|\t2. Exit               \t|\n");
                printf(" -------------------------------\n");
                printf("\nSelect the type of dish: ");
                scanf("%d", &d);
                if(d==0)
                {
                    printf("\nPrice:%d \n", f3.p[d]);
                    printf("Quantity of Cheese Nachos:");
                    scanf("%d", &q);
                    amount += (q)*(f3.p[d]);
                    q=0;
                }
                    
                else if(d==1)
                {  
                    printf("\nPrice:%d \n", f3.p[d]);
                    printf("Quantity of Mexican Tacos:");
                    scanf("%d", &q);
                    amount += (q)*(f3.p[d]);
                    q=0;
                }
                  
                else if(d==2)
                {
                    exit;
                }
                    
                else
                {
                    printf("Pressed invalid key");
                }
            }
        }
        
        
        if(fo==4)
        {
            
            f4.dish[0]="Pizza";
            f4.p[0]=200;
            f4.dish[1]= "Pasta";
            f4.p[1]= 200;
            while(d!=2)
            {
                printf(" -------------------------------\n");
                printf("|\t  Italian food        \t|\n");
                printf("|\t   0. Pizza           \t|\n");
                printf("|\t   1. Pasta           \t|\n");
                printf("|\t   2. Exit            \t|\n");
                printf(" -------------------------------\n");
                printf("\nSelect the type of dish: ");
                scanf("%d", &d);
                if(d==0)
                {
                    printf("\nPrice:%d \n", f4.p[d]);
                    printf("Quantity of Pizza:");
                    scanf("%d", &q);
                    amount += (q)*(f4.p[d]);
                    q=0;
                }
                    
                else if(d==1)
                {  
                    printf("\nPrice:%d \n", f4.p[d]);
                    printf("Quantity of Pasta:");
                    scanf("%d", &q);
                    amount += (q)*(f4.p[d]);
                    q=0;
                }
                  
                else if(d==2)
                {
                    exit;
                }
                    
                else
                {
                    printf("Pressed invalid key");
                }
            }
        }
        
        
        else if(fo==5)
            break;
            
            
        else
        {
            printf("\nInvalid information\n");
            exit;
            
        }
    }
    printf("Total amount of your order is %d \n", amount);
    printf("Your order will be delevered soon. \n\n");
}



int main()
{
    int y = 0;
    while(y != 6)
    {
        printf("---------------------------------------------------------------------------------------------------------------------------\n");
        printf("--------------------------------------------------Welcome to Hotel Pritam--------------------------------------------------\n");
        printf("--------------------------------Designed By:-|Shrey Patel| |Vatsal Balasra| |AmanPatel|------------------------------------\n");
        printf("----------------------------|Kushal Rajani| |Jayvardhansinh Chudasama| |Vivaan Srivastava|---------------------------------\n");
        printf("---------------------------------------------------------------------------------------------------------------------------\n");
        printf("What would you like to do?\n1.Customer Checkin & Checkout\n2.Restaurant & Management Services\n3.Inventory\n4.Review System\n5.Employee Details\n6.Exit\n\n");
        printf("Enter Your Choice:");
        scanf("%d",&y);
        if(y == 1)
        {
            int x = 0;
            while(x != 5)
            {
                printf("--------------------------------------------------------------------------------------------------------------------------\n");
                printf("------------------------------Welcome to Hotel Pritam Checkin & Checkout Management Services------------------------------\n");
                printf("------------------------------------------------Designed By:-|Shrey Patel|------------------------------------------------\n");
                printf("--------------------------------------------------------------------------------------------------------------------------\n\n");
                printf("Select your operation:\n1.Checkin\n2.Checkout\n3.Display Vaccant Rooms\n4.Display Customers\n5.Exit\nEnter Your Choice:");
                scanf("%d",&x);
                if(x == 1)
                {
                    int ch;
                    printf("Select Customer's Choice of Room:\n1.Deluxe\n2.Premium\n3.Regular\n4.Regular with A\\C\n5.Exit\nEnter Your Choice:");
                    scanf("%d",&ch);
                    if(ch == 1)
                    {
                        printf("Enter Customer's name:");
                        char name[50];
                        scanf("%s", name);
                        int rn;
                        printf("Enter the room alloted:");
                        scanf("%d", &rn);
                        InsertData(rn, name, "Deluxe");
                    }
                    else if(ch == 2)
                    {
                        printf("Enter Customer's name:");
                        char name[50];
                        scanf("%s", name);
                        int rn;
                        printf("Enter the room alloted:");
                        scanf("%d", &rn);
                        InsertData(rn, name, "Premium");
                    }
                    else if(ch == 3)
                    {
                        printf("Enter Customer's name:");
                        char name[50];
                        scanf("%s", name);
                        int rn;
                        printf("Enter the room alloted:");
                        scanf("%d", &rn);
                        InsertData(rn, name, "Regular");
                    }
                    else if(ch == 4)
                    {
                        printf("Enter Customer's name:");
                        char name[50];
                        scanf("%s", name);
                        int rn;
                        printf("Enter the room alloted:");
                        scanf("%d", &rn);
                        InsertData(rn, name, "Regular with A\\C");
                    }
                    else if(ch == 5)
                    {
                        printf("Exitting!!\n");
                        break;
                    }
                    else
                    {
                        printf("Invalid Entry!!\n");
                    }
                }
                else if(x == 2)
                {
                    printf("Enter Room number to be Checked Out:");
                    unsigned int rn;
                    scanf("%d", &rn);
                    if(Customer[((int)(rn/100))-1][(rn%100)-1].room_no != 0){
                        Customer[((int)(rn/100))-1][(rn%100)-1] = DefaultStructures(Customer[((int)(rn/100))-1][(rn%100)-1]);
                    }
                    else
                    {
                        printf("Room is already vaccant!!\n");
                    }
                }
                else if(x == 3)
                {
                    printf("Vaccant Rooms are:\n");
                    for(int i=0;i<4;i++)
                    {
                        printf("Floor %d : ",i);
                        for(int j=0;j<7;j++){
                            if(Customer[i][j].room_no == 0)
                            {
                                printf("%d| ", ((i+1)*100)+(j+1));
                            }
                        }
                        printf("\n");
                    }
                }
                else if(x == 4)
                {
                    int rn;
                    printf("Enter room number:");
                    scanf("%d", &rn);
                    if(Customer[((int)(rn/100))-1][(rn%100)-1].room_no != 0 && rn>100){
                        printf("The Room is currently occupied by %s!!\n",Customer[((int)(rn/100))-1][(rn%100)-1].name);
                    }
                    else if(rn<100)
                    {
                        printf("Invalid Entry!!\n");
                    }
                    else
                    {
                        printf("Room is currenlty Vaccant !!\n");
                    }
                }
                else if(x == 5)
                {
                    printf("Exitting!!\n");
                    break;
                }
                else
                {
                    printf("Invalid Entry!!\n");
                }
            }
        }
        else if(y == 2)
        {
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("---------------------------------Welcome to Hotel Pritam Restaurant & Service Management---------------------------------\n");
            printf("------------------------------------------------Designed By:-|Aman Patel|------------------------------------------------\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n\n");
            int s;
            while(s!=3)
            {
                printf("List of Services provided by our hotel\n");
                printf("1. Food services\n");
                printf("2. Car Rental Service\n");
                printf("3. Exit\n");
                printf("\nSelect the services you want:");
                scanf("%d", &s);
            
                switch (s)
                {
                case 1:
                    food();
                    break;
                    
                case 2:
                    car();
                    break;
                    
                case 3:
                    break;
                    
                default:
                    printf("Pressed invalid key");
                    break;
                }
            }
        }
        else if(y == 3)
        {
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("-----------------------------------Welcome to Hotel Pritam Inventory Management Services---------------------------------\n");
            printf("----------------------------------------------Designed By:-|Vatsal Balasra|----------------------------------------------\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n\n");
            int j = 0;
            while (j != 6)
            {
                printf("\n1. Add item information\n");
                printf("2. Display item information\n");
                printf("3. List all items of given user\n");
                printf("4. List of title of specified item\n");
                printf("5. List the count of items in the inventry\n");
                printf("6. Exit");

                printf("\n\nEnter one of the above : ");
                scanf("%d", &j);

                switch (j)
                {
                case 1:
                    inPut();        // Take input of items which are being used
                    break;

                case 2:
                    Display();      // displaying the items being used
                    break;

                case 3:
                    itemOfUser();   // shows all items used by a perticuler user
                    break;

                case 4:
                    itemInfo();     // shows all users of a perticuler item
                    break;

                case 5:
                    itemInUse();    // number of items currently in use
                    break;
                case 6:
                    break;        // to exit, function from <stdlib.h>
                default:
                    printf("Pressed invalid key");
                    break;
                }
            }
        }
        else if(y == 4)
        {
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("-----------------------------------Welcome to Hotel Pritam Inventory Management Services---------------------------------\n");
            printf("-----------------------------------------------Designed By:-|Kushal Rajani|----------------------------------------------\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n\n");
            feedback();
        }
        else if(y == 5)
        {
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("-----------------------------------Welcome to Hotel Pritam Employee Management Services----------------------------------\n");
            printf("-----------------------------------------Designed By:-|Jayvardhansinh Chudasama|-----------------------------------------\n");
            printf("------------------------------------------------|Vivaan Srivastava|------------------------------------------------------\n\n");
            int n;
            printf("Enter the number of employees:");
            scanf("%d", &n);
            // Declaring struct Employee with size n and initializing all other elements to zero
            struct Employee emp[n];
            int option = 0;
            int n1 = 0;
            int n3 = 0;
            int true = 0;
            int true2 = 0;

            // Taking user input for employee name, id, salary and designation
            for (int i = 0; i < n; i++)
            {
                printf("\nEmployee : %d\n", i + 1);
                printf("Enter Name : ");
                scanf("%s", emp[i].name);
                printf("Enter Employee ID : ");
                scanf("%d", &emp[i].empID);
                printf("Enter salary : ");
                scanf("%d", &emp[i].salary);
                printf("Enter Designation : ");
                scanf("%s", emp[i].designation);
            }
            // Providing options for user to choose and then displaying it through switch case 
            do
            {
                printf("\nPlease select from the above options\n");
                printf("1. Display Employee Information:\n");
                printf("2. Add an Employee:\n");
                printf("3. Remove an Employee:\n");
                printf("4. Display Updated Employee Information:\n");
                printf("5. Exit\n");
                scanf("%d", &option);

                switch (option)
                {
                case 1:   // Printing Employee details
                    printf("------ All Employee Details -------\n");
                    for (int i = 0; i < n; i++)
                    {
                        printf("\n");
                        printf("Name \t: ");
                        printf("%s \n", emp[i].name);

                        printf("ID \t: ");
                        printf("%d \n", emp[i].empID);

                        printf("Salary \t: ");
                        printf("%d \n", emp[i].salary);

                        printf("Designation : ");
                        printf("%s \n", emp[i].designation);

                        printf("\n");
                    }
                    break;

                case 2:  // Adding employee data
                    printf("\nAdding an Employee\n");
                    printf("How many employees you want to add?\n");
                    scanf("%d", &n1);
                    {
                        for (int i = n + 1; i <= n1 + n; i++)
                        {
                            printf("\nEmployee : %d\n", i);
                            printf("Enter Name : ");
                            scanf("%s", &emp[i].name);
                            printf("Enter Employee ID : ");
                            scanf("%d", &emp[i].empID);
                            printf("Enter salary : ");
                            scanf("%d", &emp[i].salary);
                            printf("Enter Designation : ");
                            scanf("%s", &emp[i].designation);
                            printf("\n");
                        }
                        break;
                    }

                case 3:  // Removing an employee using his unique employee ID
                    printf("Removing an Employee\n");
                    true2 = 0;
                    do
                    {
                        int i = 0;
                        printf("Enter Employee ID: ");
                        scanf("%d", &n3);

                        for (i; i < n; i++)
                        {
                            if (n3 == emp[i].empID)
                            {
                                true2 = 1;
                                printf("Employee %d will be removed\n", emp[i].empID);
                                emp[i].empID = 0;
                                n1--;
                            }
                        }

                        if (true2 == 0)
                        {
                            printf("wrong number \n");
                        }
                    } while (true2 == 0);
                    break;

                case 4: // Printing the updated details after adding or removing data of the employees
                    printf("------ All Employee Details -------\n");
                    for (int i = 0; i <= (n + n1); i++)
                    {
                        if (emp[i].empID != 0)
                        {
                            printf("\n");
                            printf("Name \t: ");
                            printf("%s \n", emp[i].name);

                            printf("ID \t: ");
                            printf("%d \n", emp[i].empID);

                            printf("Salary \t: ");
                            printf("%d \n", emp[i].salary);

                            printf("Designation : ");
                            printf("%s \n", emp[i].designation);
                        }
                        printf("\n");
                    }
                    break;

                case 5:  // If the user wants to exit the program
                    printf("Exitting Employee Data Program\n");
                    break;

                default:
                    printf("Invalid option chosen.Try Again.\n");
                    break;
                }
            } while (option != 5); // If option is other than 5, then it will display invalid option chosen
        }
        else if(y == 6)
        {
            printf("Exiting....");
            break;
        }
        else
        {
            printf("Invalid Entry!!");
        }
    }
    return 0;
}

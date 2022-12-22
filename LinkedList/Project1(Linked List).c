#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structures are declared 

// this structure is used to store the data of different menu's
struct MenuD
{
    int code;
    char name[60];
    int price;
};

//this structure is used to store the data of linked list.
struct Node
{
    int code;
    int quantity;
    struct Node *next;
};

//head and tail of linked list are declared here.
struct Node *head = NULL;
struct Node *tail = NULL;

//Menu is stored in the form of different arrays of structures.
struct MenuD VEGCOMBOS[5]={
    {101,"SHINO BIG SPICY WRAP(V)",284},
    {102,"SHINO SPICY(V)",250},
    {103,"MAHARAJA SHINO(V)",292},
    {104,"SHINO VEGGIE",197},
    {105,"SHINO ALOOTIKKI",148}
};

struct MenuD NONVEGCOMBOS[5]={
    {201,"SHINO BIG SPICY WRAP(N)",289}
    ,{202,"SHINO SPICY(N)",254}
    ,{203,"MAHARAJA SHINO(N)",308}
    ,{204,"SHINO CHICKEN",106}
    ,{205,"CHICKEN KEBAB MEAL",181}
};

struct MenuD VEG_BURGERS[5]={
    {301,"SHINO BIG SPICY WRAP(V.Bur)",177}
    ,{302,"SHINO SPICY(V.Bur)",143}
    ,{303,"MAHARAJA SHINO(V.Bur)",185}
    ,{304,"SHINO VEGGIE(Bur)",90}
    ,{305,"SHINO ALOOTIKKI(Bur)",41}
};

struct MenuD NONVEG_BURGERS[5]={
    {401,"SHINO BIG SPICY WRAP(N.Bur)",182},
    {402,"SHINO SPICY(N.Bur)",147},
    {403,"MAHARAJA SHINO(N.Bur)",201},
    {404,"SHINO CHICKEN(Bur)",99},
    {405,"CHICKEN KEBAB(Bur)",74}
};

struct MenuD EXTRAS[6]={
    {502,"CHICKEN NUGGETS(6PCS.)",123},
    {503,"CHICKEN NUGGETS(9PCS.)",185},
    {504,"EGG AND CHEESE SHINO MUFFIN",68},
    {505,"VEG SHINO MUFFIN",61},
    {506,"DOSA MASALA BROICHE",48}
};

struct MenuD BEVERAGES[6]={
    {601,"SOFT DRINKS(S)",68},
    {602,"SOFT DRINKS(M)",74},
    {603,"SOFT DRINKS(L)",83},
    {604,"COLD COFFEE",85},
    {605,"ICED TEA(R)",44},
    {606,"ICED TEA(M)",70}
};

struct MenuD DESSERTS[7]={
    {701,"PHIRNI SHINOFLURRY(R)",85},
    {702,"PHIRNI SHINOFLURRY(M)",99},
    {703,"SHINOFLURRY OREO(R)",70},
    {704,"SHINOFLURRY OREO(M)",97},
    {705,"SHINOCHOCO CRUNCH(R)",70},
    {706,"SHINOCHOCO CRUNCH(M)",97},
    {707,"SOFT SERVE(HOT FLUDGE/STRAWBERRY)",70}
};

//this function is used to create the appropriate spacing used for printing menu's and bill order
void Spacing(int name, int max)
{
    for(int i=name; i <= max; i++)        //a simple for loop is used for this purpose.
    {
        printf(" ");
    }
}

//Menu is printed using this function.
void MenuPrint(struct MenuD m[], int Length)
{
    printf("\n|  CODE  |        NAME");
    Spacing(13, 50);                           //spacing function is called to create uniform spaces after the "NAME" is printed.
    printf(" |   PRICE  |\n");
    for(int i=0; i<Length; i++)
    {
        printf("|  %d   |%s",m[i].code, m[i].name);
        Spacing(strlen(m[i].name), 50);       //spacing function is called for uniform spaces while printing the name.
        printf("|    %d   |",m[i].price);
        printf("\n");
    }
}

const char* getName(int code)                //return type is specifically chosen 'const char*' to return a string. 
{                                            
    int box = code/100;                      //box and var are used to calculate the which menu and item are to be selected to generate the respective name.
    int var = code % 10;
    if(box == 1)
    {
        return VEGCOMBOS[var - 1].name; 
    }
    else if(box == 2)
    {
        return NONVEGCOMBOS[var - 1].name; 
    }
    else if(box == 3)
    {
        return VEG_BURGERS[var - 1].name; 
    }
    else if(box == 4)
    {
        return NONVEG_BURGERS[var - 1].name; 
    }
    else if(box == 5)
    {
        return EXTRAS[var - 1].name; 
    }
    else if(box == 6)
    {
        return BEVERAGES[var - 1].name; 
    }
    else if(box == 7)
    {
        return DESSERTS[var - 1].name; 
    }
}

int getPrice(int code)
{                                          
    int box = code/100;                    //box and var are used to calculate the which menu and item are to be selected to generate the respective price.
    int var = code % 10;
    if(box == 1)
    {
        return VEGCOMBOS[var - 1].price; 
    }
    else if(box == 2)
    {
        return NONVEGCOMBOS[var - 1].price; 
    }
    else if(box == 3)
    {
        return VEG_BURGERS[var - 1].price; 
    }
    else if(box == 4)
    {
        return NONVEG_BURGERS[var - 1].price; 
    }
    else if(box == 5)
    {
        return EXTRAS[var - 1].price; 
    }
    else if(box == 6)
    {
        return BEVERAGES[var - 1].price; 
    }
    else if(box == 7)
    {
        return DESSERTS[var - 1].price; 
    }
}

int getGreatestLength()
{
    struct Node* curr = head;                                       //current Node is given the head Node value at beginning.
    if(curr != NULL){
        int max = 0;
        do                                                          //the value of the Node is changed to its next value after each iteration.
        {  
            if(max < strlen(getName(curr->code)))                   //function getName is called and size of the returned string is calculated.
            {                                                       //if max value is less than length of the string , max is given the value of string length.
                max = strlen(getName(curr->code));
            }
            curr = curr->next; 
        }while(curr != tail->next);                                 //checking if current Node value is not NULL.
        return max;                                                 //max value is returned if head is not NULL.
    }
    else
    {
        return -1;                                                  //else -1 value is returned.
    }
}

int Display()
{
    struct Node* curr = head;
    int max = getGreatestLength();                                  //max value is calculated by calling getGreatestLength function.
    if(curr == NULL)
    {
        printf("List is Empty!!");
        return 1;
    }
    else
    {
        int total = 0;
        printf("+-------+");
        for(int i = 0; i<max; i++)                                  //Menu is printed here.
        {
            printf("-");
        }
        printf("-+--------+-------+\n");
        printf("|Code   |Name");
        Spacing(4, max);
        printf("|Quantity|Price  |\n");
        printf("+-------+");
        for(int i = 0; i<max; i++)
        {
            printf("-");
        }
        printf("-+--------+-------+\n");
        do
        {
            printf("|%d    |%s", curr->code, getName(curr->code));
            Spacing(strlen(getName(curr->code)), max);                                                             //spacing function is called here.
            printf("|   %d    |  %d  |\n", curr->quantity, curr->quantity * getPrice(curr->code));                 //values at a particular nodes are calculated at here.
            total += (getPrice(curr->code) * curr->quantity);                                                      //total value is calculated here.
            curr = curr->next;
        }while (curr != tail->next);
        printf("+-------+");
        for(int i = 0; i<max; i++)
        {
            printf("-");
        }
        printf("-+--------+-------+\n");
        printf("|       Total");
        Spacing(4, max);
        printf("|       %d     |\n", total);
        printf("+-------+");
        for(int i = 0; i<max; i++)
        {
            printf("-");
        }
        printf("-+--------+-------+\n");
        return 0;
    }
}

void MisOrder(int code, int quantity)
{
    struct Node* curr = head;
    if(head == NULL)
    {
        printf("Nothing present to be Deleted!!");
    }
    else
    {
        struct Node* curr = head;                               //curr gets the head value.
        struct Node* temp = head;                               //temp is used to keep the account for previous Node of the temp.
        while (curr != tail->next)
        {
            if(curr->code == code)
            {
                if(curr->quantity - quantity <= 0)              //if the condition is satisfied then the given Node is deleted.
                {
                    if(curr == head && head == tail)            //if head is only Node in the List, it is freed from memory.
                    {
                        free(curr);                             //Node is freed from the memory.
                        head = NULL;
                        tail = NULL;
                    }
                    else if(curr == head)                       //if head is the selected Node then head is shifted to its next Node.
                    {
                        free(curr);                             //Node is freed from the memory.
                        head = head->next;
                    }
                    else
                    {
                        temp->next = curr->next;                //if Node is after head then its prev and its next Node are connected and it is deleted then.
                        free(curr);
                    }
                }
                else
                {
                    curr->quantity -= quantity;                 //if the condition is not satisfied, quantity is reduced.
                }
                break;
            }
            temp = curr;
            if(curr->next != NULL)
            {
                curr = curr->next;
            }
            else
            {
                break;
            }
        }
        if(temp->code != code)
        {
            printf("Invalid Entry!!\n");                    //if the last Node doesn't satisfy the condition then appropriate message is to be printed.
        }
    }
}

void AddNode(int code, int quantity)
{
    struct Node* curr = head;
    if(head == NULL)                                                                            //if List is empty, then head and tail are given the same value.
    {
        struct Node* New_Node = (struct Node*)malloc(sizeof(struct Node));                      //New Node is dynamically created.
        New_Node->code = code;
        New_Node->quantity = quantity;
        head = New_Node;
        tail = New_Node;
    }
    else
    {
        struct Node* temp = curr;                                                               //else temp is given the head value.
        while(curr != tail->next)
        {
            if(curr->code == code)
            {
                curr->quantity += quantity;                                                     //if the order is repeated then quantity value is increased.
                return;                                                                         //exits from the function.
            }
            temp = curr;
            curr = curr->next;
        }
        if(temp->code != code)
        {
            struct Node* New_Node = (struct Node*)malloc(sizeof(struct Node));  
            New_Node->code = code;
            New_Node->quantity = quantity;                                                     //New Node is created.
            tail->next = New_Node;                                                             //tail value is changed again.
            tail = tail->next;
        }
    }
}

int main()
{
    int x,a=0;
    printf("\t\t-------------------------------------------------\n");
    printf("\t\t--------------WELCOME  TO SHINOPSIS--------------\n");                        //Main Function has started.
    printf("\t\t----------------EATCORNER  CENTRE----------------\n");
    printf("\t\t-------------------------------------------------\n");

    while(a==0)
    {
        printf("\nWhat would you like to have for your meal?\n");
        printf("\n(01)VEG COMBOS\n(02)NON-VEG COMBOS\n(03)VEG BURGERS\n(04)NON-VEG BURGERS\n(05)EXTRAS\n(06)BEVERAGES\n(07)DESSERTS\n(08)BILLING\n(09)MISORDER\n(10)Exit.\n");
        printf("\nEnter Your Choice:");
        scanf("%d",&x);                                                                       //Choice is to be provided.
        if(x==1)
        {
            int ch, q;
            MenuPrint(VEGCOMBOS,5);                                                             //Menu is to be printed for the user for VEGCOMBOS section.
            printf("Enter the code of your choice:");
            scanf("%d",&ch);                                                                    //code and quantity are to be given.
            printf("Enter quantity:");
            scanf("%d", &q);                                                                    //Data is selected for adding it into the Linked List.
            if(ch == VEGCOMBOS[0].code)
            {
                AddNode(VEGCOMBOS[0].code, q);
            }
            else if(ch == VEGCOMBOS[1].code)
            {
                AddNode(VEGCOMBOS[1].code, q);
            }
            else if(ch == VEGCOMBOS[2].code)
            {
                AddNode(VEGCOMBOS[2].code, q);
            }
            else if(ch == VEGCOMBOS[3].code)
            {
                AddNode(VEGCOMBOS[3].code, q);
            }
            else if(ch == VEGCOMBOS[4].code)
            {
                AddNode(VEGCOMBOS[4].code, q);
            }
            else{
                printf("Invalid Entry!!");
            }
        }
        else if(x==2)
        {
            int ch, q;
            MenuPrint(NONVEGCOMBOS, 5);                                                 //Menu is to be printed for the user for VEGCOMBOS section.
            printf("Enter the code of your choice:");
            scanf("%d",&ch);                                                            //code and quantity are to be given.
            printf("Enter quantity:");
            scanf("%d", &q);                                                            //Data is selected for adding it into the Linked List.
            if(ch == NONVEGCOMBOS[0].code)
            {
                AddNode(NONVEGCOMBOS[0].code, q);
            }
            else if(ch == NONVEGCOMBOS[1].code)
            {
                AddNode(NONVEGCOMBOS[1].code, q);
            }
            else if(ch == NONVEGCOMBOS[2].code)
            {
                AddNode(NONVEGCOMBOS[2].code, q);
            }
            else if(ch == NONVEGCOMBOS[3].code)
            {
                AddNode(NONVEGCOMBOS[3].code, q);
            }
            else if(ch == NONVEGCOMBOS[4].code)
            {
                AddNode(NONVEGCOMBOS[4].code, q);
            }
            else{
                printf("Invalid Entry!!");
            }
        }
        else if(x==3)
        {
            int ch, q;
            MenuPrint(VEG_BURGERS,5);                                                   //Menu is to be printed for the user for VEGCOMBOS section.
            printf("Enter the code of your choice:");
            scanf("%d",&ch);                                                            //code and quantity are to be given.
            printf("Enter quantity:");
            scanf("%d", &q);                                                            //Data is selected for adding it into the Linked List.
            if(ch == VEG_BURGERS[0].code)
            {
                AddNode(VEG_BURGERS[0].code, q);
            }
            else if(ch == VEG_BURGERS[1].code)
            {
                AddNode(VEG_BURGERS[1].code, q);
            }
            else if(ch == VEG_BURGERS[2].code)
            {
                AddNode(VEG_BURGERS[2].code, q);
            }
            else if(ch == VEG_BURGERS[3].code)
            {
                AddNode(VEG_BURGERS[3].code, q);
            }
            else if(ch == VEG_BURGERS[4].code)
            {
                AddNode(VEG_BURGERS[4].code, q);
            }
            else{
                printf("Invalid Entry!!");
            }
        }
        else if(x==4)
        {
            int ch, q;
            MenuPrint(NONVEG_BURGERS,5);                                                //Menu is to be printed for the user for VEGCOMBOS section.
            printf("Enter the code of your choice:");
            scanf("%d",&ch);                                                            //code and quantity are to be given.
            printf("Enter quantity:");
            scanf("%d", &q);                                                            //Data is selected for adding it into the Linked List.
            if(ch == NONVEG_BURGERS[0].code)
            {
                AddNode(NONVEG_BURGERS[0].code, q);
            }
            else if(ch == NONVEG_BURGERS[1].code)
            {
                AddNode(NONVEG_BURGERS[1].code, q);
            }
            else if(ch == NONVEG_BURGERS[2].code)
            {
                AddNode(NONVEG_BURGERS[2].code, q);
            }
            else if(ch == NONVEG_BURGERS[3].code)
            {
                AddNode(NONVEG_BURGERS[3].code, q);
            }
            else if(ch == NONVEG_BURGERS[4].code)
            {
                AddNode(NONVEG_BURGERS[4].code, q);
            }
            else
            {
                printf("Invalid Entry!!");
            }
        }
        else if(x==5)
        {
            int ch, q;
            MenuPrint(EXTRAS,6);                                                        //Menu is to be printed for the user for VEGCOMBOS section.
            printf("Enter the code of your choice:");
            scanf("%d",&ch);                                                            //code and quantity are to be given.
            printf("Enter quantity:");
            scanf("%d", &q);                                                            //Data is selected for adding it into the Linked List.
            if(ch == EXTRAS[0].code)
            {
                AddNode(EXTRAS[0].code, q);
            }
            else if(ch == EXTRAS[1].code)
            {
                AddNode(EXTRAS[1].code, q);
            }
            else if(ch == EXTRAS[2].code)
            {
                AddNode(EXTRAS[2].code, q);
            }
            else if(ch == EXTRAS[3].code)
            {
                AddNode(EXTRAS[3].code, q);
            }
            else if(ch == EXTRAS[4].code)
            {
                AddNode(EXTRAS[4].code, q);
            }
            else if(ch == EXTRAS[5].code)
            {
                AddNode(EXTRAS[5].code, q);
            }
            else{
                printf("Invalid Entry!!");
            }
        }
        else if(x==6)
        {
            int ch, q;
            MenuPrint(BEVERAGES,6);                                                     //Menu is to be printed for the user for VEGCOMBOS section.
            printf("Enter the code of your choice:");
            scanf("%d",&ch);                                                            //code and quantity are to be given.
            printf("Enter quantity:");
            scanf("%d", &q);                                                            //Data is selected for adding it into the Linked List.
            if(ch == BEVERAGES[0].code)
            {
                AddNode(BEVERAGES[0].code, q);
            }
            else if(ch == BEVERAGES[1].code)
            {
                AddNode(BEVERAGES[1].code, q);
            }
            else if(ch == BEVERAGES[2].code)
            {
                AddNode(BEVERAGES[2].code, q);
            }
            else if(ch == BEVERAGES[3].code)
            {
                AddNode(BEVERAGES[3].code, q);
            }
            else if(ch == BEVERAGES[4].code)
            {
                AddNode(BEVERAGES[4].code, q);
            }
            else if(ch == BEVERAGES[5].code)
            {
                AddNode(BEVERAGES[5].code, q);
            }
            else{
                printf("Invalid Entry!!");
            }
        }
        else if(x==7)
        {
            int ch, q;
            MenuPrint(DESSERTS,7);                                                      //Menu is to be printed for the user for VEGCOMBOS section.
            printf("Enter the code of your choice:");
            scanf("%d",&ch);                                                            //code and quantity are to be given.
            printf("Enter quantity:");
            scanf("%d", &q);                                                            //Data is selected for adding it into the Linked List.
            if(ch == DESSERTS[0].code)
            {
                AddNode(DESSERTS[0].code, q);
            }
            else if(ch == DESSERTS[1].code)
            {
                AddNode(DESSERTS[1].code, q);
            }
            else if(ch == DESSERTS[2].code)
            {
                AddNode(DESSERTS[2].code, q);
            }
            else if(ch == DESSERTS[3].code)
            {
                AddNode(DESSERTS[3].code, q);
            }
            else if(ch == DESSERTS[4].code)
            {
                AddNode(DESSERTS[4].code, q);
            }
            else if(ch == DESSERTS[5].code)
            {
                AddNode(DESSERTS[5].code, q);
            }
            else if(ch == DESSERTS[6].code)
            {
                AddNode(DESSERTS[6].code, q);
            }
            else{
                printf("Invalid Entry!!");
            };
        }
        else if(x == 8)
        {
            Display();                                                                                  //Bill is to be printed.
        }
        else if(x == 9)
        {
            if(Display() == 1)
            {
                printf("");
            }                                                                                  //Bill is to be printed before misordered.
            else
            {
                int code, quantity;
                printf("Enter the code which was misordered:");
                scanf("%d", &code);
                printf("Enter quantity to be removed:");
                scanf("%d", &quantity);
                MisOrder(code, quantity);
                Display();
            }                                                                                  //Bill is to be printed after misorder function is called.
        }
        else if(x==10)
        {
            printf("Exiting. . . . ");                                                                  //program exits from this side.
            a=1;
        }
        else
        {
            printf("You have Entered wrong Choice. Try again.");                                        //for Wrong entries.
        }
    }
    return 0;
}
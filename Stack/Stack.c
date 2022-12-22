#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Character {                              // Character Stack
    int *S;
    int top;
    int size;
    int *level;
    int *health;
    int *Attack;
};
struct Weapon {                              // Weapon Stack
    int *W;
    int wtop;
    int wsize;
    int *damage;
};
struct Booster {                              // Booster Stack
    int *B;
    int btop;
    int bsize;
    int *health;
};

//Function for Character structure
void create(struct Character *st) {             // For creation of stack in heap
    st->top = -1;
    st->size = 7;
    st->S = (int *)malloc(7 * sizeof(int));
    st->level = (int *)malloc(7 * sizeof(int));
    st->health = (int *)malloc(7 * sizeof(int));
    st->Attack = (int *)malloc(7 * sizeof(int));
}
void push (struct Character *st, int char1, int level, int health, int attack, int y) {       // For adding new character
    if(st -> top == st -> size - 1) {
        printf("CharacterOverflow\n");
    }
    else {
        st -> top++;
        st -> S[st -> top] = char1;
        st->Attack[st->top] = attack;
        st->level[st->top] = level;
        st->health[st->top] = health;
        if(y == 1)
        {
            printf("Congo!!\n");
            printf("You unlocked SAURON.\n");
        }
        else if(y == 2)
        {
            printf("Congo!!\n");
            printf("You unlocked JOHNNY CAGE.\n");
        }
    }
}
void pop (struct Character *st) {               // Function for popping
    int x;
    if (st -> top == -1) {
        printf("\nNo Characters present to be deleted!!\n");
    }
    else {
        x = st -> S[st -> top];
        st -> top--;
    }
}
void swap(struct Character* stack, int index1, int index2)
{
    int temp;
    temp = stack->S[index1];
    stack->S[index1] = stack->S[index2];
    stack->S[index2] = temp;

    temp = stack->level[index1];
    stack->level[index1] = stack->level[index2];
    stack->level[index2] = temp;

    temp = stack->Attack[index1];
    stack->Attack[index1] = stack->Attack[index2];
    stack->Attack[index2] = temp;

    temp = stack->health[index1];
    stack->health[index1] = stack->health[index2];
    stack->health[index2] = temp;
}
void delete (struct Character *st, int key_index) {
    swap (st, key_index, st->top);
    pop(st);
}

//Function for Weapon structure
void wcreate(struct Weapon *wst) {             // For creation of stack in heap
    wst->wtop = -1;
    wst->wsize = 7;
    wst->W = (int *)malloc(7 * sizeof(int));
    wst->damage = (int *)malloc(7 * sizeof(int));
}
void wpush (struct Weapon *wst, int x, int dam, int y) {       // For adding new Weapon
    if(wst -> wtop == wst -> wsize - 1) {
        printf("WeaponOverflow\n");
    }
    else {
        wst -> wtop++;
        wst->damage[wst->wtop] = dam;
        wst -> W[wst -> wtop] = x;
        if(y == 1)
        {
            printf("Congo!!\n");
            printf("You unlocked AK-47.\n");
        }
        else if(y == 2)
        {
            printf("Congo!!\n");
            printf("You unlocked SPEAR.\n");
        }
    }
}
void wpop (struct Weapon *wst) {               // Function for popping
    int x;
    if (wst -> wtop == -1) {
        printf("\nNo Weapons present to be deleted!!\n");
    }
    else {
        x = wst -> W[wst -> wtop];
        wst -> wtop--;
    }
}
void wswap(struct Weapon* stack, int index1, int index2)
{
    int temp;
    temp = stack->W[index1];
    stack->W[index1] = stack->W[index2];
    stack->W[index2] = temp;

    temp = stack->damage[index1];
    stack->damage[index1] = stack->damage[index2];
    stack->damage[index2] = temp;
}
void wdelete (struct Weapon *wst, int key_index) {
    wswap(wst, key_index, wst->wtop);
    wpop(wst);
}

//Function for Booster structure
void bcreate(struct Booster *bst) {             // For creation of stack in heap
    bst->bsize = 7;
    bst->btop = -1;
    bst->B = (int *)malloc(7 * sizeof(int));
    bst->health = (int *)malloc(7 * sizeof(int));
}
void bpush (struct Booster *bst, int x, int health, int y) {       // For adding new Weapon
    if(bst -> btop == bst -> bsize - 1) {
        printf("WeaponOverflow\n");
    }
    else {
        bst -> btop++;
        bst->health[bst->btop] = health;
        bst -> B[bst -> btop] = x;
        if(y == 1)
        {
            printf("Congo!!\n");
            printf("You unlocked DEFENSE x 2.\n");
        }
        else if(y == 2)
        {
            printf("Congo!!\n");
            printf("You unlocked FIRE PUNCH.\n");
        }
    }
}
void bpop (struct Booster *bst) {               // Function for popping
    int x;
    if (bst -> btop == -1)
    {
        printf("\nNo Boosters present to be deleted!!\n");
    }
    else
    {
        x = bst -> B[bst -> btop];
        bst -> btop--;
    }
}
void bswap(struct Booster* stack, int index1, int index2)
{
    int temp;
    temp = stack->B[index1];
    stack->B[index1] = stack->B[index2];
    stack->B[index2] = temp;

    temp = stack->health[index1];
    stack->health[index1] = stack->health[index2];
    stack->health[index2] = temp;
}
void bdelete (struct Booster *wst, int key_index) {
    bswap(wst, key_index, wst->btop);
    bpop(wst);
}

//Function for Crates
void Gems()
{
    printf("Congo!!\n");
    printf("You got 50 gems.\n");
}
void Boosters(struct Booster *ptr)
{
    int b1 = 1;
    int b2 = 2;
    int num3 = (rand() % (b2 - b1 + 1)) + b1;
    if (num3 == 1)
    {
        bpush(ptr,1,25, 1);
    }
    else
    {
        bpush(ptr,2,50, 2);
    }
}
void Weapons(struct Weapon *ptr)
{
    int w1 = 1;
    int w2 = 2;
    int num4 = (rand() % (w2 - w1 + 1)) + w1;
    if (num4 == 1)
    {
        wpush(ptr,1,30, 1);
    }
    else
    {
        wpush(ptr, 2, 49, 2);
    }
}
void Characters(struct Character *ptr)
{
    int c1 = 1;
    int c2 = 2;
    int num5 = (rand() % (c2 - c1 + 1)) + c1;
    if (num5 == 1)
    {
        push(ptr, 1, 1, 100, 20, 1);
    }
    else
    {
        push(ptr,2, 1, 100, 50, 2);
    }
}

int main()
{
    //Stack structures are created.
    struct Character cst;
    create (&cst);
    struct Weapon wst;
    wcreate (&wst);
    struct Booster bst;
    bcreate(&bst);

    //character, weapon, booster strings are stored here.

    char charac[3][30] = {"SAURON", "JOHNNY CAGE"};
    char weapons[3][20] = {"AK-47", "SPEAR"};
    char booster[3][25] = {"FIRE PUNCH", "DEFENSE * 2"};

    int c1 = 0;
    int gems = 500;

    int player1chance = 0;                  //variables for calculating player's chance of winning.
    int player2chance = 0;

    int c,w,b;
    int c2,w2,b2;                               //values for player 1 and computer are declared.

    int key_index;

    while (c1 != 4)
    {
        printf("            ::WARFRAME INFINITE::\n1.Crates(Price : 50 Gems)\n2.Missions\n3.Inventory\n4.Exit\nEnter You Choice:");
        scanf("%d",&c1);
        if(c1 == 1)
        {
            if (gems >= 50)
            {
                gems = gems - 10;
                int upper = 100;
                int lower = 1;
                srand(time(NULL));
                int num = (rand() % (upper - lower + 1)) + lower;
                if (num <= 20 && num > 0)
                {
                    Gems();                                                                     //Gems function is called to add gems.
                    gems += 50;
                    printf("You now have %d gems.\n", gems);
                }
                else if (num <= 40 && num > 20)
                {
                    Boosters(&bst);                                                            // Boosters are added to the stack.
                }
                else if (num <= 60 && num > 40)
                {
                    Weapons(&wst);                                                             //Weapons are added to te stack.
                }
                else
                {
                    Characters(&cst);                                                          //Characters are added to the stack.
                }
            }
            else
            {
                printf("You don't have enough gems to open this crate.\n");
            }
        }
        else if(c1 == 2)
        {
            if(cst.top != -1 && wst.wtop != -1 && bst.btop != -1)
            {
                srand(time(0));
                printf("Your chances will decrease for wrong input!!");
                printf("\n List of Character \n");
                for(int i = 0; i<=cst.top; i++)
                {
                printf("%d. %s \n", (i+1), charac[cst.S[i]-1]);
                    }
                    printf("Select the Character:");
                    scanf("%d", &c);
                    c--;
                    if(c <= cst.top)
                    {
                        player1chance += ((cst.S[c]-1) * 10);
                    }
                    else
                    {
                        printf("Wrong input!!");
                        player1chance-=10;
                    }
                printf("\n List of Weapon \n");
                for(int i = 0; i<=wst.wtop; i++)
                {
                    printf("%d. %s \n", i+1, weapons[wst.W[i]-1]);
                }
                printf("Select the Weapon:");
                scanf("%d", &w);
                w--;
                if(w <= wst.wsize)
                {
                    player1chance += ((wst.W[w]-1) * 10);
                }
                else if(w == 1)
                {
                    printf("Wrong input!!");
                    player1chance -= 10;
                }
                else if(w == 2)
                {
                    player1chance += 0;
                }
                if(bst.btop != -1)
                {
                    printf("\n List of Booster \n");
                    for(int i = 0; i<=bst.btop; i++)
                    {
                        printf(" %d. %s \n", (i+1), booster[bst.B[i]-1]);
                    }
                    printf("Select the Booster:");
                    scanf("%d", &b);
                    b--;
                    if(b <= bst.bsize)
                    {
                        player1chance += ((bst.B[b]-1) * 10);
                    }
                    else
                    {
                        printf("Wrong input!!");
                        player1chance-=10;
                    }
                }
                else
                {
                    player1chance += 0;
                }

                c2 = (rand() % (3 - 1 +1)) + 1;
                if(c2 == 1)
                {
                    player2chance += 30;
                }
                else if(c2 == 2)
                {
                    player2chance += 40;
                }
                else if(c2 == 3)
                {
                    player2chance += 50;
                }

                w2 = (rand() % (3 - 1 +1)) + 1;
                if(w2 == 1)
                {
                    player2chance += 30;
                }
                else if(w2 == 2)
                {
                    player2chance += 40;
                }
                else if(w2 == 3)
                {
                    player2chance += 50;
                }

                b2 = (rand() % (3 - 1 +1)) + 1;
                if(b2 == 1)
                {
                    player2chance += 40;
                }
                else if(b2 == 2)
                {
                    player2chance += 30;
                }
                else if(b2 == 3)
                {
                    player2chance += 20;
                }

                if(player1chance > player2chance)
                {
                    printf("You Lost!!!\n");
                    gems -= 10;
                }
                else if(player1chance == player2chance)
                {
                    printf("It's a tie!!!\n");
                    gems += 25;
                }
                else
                {
                    printf("You Won!!\n");
                    gems += 100;
                }
                printf("You now have %d\n", gems);
            }
            else
            {
                printf("Get a character atleast from the crate.\n");
            }
        }
        else if(c1 == 3)
        {
            //Menu for Inventory Management
            int ch = 0;
            while(ch != 6)
            {
                printf("           ::SHIN VALLEY INVENTORY::\n1.Remove any Component\n2.Display Components\n3.Exit\n");       //Menu is given
                printf("Enter Your choice:");
                scanf("%d",&ch);                                                                                              //Choice is given to user
                if(ch == 1)
                {
                    int x = 0;
                    while(x != 4)
                    {
                        printf("Choose Your Component :\n1.Remove character\n2.Remove Weapon\n3.Remove Booster\n4.Exit\n");
                        printf("Enter Your Choice:");
                        scanf("%d", &x);
                        if(x == 1)
                        {
                            printf("Name   Level   Attack   Health\n");
                            for (int i = cst.top; i >= 0; i--)
                            {
                                printf("%s \t%d \t%d \t%d\n", charac[cst.S[i]-1], cst.level[i], cst.Attack[i], cst.health[i]); //character stack are displayed!!
                            }
                            printf("\n");
                            printf("Enter the number which is to be deleted:");
                            scanf("%d",&key_index);
                            delete(&cst, key_index - 1);                                                                       //element is deleted!!
                        }
                        else if(x == 2)
                        {
                            printf("Name   Damage\n");
                            for (int i = wst.wtop; i >= 0; i--)
                            {
                                printf("%s \t%d\n", weapons[wst.W[i]-1], wst.damage[i]);                                    //weapon stack are displayed!!
                            }
                            printf("\n");
                            printf("Enter the number which is to be deleted:");
                            scanf("%d",&key_index);
                            wdelete(&wst, key_index - 1);
                        }
                        else if(x == 3)
                        {
                            printf("Name   Powerup\n");
                            for (int i = bst.btop; i >= 0; i--)
                            {
                                printf("%s \t%d\n", booster[bst.B[i]-1], bst.health[i]);                                        //booster stack are displayed!!
                            }
                            printf("\n");
                            printf("Enter the number which is to be deleted:");
                            scanf("%d",&key_index);
                            bdelete(&bst, key_index - 1);
                        }
                        else if(x == 4)
                        {
                            break;
                        }
                        else
                        {
                            printf("Invalid Choice. Try again!!!\n");
                            scanf("%d", &x);
                        }
                    }
                }
                else if (ch == 2)
                {
                    int x = 0;
                    while(x != 4)
                    {
                        printf("Choose Your Component :\n1.Display character\n2.Display Weapon\n3.Display Booster\n4.Exit\n");
                        printf("Enter Your Choice:");
                        scanf("%d", &x);
                        if(x == 1)
                        {
                            printf("Name   Level   Attack   Health\n");
                            for (int i = cst.top; i >= 0; i--)
                            {
                                printf("%s \t%d \t%d \t%d\n", charac[cst.S[i]-1], cst.level[i], cst.Attack[i], cst.health[i]);    //character stack are displayed!!
                            }
                            printf("\n");
                        }
                        else if(x == 2)
                        {
                            printf("Name   Damage\n");
                            for (int i = wst.wtop; i >= 0; i--)
                            {
                                printf("%s \t%d\n", weapons[wst.W[i]-1], wst.damage[i]);                                         //weapon stack are displayed!!
                            }
                            printf("\n");
                        }
                        else if(x == 3)
                        {
                            printf("Name   Powerup\n");
                            for (int i = bst.btop; i >= 0; i--)
                            {
                                printf("%s \t%d\n", booster[bst.B[i]-1], bst.health[i]);                                        //booster stack are displayed!!
                            }
                            printf("\n");
                        }
                        else if(x == 4)
                        {
                            break;
                        }
                        else
                        {
                            printf("Invalid Choice. Try again!!!\n");
                        }
                    }
                }
                else if(ch == 3)
                {
                    printf("Exiting !!!!\n");
                    break;
                }
                else
                {
                    printf("Invalid choice.Try Again !!!\n");
                }
            }
        }
        else if(c1 == 4)
        {
            break;
        }
        else
        {
            printf("You have Entered Invalid Choice !!!");
        }
    }
}

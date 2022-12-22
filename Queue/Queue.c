#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

struct MenuD
{
    int code;
    char name[50];
    int price;
};

struct MenuD VEGCOMBOS[20] = {
    {101, "SHINO BIG SPICY WRAP(V)", 284},
    {102, "SHINO SPICY(V)", 250},
    {103, "MAHARAJA SHINO(V)", 292},
    {104, "SHINO VEGGIE", 197},
    {105, "SHINO ALOOTIKKI", 148}};

struct MenuD NONVEGCOMBOS[20] = {
    {201, "SHINO BIG SPICY WRAP(N)", 289}, {202, "SHINO SPICY(N)", 254}, {203, "MAHARAJA SHINO(N)", 308}, {204, "SHINO CHICKEN", 106}, {205, "CHICKEN KEBAB MEAL", 181}};

struct MenuD VEG_BURGERS[20] = {
    {301, "SHINO BIG SPICY WRAP(V.Bur)", 177}, {302, "SHINO SPICY(V.Bur)", 143}, {303, "MAHARAJA SHINO(V.Bur)", 185}, {304, "SHINO VEGGIE(Bur)", 90}, {305, "SHINO ALOOTIKKI(Bur)", 41}};

struct MenuD NONVEG_BURGERS[20] = {
    {401, "SHINO BIG SPICY WRAP(N.Bur)", 182},
    {402, "SHINO SPICY(N.Bur)", 147},
    {403, "MAHARAJA SHINO(N.Bur)", 201},
    {404, "SHINO CHICKEN(Bur)", 99},
    {405, "CHICKEN KEBAB(Bur)", 74}};

struct MenuD EXTRAS[20] = {
    {502, "CHICKEN NUGGETS(6PCS.)", 123},
    {503, "CHICKEN NUGGETS(9PCS.)", 185},
    {504, "EGG AND CHEESE SHINO MUFFIN", 68},
    {505, "VEG SHINO MUFFIN", 61},
    {506, "DOSA MASALA BROICHE", 48}};

struct MenuD BEVERAGES[20] = {
    {601, "SOFT DRINKS(S)", 68},
    {602, "SOFT DRINKS(M)", 74},
    {603, "SOFT DRINKS(L)", 83},
    {604, "COLD COFFEE", 85},
    {605, "ICED TEA(R)", 44},
    {606, "ICED TEA(M)", 70}};

struct MenuD DESSERTS[20] = {
    {701, "PHIRNI SHINOFLURRY(R)", 85},
    {702, "PHIRNI SHINOFLURRY(M)", 99},
    {703, "SHINOFLURRY OREO(R)", 70},
    {704, "SHINOFLURRY OREO(M)", 97},
    {705, "SHINOCHOCO CRUNCH(R)", 70},
    {706, "SHINOCHOCO CRUNCH(M)", 97},
    {707, "SOFT SERVE(HOT FLUDGE/STRAWBERRY)", 70}};

struct Queue // structure for queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size) // dynamic allocation of memory
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x) // adding elements in queue
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) // deletion elements from *REAR*
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = q->Q[q->rear];
        q->rear--;
    }
    return x;
}

int fdequeue(struct Queue *q) // deletion of elements from *Front*
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

struct Stack // Stack for storing elements Dequeued from Queue
{
    int size;
    int *S;
    int top;
};

void createSt(struct Stack *st) // Dynamic allocation of memory for stack
{
    st->size = 20;
    st->top = -1;
    st->S = (int *)malloc(20 * sizeof(int));
}

void push(struct Stack *st, int x) // adding element in stack
{
    if (st->top == st->size - 1)
    {
        printf("StackOverFlow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) // removing element from stack
{
    int x;
    if (st->top == -1)
    {
        printf("StackUnderFlow\n");
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

void Display(struct Queue *q) //  for display of the Queue
{
    int i;

    for (i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->Q[i]);
    }
    printf("\n");
}

void deleter(int x, struct Queue *q, struct Stack *s) // traves from rear of queue and delets the required element
{
    int data = -1;
    int deqData = -1;
    while (q->Q[q->rear] != x)
    {
        deqData = dequeue(q); // dequeue from the rare
        push(s, deqData);     // push all in stack
    }

    dequeue(q); // target found -> dequeue without push
    printf("%d deleted from the queue\n", x);

    int popData = -1;
    while (s->top != -1)
    {
        popData = pop(s);    // pop the stack
        enqueue(q, popData); // enqueue in queue
    }
}

void checker(int x, struct Queue *q, struct Stack *s) // For checking the exception while deletion of element
{
    int flag = 0; // For notifying the input is valid or not
    for (int i = q->front; i < q->rear; i++)
    {
        if (x == q->Q[i])
        {
            flag = 1;
            deleter(x, q, s); // the call will be made from here to delete the element
            break;
        }
    }
    if (flag == 0)
    {
        printf("Invalid input\n");
    }
}

int main()
{
    struct Queue q;
    create(&q, 15);
    struct Stack s;
    createSt(&s);

    int i, j, x, a = 0, n, ch, cd, amt=0, pr;
    printf("\t\t-------------------------------------------------\n");
    printf("\t\t--------------WELCOME  TO SHINOPSIS--------------\n");
    printf("\t\t----------------EATCORNER  CENTRE----------------\n");
    printf("\t\t-------------------------------------------------\n\n");
    printf("What would you like to have for your meal?\n");
    printf("\n(01)VEG COMBOS\n(02)NON-VEG COMBOS\n(03)VEG BURGERS\n(04)NON-VEG BURGERS\n(05)EXTRAS\n(06)BEVERAGES\n(07)DESSERTS\n(08)BILLING\n(09)MISORDER\n(10)Exit.\n");
    while (a == 0)
    {
        printf("\nEnter Your menu Choice: ");
        scanf("%d", &x);
        if (x == 1)
        {
            printf("\n|  CODE  |        NAME           |   PRICE  |\n");
            for (i = 0; i < 5; ++i)
            {
                printf("|  %d  |", VEGCOMBOS[i].code);
                printf("  %s   |", VEGCOMBOS[i].name);
                printf("   %d   |", VEGCOMBOS[i].price);
                printf("\n");
            }
        }
        else if (x == 2)
        {
            for (i = 0; i < 5; ++i)
            {
                printf("%d  ", NONVEGCOMBOS[i].code);
                printf("%s  ", NONVEGCOMBOS[i].name);
                printf("%d  ", NONVEGCOMBOS[i].price);
                printf("\n");
            }
        }
        else if (x == 3)
        {
            for (i = 0; i < 5; ++i)
            {
                printf("%d  ", VEG_BURGERS[i].code);
                printf("%s  ", VEG_BURGERS[i].name);
                printf("%d  ", VEG_BURGERS[i].price);
                printf("\n");
            }
        }
        else if (x == 4)
        {
            for (i = 0; i < 5; ++i)
            {
                printf("%d  ", NONVEG_BURGERS[i].code);
                printf("%s  ", NONVEG_BURGERS[i].name);
                printf("%d  ", NONVEG_BURGERS[i].price);
                printf("\n");
            }
        }
        else if (x == 5)
        {
            for (i = 0; i < 6; ++i)
            {
                printf("%d  ", EXTRAS[i].code);
                printf("%s  ", EXTRAS[i].name);
                printf("%d  ", EXTRAS[i].price);
                printf("\n");
            }
        }
        else if (x == 6)
        {
            for (i = 0; i < 6; ++i)
            {
                printf("%d  ", BEVERAGES[i].code);
                printf("%s  ", BEVERAGES[i].name);
                printf("%d  ", BEVERAGES[i].price);
                printf("\n");
            }
        }
        else if (x == 7)
        {
            for (i = 0; i < 7; ++i)
            {
                printf("%d  ", DESSERTS[i].code);
                printf("%s  ", DESSERTS[i].name);
                printf("%d  ", DESSERTS[i].price);
                printf("\n");
            }
        }

        else if (x == 8)
        {
            printf("\nEnter no. of items you want to order: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter code of the item you want: ");
                scanf("%d", &cd);
                printf("Enter it's price: ");
                scanf("%d", &pr);
                amt+=pr;
                enqueue(&q, cd);
            }
            printf("\nAmount to be paid: %d\n", amt);
            amt=0;
        }

        else if (x == 9)
        {
            while (ch != 4)
            {
                printf("1) view orders\n");
                printf("2) complete first order\n");
                printf("3) complete last order\n");
                printf("4) exit\n");
                printf("Enter your choice: ");
                scanf("%d", &ch);
                if (ch == 1)
                    Display(&q);
                else if (ch == 2)
                    checker((q.Q[q.front]), &q, &s);
                else if (ch == 3)
                    checker((q.Q[q.rear]), &q, &s);
                else if(ch == 4)
                    break;
                else
                    printf("Invalid choice!");
            }
        }

        else if (x == 10)
        {
            printf("Exiting. . . . ");
            a = 1;
        }
        else
        {
            printf("You have Entered wrong Choice!");
            break;
        }
    }
    return 0;
}
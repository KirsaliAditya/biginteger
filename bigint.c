#include <string.h>
#include <stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *temp =(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=data;
    return temp;
}

struct node *convertList(char *ch)
{
    struct node *head = NULL;
    for(int i = 0;i < strlen(ch); i++)
    {
        struct node *temp = createNode(ch[i] - '0');
        temp->next = head;
        head = temp;
    }
    return head;
}

void append(struct node **head, int data)
{
    struct node *temp = createNode(data);
    if(*head == NULL) {
        *head = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
}

void printList(struct node* list){
    struct node* counter = list;
    while( counter != NULL){
        printf("%d",counter -> data);
        counter = counter -> next;
    }
    printf("\n\n");
}

void add(char *c1, char *c2)
{
    struct node *head = NULL;
    struct node *p1 = convertList(c1);
    struct node *p2 = convertList(c2);
    int carry = 0, sum = 0, x, y;
    while(p1 || p2)
    {
        if(p1)
            x = p1->data;
        else
            x = 0;

        if(p2)
            y = p2->data;
        else
            y = 0;

        sum = x + y + carry;
        carry = sum/10;
        append(&head, sum%10);
        if(p1)
            p1 = p1->next;
        if(p2)
            p2 = p2->next;
    }
    if(carry > 0)
        append(&head, carry);
    printList(head);
}

void sub(char *c1, char *c2)
{
    struct node *head = NULL;
    struct node *p1 = convertList(c1);
    struct node *p2 = convertList(c2);
    int borrow = 0, diff = 0 ,x, y;
    while(p1 || p2)
    {
        if(p1)
            x = p1->data;
        else
            x = 0;

        if(p2)
            y = p2->data;
        else
            y = 0;

        diff = x - y - borrow;
        if(diff < 0) {
            diff = diff+10;
            borrow = 1;
        }
        else
            borrow = 0;
        append(&head, diff%10);
        if(p1)
            p1 = p1->next;
        if(p2)
            p2 = p2->next;
    }
    if(borrow)
    {
        append(&head, borrow);
    }
    printList(head);
}

struct node *reverse(struct node *head)
{
    struct node* current = head;
    struct node *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

struct node *mulAdd(struct node *result, struct node *temp)
{
    struct node *head = NULL;
    result = reverse(result);
    temp = reverse(temp);
    int carry = 0, sum = 0, x, y;
    while(result || temp)
    {
        if(result)
            x = result->data;
        else
            x = 0;

        if(temp)
            y = temp->data;
        else
            y = 0;

        sum = x + y + carry;
        carry = sum/10;
        append(&head, sum%10);
        if(result)
            result = result->next;
        if(temp)
            temp = temp->next;
    }
    if(carry > 0)
        append(&head, carry);
    return head;
}


void mul(char *c1, char *c2)
{
    struct node *p1 = convertList(c1);
    struct node *p = p1;
    struct node *p2 = convertList(c2);
    struct node *result = NULL;
    int mul, pos=0;
    while(p2)
    {
        struct node *head = NULL;
        int carry = 0;
        for(int i=0;i<pos;i++)
            append(&head, 0);
        while(p1)
        {
            mul = ((p1->data) * (p2->data)) + carry;
            carry=mul/10;
            append(&head, mul%10);
            p1 = p1->next;
        }
        while(carry!=0)
        {
            append(&head, carry%10);
            carry/=10;
        }
        p2 = p2->next;
        pos++;
        result = mulAdd(result, head);
        p1 = p;
    }
    printList(result);
}

char *convert(struct node *temp, int len)
{
    char *ch = (char *) malloc(len*sizeof(char));
    int i =0;
    while(temp)
    {
        ch[i] = (char)(temp->data + '0');
        i++;
        temp = temp->next;
    }
    ch[i]='\0';
    return ch;
}

struct node* createCopy(struct node* head) {
    struct node* newHead = NULL;
    struct node* current = head;
    struct node* temp = NULL;

    while (current != NULL) {
        temp = createNode(current->data);
        temp->next = newHead;
        newHead = temp;
        current = current->next;
    }

    return newHead;
}


void divide(char *c1, char *c2)
{
    int i=0;
    int len = strlen(c1);
    struct node *result =NULL;
    struct node *p = convertList(c2);
    p = reverse(p);
    while(atoi(c1)> atoi(c2)) {
        struct node *p2 = reverse(createCopy(p));
        result = mulAdd(result, p2);
        c2 = convert(result, len);
        if(atoi(c1)>= atoi(c2)) {
            i++;
        }
    }
    printf("%d", i);
}


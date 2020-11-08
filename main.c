#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct stack {
    long long int number;
    char name[15];
    char email[MAX];
    struct stack *next;
    struct stack *previous;
}*head;

void addtoStack(struct stack* ptr, long long int ph_number, char name[], char email_id[]) {
        int flag = 0;
        struct stack* temp = head;
        ptr = malloc(sizeof(struct stack));
        ptr->number = ph_number;
        strcpy(ptr->name, name);
        strcpy(ptr->email, email_id);
        ptr->next = NULL;

        if(head == NULL) {
            head = ptr;
            return;
        }

        int result1 = strcmp(head->name, ptr->name);
        if(result1 >= 0) {
            ptr->next = head;
            head->previous = ptr;
            head = ptr;
            return;
        }
        if(head->next != NULL) {
            temp = head->next;
            while(temp->next != NULL) {
                int result = strcmp(temp->name, ptr->name);

                if(result>=0){
                    struct stack* temp_prev = temp->previous;
                    ptr->next = temp;
                    temp_prev->next = ptr;
                    ptr->previous = temp_prev;
                    temp->previous = ptr;
                    flag = 1;
                    return;
                }
                temp = temp->next;
            }
        }

        if(flag == 0) {
            temp->next = ptr;
            ptr->previous = temp;
        }
}

void display(struct stack* ptr) {
    struct stack* temp = head;
    if(temp == NULL) {
        printf("stack empty\n");
    }
    else {
        while(temp != NULL) {
            printf("Name: %s\nNumber: %lli\nemail: %s\n\n\n ",temp->name, temp->number, temp->email);
            temp = temp->next;
        }
    }
}
 struct stack* deletebyname(struct stack*ptr,char delname[])
 {
   struct stack*temp;
   temp=head;
   int flag=0;
   if(temp==NULL)
   {
     printf("Stack is empty");
   }
   else{
   
   while(temp!=NULL)
   {
    if(strcmp(temp->name,delname)==0)
    {
     flag=1;
     break;
    }
    else
    {
      flag=2;
    }
    temp=temp->next;
   }
  

    if(flag==1 && temp!=head && temp->next!=NULL)
    {
      temp->previous->next=temp->next;
      temp->next->previous=temp->previous;
      printf("Your contact has been deleted");
      
    }
    else if(temp==ptr)
    {
     temp=temp->next;
     temp->previous=NULL;
     head=temp;
     printf("Your contact has been deleted");
    }
    else if(temp->next==NULL)
    {
      temp->previous->next=NULL;
      printf("Your contact has been deleted");
    }
    else if(flag==2)
    {
      printf("The number you entered is not in the stack");
    }

   }
   return head;
 }
 

int main()
{
    struct stack s;
    struct stack *p;
    p = &s;
    int option;
    long long int number;
    char name[20], email[100];
    char delname[20];
    do {
        printf("\nEnter a choice\n0. exit\n1. add\n2. display\n3. clear screen\n4.Delete by name\n");
        scanf("%d", &option);
        switch(option){
    case 0:
        break;
    case 1:
        printf("enter name\n");
        scanf("%s", &name);
        printf("enter number\n");
        scanf("%lli", &number);
        printf("enter email\n");
        scanf("%s", &email);
        addtoStack(p, number, name, email);
        break;
    case 2:
        display(p);
        break;
    case 3:
        system("cls");
        break;
       
      case 4:
      printf("Enter the name to be deleted=");
      scanf("%s",delname);
      p=deletebyname(p, delname);
      break;


        
    default:
        printf("enter valid option\n");

        }
    }while(option!=0);

    return 0;
}

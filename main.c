#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
            int result2 = strcmp(temp->name, ptr->name);
            if(result2>=0) {
                    struct stack* temp_prev1 = temp->previous;
                    ptr->next = temp;
                    temp_prev1->next = ptr;
                    ptr->previous = temp_prev1;
                    temp->previous = ptr;
                    flag = 1;
                    return;
            }
        }

        if(flag == 0) {
            temp->next = ptr;
            ptr->previous = temp;
        }
}

bool searchbyName(char name[]) {
    struct stack* temp = head;
    while(temp!=NULL) {
        int result = strcmp(temp->name, name);
        if(result == 0) {
            printf("Number=%lli\nName=%s\nEmailid=%s\n", temp->number, temp->name, temp->email);
            return true;
        }
        temp = temp->next;
    }
    printf("contact not found\n");
    return false;
}

bool searchbyEmail(char email_id[]) {
    struct stack* temp = head;
    while(temp!=NULL) {
        int result = strcmp(temp->email, email_id);
        if(result == 0) {
            printf("Number=%lli\nName=%s\nEmailid=%s\n", temp->number, temp->name, temp->email);
            return true;
        }
        temp = temp->next;
    }
    printf("contact not found\n");
    return false;
}

bool searchbyNumber(long long int ph_number) {
    struct stack* temp = head;
    while(temp!=NULL) {

        if(temp->number == ph_number) {
            printf("Number=%lli\nName=%s\nEmail id=%s\n", temp->number, temp->name, temp->email);
            return true;
        }
        temp = temp->next;
    }
    printf("Contact not found\n");
    return false;
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
 struct stack* deletebyname(char delname[])
 {
   struct stack*temp;
   temp=head;
   int flag=0;
   if(temp==NULL)
   {
     printf("list is empty");
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
    else if(temp==head)
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
      printf("The number you entered is not in the list");
    }

   }
   return head;
 }

  struct stack*delbynumber(long long int delnumber)
 {
   struct stack*temp;
   temp=head;
   int flag=0;
   if(temp==NULL)
   {
     printf("Contact book is empty");
    
   }
   else{
   while(temp!=NULL)
   {
     if(temp->number==delnumber)
     {
       flag=1;
       break;
     }
     else{
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
     else if(temp==head)
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
    else if(temp==head && temp->next==NULL)
    {
      temp=NULL;
      head=temp;
      printf("Your contact has been deleted");
    }
    else if(flag==2)
    {
      printf("The number you entered is not in the contact book");
    }
   }
 

 return head;

 }

  struct stack*delbyemail(char delemail[])
 {
   struct stack*temp;
   temp=head;
   int flag=0;
   if(temp==NULL)
   {
     printf("Contact book is empty");
    
   }
   else{
   while(temp!=NULL)
   {
     if(strcmp(temp->email,delemail)==0)
     {
       flag=1;
       break;
     }
     else{
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
     else if(temp==head)
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
     else if(temp==head && temp->next==NULL)
    {
      temp=NULL;
      head=temp;
      printf("Your contact has been deleted");
    }
    else if(flag==2)
    {
      printf("The number you entered is not in your contact book");
    }
   }
 

 return head;

 }

void updateByName()
{
  char name[MAX];
  printf("Enter name of the record which you wish to update: ");
  scanf("%s",name);

  struct stack* temp = head;

  if(searchbyName(name))
  {
    printf("Contact Found\n");

    while(temp!=NULL)
    {
      int result = strcmp(temp->name,name);
      if(result == 0)
      {
        printf("Enter New name: ");
        scanf("%s",name);
        strcpy(temp->name, name);
        printf("Update Successful !!!\n");
        break;
      }
      temp = temp->next;
    }
  }
}

void updateByNumber()
{
  long long int number;
  printf("Enter number of the record you wish to update: ");
  scanf("%lli",&number);

  struct stack* temp = head;

  if(searchbyNumber(number))
  {
    printf("Contact Found\n");

    while(temp!=NULL)
    {
      if(temp->number == number)
      {
        printf("Enter New number: ");
        scanf("%lli",&number);
        temp->number = number;
        printf("Update Successful !!!\n");
        break;
      }
      temp = temp->next;
    }
  }
}

void updateByEmail()
{
  char email[MAX];
  printf("Enter email of the record which you wish to update: ");
  scanf("%s",email);

  struct stack* temp = head;

  if(searchbyEmail(email))
  {
    printf("Contact Found\n");

    while(temp!=NULL)
    {
      int result = strcmp(temp->email,email);
      if(result == 0)
      {
        printf("Enter New email: ");
        scanf("%s",email);
        strcpy(temp->email, email);
        printf("Update Successful !!!\n");
        break;
      }
      temp = temp->next;
    }
  }
}

void updateRecord()
{
  struct stack* ptr = head;

  if(ptr == NULL)
  {
    printf("No records in contact to Update!!!\n");
  }
  else
  {
    int choice;
    printf("To Update Contact by Name press 1.\n");
    printf("To Update Contact by Number press 2.\n");
    printf("To Update Contact by Email press 3.\n");
    printf("To Return press 4.\n");

    scanf("%d",&choice);
    
    switch(choice)
    {
      case 1:
      {
        updateByName();
        break;
      }

      case 2:
      {
        updateByNumber();
        break;
      }

      case 3:
      {
        updateByEmail();
        break;
      }

      case 4:
      {
        printf("Exiting the search option!!!\n");
        break;
      }
    }
  }
}

int main()
{
    struct stack s;
    struct stack *p;
    p = &s;
    int option, option2;
    long long int number;
    char name[20], email[100];
    char delname[20];
    char username[20];
     printf("Welcome To Your Contact Book!!!");
    printf("\nWhat is your name?\n");
    scanf("%s",username);
    printf("Hello %s let's start exploring your contact book",username);
    do {
        printf("\nEnter a choice\n0. Exit\n1. Add\n2. Display\n3. Search a contact\n4.Delete contact\n5. Clear screen\n6. Update record\n");
        scanf("%d", &option);
        switch(option){
    case 0:
        break;
                
    case 1:
        printf("enter name\n");
        scanf("%s", name);
        printf("enter number\n");
        scanf("%lli", &number);
        printf("enter email\n");
        scanf("%s", email);
        addtoStack(p, number, name, email);
        break;
                
    case 2:
        display(p);
        break;
                
    case 3:
        system("cls");
        printf("search by \n1.Name\n2.Email\n3.Number\n");
        scanf("%d", &option2);
        if(option2 == 1)
        {
            printf("Enter name\n");
            scanf("%s", name);
            searchbyName(name);
        }
        else if(option2 == 2){
            printf("Enter email\n");
            scanf("%s", email);
            searchbyEmail(email);
        }
        else if(option2 == 3) {
            printf("Enter number\n");
            scanf("%lli", &number);
            searchbyNumber(number);
        }
        else {
            printf("Please enter valid option\n");
        }
        break;
       
      

      case 4:
      printf("Delete contact by:");
      printf("Delete by \n1.Name\n2.Email\n3.Number\n");
      scanf("%d", &option2);
      if(option2==1)
      {
        printf("Enter the name to be deleted=");
      scanf("%s",delname);
      p=deletebyname(delname);
      }
     else if(option2==2)
      {
         printf("Enter email id to be deleted=");
      scanf("%s",email);
      p=delbyemail(email);
      }
      else if(option2==3)
      {
      printf("Enter the number to be deleted=");
      scanf("%lli",&number);
      p=delbynumber(number);
      }
      else {
            printf("Please enter valid option\n");
        }
        break;

                
      case 5:
        system("cls");
        break;
      
      case 6:
      {
        updateRecord();
        break;
      }
      
    default:
        printf("Enter valid option\n");
        }
    }while(option!=0);

    return 0;
}

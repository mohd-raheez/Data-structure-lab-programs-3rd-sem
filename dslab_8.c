#include <stdio.h>
#include <stdlib.h>

struct node{

    char ssn[40],name[30],dept[30],salary[30];

    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;
NODE head=NULL;

int count=0;

NODE getnode()
{

    NODE temp=(NODE)malloc(sizeof(struct node));

    return temp;

}

NODE create()
{

    NODE temp=getnode();
    
    printf("Enter SSN\n");
    scanf("%s",temp->ssn);

    printf("Enter name\n");
    scanf("%s",temp->name);

    printf("Enter department\n");
    scanf("%s",temp->dept);

    printf("Enter salary\n");
    scanf("%s",temp->salary);
    temp->llink=NULL;
    temp->rlink=NULL;

    return temp;

}

void insert_front()
{
    NODE temp=create();

    if(head==NULL){

        head=temp;
    }
    else{

        temp->rlink=head;
        head->llink=temp;
        head=temp;
        
    }
    count++;
}

void insert_end()
{
    NODE temp=create();
    if(head==NULL){

        head=temp;
    }
    else{

        NODE cur=head;

        while(cur->rlink!=NULL){

            cur=cur->rlink;
        }
        
        cur->rlink=temp;
        temp->llink=cur;

    }
    count++;
}

void delete_front()
{
    if(head==NULL){

        printf("List is empty\n");
    }
    else{

        NODE temp=head;

        printf("Deleted node is :SSN: %s Name: %s Department: %s Salary: %s\n",temp->ssn,temp->name,temp->dept,temp->salary);
        
        free(head);
        head=NULL;
        head=temp->rlink;
        if(temp->rlink!=NULL){
            temp->rlink=NULL;
            head->llink=NULL;
        }
        count--;
    }
    
}

void delete_end()
{
    if(head==NULL){

        printf("List is empty\n");

    }
    else{
        NODE temp=head;

        if(head->rlink==NULL){

            free(head);
            head=NULL;
                        printf("Deleted node is :SSN: %s Name: %s Department: %s Salary: %s\n",temp->ssn,temp->name,temp->dept,temp->salary);

        }
        else{
        while(temp->rlink!=NULL){

            temp=temp->rlink;
        }
                    printf("Deleted node is :SSN: %s Name: %s Department: %s Salary: %s\n",temp->ssn,temp->name,temp->dept,temp->salary);

        temp->llink->rlink=NULL;
        temp->llink=NULL;
        free(temp);
        count--;
    }
    }
    

}

void display()
{
    if(count==0){

        printf("List is empty\n");
    }
    else{

        NODE temp=head;
        while(temp!=NULL){

            printf("SSN: %s Name: %s Department: %s Salary: %s\n",temp->ssn,temp->name,temp->dept,temp->salary);
            temp=temp->rlink;
        }
    }
}

void main()
{
    int choice,n,i;

    while(1){

        printf("\nMake a choice\n1.Create\n2.Insert Front\n3.Insert End\n4.Delete Front\n5.Delete End\n6.Display\n7.Exit\n");
        scanf("%d",&choice);

        switch(choice){

            case 1:printf("Enter the number of nodes\n");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                insert_end();
            }
            break;
            case 2: insert_front();
            break;

            case 3: insert_end();
            break;

            case 4:delete_front();
            break;

            case 5:delete_end();
            break;

            case 6: display();
            break;

            case 7: exit(0);
            break;

            default:printf("Invalid choice\n");
            break;
        }
    }

}

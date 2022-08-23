#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* head;


void front_insert(){
    int x;
    scanf("%d", &x);
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=head;
    head=temp;
    printf("inserted %d at the front\n", x);
}

void rear_insert(){
    int x;
    scanf("%d",&x);
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp;
    newnode->data=x;
    temp=head;
    newnode->link=NULL;
    while(temp->link!=NULL){
        temp=temp->link;
    temp->link=newnode;
    printf("inserted %d at end",x);
    }
}

int get_size(){
    int count=0;
    struct node* temp=head;
    while(temp!=NULL){
        temp=temp->link;
        count++;
    }
    return count;
}

void insert(){
    int x;
    scanf("%d",&x);
    int pos;
    scanf("%d", &pos);
    int c=0, i=0;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp;
    temp=head;
    c=get_size();
    if (pos==0){
        front_insert(x);
    }
    else if(pos==c){
        rear_insert(x);
    }
    else if (pos>c){
        printf("u high");
    }
    else{
        temp=head;
        while(i!=pos){
            temp=temp->link;
            i++;
        }
        struct node* temp1=temp->link;
        newnode->data=x;
        temp->link=newnode;
        newnode->link=temp1;
		printf("Inserted %d at %d\n",x,pos);

    }  
}

void delete(){
    int x;
    scanf("%d\n", &x);
    struct node* curr=head;
    struct node* prev=NULL;
    while (curr!=NULL){
        if(head->data==x){
            prev=head;
            head=head->link;
            free(prev);
            break;
        }
        if(curr->data==x){
            prev->link=curr->link;
            free(curr);
            break;
        }
        prev=curr;
        curr=curr->link;

    }
}

void pop(){
	struct node* temp =  head;
	struct node* temp1 = head;
	temp = temp->link;
	while(temp->link!=NULL){
		temp = temp->link;
	    temp1 = temp1->link;
	}
	int a = temp->data;
	free(temp);
	temp1->link = NULL;
	printf("popped %d\n", a);
}

void display(){
    struct node* temp= head;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp=temp->link;
        
    }
}
void main(){
	int choice;
	
	do{
		printf("Enter your choice\n1.Front insert\n2.Rear insert\n3.Insert at a position\n4.Pop\n5.Delete an element\n6.Display\n7.Sort");
		scanf("%d", &choice);
		switch (choice)
	{
	case 1:
		front_insert();
		break;
	case 2:
		rear_insert();
		break;
	case 3:
		insert();
		break;
	case 4:
		pop();
		break;
	case 5:
		delete();
		break;
	case 6:
		display();
		break;
	} 

}while(choice>=1 && choice<8);



}
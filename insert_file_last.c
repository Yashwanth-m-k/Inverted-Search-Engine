#include<stdio.h>
#include<string.h>
#include "inverted.h"
#include <stdlib.h>

int insert_at_last(Slist **head, char *file)
{
     Slist *new=(Slist *)malloc(sizeof(Slist));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->file=file;
    new->link=NULL;
    
    if(*head==NULL)
    {
        *head=new;
        
        return SUCCESS;
    }
    else{
        Slist *temp=*head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new;
    }
        
        return SUCCESS;
 

}
int print_list(Slist *head)
{
	if (head == NULL)
	{
		
        return FAILURE;
	}
    else
    {
	    while (head)		
	    {
		    printf("%s-> ", head -> file);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}
int find_node(Slist *head, char *key)
{
   
    if(head==NULL)
    {
        return SUCCESS;
    }
    Slist *temp=head;
    while(temp != NULL)
    {
       
        if((strcmp(temp->file,key))==0)
        {
            return FAILURE;
        }
        temp=temp->link;
    }
    return SUCCESS;

	
	
}


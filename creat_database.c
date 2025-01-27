#include<stdio.h>
#include<string.h>
#include "inverted.h"
#include <stdlib.h>

void creat_hash_table(Hash *table,int size)
{
    for(int i=0;i<size;i++)
    {
    table[i].key=i;
    table[i].hash_link=NULL;
    }
}

int creat_data_base(Hash *arr,Slist **head)
{
    Slist *temp=*head;
    while(temp!=NULL)
    {
       char *file_Lname=temp->file;
      
    
      
        FILE *file_ptr;
        file_ptr=fopen(file_Lname,"r");
        if(file_ptr==NULL)
        {
            printf("%s file_name not opened\n",file_Lname);
            temp = temp->link;
            continue;
        }
   
         char file_wrd[100];

       while( fscanf(file_ptr,"%99s",file_wrd)==1)
       {
                       
                        int i=0,count=0,index;
                        
                          if(file_wrd[0]>='0'&&file_wrd[0]<='9')
                          {
                                index=26;
                          }
                          else if(file_wrd[0] >= 32 && file_wrd[0] <= 47||file_wrd[0] >= 60&& file_wrd[0] <= 64)
                          {
                            index=27;
                          }
                          else{
                             index=file_wrd[0] % 97;
                            
                          }
                      
                        int flag=0,flag1=0;
            Main *new_m_node=malloc(sizeof(Main));
            if(new_m_node == NULL)
            {
                printf("Node not creaed\n");
                return FAILURE;
            }
            
            strcpy(new_m_node->word, file_wrd);
            new_m_node->main_link=NULL;
            new_m_node->file_count=1;
            new_m_node->sub_link=NULL;

            if(arr[index].hash_link == NULL)
            {
                 arr[index].hash_link=new_m_node;
                 new_m_node->file_count=1;


                                         Sub *new_S_node=malloc(sizeof(Sub));
                                        if(new_S_node == NULL)
                                        {
                                            printf("Node not creaed\n");
                                            return FAILURE;
                                        }
                                        new_S_node->filename=file_Lname;
                                        new_S_node->sub_link=NULL;

                                        new_m_node->sub_link=new_S_node;
                                        new_S_node->word_count=1;
                                        
            }
            else
            {
                        
                           Main *temp_for_main = arr[index].hash_link;
                    while (temp_for_main != NULL)
                     {
                        if(strcmp(temp_for_main->word,file_wrd)==0)
                        {
                                    flag=1;
                                  Sub *temp3 =temp_for_main->sub_link ;
                                   while( temp3 != NULL)
                                    {
                                        if(strcmp(temp3->filename,file_Lname)==0)
                                        {
                                           temp3->word_count++;
                                           flag1=1;
                                        }
                                           if(temp3->sub_link==NULL)
                                           {
                                            break;
                                           }
                                            temp3=temp3->sub_link;
                                    }
                                    if(flag1!=1){
                                     if(!(strcmp((temp_for_main->sub_link)->filename,file_Lname)==0))
                                    {
                                        
                                         Sub *new_S_node=malloc(sizeof(Sub));
                                                            if(new_S_node == NULL)
                                                            {
                                                                printf("Node not creaed\n");
                                                                return FAILURE;
                                                            }

                                                            new_S_node->filename=file_Lname;
                                                             temp_for_main->file_count++;
                                                            new_S_node->word_count++;
                                                            new_S_node->sub_link=NULL;
                                                            Sub *temp3=temp_for_main->sub_link;
                                                            while(temp3!=NULL)
                                                            {
                                                                if(temp3->sub_link==NULL)
                                                                {
                                                                    break;
                                                                }
                                                                temp3=temp3->sub_link;

                                                            }
                                                            temp3->sub_link=new_S_node;
                                    }
                                    }
                                    
                                    break;
                        }
                       
                    
                        if(temp_for_main->main_link==NULL)
                            {
                                break;
                            }
                        temp_for_main = temp_for_main->main_link;
                    }

                
                   if(flag!=1)
                   {
                    temp_for_main->main_link = new_m_node;
                   temp_for_main=temp_for_main->main_link;

                                                        Sub *new_S_node=malloc(sizeof(Sub));
                                                            if(new_S_node == NULL)
                                                            {
                                                                printf("Node not creaed\n");
                                                                return FAILURE;
                                                            }

                                                            new_S_node->filename=file_Lname;
                                                             
                                                            new_S_node->word_count=1;
                                                            new_S_node->sub_link=NULL;
                                                            
                                                            temp_for_main->sub_link=new_S_node;
                   }
                   }
                                                          
                    }
            temp=temp->link;
       }
        
        return SUCCESS;
    }

    


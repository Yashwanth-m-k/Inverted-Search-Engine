#include<stdio.h>
#include<string.h>
#include "inverted.h"
#include <stdlib.h>


void display_SubList(Sub *sub_link) {
    Sub *temp1 = sub_link;
    while (temp1 != NULL) {
        
        printf("%-15s %-15d\n", temp1->filename, temp1->word_count);
        temp1 = temp1->sub_link;
    }
}

void display_MainNode(int index, Main *main_node) {
    
    printf("%-15d %-20s %-12d", index, main_node->word, main_node->file_count);
    display_SubList(main_node->sub_link);  
}

void display_Database(Hash *arr, int size) {
    
    printf("%-15s %-15s %-15s %-12s %-15s\n", "Index", "Word", "File Count", "Filename", "Word Count");
    printf("----------------------------------------------------------------------------\n");

 
    for (int i = 0; i < size; i++) {
        if (arr[i].hash_link != NULL) {
            Main *temp = arr[i].hash_link;

            
            while (temp != NULL) {
                display_MainNode(i, temp);
                temp = temp->main_link;  
            }
        }
    }
    printf("\n");  
}
int search_database(Hash *arr,int size)
{
  char read[20];
  printf("Enter the word you want search :");
  scanf("%s",read);
  int index;
  
                     if(read[0]>='0'&&read[0]<='9')
                          {
                                index=26;
                          }
                           else if(read[0] >= 33 && read[0] <= 47)
                          {
                            index=27;
                          }
                          else{
                                index = read[0] % 97;
                          }
         if(arr[index].hash_link != NULL)
        {
            Main *temp;

           temp=arr[index].hash_link;
         
           while(temp != NULL)
           {
             
             if(strcmp(temp->word,read)==0)
              {
              printf("Word %s Present in %d Files",temp->word,temp->file_count);
              goto L1;
              }
              if(temp->main_link==NULL)
              {
                return FAILURE;
              }

                temp=temp->main_link;     
           }

            L1:
               Sub *temp1=temp->sub_link;
               while(temp1 != NULL)
                {
                    printf("\nIn File  %s  %d Times\n",temp1->filename,temp1->word_count);
                    temp1=temp1->sub_link;
                }
          
        }

        else{
          return FAILURE;
        }

}
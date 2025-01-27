#include<stdio.h>
#include<string.h>
#include "inverted.h"
#include <stdlib.h>
int save_database(char *str1,Hash *arr,int size)
{
    
     char *str;
     if(strchr(str1,'.')==NULL)
    {
         printf("please provide the .txt extension\n");
         return FAILURE;
    }
    else if(str=strstr(str1,".txt"))
    {
        if((strcmp(str,".txt"))==0)
        {
            
                FILE *file;
            file=fopen(str1,"w");
            if(file == NULL)
            {
                printf("%s File not opened\n",str1);
            }
          
     for (int i = 0; i < size; i++)
      {
        
        if(arr[i].hash_link != NULL)
        {
            Main *temp;

           temp=arr[i].hash_link;
         
           while(temp != NULL)
           {
            
            fprintf(file,"#%d;%s;%d;",i,temp->word,temp->file_count);
            
              Sub *temp1=temp->sub_link;
               
                while(temp1 != NULL)
                {
                    fprintf(file,"%s;%d",temp1->filename,temp1->word_count);
                    
                    temp1=temp1->sub_link;
                    if (temp1 != NULL) {
                        fprintf(file, ";");
                    }
                    
                }
                fprintf(file,"#\n");
                temp=temp->main_link;     
            }
        }
    }
             printf("\nINFO : Database is Saved \n");
             fclose(file);
        }
        else{
            printf("Extension should be .txt");
        }

    }
    else{
        printf("INFO : %s => This file is not a .txt file",str1);
    }


    
}
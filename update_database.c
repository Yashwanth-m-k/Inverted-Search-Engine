#include <stdio.h>
#include <string.h>
#include "inverted.h"
#include <stdlib.h>

int update_database(Hash *arr, int size,Slist **head,char *file) {
    
    
     char str1[20];
                            printf("Enter the file name: ");
                            scanf(" %[^\n]", str1); 
    if (strstr(str1, ".txt") == NULL) {
        printf("Error: Extension should be .txt\n");
        return FAILURE;  
    }

    FILE *src = fopen(str1, "r");
    if (src == NULL) {
        printf("%s File not opened\n", str1);
        return FAILURE; 
    }

    int line_count = 0,flag=0;
    char ch;

    // Count the number of lines starting with '#'
    while ((ch = fgetc(src)) != EOF) {
        if (ch == '#') {
            line_count++;
            flag=1;  
        }
    }
    if(flag != 1)
    {
        printf("\nINFO : %s => This file doesn't have the database\n",str1);
        return FAILURE;
    }
    
    rewind(src); // Reset the file pointer for reading the actual data

    int j = 0;
    while (j < line_count) {
        int index, file_count;
        char word[100];

        // Read each record starting with #
        if (fscanf(src, "#%d;%[^;];%d", &index, word, &file_count) == 3) 
        {
            Main *new_main_node = malloc(sizeof(Main));
            if (new_main_node == NULL) {
                printf("Memory allocation failed for Main node\n");
                fclose(src);
                return FAILURE;
            }

            strcpy(new_main_node->word, word);
            new_main_node->file_count = file_count;
            new_main_node->main_link = NULL;
            new_main_node->sub_link = NULL;

            Main *temp = arr[index].hash_link;
            if (arr[index].hash_link == NULL)
             {
                arr[index].hash_link = new_main_node;
            } 
            else {
                
                while (temp != NULL) {
                    if(temp->main_link == NULL)
                    {
                        break;
                    }
                    temp = temp->main_link;
                }
                temp->main_link = new_main_node;
            }

            // Process the file data
            int i=0;
            while(i<file_count){
                char file_name[100];
                int word_count;
                if (fscanf(src, ";%[^;];%d", file_name, &word_count) == 2) 
                {
                    Sub *new_sub_node = malloc(sizeof(Sub));
                    if (new_sub_node == NULL) {
                        printf("Memory allocation failed for Sub node\n");
                        fclose(src);
                        return FAILURE;
                    }
                    new_sub_node->filename = strdup(file_name);
                    new_sub_node->word_count = word_count;
                    new_sub_node->sub_link = NULL;

                        Sub *temp1 = new_main_node->sub_link;
                    if (new_main_node->sub_link == NULL) 
                    {
                        new_main_node->sub_link = new_sub_node;
                    } 
                    else {
                        
                        while (temp1 != NULL) {
                            if(temp1->sub_link == NULL)
                            {
                                break;
                            }
                            temp1 = temp1->sub_link;
                        }
                        temp1->sub_link = new_sub_node;
                        
                    }
                    // Delete file->
                    
                    // Check if we need to delete the file from the Slist
                    Slist *delete = *head;
                    Slist *before = NULL;

                    while (delete != NULL)
                     {
                        if (strcmp(new_sub_node->filename, delete->file) == 0) {
                          
                            if (before == NULL) {
                                
                                *head = delete->link;
                            } else {
                               
                                before->link = delete->link;
                            }
                            free(delete);  
                            break;  
                        }
                        before = delete; 
                        delete = delete->link;  
                    }
                                        
                                        
                }
                
                i++;
                
            }
        }
        j++;
        
    }

    // Display the updated database
  
    return SUCCESS;  
}

   

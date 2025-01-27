#include<stdio.h>
#include<string.h>
#include "inverted.h"
int main(int argc,char *argv[])
{
    int i=1,size=28;
    char *str;
    char *file_name;
    Slist *head=NULL;

    Hash arr[size];
    creat_hash_table(arr, size);
    if(argc<=1)
        {
            printf("INFO : Insufficient arguments\nplease pass the argumnets like a.out <txt file>\n");
            return FAILURE;
        }

    while(i<argc)
    {
      
        file_name=argv[i];
    if(strchr(argv[i],'.')==NULL)
    {
         printf("INFO : %s=>This file has without Extension file\n",file_name);
    }
    else if(str=strstr(argv[i],".txt"))
    {
        
        if((strcmp(str,".txt"))==0)
        {
                FILE *file;
            file=fopen(file_name,"r+");
            if(file == NULL)
            {
                printf("INFO : %s => This file not exist in the current directory\n",file_name);
                
            }
            else{
                        fseek(file, 0, SEEK_END);
                        long fileSize = ftell(file);
                        
                        if (fileSize == 0) 
                        {
                            printf("INFO : %s = The file is empty.\n",file_name);
                        } 
                        else 
                        {
                            
                            if((find_node(head,file_name))==FAILURE)
                            {
                                printf("INFO : %s This file is repeated ,so it will not store into sll\n",file_name);
                            }
                            else{
                            insert_at_last(&head,file_name);
                           printf("INFO : Successfull : file name %s into file linked list \n",file_name);
                            }
                        }
            }
        }
        
    }
    else{
        printf("INFO : %s=>This file has not a .txt file\n",file_name);

        }
         i++;
    }
   
   
if(print_list(head)==FAILURE)
{
    printf("\nINFO : Files are not there\nCreat database is not possible\n->NULL\n");
    return FAILURE;
}
int flag=0,flag1=0;
int op = 0;
do {
    op = 0;
    printf("\nSelect your choice among following opration: \n");
    printf("1. Create Database\n");
    printf("2. Display Database\n");
    printf("3. Search Database\n");
    printf("4. Save Database\n");
    printf("5. Update Database\n");
    printf("6. Exit\n");
    printf("\nEnter The choice: ");
    scanf("%d", &op);
        
    switch (op) {
        case 1:
                if(flag == 1)
                {
                    printf("INFO : Database is already created\n");
                }
            else if(creat_data_base(arr, &head) == FAILURE) {
                printf("Database Not created\n");
            }
            else{
                    printf("INFO : Database is created\n");
                flag=1;
                flag1=1;
            }

            break;
        case 2:
            display_Database(arr, size);
            break;
        case 3:
            if (search_database(arr, size) == FAILURE) {
                printf("INFO : word is not Found in database\n");
            }
            break;
        case 4:
            {
                char str[20];
                printf("Enter the file name to save database: ");
                scanf(" %[^\n]", str);  // This reads the file name including spaces
                save_database(str, arr, size);
            }
            break;
        case 5:
                           
                    if(flag1 == 1)
                    {
                        printf("INFO : Database is already created, Update is not possible\n");
                    }
                 
                else if (update_database(arr, size, &head, file_name) == FAILURE) {
                    print_list(head);
                }
                else{
                   printf("INFO : Database is updated Successfull\n");
                   print_list(head);
                   flag1=1;
                }
            
            break;
        case 6:
            return 0;
        default:
            printf("Invalid! Choose between 1-6\n");
    }

    // Clear the input buffer before reading the 'ch' character
    while (getchar() != '\n');  // This flushes the newline character from the buffer

    char ch;
    printf("\nDo you want to Continue ?\nEnter y/Y to continue and N/n to discontinue: ");
    scanf("%c", &ch);

    if (ch == 'N' || ch == 'n') {
        return 0;
    }

} while (op > 0 && op < 7);
return 0;

}

    

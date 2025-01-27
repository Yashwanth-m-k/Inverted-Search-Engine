#ifndef INVERTED_H
#define INVERTED_H

#define SUCCESS 0
#define FAILURE -1
// Structure for List
typedef struct  node
{
    /* data */
    char *file;
    struct node *link;
}Slist;
// struct for hashing

//struct main_node

 typedef struct main_node
 {
    int file_count;
    char word[20];
    struct main_node *main_link;
    struct sub_node *sub_link;
 }Main;
 typedef struct hash
{
    int key;
    struct main_node *hash_link;
}Hash;
 //struct sub_node
 typedef struct sub_node
 {
    int word_count;
    char *filename;
    struct sub_node *sub_link;
 }Sub;



//
int insert_at_last(Slist **head, char *file);
//
int print_list(Slist *head);
//
int find_node(Slist *head, char *key);
//
void creat_hash_table(Hash *table,int size);
//
int creat_data_base(Hash *arr,Slist **head);
//
void display_Database(Hash *arr, int size);
//
int search_database(Hash *arr,int size);
//
int save_database(char *str1,Hash *arr,int size);
//
int update_database(Hash *arr, int size,Slist **head,char *file);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct transaction
{
    char debit_credit;
    float amount;
    char username_origin[20];
    char username_destination[20];
}
transaction;
typedef struct node
{
    char previous_node_hash[258];
    char node_hash[258];
    transaction data;
    char next_node[258];
}
node;

//declare a function that takes in a string and prints the md5 hash of the string
void hash_function(char *string){
    unsigned char digest[16];
    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, string, strlen(string));
    MD5_Final(digest, &context);
    int i;
    for (i = 0; i < 16; i++)
        printf("%02x", digest[i]);
    printf("\n");

}

int main(void){
    //declare an array of 4 strings
    char *input_array[4];
    //declare 4 strings
    char *string1 = malloc(sizeof(char)*258);
    char *string2 = malloc(sizeof(char)*258);
    char *string3 = malloc(sizeof(char)*258);
    char *string4 = malloc(sizeof(char)*258);
    
    string1 = "abc";
    string2 = "def";
    string3 = "ghi";
    string4 = "jkl";
    //put the strings in the array
    input_array[0] = string1;
    input_array[1] = string2;
    input_array[2] = string3;
    input_array[3] = string4;

    //call the hash function
    hash_function(string1);
    return 0;
}
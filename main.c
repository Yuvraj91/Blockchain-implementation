#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <openssl/sha.h>
#include <unistd.h>

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

//sha256 hash function
char *sha256(char *str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    int i = 0;
    char *hash_str = (char *)malloc(SHA256_DIGEST_LENGTH * sizeof(char)*256);
    for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(hash_str + (i * 2), "%02x", hash[i]);
    }
    free(hash_str);
    return hash_str;
}
//login and signup validation
char losi(void)
{
    system("clear");
    printf("(L)ogin\n(S)ignup\n");
    char losi;
    scanf("%c", &losi);
    losi = tolower(losi);
    system("clear");
    return losi;
}

//login and signup validation
char *losin(void){
    //custom data-structure for profile
    typedef struct
    {
        char username[20];
        char password[16];
    }
    profile;
    profile template_profile;
    char a;
    //login and signup prompt
    do
    {
        a = losi();

        if(a == 'l'){
            printf("username:- ");
            scanf("%s",template_profile.username);
            printf("password:- ");
            scanf("%s",template_profile.password);
            break;
        }
        else if(a == 's'){
            printf("username:- ");
            scanf("%s",template_profile.username);
            printf("password:- ");
            scanf("%s",template_profile.password);
            break;
        }
        else{
            continue;
        }
    
    }while(1);

    system("clear");

    if(a == 'l'){
        //opening database
        FILE *db = fopen("user_database.csv","r");
        //exceptional handling
        if(db == NULL){
            printf("Some error opening file\n");
            return "failed";
        }
        //buffer for read
        char buffer[256];

        int row = -1;
        int column = 0;
        while(fgets(buffer, 256, db)){
            column = 0;
            row++;
            char *data = strtok(buffer, ", ");
            while(data){
                if(strcmp(data,sha256(template_profile.username)) == 0){
                    data = strtok(NULL,", ");
                    if(strcmp(data, sha256(template_profile.password)) == 0){
                        printf("You are now logged in as %s\n",template_profile.username);
                        char *logged_in_user = (char *)malloc(20 * sizeof(char));
                        strcpy(logged_in_user,template_profile.username);
                        return logged_in_user; 
                    }
                    else{
                        printf("Either the password or the username is not correct");
                        return "passed";
                    }
                }
                data = strtok(NULL,", ");
            }
        }
        fclose(db);
        return "passed";
    }
    else{
        //opening database
        FILE *db = fopen("user_database.csv","r+");
        //exceptional handling
        if(db == NULL){
            printf("Some error opening file\n");
            return "failed";
        }
        //buffer for reading
        char buffer[256];

        int row = -1;

        while(fgets(buffer, 256, db)){
            row++;
            char *data = strtok(buffer, ", ");
            while(data){
                if(strcmp(data,sha256(template_profile.username)) == 0){
                    printf("Username already exits");
                    return "passed";
                }
                data = strtok(NULL,", ");
            }
        }
        
        fprintf(db, "\n%s, %s,",sha256(template_profile.username), sha256(template_profile.password));
        printf("Account created\n");
        
        fclose(db);
    }
}

int main(void){
    char *username = losin();
    //wait for 2 seconds
    sleep(2);
    system("clear");
    printf("Welcome %s\n",username);
    return 0;
}
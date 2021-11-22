#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char previous_node_hash[258];
    char node_hash[258];
    char node_content[258];
    char next_node[258];
}
node;

int main(void){
    node temp;
    char default_starting_node_hash[258] = 0x0;
    char default_ending_node_hash[258] = 0xf;
    

}
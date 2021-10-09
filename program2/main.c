#include <stdio.h>
#include "class.h"
//main function
int main(int argc, char** argv) {
    
	node_t* list_head = NULL;
  

    // read in the file and place data in the data structure
    readClasses(&list_head);

    // Stay in this function until 'q' hit to handle user's requests
    queryUser(list_head);

    return(0);
}
     

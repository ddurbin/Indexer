
#include "indexer.h"

//function opens current file and hashes tokens to the hash table
int hash_Tokens(const char *fileName){
    if(fileName == NULL){   //file doens't exist
        printf("***Filename does not exist***\n");
        return 1;
    }
    int fileCheck;
    char c;
    char *string = (char*)malloc(sizeof(char));
    string = "";
    fileCheck = access(fileName, F_OK);
    if(fileCheck == 0){ //open file 
        fp = fopen(fileName, "r");
        c = getc(fp);
        while(c != EOF){    //create string to send to tokenizer
            c = tolower(c);
            string = Concat(string, c);
            c = getc(fp);
        }
    }
    tokenizer = TKCreate(string);
    char* token = TKGetNextToken(tokenizer);
    while(token != NULL ){ //parse and insert tokens into hash table
        HTinsert(ht, token, fileName);
        token = TKGetNextToken(tokenizer);
    }
    free(token);
    fclose(fp);
    return 0;
}

int main(int argc, const char * argv[]){
    
    if(argc < 3){
        printf("***Error improper number of command line arguments***\n");
    }
    ht = HTcreate(argv[1]);
    traverse_Dir((char*)argv[2]);
    HToutput(ht);
    HTdestroy(ht);
    return 0; 
}


char *Concat(char *string, char letter){    //concatenate character to end of a string
    char *str = string;
    char let = letter;
    size_t len = strlen(str);
    char *result = (char*) malloc((len + 2) * sizeof(char));
    strcpy(result, str);
    result[len] = let;
    return result;
}

char *ConcatString(char *string1, char *string2){   //concatenate 2 strings together
    size_t len = strlen(string2);
    int i;
    for(i = 0; i<len; i++){
        string1 = Concat(string1, string2[i]);
    }
    return string1;
}

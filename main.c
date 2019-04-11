#include <stdio.h>  
#include <string.h>

//Have prototype functions (total 4?) written here for 
//      Encrypting and decrypting rotation ciphers
//          Rotation ciphers with with a "key" which could be int k
//          which holds some value between -25 and 25 where 0 and 26
//          are imply no encryption.
//          See functions for equation information.
char roten(char codestr[], int rotfac);

char rotde(char codestr[], int rotfac);
//      Encrypting and decrytping substitution ciphers
//          No algebra here, essentially just a lookup table.
//          Use an array to hold the alphabet string
char suben(char codestr[], char substr[]);

char subde(char codestr[], char substr[]);    

int main(){
    int option;                 //for the switch so it knows what function it's handling
    char codestr[256];      //array storage for the string to be encrypted/decrypted
    int rotfac;                 //the key for rotation ciphers
    char substr[256];       //array for storing the key for substitution ciphers
    
//get information for what function is being performed
//      take the text string and store it in an array
//      take integer value of 1-4
    printf("select decryption option: \n1.Rotation encryption with key\n2.Rotation decryption with key\n");
    printf("3.Substitution encryption with key\n4.Substitution decryption with key\n");
    printf("5.Rotation brute force\n6.Substitution brute force");
    printf("Select option: ");
    scanf("%d", &option);


//set up a switch for performing the requested function
//Inside the Switch
switch(option){

//1.Rotation Encryption: Get the text string and rotation amount
//      scan rotation factor into memory
//      pass required variables into the appropriate function
    case 1:
        printf("Provide a rotation factor");
        scanf("%d", &rotfac);
        
        if(-25<= rotfac <= 25){
            printf("Input string for encryption")
            scanf("%s", codestr);
            char roten(char codestr[], int rotfac);
        }
        
        break;
    
//2.Rotation Decryption: Get the text string and rotation amount
//      scan rotation amount into memory    
//      pass required variables into the appropriate function
    case 2:
        printf("Provide a rotation factor");
        scanf("%d", &rotfac);
        
        if(-25<= rotfac <= 25){
            printf("Input string for encryption")
            scanf("%s", codestr);
            char rotde(char codestr[], int rotfac);
        break;
        
//3.Sub Enryption: Get the text string and alphabet substitution
//      scan alphabet string into an array
//      pass required variables into the appropriate function
    case 3:
        printf("Input string for encryption");
        scanf("%s", codestr);
        
        printf("input the substitution string");
        scanf("%s", substr);
        
        char suben(char codestr[], char substr[]);

        break;
    
//4.Sub Decryption: Get the text string and alphabet substitution
//      scan alphabet string into memory
//      pass required variables into the appropriate function
    case 4:
        printf("Input string for decryption");
        scanf("%s", &codestr);
        
        printf("input the substitution string");
        scanf("%s", &substr);
        
        char subde(char codestr[], char substr[]);

        break;
    
//5.Decrypt rotation with text only
//    case 5:
//        break;

//6.Decrypt sub with text only
//    case 6:
        
//        break;
    
    default: printf("invalid parameter supplied");
        break; 
    

//deafault.Throw the user out for invalid parameter

//print out the the text recieved, and the [de/en]crypted string
  }
  return 0;
  }


//Function for decrypting rotations goes here
//REQUIREMENTS: Text string
//              Rotation factor
//      d(c) = (c − k)(mod 26)

char rotde(char codestr[], int rotfac){
    if(rotfac == 0){
        printf("%s\n", codestr);
        printf("%s\n", codestr);
    }else{
        
    }
}

//Function for encrypting rotations goes here
//REQUIREMENTS: Text string
//              Rotation factor
//      e(x) = (m + k)(mod 26)

char roten(char codestr[], int rotfac){
    if(rotfac == 0){
        printf("%s\n", codestr);
        printf("%s\n", codestr);
    }else{
        
    }
}

//Function for decrypting substitution goes here
//REQUIREMENTS: Text string
//              alphabet string

char suben(char codestr[], char substr[]){
    
    
    
    if(strcmp(codestr, substr) == 0){
        printf("%s\n", codestr);
        printf("%s\n", codestr);
    }else{
        
    }
}
//Function for encrypting substitution goes here
//REQUIREMENTS: Text string
//              alphabet string

char subde(char codestr[], char substr[]){
    
    
    
    if(strcmp(codestr, substr) == 0){
        printf("%s\n", codestr);
        printf("%s\n", codestr);
    }else{
        
    }
}
#include <stdio.h>          //this is for fget(), and stdin
#include <string.h>         //this is for stringlen()
#include <stdlib.h>
#include "cipher_info.h"    //this is our header file

/*this is the prototype for the encryption function. It takes  */
void roten(char codestr[], int rotfac);

/*This is the decryption function. It passes the encrypted string (codestr), a key (rotfac) and passes it to 
the function of the same name below */
void rotde(char codestr[], int rotfac);
//      Encrypting and decrytping substitution ciphers
//          No algebra here, essentially just a lookup table.
//          Use an array to hold the alphabet string
void suben(char codestr[], char substr[]);

void subde(char codestr[], char substr[]);    

/*This is the main function. It takes a key and an encrypted/decrypted sting
before passing it on to the appropriate funtion by using a switch
It returns the users original string, and the changed text  */
int main(void){
    int option = 2;             //for the switch so it knows what function it's handling
    int rotfac = 2;             //the key for rotation ciphers
    char codestr[256];      //array storage for the string to be encrypted/decrypted
    char substr[256];       //array for storing the key for substitution ciphers
    
    

    
    
//set up a menu to initialise the switch
    printf("select decryption option: \n1.Rotation encryption with key\n2.Rotation decryption with key\n");
    printf("3.Substitution encryption with key\n4.Substitution decryption with key\n");
    printf("Select option: ");
    scanf("%d", &option);


//This is the switch that will take user info and return appropriate respones, or notify the user if an invalid option has been selected
switch(option){

//1.Rotation Encryption: Get the text string and rotation amount
//      scan rotation factor into memory
//      pass required variables into the appropriate function
    case 1:
        printf("Provide a rotation factor\n");              //ask for and scan in a rotation factor
        scanf("%d", &rotfac);
        
        printf("Input string for encryption: \n");            
        fgets(codestr, sizeof(codestr), stdin);             //scanf doesnt like spaces so using fgets, this also gets the size of the string
        
        printf("Your plain text is: %s" codestr);
        
        
        void roten(char codestr[], int rotfac);             //calling to the encryption function
        
        printf("The text will now read as:");
        roten(codestr, rotfac);                             //this is where we want the printf from the function we called to, to be
        
        printf("\n");                                      
        
        
        break;
    
/*2.Rotation Decryption: Get the text string and rotation amount
      scan rotation amount into memory    
      pass required variables into the appropriate function
*/
    case 2:
        printf("Provide a rotation factor\n");              //ask for and scan in a rotation factor
        scanf("%d", &rotfac);
        
        fgets(codestr, sizeof(codestr), stdin);             //scanf doesnt like spaces so using fgets, this also gets the size of the string
          
        void rotde(char codestr[], int rotfac);             //calling to the decryption function
        
        printf("The text will now read as: ");              
        rotde(codestr, rotfac);                             //Just like before, but we're printing our decryption here
        
        printf("\n");


        break;
        
//3.Sub Enryption: Get the text string and alphabet substitution
//      scan alphabet string into an array
//      pass required variables into the appropriate function                       
   case 3:
        printf("Input string for encryption");
        fgets("%s", codestr);
        
        fgets(codestr, sizeof(codestr), stdin);         //this is just like the rotation ciphers
        
        printf("input the substitution string");
        fgets("%s", substr);
        
        fgets(substr, sizeof(substr), stdin);           //this is just like the roation ciphers but sending the information to substr instead
        
        char suben(char codestr[], char substr[]);      //making the call to the substitution encryption function

        break;
 /*   
//4.Sub Decryption: Get the text string and alphabet substitution
//      scan alphabet string into memory
//      pass required variables into the appropriate function
    case 4:
        printf("Input string for decryption");
        fgets("%s", &codestr);
        
        printf("input the substitution string");
        fgets("%s", &substr);
        
        char subde(char codestr[], char substr[]);

        break;


//deafault.Throw the user out for invalid parameter   
    default: printf("invalid parameter supplied");      //bad variable from the user
        break; 
    return 0;
  }
  return 0;
  }


/*This is the decryption function known as rotde
It ses a while loop to print the letters of an encrypted string as plain text.
Takes in:   Text string
            Rotation factor
            Uses this equation: d(c) = (c − k)(mod 26) NOTE: it uses this format, not the exact letters
Returns: A decrypted string of letters, followed by a new line when the loop terminates
*/
void rotde(char codestr[], int rotfac){
    int i = 0;
    int cipherValue;
    char cipher;
    
    printf("decryption reached");

    while(codestr[0] != '\0' && strlen(codestr)-1 > i){
         cipherValue = ((int)codestr[i] - 65 - rotfac) % 26 + 65;
         cipher = (char)(cipherValue);
        
        printf("%c", cipher);
        i++;
    }
    printf("\n");
}

/*This is the encryption function, known as roten. It uses the same while loop method as rotde
but takes plain text and changes it to an encrypted string
Takes in:   Text string
            Rotation factor
            e(x) = (m + k)(mod 26) This format is similar to encryption but uses a + instead of a -
Returns: An encrypted string of letters followed by a new line at the end 
*/
void roten(char* codestr, int rotfac){
    int i = 0;
    int cipherValue;
    char cipher;
 
    while(codestr[i] != '\0' && strlen(codestr)-1 > i){
         cipherValue = ((int)codestr[i] - 65 + rotfac) % 26 + 65;
         cipher = (char)(cipherValue);
     
         printf("%c", cipher);
         i++;
    }
    printf("\n");
}

//Function for decrypting substitution goes here
//REQUIREMENTS: Text string
//              alphabet string

char suben(char *codestr[], char substr[]){
    int i = 0;
    int length = strlen(codestr);
    char *encrypt_mess = (char*) malloc(sizeof(char)*length);
    
    for(int i = 0; i < length; i++){
        int endex = toupper(codstr[i]) - 'a';
        if(endex >= 0 && endex < 26){
            encrypt_mess[i] = substr[i];
        }else{
            encrypt_mess[i] = codestr[i]
        }
    }
    return encrypt_mess
}

//Function for encrypting substitution goes here
//REQUIREMENTS: Text string
//              alphabet string
/*
char subde(char codestr[], char substr[]){
    
    
    
    if(strcmp(codestr, substr) == 0){
        printf("%s\n", codestr);
        printf("%s\n", codestr);
    }else{
        
    }
}*/
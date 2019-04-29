#include <stdio.h>          //this is for fgets(), and stdin
#include <string.h>         //this is for stringlen()
#include <stdlib.h>
#include <ctype.h>
#include "cipher_info.h"    //this is our header file, I'm not exactly sure if this is what the assignment wants, and at this point im too afraid to ask
//making this comment so git commits
/*This are the prototypes for the encryption/decryption functions. They take the plaintext string 
 and a KEY then use some math to change the ascii values around to decrypt/encrypt
*/
void en_rotation(char *MESSAGE, int KEY);

void de_rotation(char *MESSAGE, int KEY);

//void de_brute_rotation(char *MESSAGE, int KEY);

/* Encrypting and decrytping substitution ciphers
        No algebra here, essentially just a lookup table.
        Use an array to hold the alphabet string
*/
char *en_substitution(char *MESSAGE, char CODE[]);

char *de_substitution(char *MESSAGE, char CODE[]);    

int *find_index(char *CODE,char MESSAGE);

int main(void){
/*  
    int option;         //enables a switch for choosing a method
    int KEY;                //used to change values of the ratation ciphers
    char message[256];      //contains our message, should be big enough for the purposes of this course
    char CODE[26];          //this is to hold the changed alphabet
*/   
// this is a menu for selecting options, nothing fancy here, may come from a header later based on time constraints
    printf("Please choose an option for encryption or decryption\n");
    printf("1. Encryption via rotation\n");
    printf("2. Decryption via rotation\n");
    printf("3. Encryption via substitution\n");
    printf("4. Decryption via substitution\n");
//    printf("5. Brute force rotation decryption\n");
    
    switch(OPTION){
        case 1:
        /*This takes in the message, the KEY, and sends it to the function en_rotation
         * it then returns the results from that function, and pauses the system so the user can see the results
         *The first 3 lines of this are going to repeated across the board as it gathers basic info required everything to function
         * It may be deleted later once this is reading that info from elsewhere.
         */
            printf("\nRotation encryption\n");
            
            printf("\nEnter the text for encryption: ");
            
            fgets(MESSAGE, sizeof(MESSAGE), stdin);
            
            printf("\nYour plaintext is: %s \n", MESSAGE);
            
            printf("Your encrpyted text is: ");
            
            en_rotation(MESSAGE, KEY);           
        break;
         
        case 2:
        //this is largely similar to case 1 (encryption) but we're going the other way this time
            printf("\nRotation decryption\n");
            
            printf("Enter the text for decrpytion: ");
            
            fgets(MESSAGE, sizeof(MESSAGE), stdin);
            
            printf("\nYour plaintext is: %s \n", MESSAGE);
            
            printf("Your decrpyted text is: ");
            
            de_rotation(MESSAGE, KEY);
        break;
        
        case 3:
        /*This case handles substitution encryption. It's a bit tricky because C doesn't like just replacing things
         * so it has to function as essentially a lookup table and print letter by letter
         */
            printf("\nSubstitution encryption\n");
            
            printf("Enter the text for encryption: ");
            
            fgets(MESSAGE, sizeof(MESSAGE), stdin);
            
            /*declaring the message_sub_encrypt variable here so that I don't have to worry about it elsewhere
             * this is probably a bad practice but i expect this to be deleted in its entirity fairly soon*/
            char message_sub_encrypt = en_substitution(MESSAGE, CODE);
            
            printf("You plaintext is: %s\n", MESSAGE);
            
            printf("Your encrypted text is: %s\n", message_sub_encrypt);          
        break;
        
        case 4:
        /* This is going to be largely similar to the encryption but the function itself will call to an indexing function
         * 
         */
            printf("\nSubstitution decryption\n");
            
            printf("Enter the text for decryption: ");
            
            fgets(MESSAGE, sizeof(MESSAGE), stdin);
            
            char decrypt_sub_message = en_substitution(MESSAGE, CODE);      //surprise a bad habit makes a return because im largely copy pasting
                                                                            //similar structures
            printf("You plaintext is: %s\n", MESSAGE);
            
            printf("Your encrypted text is: %s\n", decrypt_sub_message);           
        break;
      
//        case 5:
            /*This is just going to run a function identical to de_rotation and print out every possible result
             * it'll just have a while loop, only need the message
             */
 /*           printf("Brute force rotation\n");
            
            printf("Enter the text for decryption: ");
            
            fgets(MESSAGE, sizeof(MESSAGE), stdin);
            
             printf("\nYour plaintext is: %s \n", MESSAGE);
            
            printf("Your decrpyted text is in here somewhere...\n ");
            
            de_brute_rotation(MESSAGE, KEY);
        break;
 */       
        default:
            printf("Invalid parameter supplied");
        break;
    
    }
    
    return 0;
}

/*This is the function for rotation encyption
    It takes in the message, and the rotation KEY
    It uses this KEY to change the ascii value of each letter in the message, resulting in an encrypted message being returned.
local variables will be a counting integer i
    a temp value for adjusting ascii values
    and a value to use for printing the value of each new letter before being incremented
*/
void en_rotation(char* MESSAGE, int KEY){
    int i = 0;
    int newValue;
    char newLetter;
    
/* I'm going to do this in a while loop because that's what feels comfortable for me here
The while loop is set up to run while one of two conditions have not been met
    The current character of the string "message" is not '\0' which is the value for enter
    The value of i is less than 255 which will allow the user to use all the space available in the array
*/
    
    while(MESSAGE[i] != '\0' && strlen(MESSAGE) > i){
        
        newValue = ((int)MESSAGE[i] - 65 + KEY) % 26 + 65;      //this is changing our ascii values to other letters for us
        
        newLetter = (char)(newValue);                           //this is temp storage for the new value
        
        printf("%c", newLetter);                                //printing the new letter so that we don't need to worry about saving it somewhere
        i++;                                                    //incrementing the counter so that it doesn't loop the first letter forever
    }
    printf("\n");
}
/*This is the function for ratoation decryption
   It functions largely identically to en_rotation, except that there is a slight adjustment
   that makes it go in the other direction
 It takes all the same inputs, and puts out info in the same manner as en_rotation
 It will also contain all the same local variable
 The only reason it's a seperate function is because im trash at coding and didn't want to muddle them together and mess something up
 */
void de_rotation(char *MESSAGE, int KEY){
    int i = 0;
    int newValue;
    char newLetter;
 /* I'm going to do this in a while loop because that's what feels comfortable for me here
The while loop is set up to run while one of two conditions have not been met
    The current character of the string "message" is not '\0' which is the value for enter
    The value of i is less than 255 which will allow the user to use all the space available in the array
*/  
    while(MESSAGE[i] != '\0' && strlen(MESSAGE) > i){
        
        newValue = ((int)MESSAGE[i] - 65 - KEY) % 26 + 65;      //the only difference is here right before "KEY" as this is going in the other direction
        
        newLetter = (char)(newValue);
        
        printf("%c", newLetter);
        
        i++;
    }
    printf("\n");
}

/*Substitution has been weird, so this will essentially go character by character, and only make a change if it needs to.
 *Takes in the plaintext message, and the CODE strings 
 *I'm only using upper case letters, so I'm going to make use of toupper just in case 
 * uses local counter i, an int length to check for weird values, and an int encryption_index to help change 
 * the letters to appropriate values
 * at the end of the loop it returns the new encrypted message(message_sub_encrypt)
 */
char *en_substitution(char *MESSAGE, char CODE[]){
    int length = strlen(MESSAGE);
    int encryption_index;
    
    char *message_sub_encrypt = (char *) malloc(sizeof(char)*length);   //allocating space for the message_sub_encrypt here
    
/*I'm running a for loop here because it felt a little more suited to this, than the while loops in the rotation stuff
 * In reality they are probably totally interchangable.
 *This will also contain an if statement which checks if the letter on the CODE is the same as the one in the message.
 * if they are, then the function just sends it
 */

    for(int i = 0; i < length; i++){
        int encryption_index = toupper(MESSAGE[i]) - 'A';       //bringing ascii values to the 0-26 range to make things easier
        if(encryption_index >= 0 && encryption_index <26){      //0-26 are postisions in the CODE string A through Z
            message_sub_encrypt[i] = CODE[encryption_index];     //this is where the change happens
        }else{
            message_sub_encrypt[i] = MESSAGE[i];                //if theyre the same then the loops just sends it as is
        }
    }
    return message_sub_encrypt;
}
/*This is the decryption sub function, it does similar stuff to the last one.
 * This one is special because it makes use of another function called index_lookup which ill talk about there
 * other than that it uses all the same stuff ints for i and length, then a decryption_index and (a new because of 
 * the new index function being used here) code_index for ascii stuff
 * then it passes back decrypt_sub_message
 */
char *de_substitution(char *MESSAGE, char CODE[]){
    int length = strlen(MESSAGE);
    int decryption_index;
    int code_index;
    
    char *decrypt_sub_message = (char *) malloc(sizeof(char)*length);       //assigning memory
    
    for(int i = 0; i < length; i++){
        int decryption_index = toupper(MESSAGE[i] - 'A');  
        if(decryption_index >= 0 && decryption_index < 26){
            int code_index = find_index(CODE, toupper(MESSAGE[i]));
            
           //just adding the ascii value of 'A' to the altered code_index value to get the original value          
            decrypt_sub_message[i] = 'A' + code_index;     
            
        }else{
            decrypt_sub_message[i] = MESSAGE[i];
        }
    }
    return decrypt_sub_message;
}

/*This is the find_index function that is used in de_substitution
 * this iterates until it finds a match, and then sends back the value to 
 * de_substitution
 */
int *find_index(char *CODE,char MESSAGE){
  
  for(int i = 0 ; i < 26; i++){
      if(CODE[i] == MESSAGE){
      
      return i;
    }
  }
  return -1;
}
/*Oh look its de_brute_rotation
 * we're just running de_decryption 25 times because there are only 26 combinations and we already have one
 */
/*void de_brute_rotation(char *MESSAGE, int KEY){
    int i = 0;
    int j = 0;
    int newValue;
    char newLetter;
    char newWord[256];
    
    //the for loop here should make the while loop repeat 25 more times
    for(int j = 0; j < 26; j++){
        while(MESSAGE[i] != '\0' && strlen(MESSAGE) > i){
        
            newValue = ((int)MESSAGE[i] - 65 - KEY) % 26 + 65;     
        
            newLetter = (char)(newValue);
        
            printf("%c", newLetter);
        
            i++;
        }
        newWord[j] == newValue;
        printf("\n");
        KEY++;
    }

}*/
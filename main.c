#include <stdio.h>
//Have prototype functions (total 4?) written here for 
//      Encrypting and decrypting rotation ciphers
//          Rotation ciphers with with a "key" which could be int k
//          which holds some value between -25 and 25 where 0 and 26
//          are imply no encryption.
//          See functions for equation information.

//      Encrypting and decrytping substitution ciphers
//          No algebra here, essentially just a lookup table.
//          Use an array to hold the alphabet string

int main(){
//get information for what function is being performed
//      take the text string and store it in an array
//      take integer value of 1-4

//set up a switch for performing the requested function
//Inside the Switch

//1.Rotation Encryption: Get the text string and rotation amount
//      scan rotation factor into memory
//      pass required variables into the appropriate function

//2.Rotation Decryption: Get the text string and rotation amount
//      scan rotation amount into memory    
//      pass required variables into the appropriate function

//3.Sub Enryption: Get the text string and alphabet substitution
//      scan alphabet string into an array
//      pass required variables into the appropriate function

//4.Sub Decryption: Get the text string and alphabet substitution
//      scan alphabet string into memory
//      pass required variables into the appropriate function

//5.Throw the user out for invalid parameter

//6.Decrypt rotation with text only

//7.Decrypt sub with text only

//print out the the text recieved, and the [de/en]crypted string
  return 0;
  }


//Function for decrypting rotations goes here
//REQUIREMENTS: Text string
//              Rotation factor
//      d(c) = (c − k)(mod 26)

//Function for encrypting rotations goes here
//REQUIREMENTS: Text string
//              Rotation factor
//      e(x) = (m + k)(mod 26)


//Function for decrypting substitution goes here
//REQUIREMENTS: Text string
//              alphabet string

//Function for encrypting substitution goes here
//REQUIREMENTS: Text string
//              alphabet string
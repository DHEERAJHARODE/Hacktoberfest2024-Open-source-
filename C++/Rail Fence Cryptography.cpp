#include<iostream>
using namespace std;

// return type is string that returns ciphertext and one argument that is plaintext
string encrypt(string plainText){
//   d denotes ciphertext
    string d="";
//   iterating over the plaintext for taking even indexed values
    for(int i=0;i<plainText.length();i+=2){
        d+=plainText[i];
    }
//   interating over the plaintext for taking odd indexed values
    for(int i=1;i<plainText.length();i+=2){
        d+=plainText[i];
    }
//   returning ciphertext
    return d;
}
// end of function
// return type is string that returns plaintext for the argument of ciphertext
string decrypt(string CipherText){
//   d stores plaintext
    string d="";
//  outputs will vary for even and odd length ciphertext.
//   firstly considering even length of ciphertext
    if(CipherText.length()%2==0){
//       adding the ith and n/2+ith index substring values from ciphertext to d till all the characters are not considered
        for(int i=0;i<CipherText.length()/2;i++){
            d+=CipherText[i];
            d+=CipherText[i+CipherText.length()/2];
        }
    }
//   considering odd length of ciphertext
    else{
//       n will keep a count of the length of string d
        int n=0;
//       determining the d (plaintext string)
        for(int i=0;n<CipherText.length();i=(i+CipherText.length()/2+1)%CipherText.length()){
            d+=CipherText[i];
            n++;
        }
    }
//   returning plaintext stored in d
    return d;
}
// end of decryption function
// main function
int main(){
//   text will store the string to be encrypted or decrpted
    string text;
    cout<<"Enter the string: ";
    cin>>text;
//   a will store the choice opted (either encryption or decryption
    char a;
    cout<<"Enter E for encryption and D for decryption: ";
    cin>>a;
//   if-else ladder for performing cryptography and printing result
    if(a=='E'){
        cout<<"Encrypted text: "<<encrypt(text);
    }
    else if(a=='D'){
        cout<<"Decrypted text: "<<decrypt(text);
    }
    else{
        cout<<"Invalid input!";
    }
//   end of if-else
}
// end of main block
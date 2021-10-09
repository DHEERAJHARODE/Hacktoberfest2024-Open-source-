// to decrpyt what we just encrypted by adding 1 to the ascii value
#include<stdio.h>
#include<string.h>
void decrypt (char *str){
    char *ptr=str;
    while(*ptr!='\0'){
        *ptr=*ptr-1;
        ptr++;
    }
}
int main(){
    char str[]="nxpovtff";
    decrypt(str);
    printf("Decrypted string:%s",str);
    return 0;
}
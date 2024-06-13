#include <stdio.h>
#include <ctype.h>

int main(void) {
	char user_ip;
	printf("\n *** Check Alphabet or no ***");
	printf("\n Enter Charcter: ");
	scanf("%c",&user_ip);
	if(isalpha(user_ip))
	{
	    printf("\n Is Alphabet.");
	}
	else if(isdigit(user_ip))
	{
	    printf("\n Is Number.");
	}
	else
	{
	   printf("\n neither alphabet nor number."); 
	}
	return 0;
}

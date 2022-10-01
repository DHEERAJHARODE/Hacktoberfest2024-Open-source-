#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
	int score,high_score = 0,input,i,random,time_bonus;
	time_t start_game_time,check_time, round_time;
	char y, mode;
	start: printf("Enter Y to start  ");
	scanf("%s", &y);
	if (y == 'y' || y == 'Y')
	{
		regame:
        printf("\nWhich mode would you like to play?\n");
		printf("1. Race Against Time\n2. Challenger Mode\n");
		mode_choice: printf("\nPick a choice: (1/2)\t");
		scanf("%s", &mode);
		input = 1; i = random = time_bonus = 0;
		if (mode == '1')
		{
			printf("\nYou have 20 seconds.\n");
			sleep(2);
			printf("Answer as fast as possible.\n");
			sleep(2);
			printf("Game starts in\t3  ");
			sleep(1);
			printf("2  ");
			sleep(1);
			printf("1  ");
			sleep(1);
			printf("...\n\n");
			time(&start_game_time);
			time(&check_time);
			while (input == pow(2, i) && (check_time - start_game_time) <= 20)
			{
				time(&round_time);
				printf("What is 2^%d?\t", i + 1);
				scanf("%d", &input);
				i++;
				time(&check_time);
				if (check_time - round_time <= 3)
				{
					time_bonus += 3 - (check_time - round_time);
				}
			}
		}
		else if (mode == '2')
		{
			printf("\nThere is no time limit.\n");
			sleep(2);
			printf("Level becomes difficult progressively.\n");
			sleep(2);
			printf("Game starts in\t3  ");
			sleep(1);
			printf("2  ");
			sleep(1);
			printf("1  ");
			sleep(1);
			printf("...\n\n");
			time(&start_game_time);
			time(&check_time);
			srand(time(NULL));
			while (input == pow(2, random))
			{
				random = ((rand() % 6)+i);
				time(&round_time);
				printf("What is 2^%d?\t", random);
				scanf("%d", &input);
				i++;
				time(&check_time);
				if (check_time - round_time <= 3)
				{
					time_bonus += 3 - (check_time - round_time);
				}
			}
		}
		else
		{
			printf("Invalid Choice\n");
			goto mode_choice;
		}
	}
	else
	{
		goto start;
	}

	score = (i - 1) *10 + time_bonus;
	if (score > high_score)
	{
		high_score = score;
	}

	printf("\n Raw Score \t : %d", (i - 1) *10);
	printf("\n Time Bonus \t : %d", time_bonus);
	printf("\n Final Score \t : %d\n", (i - 1) *10 + time_bonus);
	printf("\n Current High Score\t : %d\n", high_score);
	printf("\n\nWould you like to play again? (Y/n)\t");
	scanf("%s", &y);
	if (y == 'y' || y == 'Y')
		goto regame;
	else if (y == 'n' || y == 'N')
	{
		printf("\nThanks for playing. Please leave a feedback @anxkhn..\n");
		return 0;
	}
}

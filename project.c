// Name: Joseph Bertram
// Class: Fundamentals of Computing Lab
// Assignment: Lab 11: (Mini) Final Project
// Purpose: A simple hangman game that serves as my mini final project (Main Driver)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "projectfunc.h"


int main() {

	char name[16];
	char word[30];
	char theme[30];
	// char word_chosen[30];
	char letter;
	int choice;
	int choice2;
	int flag_past;
	int flag_current;
	int chance;
	int mistakes;
	int num_correct;
	int trials;
	int length;
	int check;
	int matches;
	int index;
	// int chosen_flag;

	while (choice != 2) {
		printf("Welcome to Hangman!");
		printf("\n");
		printf("\n");
		options();
		printf("Please enter the choice of your choosing: ");
		scanf("%d", &choice);
		getchar();
		printf("\n");

		if (choice == 1) {
			while (choice2 != 'n') {
				printf("Please enter your name: ");
				fgets(name, 15, stdin);
				name[strlen(name) - 1] = '\0';

				printf("Please enter the word: ");
				fgets(word, 29, stdin);
				word[strlen(word) - 1] = '\0';
				printf("Please enter the theme of the word: ");
				fgets(theme, 29, stdin);
				theme[strlen(theme) - 1] = '\0';
				printf("\n");

				printf("The game begins!");
				printf("\n");
				printf("\n");
				printf("The number of alphabets in the word: %d", strlen(word));
				printf("\n");
				printf("Theme of the word: %s", theme);
				printf("\n");
				printf("\n");


				flag_current = 0;
				flag_past = 0;
				chance = 7;
				printf("You have %d chances left", chance);
				printf("\n");
				printf("\n");
				mistakes = 0;
				num_correct = 0;
				draw_hangman(flag_current, flag_past, mistakes);
				length = strlen(word);

				char censored[strlen(word)];
				censor(word, censored);

				printf("Status of your word: %s", censored);
				printf("\n");
				printf("\n");

				check = 0;
				index = 0;


				while (chance > 0) {
					printf("Please enter your guess (one letter at a time): ");
					scanf("%c", &letter);
					getchar();
					letter = tolower(letter);
					// index = chosen(word_chosen, letter, index);
					// chosen_flag = check_chosen(word_chosen, letter);
					printf("\n");
					printf("\n");
					flag_current = match(letter, word, censored, length); 
					matches = replace(letter, word, censored, length);
					if (check == 0 && flag_current == 1) {
						check = 1;
						flag_past = 1;
					}
					mistakes = wrong(mistakes, flag_current);
					num_correct = correct(num_correct, flag_current, matches);
					chance = num_trials(word, chance, flag_current);
					draw_hangman(flag_current, flag_past, mistakes);
					printf("Status of your word: %s", censored);
					printf("\n");
					printf("\n");	
					comments(flag_current, chance, num_correct, mistakes, strlen(word));
					printf("You have %d trials left", chance);
					printf("\n");
					printf("\n");
					if (num_correct == strlen(word)) {
						break;
					}
					else if (chance == 0) {
						printf("Game Over! Better luck next time.");
						printf("\n");
						printf("The word you are trying to guess is: %s", word);
						printf("\n");
						printf("\n");
						break;
					}
				}
				printf("Do you still want to continue playing? (y for yes / n for no): ");
				scanf("%c", &choice2);
				getchar();
				printf("\n");
				if (choice2 == 'y') {
					continue;
				}
				else if (choice2 == 'n') {
					break;
				}
			}
		if (choice == 2) {
			printf("Goodbye!");
			printf("\n");
			break;
		}
		}
	}
	
	return 0;
}




// Name: Joseph Bertram
// Class: Fundamentals of Computing Lab
// Assignment: Lab 11: (Mini) Final Project
// Purpose: A simple hangman game that serves as my mini final project (Function)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "projectfunc.h"

void options() {

	printf("Please select a choice from the list of this drop down menu: ");
	printf("\n");
	printf("1. Play game");
	printf("\n");
	// printf("2. Help");
	// printf("\n");
	printf("2. Quit");
	printf("\n");

}

/*
int chosen(char chosen[], char letter, int index) {

	for (int i = 0; i < strlen(chosen); i++) {
		if (chosen[i] == letter) {
			return index;
		}
	}

	index = index + 1;

	chosen[index] = letter;
	
	return index;

}
*/


/*
void display_chosen(char chosen[], int length) {

	for (int i = 0; i < length; i++) {
		printf("%c", chosen[i]);
		printf(", ");
	}

}
*/

void censor(char word[16], char censored[]) {
	
	for (int i = 0; i < strlen(word); i++) {
		censored[i] = '_';
	}
}

void updated_censor(char censored[], char letter, int index) {

	censored[index] = letter;

}

int num_trials(char word[16], int count, int flag) {

	if (flag == 1) {
		count = count - 1;
	}
	else if (flag == 0) {
		count = count;
	}

	return count;
}

int wrong(int mistakes, int flag) {
	
	if (flag == 1) {
		mistakes = mistakes + 1;
	}
	else if (flag == 0) {
		mistakes = mistakes;
	}

	return mistakes;
}

int correct(int count, int flag, int matches) {
	
	if (flag == 0) {
		count = count + matches;
	}
	else if (flag == 1) {
		count = count;
	}

	return count;
}
	
void draw_hangman(int flag_current, int flag_past, int wrong ) {

	for (int i = 0; i < 21; i++) {
		printf("-");
	}
	printf("\n");
	
	printf("|");
	printf("                    |");
	printf("\n");

	if (flag_past == 1 && (wrong >= 1 && wrong <= 7)) {
		printf("|");
		printf("                    @");
		printf("\n");
	}
	else if ((flag_current == 0 || flag_past == 1)) {
		printf("|");
		printf("\n");
	}
	
	if (flag_past == 1 && (wrong >= 2 && wrong <= 7)) {
		printf("|");
		printf("                   /");
		// printf("\\");
		// printf("\n");
	}
	else if ((flag_current == 0 || flag_past == 1)) {
		printf("|");
		printf("\n");
	}
	
	if (flag_past == 1 && (wrong >= 3 && wrong <= 7)){
		printf("|");
	}
	else if ((flag_current == 0 || flag_past == 1)) {
		if (wrong >= 2 && wrong <= 7) {
			printf("\n");
			printf("|");
			printf("\n");
		}
		else {
			printf("|");
			printf("\n");
		}
	}
	
	if (flag_past == 1 && (wrong >= 4 && wrong <= 7)) {
		printf("\\");
		printf("\n");
	}
	else if (flag_current == 0 || flag_past == 1) {
		if (wrong >= 3 && wrong <= 7) {
			printf("\n");
			printf("|");
			printf("\n");
		}
		else {
			printf("|");
			printf("\n");
		}
	}

	if (flag_past == 1 && (wrong >= 5 && wrong <= 7)){
		printf("|");
		printf("                    |");
		printf("\n");
	}
	else if ((flag_current == 0 || flag_past == 1)) {
		printf("|");
		printf("\n");
	}

	if (flag_past == 1 && (wrong >= 6 && wrong <= 7)){
		printf("|");
		printf("                   /");
	}
	else if ((flag_current == 0 || flag_past == 1)) {
		printf("|");
		printf("\n");
	}

	if (flag_past == 1 && wrong == 7) {
		printf(" \\");
		printf("\n");
	}
	else if (flag_current == 0 || flag_past == 1) {
		if (wrong >= 6 && wrong <= 7) {
			printf("\n");
			printf("|");
			printf("\n");
		}
		else {
			printf("|");
			printf("\n");
		}
	}

	printf("|");
	printf("\n");
	printf("|");
	printf("\n");
	printf("|");
	printf("\n");
	printf("|");
	printf("\n");

	for (int i = 0; i < 4; i++) {
		printf("-");
	}
	printf("\n");
	
	printf("    |");
	printf("\n");
	printf("\n"); 
}

int match(char letter, char word[16], char censored[], int count) {

	int word_match = 0;

	for (int i = 0; i < count; i++) {
		if (letter == word[i]) {
			word_match = 0;
			break;
		}
		else {
			word_match = 1;
		}
	}

	return word_match;
}

int replace(char letter, char word[16], char censored[], int count) {

	int flag = match(letter, word, censored, count);
	int matches = 0;
	
	if (flag == 0) {
		for (int i = 0; i < count; i++) {
			if (letter == word[i]) {
				matches = matches + 1;
				updated_censor(censored, letter, i);
			}
		}
	}
	
	return matches;
}


void comments(int flag, int chance, int correct, int mistakes, int length) {

	if (flag == 0 && correct == length) {
		printf("Congratulations! You have fully revealed the word.");
		printf("\n");
	}
	else if (flag == 1 && chance == 0) {
		printf("Game Over! Better luck next time.");
		printf("\n");
	}
	else if (flag == 0 && chance > 0) {
		printf("Good Job!");
		printf("\n");
	}
	else if (flag == 1 && chance > 0) {
		printf("Try again!");
		printf("\n");
	}
	
}

/*
int check_chosen(char chosen[], char letter) {

	int chosen_flag = 1;

	for (int i = 0; i < strlen(chosen); i++) {
		if (chosen[i] == letter) {
			printf("You have already chosen that letter.");
			chosen_flag = 0;
			break;
		}
	}

	return chosen_flag;

}
*/		

	
		



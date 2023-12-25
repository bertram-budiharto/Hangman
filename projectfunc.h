// Name: Joseph Bertram
// Class: Fundamentals of Computing Lab
// Assignment: Lab 11: (Mini) Final Project
// Purpose: A simple hangman game that serves as my mini final project (Main Driver)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void options();
void censor(char [], char[]);
void updated_censor(char [], char, int );
void draw_hangman(int, int, int );
void comments(int, int, int, int, int );
// int chosen(char [], char, int );
// void display_chosen(char [], int );
// int check_chosen(char [], char );
int num_trials(char [], int , int );
int wrong(int, int );
int match(char, char[], char [], int);
int replace(char, char[], char [], int);
int correct(int, int, int);	


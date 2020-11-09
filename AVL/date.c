//author: jack tickoo 2397224t

#include "date.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date{
	int day;
	int month;
	int year;
};

Date *date_create(char *datestr){
	Date *a = malloc(sizeof(Date));
	if (a != NULL){
		char *token = strtok(datestr, "/");
		int counter = 0;
		while (token != NULL) {
			if (counter == 0){
				a->day = atoi(token);
			}
			else if (counter == 1){
				a->month = atoi(token);				
			}
			else if (counter == 2){
				a->year = atoi(token);
			}
		token = strtok(NULL, "/");
		counter ++; 
	} 
		return a;
	}
	else {
		return NULL;
	}

}	

Date *date_duplicate(Date *d){
	Date *a = malloc(sizeof(Date));
	if (a != NULL){
		a->day = a->day;
		a->month = a->month;
		a->year = a->year;
		return a;
	}
	else {
		return NULL;
	}
}

int date_compare(Date *date1, Date *date2){

	if (date1->year > date2->year){
		return 1;
	}
	else if (date1->year < date2->year){
		return -1;
	}
	else if (date1->month > date2->month){
		return 1;
	}
	else if (date1->month < date2->month){
		return -1;
	}
	else if (date1->day > date2->day){
		return 1;
	}
	else if (date1->day < date2->day){
		return -1;
	}		
	else {
		return 0;
	}
}

void date_destroy(Date *d){
	free(d);
}
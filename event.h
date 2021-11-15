#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#define TITLE_LENGTH 30


#ifndef EVENT_H
#define EVENT_H


typedef struct
{
	int AAAA, MM, DD, hh, mm;
}Date;

typedef struct
{
	int id;
	char title[TITLE_LENGTH];
	Date date;
} event;

typedef struct _node
{
	event value;
	struct _node *next;
} node;

void initList(node **head);
void prtList(node *head);
void prtEvent(event e);
node *newNode(event value);
void addToHead(node **head, node *newNode);
node *findTail(node *head);
void addToTail(node **head, node *newNode);
void loadList(node **head, void(*add)(node**, node*));
node *findEvent(node *head, int id);
int eventExists(node *head, int id);
void deleteEvent(node **head, int id);
void deleteHead(node **head);
void deleteTail(node **head);
void addInOrder(node **head, node *newNode);
int sumValues(node *head);
void deleteList(node **head);
void fileToList(char *file, node **head, void(*add)(node**,node*));
node *fusionLists(node **head, node **lista, node *fusion);


#endif // EVENT_H

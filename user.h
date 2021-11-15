#include "event.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define USER_LENGTH 20
#define PASS_LENGTH 20

#ifndef USER_H
#define USER_H

typedef struct
{
	char username[USER_LENGTH];
	char password[PASS_LENGTH];
	node *eventList;
}user;

typedef struct t_node
{
	user val;
	struct t_node *left;
	struct t_node *right;
}treeNode;

void initTree(treeNode **head);
treeNode *newTreeNode(user val);
treeNode *findFromId(treeNode *root, int id);
treeNode *findFromUsername(treeNode *root, char *username);
void insertTreeNode(treeNode **root, treeNode *newNode);
int countLeafs(treeNode *root);
int countNodes(treeNode *root);
treeNode *rightestNode(treeNode *root);
treeNode *leftestNode(treeNode *root);
void deleteTreeNode(treeNode **root, char *username);
void deleteTree(treeNode **root);
void balanceTree(treeNode **root);
void forceBalanceTree(treeNode **root);

void loadUser(treeNode **root);
char *logIn(treeNode *root);
void changeUsername(treeNode *root, char *username);
void changePassword(char *password);
void deleteUser(treeNode **root, char *username);

// PRINTING FUNCTIONS
void prtUser(user u);
void prtPreOrder(treeNode *root);
void prtInOrder(treeNode *root);
void prtPostOrder(treeNode *root);
void gotoxy(int x, int y);
void prtTree(treeNode *root);


#endif // USER_H

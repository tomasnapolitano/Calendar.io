#include "main.h"
// pruieasdas

int main()
{
	treeNode *root;
	char input;

	initTree(&root);

	do {
		mainMenu();
		input = getch();
		switch (input)
		{
		case 49:
			system("cls");
			userLogIn(&root);
			break;
		case 50:
			system("cls");
			loadUser(&root);
			balanceTree(&root);
			break;
		case 51:
			system("cls");
			prtInOrder(root);
			getch();
			break;
		case 52:
			system("cls");
			prtTree(root);
			getch();
			break;
		default:
			break;
		}

	} while (input != ESC);

	return 0;
}

/*
	Al cargar eventos, lo hago a nivel general buscando primero en el arbol a partir
	del username y despues cargandolo en la lista correspondiente o cargo en la lista
	directamente desde la estructura devuelta en el log-in?

	Log-in : corroboro con puntero a estructura y la devuelvo (NULL/puntero valido)?
*/

void userLogIn(treeNode **root)
{
	char input;
	char *userLog = logIn(*root);

	if (userLog)
	{
		logInMessage();
		do {
			userMenu();
			input = getch();
			switch (input)
			{
			case 51:
				input = userProfile(root, userLog);
				break;
			default:
				break;
			}
		} while (input != ESC);
	} else
	{
		logInErrorMessage();
	}
}

char userProfile(treeNode **root, char *username)
{
	char input;
	int deleted = 0;
	treeNode *temp = findFromUsername(*root, username);

	do {
		profileMenu(temp->val);
		input = getch();
		switch (input)
		{
		case 49:
			changePassword(temp->val.password);
			break;
		case 50:
			deleteUser(root, temp->val.username);
			deleted = 1;
			logOutMessage();
			break;
		default:
			break;
		}
	} while (input != ESC && !deleted);

	if (deleted)
		input = ESC;
	else
		input = 0;

	return input;
}

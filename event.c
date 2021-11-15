#include "event.h"

/// Inicializa la lista asignando NULL al nodo cabeza la de la misma
void initList(node **head)
{
    *head = NULL;
}

/// Recorro e imprimo los valores de la lista
void prtList(node *head)
{
    printf("\n");

    while(head)
    {
        prtEvent(head->value);
        head = head->next;
    }

    printf("\n");
}

/// Subprograma de prtList
void prtEvent(event e)
{
    printf("\nID.....: %d", e.id);
    printf("\nTitle..: %s", e.title);
    printf("\nDate...: %02d/%02d/%02d", e.date.DD, e.date.MM, e.date.AAAA);
    printf("\nTime...: %02d:%02d", e.date.hh, e.date.mm);
    printf("\n-----------------------");
}

/// Asigna el valor pasado por parametro a un nodo creado y retorna el mismo
node *newNode(event value)
{
    node *aux = (node *) malloc (sizeof(node));

    aux->value = value;
    aux->next = NULL;

    return aux;
}

/// Se agrega un nodo ya creado al inicio de la lista
void addToHead(node **head, node *newNode)
{
    if(*head)
    {
        newNode->next = (*head);
        (*head) = newNode;
    }else
    {
        (*head) = newNode;
    }
}

/// Subprograma de loadList
event insertEvent()
{
    char title[TITLE_LENGTH];
    int AAAA, MM, DD, hh, mm;
    event e;

    printf("\nTitle: ");
    fflush(stdin);
    scanf("%s", title);
    // Verify input..?
    strcpy(e.title, title);

    printf("\nDate: ");
    fflush(stdin);
    scanf("%d/%d/%d", &DD, &MM, &AAAA);
    // Verify input..?
    e.date.DD = DD;
    e.date.MM = MM;
    e.date.AAAA = AAAA;

    printf("\nTime: ");
    fflush(stdin);
    scanf("%d:%d", &hh, &mm);
    // Verify input..?
    e.date.hh = hh;
    e.date.mm = mm;

    return e;
}

/// Funcion de carga mediante ingreso del usuario
void loadList(node **head, void(*add)(node**, node*))
{
    node *temp = newNode(insertEvent());
    (*add)(head, temp);
}

/// Encuentra el ultimo nodo de la lista y lo retorna
node *findTail(node *head)
{
    node *tail = head;

    if(tail)
    {
        while(tail->next)
        {
            tail = tail->next;
        }
    }

    return tail;
}

/// Busca un nodo segun el valor pasado por parametro y lo devuelve (NULL si no lo encuentra)
node *findEvent(node *head, int id)
{
    if(head)
    {
        while(head && head->value.id != id)
        {
            head = head->next;
        }
    }

    return head;
}

/// Busca un nodo segun el valor pasado por parametro y devuelve 1 o 0  
int eventExists(node *head, int id)
{
    int flag = 0;

    if(head)
    {
        while(head && head->value.id != id)
        {
            head = head->next;
        }

        if(head && head->value.id == id)
        {
            flag = 1;
        }
    }

    return flag;
}

/// Agrega un nodo creado al final de la lista
void addToTail(node **head, node *newNode)
{
    if(!(*head))
    {
        *head = newNode;
    }else
    {
        node *tail = findTail(*head);
        tail->next = newNode;
    }
}

/// Elimina un nodo si coincide con el valor pasado por parametro
void deleteEvent(node **head, int id)
{
    if((*head) && (*head)->value.id == id)
    {
        node *aux = (*head);
        (*head) = (*head)->next;
        free(aux);
    }else
    {
        node *prev;
        node *temp = (*head);

        while(temp && temp->value.id != id)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp)
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}

/// Agrega un nodo en orden ascendente a la lista
void addInOrder(node **head, node *newNode)
{
    if(*head == NULL)
    {
        *head = newNode;
    }else
    {
        if(*head && newNode->value.id <= (*head)->value.id)
        {
            newNode->next = (*head);
            (*head) = newNode;
        }else
        {
            node *temp = (*head);
            node *prev;

            while(temp && temp->value.id <= newNode->value.id)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = newNode;
            newNode->next = temp;
        }
    }
}

/// Elimina la lista y libera el espacio en memoria
void deleteList(node **head)
{
    if(*head)
    {
        node *temp;

        while(*head)
        {
            temp = (*head);
            (*head) = (*head)->next;
            free(temp);
        }
    }
}

/// Elimina el primer nodo de la lista
void deleteHead(node **head)
{
    if(*head)
    {
        node *temp = (*head);
        (*head) = (*head)-> next;
        free(temp);
    }
}

/// Elimina el ultimo nodo de la lista
void deleteTail(node **head)
{
    if(*head)
    {
        if((*head)->next == NULL)
        {
            node *temp = (*head);
            (*head) = (*head)->next;
            free(temp);
        }else
        {
            node *temp = (*head);
            node *prev;

            while(temp->next)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = NULL;
            free(temp);
        }
    }
}
#include <stdio.h>
#include <malloc.h>
#include "list.h"

List create(){
    List list;
    list.root = NULL;
    list.len = 0;
    return list;
}

Node *nodeCreate(int x){
    size_t tam = sizeof(Node);
    Node *node = (Node *)malloc(tam);
    node -> data = x;
    node -> next = NULL;
    return node;
}

void addBegin(List *list, int x){
    Node *node = nodeCreate(x);
    node -> next = list -> root;
    list -> root = node;
    list -> len++;
}

void addEnd(List *list, int x){
    Node *node = nodeCreate(x);
    Node *p = list -> root;
    while(p -> next != NULL){
        p = p -> next;
    }
    p -> next = node;
}

void print(List *list){
    Node *p = list -> root;
    while(p != NULL){
        printf("%d ", p -> data);
        p = p -> next;
    }
}

void delete(List *, int){
    if (list -> root == NULL)
    return;

    Node * anterior = list -> root;
    Node * atual = list -> root;

    while (atual != NULL){
        if (atual -> data == x){
            anterior -> next = atual -> next;
            free(atual);
            list -> len--;
            return;
        }
        anterior = atual;
        atual = atual -> next;
    }
    
    
}
// tem que ser recursivo pois se destruir o primeiro ficaria sem referencia para os proximos
void _destroy(Node * node){
    if (node == NULL)
    return;

    _destroy(node -> next);
    free(node);    
}

void destroy(List * list){
    _destroy(list -> root);
    free(list);
}

void reverse(List *){

}




int main(){
    List lista = create();
    addEnd(&lista, 9);
    addEnd(&lista, 11);
    addEnd(&lista, 13);
    addBegin(&lista, 7);

    printf("%d \n", lista.len);

    print(&lista);
    delete(&lista,11);
    print(&lista);



    return 0;
}
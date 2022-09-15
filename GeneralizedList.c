#include "GeneralizedList.h"

int addAtom(Node **list, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return -1;
    node->type=0;
    node->atomList.atom=data;
    node->tail=NULL;
    if (*list == NULL){
        *list = node;
    } else {
        Node *aux = NULL;
        for (aux = *list; aux->tail!=NULL; aux=aux->tail);
        aux->tail = node;
    }
    return 1;
}

int addList(Node **list, Node **subList) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return -1;
    node->type=1;
    node->atomList.list = *subList;
    node->tail=NULL;
    if (*list == NULL){
        *list = node;
    } else {
        Node *aux = NULL;
        for (aux = *list; aux->tail!=NULL; aux=aux->tail);
        aux->tail = node;
    }
    return 1;
}

Node* head(Node *list) {
    Node *headAux = NULL;
    if ((list)->type==0){
        headAux = (Node*)malloc(sizeof(Node));
        headAux->type=0;
        headAux->atomList.atom = (list)->atomList.atom;
        headAux->tail=NULL;
    }else{
        headAux = list->atomList.list;
    }
    return headAux;
}

Node* tail(Node *list) {
    return (list)->tail;
}

void showGeneralizedList(Node *list){
    printf("( ");
    Node *aux = NULL;
    for (aux = list; aux!=NULL; aux=aux->tail) {
        if (aux->type==0) {
            printf("%d ",aux->atomList.atom);
        } else {
            showGeneralizedList(aux->atomList.list);
        }
    }
    printf(")");
}

int depth(Node *list) {
    int profundidadeAtual = 0;
    if (list==NULL)
        return 0;
    
    Node *aux = NULL;
    for (aux = list; aux!=NULL; aux=aux->tail) {
        if (aux->type==1) {
            int prof = depth(aux->atomList.list);
            if (prof>profundidadeAtual)
                profundidadeAtual=prof;
        }
    }
    return profundidadeAtual+1;
}

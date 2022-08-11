#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

void init(LinkedList *list) {
    log_info("Inicializando a lista");
    log_trace("init ->");
    list->first=NULL;
    list->size=0;
    log_debug("list->first: %p", list->first);
    log_debug("list->size: %d", list->size);
    log_trace("init <-");
}

int enqueue(LinkedList *list, void *data) {
    log_info("Adicionando elemento na fila");
    log_trace("enqueue ->");    
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        log_error("Memória insuficiente!");
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;
    log_debug("newNode(data,next): %p(%p,%p)",newNode,newNode->data,newNode->next);
    if (isEmpty(list)) {            //se a lista estiver vazia
        log_debug("A lista está vazia");
        list->first = newNode;    //novo nó é o primeiro
        log_debug("list->first: %p", list->first);
    } else {
        Node *aux = list->first;  //aux aponta para o primeiro
        log_debug("(aux,next):(%p,%p)",aux,aux->next);
        while (aux->next != NULL) { //enquanto não for o último nó
            aux = aux->next;      //aux avança para o nó seguinte
            log_debug("(aux,next):(%p,%p)",aux,aux->next);
        }
        aux->next = newNode;      //último nó aponta para o novo nó
    }

    list->size++;
    log_trace("enqueue <-");
    return 1;
}

void* dequeue(LinkedList *list) {
    log_info("Removendo elemento da fila");
    log_trace("dequeue ->");    
    if (isEmpty(list)) {
        log_warn("Não há elementos a serem removidos");
        return NULL;
    }
    Node *trash = list->first;
    list->first = list->first->next;
    
    void *data = trash->data;
    free(trash);
    list->size--;
    
    log_trace("dequeue <-");
    return data;
}

void* first(LinkedList *list) {
    return (isEmpty(list))?NULL:list->first->data;
}

void* last(LinkedList *list) {
    log_info("Buscando último elemento da lista");
    log_trace("last ->");    
    void *data = NULL;
    if (!isEmpty(list)) {          //Se a lista não estiver vazia
        Node *aux = list->first;   //aux aponta para o primeiro nó
        while (aux->next != NULL)  //enquanto não for o último nó
            aux = aux->next;       //aux avança para o nó seguinte
        data = aux->data;          //endereço de memória do dado no último nó
    }
    log_trace("dequeue <-");    
    return data;
}

int push(LinkedList *list, void *data) {
    log_info("Inserindo elemento na pilha");
    log_trace("push ->");    
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) {
        log_error("Memória insuficiente!");
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty(list))               //se a lista estiver vazia
        list->first = newNode;       //novo nó é o primeiro
    else {
        newNode->next = list->first; //o topo atual será o segundo da lista
        list->first = newNode;       //o novo nó será o topo
    }

    list->size++;
    log_trace("push <-");    
    return 1;
}

void* pop(LinkedList *list) {
    return dequeue(list);
}

void* top(LinkedList *list) {
    return first(list);
}

bool isEmpty(LinkedList *list) {
    return (list->size==0);
}

int indexOf(LinkedList *list, void *data, compare equal) {
    log_info("Buscando posição do elemento");
    log_trace("indexOf ->");    
    if (isEmpty(list)) return -1;
    int count=0;
    Node *aux = list->first;
   
    while(aux!=NULL && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    log_trace("indexOf <-");    
    return (aux==NULL)?-1:count;
}

Node* getNodeByPos(LinkedList *list, int pos) {
    log_info("Obtendo o Nó de uma posição");
    log_trace("getNodeByPos ->");    
    if (isEmpty(list) || pos>=list->size) return NULL;

    Node *aux = list->first;

    for (int count=0;(aux!=NULL && count<pos);count++,aux=aux->next);
    log_trace("getNodeByPos <-");
    return aux;
}

void* getPos(LinkedList *list, int pos) {
    log_info("Buscando o dado em uma posição");
    log_trace("getPos ->");    
    Node *aux = getNodeByPos(list,pos);
    log_trace("getPos <-");
    if (aux==NULL) 
        return NULL;
    else
        return aux->data;
}

int add(LinkedList *list, int pos, void *data) {
    log_info("Adicionando elemento em uma posição");
    log_trace("add ->");    
    if (pos <= 0) return push(list,data);

    Node *aux = getNodeByPos(list, (pos-1));
    if (aux==NULL) return -2;
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) {
        log_error("Memória insuficiente!");
        return -1;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    newNode->next = aux->next;
    aux->next = newNode;
    
    list->size++;
    log_trace("add <-");    
    return 1;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource) {
    log_info("Adicionando vários elementos a partir de uma posição");
    log_trace("addAll ->");
    if (listDest==NULL || isEmpty(listDest)) return -1;
    if (listSource==NULL || isEmpty(listSource)) return -2;

    Node *last = NULL;
    for (last = listSource->first;last->next!=NULL;last=last->next);
    if (pos == 0) {
        last->next = listDest->first;
        listDest->first = listSource->first;
    } else {
        Node *aux = getNodeByPos(listDest, (pos-1));
        if (aux==NULL) return -3;        
        last->next = aux->next; 
        aux->next = listSource->first;
    }
    listDest->size+=listSource->size;
    log_trace("addAll ->");
    return listSource->size;
}

void* removePos(LinkedList *list, int pos) {
    log_info("Removendo uma posição da lista");
    log_trace("removePos ->");
    if (isEmpty(list) || pos>=list->size) return NULL;
    
    Node *nodeRemove = NULL;
    Node *aux = NULL;
       
    if (pos<=0)
        return dequeue(list);
    else
        aux = getNodeByPos(list, pos-1);

    nodeRemove = aux->next;
    aux->next = nodeRemove->next;
    
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    log_trace("removePos <-");    
    return dataRemove;
}

bool removeData(LinkedList *list, void *data, compare equal) {
    log_info("Removendo um dado da lista");
    log_trace("removeData ->");
    if (isEmpty(list)) return -1;

    Node *nodeRemove = NULL;
    if (equal(list->first->data,data)) {
        nodeRemove = list->first;
        list->first = list->first->next;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        log_trace("removeData <-");
        return true;
    } else {
        Node *aux = list->first;
        while(aux->next!=NULL && !equal(aux->next->data,data))
            aux=aux->next;
    
        if (aux->next!=NULL) {
            Node *nodeRemove = aux->next;
            aux->next = nodeRemove->next;
            free(nodeRemove->data);
            free(nodeRemove);
            list->size--;
            log_trace("removeData <-");
            return true;
        } else {
            log_trace("removeData <-");
            return false;
        }
    }
}
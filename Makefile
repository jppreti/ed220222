all: clean pointers linkedlist

pointers:
	@echo ""
	@echo "============================="
	@echo "|       PONTEIROS           |"
	@echo "============================="
	@echo "Compilando o exemplo de ponteiros. Programa pointers."
	gcc Pointers.c -o pointers
	gcc PointersMatrix.c -o pointersmatrix
	chmod +x pointers
	chmod +x pointersmatrix
linkedlist:
	@echo ""
	@echo "============================="
	@echo "|         LISTAS            |"
	@echo "============================="
	@echo "Compilando o exemplo de lista simplesmente ligada."
	gcc log.h log.c LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	chmod +x linkedlist
	@echo "Compilando o exemplo de lista simplesmente ligada."
	gcc log.h log.c DoublyLinkedList.h DoublyLinkedList.c DoublyLinkedListTest.c -o doublylinkedlist
	chmod +x doublylinkedlist
	@echo "Compilando o exemplo de lista generalizada."
	gcc log.h log.c GeneralizedList.h GeneralizedList.c GeneralizedListTest.c -o generalizedlist
	chmod +x generalizedlist
clean:
	@echo ""
	@echo "============================="
	@echo "|   REMOVENDO PROGRAMAS     |"
	@echo "============================="
	@echo "Removendo todos os arquivos compilados"
	rm -f pointers pointersmatrix linkedlist doublylinkedlist generalizedlist
all: clear pointers linkedlist

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
	gcc LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	chmod +x linkedlist
clear:
	@echo ""
	@echo "============================="
	@echo "|   REMOVENDO PROGRAMAS     |"
	@echo "============================="
	@echo "Removendo todos os arquivos compilados"
	rm -f pointers pointersmatrix linkedlist
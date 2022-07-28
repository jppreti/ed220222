all: clear pointers

pointers:
	@echo -e "\nCompilando o exemplo de ponteiros. Programa pointers."
	gcc Pointers.c -o pointers
	gcc PointersMatrix.c -o pointersmatrix
	chmod +x pointers
	chmod +x pointersmatrix
clear:
	@echo -e "\nRemovendo todos os arquivos compilados"
	rm -f pointers pointersmatrix
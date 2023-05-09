all:compile run

compile:
	gcc -I ./include/ -o ./lib/Tactic.o -c ./src/Tactic.c
	gcc -I ./include/ -o ./lib/TacticA.o -c ./src/TacticA.c
	gcc -I ./include/ -o ./lib/TacticB.o -c ./src/TacticB.c
	gcc -I ./include/ -o ./lib/Production.o -c ./src/Production.c
	gcc -I ./include/ -o ./lib/ProductionA.o -c ./src/ProductionA.c
	gcc -I ./include/ -o ./lib/ProductionB.o -c ./src/ProductionB.c
	gcc -I ./include/ -o ./bin/Program ./lib/Tactic.o ./lib/TacticA.o ./lib/TacticB.o ./lib/Production.o ./lib/ProductionA.o ./lib/ProductionB.o ./src/Test.c	

run:
	./bin/Program
main: bank.o account.o date.o
	g++ bank.o account.o date.o -o bank
bank.o: bank.cpp account.h
	g++ -c bank.cpp
account.o: account.cpp account.h
	g++ -c account.cpp
date.o: date.cpp date.h
	g++ -c date.cpp
clean:
	rm *.o
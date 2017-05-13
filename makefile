main: bank.o account.o
	g++ bank.o account.o -o bank
bank.o: bank.cpp account.h
	g++ -c bank.cpp
account.o: account.cpp account.h
	g++ -c account.cpp
clean:
	rm *.o
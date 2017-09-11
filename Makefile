# author Janik Tinz
CC = g++

OBJ = Account.o CompanyGiroAccount.o PrivateGiroAccount.o Transaction.o TransactionsGenerator.o Management.o Menu.o main.o

# name of the program
TARGET = bankManagement

FLAGS = -g -std=c++14 -Wall -MMD -fmessage-length=0

all: $(TARGET)

# "make clean" delete all *.o files
clean:
	rm bankManagement $(OBJ)

%.o : %.cpp
	$(CC) -c $(FLAGS) -o $@ $<

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)
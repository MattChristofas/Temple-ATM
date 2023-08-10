#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Matthew Christofas
February 8, 2023
Computer Systems & LL Programming
Lab 03 ATM Machine
Mission: Write a C Program for an ATM machine by implementing functions and
protect your program from suspicious activities.
*/

#define PIN 3014
int pin,transaction,receipt;
int i = 0;
int g = 0;
int ag = 0;
double balance = 5000;
int numtransactions = 0;
int withdrawallimit = 0;

int checkbalance (int y);
int cashwithdrawal (int x);
int cashdeposition (int z);
int printreceipt (int r);
int runagain(int p);


int main(){
    printf("\nWelcome to the Temple ATM!\n\nPlease enter your pin number:");
    scanf("%4d", &pin);

    if(pin == PIN){
        printf("\nVALID PIN NUMBER\n");
        printf("\nPlease choose a transaction type.\n\n1. Balance\n2. Cash withdrawal\n3. Cash deposition\n4. Quit\n\n");
        scanf("%d", &transaction);

        if(transaction == 1){
            checkbalance(transaction);
            numtransactions++;
            transaction = 0;
            runagain(ag);
        }
        if (transaction == 2){
            cashwithdrawal(transaction);
            numtransactions++;
            transaction = 0;
            printreceipt(1);
            runagain(ag);
        }
        if (transaction == 3){
            cashdeposition(transaction);
            numtransactions++;
            transaction = 0;
            runagain(ag);
        }
        if (transaction == 4){
            printreceipt(transaction);
            transaction = 0;
            runagain(ag);
        }
    } 
    else{
    
        while (pin != PIN) {
            printf("Incorrect PIN, please reenter your PIN number: ");
            scanf("%d", &pin);
            i++;

            
            if(i>2){
                printf("\nToo many incorrect PIN attempts.\nGoodbye.\n");
                exit(0);
            }
        }
        printf("\nVALID PIN NUMBER\n");
        printf("\nPlease choose a transaction type.\n\n1. Balance\n2. Cash withdrawal\n3. Cash deposition\n4. Quit\n\n");
        scanf("%d", &transaction);

        if(transaction == 1){
            checkbalance(transaction);
            numtransactions++;
            transaction = 0;
            runagain(ag);
        }
        if (transaction == 2){
            cashwithdrawal(transaction);
            numtransactions++;
            transaction = 0;
            printreceipt(1);
            runagain(ag);
        }
        if (transaction == 3){
            cashdeposition(transaction);
            numtransactions++;
            transaction = 0;
            runagain(ag);
        }
        if (transaction == 4){
            printreceipt(transaction);
            transaction = 0;
            runagain(ag);
        }
        
    }
    
    
    
    }


    


int checkbalance (int y){
    printf("\nBalance: $%.2f\n", balance);
}

int cashwithdrawal (int x){
    int twenties;
    printf("How much would you like to withdrawal?\nPlease enter amount in multiples of $20: $");
    scanf("%d", &twenties);
    
    if (twenties % 20 == 0 ){
        balance = balance - twenties;
        printf("\nUpdated Balance: $%.2f\n", balance);
    }
    else{
        while (twenties % 20 != 0) {
            printf("ERROR.\nPlease enter a withdrawal amount in multiples of $20: $");
            scanf("%d", &twenties);
            g++;

            
            if(g>1){
                printf("\nToo many incorrect withdrawal attempts.\nGoodbye.\n");
                exit(0);
            }
        }
    }
    
    
}

int cashdeposition(int z){
    int deposition;
    puts("Please enter deposition amount.\nNO change accepted: $ ");
    scanf("%d", &deposition);
    if (deposition % 1 != 0){
        puts("ERROR.\nPlease enter a valid deposition amount.\nNO change: $ ");
        scanf("%d", &deposition);
    }
    else{
        balance = balance + deposition;
        printf("\nUpdated Balance: $%.2f\n", balance);
    }

}

int printreceipt(int r){
    receipt = 0;
    puts("\nWould you like a receipt?\nEnter 1 for YES or 2 for NO\n");
    scanf("%d",&receipt);

    if(receipt == 1){
        printf("Receipt Printing...\nThank you for using the Temple ATM\nNumber of transactions: %d\n",numtransactions);
        exit(0);
    }
    else {
        printf("\nThank you for using the Temple ATM\nNumber of transactions: %d\n",numtransactions);
        exit(0);
    }
}

int runagain(int p){
    printf("Would you like to complete another transaction?\n Enter 1 for YES or 2 for NO: ");
    scanf("%d",&ag);
    while (ag == 1){
        printf("\nPlease choose a transaction type.\n\n1. Balance\n2. Cash withdrawal\n3. Cash deposition\n4. Quit\n\n");
        scanf("%d", &transaction);

        if(transaction == 1){
            checkbalance(transaction);
            numtransactions++;
            transaction = 0;
        }
        if (transaction == 2){
            cashwithdrawal(transaction);
            numtransactions++;
            transaction = 0;
        }
        if (transaction == 3){
            cashdeposition(transaction);
            numtransactions++;
            transaction = 0;
        }
        if (transaction == 4){
            printreceipt(transaction);
            transaction = 0;
        }
    }
    if(ag == 2){
        printreceipt(receipt);
    }
}


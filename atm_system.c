#include<stdio.h>
#include<string.h>

typedef struct Account {
    int ac_number;
    char name[50];
    int age;
    float balance;
    int card;
    int pass;
} Ac;

void saveCustomer(int *index, Ac clint[]) {
if (*index < 500) {
for (int i = 1; i <= 500; i++) {
    for (int j = 6789; j >= 1; j--) {
    printf("\n");
    printf("===== OM's Bank =====\n");
    printf("Enter The Name: ");
    scanf("%49s", clint[*index].name);
    printf("Enter The Age: ");
    scanf("%d", &clint[*index].age);
    clint[*index].ac_number = *index + 1;
    clint[*index].card = strlen(clint[*index].name) * 4586 * clint[*index].age;
    clint[*index].pass = strlen(clint[*index].name) * 4586 + clint[*index].age;
    clint[*index].balance = 0; 
    printf("Your Account Created Successfully\n");
    printf("-----------------------------\n");
    printf("Your Account Number is = %d\n", clint[*index].ac_number);
    printf("Your Card Number is    = %d\n", clint[*index].card);
    printf("Your Password is       = %d\n", clint[*index].pass);

    (*index)++;
    break; 
            }
            break; 
        }
    } else {
        printf("Array is full. Cannot add more entries.\n");
    }
}

void deposit(Ac *customer) {
    float amount;
    printf("\nEnter the amount to deposit: ");
    scanf("%f", &amount);
    customer->balance += amount;
    printf("Amount deposited successfully. Your new balance is: %.2f\n", customer->balance);
}

void withdrawal(Ac *customer) {
    float amount;
    printf("\nEnter the amount to withdraw: ");
    scanf("%f", &amount);
    customer->balance -= amount;
    printf("Amount withdrawn successfully. Your new balance is: %.2f\n", customer->balance);
}

int main() {
    Ac clint[500];
    int index = 0;
    int op;

    do {
        printf("\n");
        printf("===== OM's Bank =====\n");
        printf("1 - Create Bank Account\n");
        printf("2 - Deposit\n");
        printf("3 - Withdrawal\n");
        printf("4 - Balance Check\n");
        printf("5 - Exit\n");
        printf("Choose The Option (1-5): ");
        scanf("%d", &op);

 switch (op) {
     case 1:
     saveCustomer(&index, clint);
     break;

    case 2:
    if (index > 0) {
    int accountNumber;
     int accountCard;
    int accountPass;
    printf("\n");
    printf("===== DEPOSIT =====\n");
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("Enter your account card number: ");
    scanf("%d", &accountCard);
    printf("Enter your account pass: ");
    scanf("%d", &accountPass);

     int i;
    for (i = 0; i < index; i++) {
    if (clint[i].ac_number == accountNumber && clint[i].card == accountCard && clint[i].pass == accountPass) {
    deposit(&clint[i]);
         break;
         }
    }

    if (i == index) {
     printf("Account not found.\n");
     }
} else {
    printf("No accounts available. Please create an account first.\n");
        }
    break;

    case 3:
    if (index > 0) {
        int accountNumber;
        int accountCard;
         int accountPass;
         printf("\n");
        printf("===== WITHDRAWAL =====\n");
         printf("Enter your account number: ");
         scanf("%d", &accountNumber);
         printf("Enter your account card number: ");
         scanf("%d", &accountCard);
         printf("Enter your account pass: ");
         scanf("%d", &accountPass);

        int i;
for (i = 0; i < index; i++) {
        if (clint[i].ac_number == accountNumber && clint[i].card == accountCard && clint[i].pass == accountPass) {
         withdrawal(&clint[i]);
                break;
        }
    }
if (i == index) {
    printf("Account not found.\n");
}
} else {
printf("No accounts available. Please create an account first.\n");
}
break;
 case 4:
 if (index > 0) {
     int accountNumber;
     int accountCard;
    int accountPass;
    printf("\n");
     printf("===== BALANCE CHECK =====\n");
printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("Enter your account card number: ");
    scanf("%d", &accountCard);
 printf("Enter your account pass: ");
 scanf("%d", &accountPass);

     int i;
    for (i = 0; i < index; i++) {
     if (clint[i].ac_number == accountNumber && clint[i].card == accountCard && clint[i].pass == accountPass) {
      printf("\n");
    printf("Account Number : %d\n", clint[i].ac_number);
    printf("Name           : %s\n", clint[i].name);
    printf("Age            : %d\n", clint[i].age);
    printf("Balance        : %.2f\n", clint[i].balance);
    printf("Card Number    : %d\n", clint[i].card);
    printf("\n");
      printf("========== THANK YOU =========\n");
            break;
    }
}

 if (i == index) {
printf("Account not found.\n");
}} else {
printf("No accounts available. Please create an account first.\n");
}
    break;
 }
} while (op != 5);

    return 0;
}

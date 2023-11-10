//
// Created by youzi on 2023/11/9.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Define a struct for person information
typedef struct {
    char name[50];
    int age;
    char gender;
    char phone[15];
    char address[100];
} Person;

// Declare an array to store information for 100 people
Person *addressBook;
int count = 0; // Counter for the number of people in the address book
int capacity = 0; // Capacity of the address book

int init() {
    addressBook = (Person *) malloc(2 * sizeof(Person));

    if (addressBook == NULL) {
        printf("%s", strerror(errno));
        return 1;
    }
    capacity = 2;

    return 0;
}

// Function to add a contact
//静态版本
//void addContact() {
//    if (count < 100) {
//        printf("Enter name: ");
//        scanf("%s", addressBook[count].name);
//        printf("Enter age: ");
//        scanf("%d", &addressBook[count].age);
//        printf("Enter gender (M/F): ");
//        scanf(" %c", &addressBook[count].gender);
//        printf("Enter phone: ");
//        scanf("%s", addressBook[count].phone);
//        printf("Enter address: ");
//        scanf("%s", addressBook[count].address);
//        count++;
//        printf("Contact added successfully!\n");
//    } else {
//        printf("Address book is full!\n");
//    }
//}
//动态版本
void addContact() {

    // 增容
    if (count == capacity) {
        Person *newAddressBook = (Person *) realloc(addressBook, (capacity + 2) * sizeof(Person));

        if (newAddressBook) {
            addressBook = newAddressBook;
            capacity += 2;
        } else {
            // 输出错误信息，并且考虑退出程序或者其他错误处理逻辑
            printf("Failed to expand address book: %s\n", strerror(errno));
            // 注意，这里我们不释放 addressBook，因为 realloc 已经保留了原有内存
            return;
        }
    }
    // 读取新联系人信息
    printf("Enter name: ");
    scanf("%49s", addressBook[count].name); // 使用 %49s 以避免缓冲区溢出
//    printf("Enter age: ");
//    scanf("%d", &addressBook[count].age);
//    printf("Enter gender (M/F): ");
//    scanf(" %c", &addressBook[count].gender);
//    printf("Enter phone: ");
//    scanf("%s", addressBook[count].phone);
//    printf("Enter address: ");
//    scanf("%s", addressBook[count].address);
    count++;

    printf("Contact added successfully!\n");
}

// Function to find a contact by name
int findContact(char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(addressBook[i].name, name) == 0) {
            return i; // Return the index of the contact
        }
    }
    return -1; // Return -1 if not found
}

// Function to delete a contact
void deleteContact(char *name) {
    int index = findContact(name);
    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            addressBook[i] = addressBook[i + 1]; // Shift contacts
        }
        count--;
        printf("Contact deleted successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

// Function to edit a contact
void editContact(char *name) {
    int index = findContact(name);
    if (index != -1) {
        printf("Enter new name: ");
        scanf("%s", addressBook[index].name);
        printf("Enter new age: ");
        scanf("%d", &addressBook[index].age);
        printf("Enter new gender (M/F): ");
        scanf(" %c", &addressBook[index].gender);
        printf("Enter new phone: ");
        scanf("%s", addressBook[index].phone);
        printf("Enter new address: ");
        scanf("%s", addressBook[index].address);
        printf("Contact updated successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

// Function to display all contacts
void displayContacts() {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Gender: %c, Phone: %s, Address: %s\n",
               addressBook[i].name, addressBook[i].age, addressBook[i].gender,
               addressBook[i].phone, addressBook[i].address);
    }
}
void freeAddressBook() {
    free(addressBook);
    addressBook = NULL;
    capacity = 0;
    count = 0;
}
void sortContacts() {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(addressBook[j].name, addressBook[j + 1].name) > 0) {
                Person temp = addressBook[j];
                addressBook[j] = addressBook[j + 1];
                addressBook[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        printf("%s\n", addressBook[i].name);
    }
}

// Main function
int main12() {
    int choice;
    char name[50];

    init();
    do {
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("6. Sort Contacts\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(name);
                break;
            case 3:
                printf("Enter name to edit: ");
                scanf("%s", name);
                editContact(name);
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("Exiting the program.\n");
                freeAddressBook();
                break;
            case 6:
                sortContacts();
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}


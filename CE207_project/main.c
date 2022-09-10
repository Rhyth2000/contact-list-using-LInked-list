#include <stdio.h>
#include <stdlib.h>
#include "List.h"

List l;

void printMenu() {
    printf("\n\t\t -------------MENU-------------- \n\t\t|\t\t\t\t|");
    printf("\n\t\t|\t1. New Contact      \t|");
    printf("\n\t\t|\t2. Edit Contact     \t|");
    printf("\n\t\t|\t3. Search Contact   \t|");
    printf("\n\t\t|\t4. Delete Contact   \t|");
    printf("\n\t\t|\t5. View List        \t|");
    printf("\n\t\t|\t6. EXIT             \t|");
    printf("\t\t|\t\t\t\t|\n\t\t ------------------------------- \n");
}

void printNewContactMenu(char FirstName[], char LastName[], char number[], char email[], char blood[], char relationship[],char address[]) {

printf("\n ----------------New Contact----------- \n");
printf("\t1. First Name : %s", FirstName);
printf("\t2. Last Name : %s", LastName);
printf("\t3. Number : %s", number);
printf("\t4. Email : %s", email);
printf("\t5. Blood : %s", blood);
printf("\t6. Relationship : %s", relationship);
printf("\t7. Address : %s", address);
printf("\n\tSAVE   -&gt; (Press 0)");
printf("\tCANCEL -&gt; (Press 9)");
printf("\n -------------------------------------- \n");

 }


 void printEditContactMenu(char FirstName[], char LastName[], char number[], char email[], char blood[], char relationship[],char address[]) {

    printf("\n ----------------Edit Contact----------- \n");
    printf("\t1. First Name : %s", FirstName);
    printf("\t2. Last Name : %s", LastName);
    printf("\t3. Number : %s", number);
    printf("\t4. Email : %s", email);
    printf("\t5. Blood : %s", blood);
    printf("\t6. Relationship : %s", relationship);
    printf("\t7. Address : %s", address);
    printf("\n\tSAVE   -> (Press 0)");
    printf("\tCANCEL -> (Press 9)");
    printf("\n -------------------------------------- \n");
}


void printDeleteMenu() {

    printf("\n ----------------Delete Contact----------- \n");
    printf("\t1. Delete A contact ");
    printf("\t2. Delete multiple contact ");
    printf("\t3. Merge Duplicate contact ");
    printf("\n ----------------------------------------- \n");
}

bool isNumber(char s[]) {

    for(int i=0; i<s.size(); i++) {
        if(!isdigit(s.at(i)))
            return false;
    }
    return true;
}

int inputValidity(char *s) {

    if(!isNumber(s))
        return -1;
    else
        return stoi(s);
}


void newContact() {

    bool run = true;

    char FirstName;
    char LastName;
    char number;
    char email;
    char blood;
    char relationship;
    char address;

    while(run) {

        system("cls"); //system("clear"); for linux users.
        printNewContactMenu(FirstName,LastName,number,email,blood,relationship,address); //printNewContactMenu(FirstName,LastName,number,email,blood,relationship,address); for linux users.
        printf(" Enter choice : "); //cout << " Enter choice : "; for linux users.
        int ch; //int ch = inputValidity(c); for linux users.
        scanf("%d",&ch); //cin >> c; for linux users.


        switch(ch) {

            case 1 :
                printf("\n Enter First Name : ");
                scanf("%s",FirstName);
                break;

            case 2 :
                printf("\n Enter Last Name : ");
                scanf("%s",LastName);
                break;

            case 3 :
                printf("\n Enter Number : ");
                scanf("%d",&number);
                break;

            case 4 :
                printf("\n Enter email : ");
                scanf("%s",email);
                break;

            case 5 :
                printf("\n Enter blood : ");
                scanf("%s",blood);
                break;

            case 0:
                if((!FirstName || !LastName) && !number) {
                        Contact contact(FirstName,LastName,number,email,blood,relationship,address);
                l.insertAtFirst(contact);
                l.sort();
                run = false;
}
else {
printf("\n\t [Please Input Name and Number]\n\n");
system("pause");
}
break;
case 9:
run = false;
break;
default:
printf("\n\t Invalid Option\n\n");
system("pause");
break;
}

    }


}

void editContact() {




    if(!l.isEmpty()) {

        system("cls");
        printf("\n ----------------Edit Contact----------- \n\n");

        l.printList();

        printf("\n\n\n Enter Serial No : ");
        char ch[100];
        scanf("%s",ch);

        int sr = inputValidity(ch);
        if(sr==-1) {
            printf("\n\t Invalid Option\n");
            system("pause");
            return;
        }

        Contact contact = l.findNodeContact_Index(sr);

        if(contact.getViewName().empty()) {
            printf("\n\t Contact Not Found\n\n");
            system("pause");
            return;
        }

        bool run = true;

        char FirstName[] = contact.getFirstName();
        char LastName[] = contact.getLastName();
        char number[] = contact.getNumber();
        char email[] = contact.getEmail();
        char blood[] = contact.getBlood();
        char relationship[] = contact.getRelationShip();
        char address[] = contact.getAddress();

        while(run) {

            system("cls");

            printEditContactMenu(FirstName,LastName,number,email,blood,relationship,address);

            char c[];
            printf(" Enter choice : ");
            scanf("%s",&c);

            int cc = inputValidity(c);

            switch(cc) {

                case 1 :
                    printf("\n Enter First Name : ");
                    scanf("%s",FirstName);
                    contact.setFirstName(FirstName);
                    break;

                case 2 :
                    printf("\n Enter Last Name : ");
                    scanf("%s",LastName);
                    contact.setLastName(LastName);
                    break;

                case 3 :
                    printf("\n Enter Number : ");
                    scanf("%d",&number);
                    contact.setNumber(number);
                    break;

                case 4 :
                    printf("\n Enter email : ");
                    scanf("%s",email);
                    contact.setEmail(email);
                    break;

                case 0:
                        l.insertAt(contact,sr);
                        l.sort();
                        run = false;
                        printf("\n\t Contact Updated");

                        // if((!FirstName.empty() || !LastName.empty()) && !number.empty()) {
                    //     l.insertAt(contact,ch);
                    //     l.sort();
                    //     run = false;
                    // }

                    // else {
                    //     cout << "\n\t [Please Input Name and Number]\n\n" << endl;
                    //     system("pause");
                    // }

                    break;

                case 9:
                    run = false;
                    break;

                default:
                    printf("\n\t Invalid Option\n\n");
                    system("pause");
                    break;

                    }

        }

    }

    else
        printf("\n\t List is EMPTY");

    printf("\n");
    system("pause");
}

void editDelSearch(Contact contact, int ch) {


    if(ch==1) {

        system("cls");
        printf("\n ----------------Edit Contact----------- \n\n");

        if(contact.getViewName().empty()) {
            printf("\n\t Contact Not Found\n\n");
            system("pause");
            return;
        }

        bool run = true;

        char FirstName[] = contact.getFirstName();
        char LastName[] = contact.getLastName();
        char number[] = contact.getNumber();
        char email[] = contact.getEmail();
        char blood[] = contact.getBlood();
        char relationship[] = contact.getRelationShip();
        char address[] = contact.getAddress();

        while(run) {

            system("cls");

            printEditContactMenu(FirstName,LastName,number,email,blood,relationship,address);

            int c;
            printf(" Enter choice : ");
            scanf("%d",&c);


            switch(c) {

                case 1 :
                    printf("\n Enter First Name : ");
                    scanf("%s",FirstName);
                    contact.setFirstName(FirstName);
                    break;

                case 2 :
                    printf("\n Enter Last Name : ");
                    scanf("%s",LastName);
                    contact.setLastName(LastName);
                    break;

                case 3 :
                    printf("\n Enter Number : ");
                    scanf("%s",number);
                    contact.setNumber(number);
                    break;
                case 4 :
                    printf("\n Enter email : ");
                    scanf("%s",email);
                    contact.setEmail(email);
                    break;
                case 5 :
                    printf("\n Enter blood : ");
                    scanf("%s",blood);
                    contact.setBlood(blood);
                    break;
                case 6 :
                    printf("\n Enter relationship : ");
                    scanf("%s",relationship);
                    contact.setRelationShip(relationship);
                    break;
                case 7 :
                    printf("\n Enter address : ");
                    scanf("%s",address);
                    contact.setAddress(address);
                    break;
                case 0:

                    if((FirstName.empty() || LastName.empty()) && number.empty()) {
                        printf("\n\t [Please Input Name and Number]\n\n");
                        system("pause");
                    }

                    else {
                        l.insertAt(contact,ch);
                        l.sort();
                        run = false;
                        printf("\n\t Contact Updated");
                    }

                    break;

                case 9 :
                    run = false;
                    break;

                default:
                    printf("\n\t Invalid Option\n\n");
                    system("pause");

                    }

        }



}

                else {
        l.deleteNode_Contact(contact);
    }

    }



void searchContact() {

    if(!l.isEmpty()) {

        system("cls");
        printf("\n ----------------Search Contact----------- \n\n");

        printf(" Enter search info : ");
        char src[100];
        scanf("%s",src);

        if(!l.findNodeContact(src).getViewName().empty()) {

            l.findNodeContact(src).contactInfo();

            printf("\n ----------------------------------------- \n\n");
            printf("\t> Press 1 to EDIT the contact");
            printf("\t> Press 2 to Delete the Contact");
            printf("\t> Press 0 to BACK to the MENU");

            printf("\n\t  Enter choice : ");
            char ps[100];
            scanf("%s",ps);

            int pr = inputValidity(ps);

            if(pr==1 || pr==2) {
                editDelSearch(l.findNodeContact(src), pr);
            }

            else if(pr==-1)
                printf("\n\t Invalid option\n");

        }

        else
            printf("\n\t Contact Not found");

    }

    else
        printf("\n\t List is EMPTY");


    printf("\n");
    system("pause");

}


void deleteContact() {

    if(!l.isEmpty()) {

        system("cls");
        printDeleteMenu();

        printf("Enter choice : ");
        char str[100];
        scanf("%s",str);

        int ch = inputValidity(str);
        if(ch==-1) {
            printf("\n\t Invalid Option\n");
            system("pause");
            return;

        }

        switch(ch) {

            case 1: {

                l.printList();

                printf("\n\n\n Enter Serial No : ");
                char str[100];
                scanf("%s",str);

                int sr = inputValidity(str);
                if(sr==-1) {
                    printf("\n\t Invalid Option\n");
                    system("pause");
                    return;
                }

                l.deleteNode(sr);
                }
                break;

                case 2: {

                l.printList();


                vector<int> v;

                printf("\n\n\n Enter Serial No (Press -1 to stop) : ");


                while(true) {
                    int a;
                    scanf("%d",&a);

                    if(a==-1)
                        break;

                    v.push_back(a);
                }

                }
                break;


                case 3: {

                printf("\n\t Are you sure? (This will delete duplicate contacts)");
                printf("\n\t Press ~ Y or N : ");
                char yn[10];
                scanf("%s",yn);

                if(strcmp(yn,"Y")==0 || strcmp(yn,"y")==0) {
                    l.deleteDuplicate();
                }

            }
                break;


                default:
                printf("\n\t Invalid Option\n\n");
                //system("pause");
                break;


        }


    }
    else
        printf("\n\t List is EMPTY");

    printf("\n");
    system("pause");


}


int main() {
    while(1) {
        printMenu();
        char choice[10];
        printf("Enter choice : ");
        scanf("%s", choice);
        int ch = inputValidity(choice);
        printf("\n");

        switch(ch) {

            case 1:
                newContact();
                break;


            case 2:
                editContact();
                break;


            case 3:
                searchContact();
                break;


            case 4:
                deleteContact();
                break;


            case 5:
                l.printList(); //error here, l is not defined in this scope. How do I fix this? I tried to define it as a global variable but that didn't work.

                system("pause"); //error here, system is not defined in this scope. How do I fix this? I tried to define it as a global variable but that didn't work.

                break;

            case 6:

                exit(0); //error here, exit is not defined in this scope. How do I fix this? I tried to define it as a global variable but that didn't work.

                break;

            default:

                printf("\n\t Invalid Option\n\n"); //error here, printf is not defined in this scope. How do I fix this? I tried to define it as a global variable but that didn't work.

                system("pause"); //error here, system is not defined in this scope. How do I fix this? I tried to define it as a global variable but that didn't work.

                break;

        }

        system("cls");
a
    }





    system("pause");

    return 0;

}

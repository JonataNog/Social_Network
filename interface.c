#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

    /**
     * Main menu interface
     */
void MSG_MENU(){
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. MODULE 1 - USER MANAGEMENT");
    printf("\n\t2. MODULE 2 - FRIENDSHIP MANAGEMENT ");
    printf("\n\t3. EXIT");
}

    /**
     * Sub menu user management interface
     *
     *@param module_number int number of the chosen user management option
     */
void MSG_SUBMENU1(int module_number){
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>> MODULE %d: <<<<<<<<<<<<<<<<<<<<", module_number);
    printf("\n\n\t1. REGISTER");
    printf("\n\t2. SEARCH");
    printf("\n\t3. MODIFY");
    printf("\n\t4. DELETE");
    printf("\n\t5. PRINT");
    printf("\n\t6. EXIT");
}

    /**
     * Sub menu friendship management interface
     *
     *@param module_number int number of the chosen friendship management option
     */
void MSG_SUBMENU2(int module_number){
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>> MODULE %d: <<<<<<<<<<<<<<<<<<<<\n", module_number);
    printf("\n\t1. REGISTER FRIENDSHIPS");
    printf("\n\t2. SEARCH FRIENDSHIPS");
    printf("\n\t3. DELETE FRIENDSHIPS");
    printf("\n\t4. PRINT FRIENDSHIPS");
    printf("\n\t5. POPULAR USER");
    printf("\n\t6. COMMON FRIENDSHIPS");
    printf("\n\t7. INDIRECT FRIENDSHIPS LEVEL 1");
    printf("\n\t8. INDIRECT FRIENDSHIPS LEVEL 2");
    printf("\n\t9. EXIT");
}

    /**
     * Sub menu user management module 1
     *
     *@param *network TSocialNetwork reference to make the changes
     *@param user TUsers value to be changed
     */
void SubMenuModule1(TSocialNetwork *network, TUsers user){
    int option = 0;
    int i;
    do{
        MSG_SUBMENU1(1);
        printf("\n\nType an option:");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
            case 1:
                /**
                    Code for the Register menu option
                */
                system("cls");
                printf("\n\n>>>>>> MSG: Register a user: <<<<<<\n\n");
                Read(&user);
                Register(network, user);
                printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
                system("pause");
                break;

            case 2:
                /**
                    Code for the Search menu option
                */
                system("cls");
                printf("\n MSG: Enter the name of the user you want to search: ");
                fflush(stdin);
                fgets(user.name, 100, stdin);
                i = Search(*network, user);
                if(i >= 0){
                    printf("\n\n >>>>>> MSG: Searched user found: <<<<<<\n\n");
                    Print(network->usersArray[i]);
                }else{
                    printf("\n\n >>>>>> MSG: Searched user is not registered! <<<<<< \n\n");
                }

                printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
                system("pause");
                break;

            case 3:
                /**
                    Code for the Modify menu option
                */
                system("cls");
                printf("\n\n MSG: Enter the name of the user you want to modify: \n\n");
                fflush(stdin);
                fgets(user.name, 100, stdin);
                i = Search(*network, user);
                if(i >= 0){
                    printf("\n\n >>>>>> MSG: Enter data to modify: <<<<<< \n\n");
                    Read(&user);
                    Modify(network, user, i);
                    printf("\n\n >>>>>> MSG: User successfully modified! <<<<<< \n\n");
                }else{
                    printf("\n\n >>>>>> MSG: Searched user is not registered! <<<<<< \n\n");
                }
                printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
                system("pause");
                break;
            case 4:
                /**
                    Code for the Delete menu option
                */
                system("cls");
                printf("\n\n MSG: Enter the name of the user you want to delete: \n\n");
                fflush(stdin);
                i = Search(*network, user);
                if(i >= 0){
                    Delete(network, i);
                    printf("\n\n >>>>>> MSG: User deleted successfully!  <<<<<< \n\n");
                }else{
                    printf("\n\n >>>>>> MSG: Searched user is not registered! <<<<<< \n\n");
                }
                printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
                system("pause");
                break;
            case 5:
                /**
                    Code for the Print2 menu option
                */
                system("cls");
                if(network->index > 0){
                    printf("\n\n >>>>>> MSG: List of registered users: <<<<<< \n\n");
                    Print2(*network);
                }else{
                    printf("\n\n >>>>>> MSG: There are no registered users! <<<<<< \n\n");
                }
                printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
                system("pause");
                break;
            case 6:
                system("cls");
                printf("\n\n\n\t>>>> MSG: Exiting the module...!!! <<<<\n\n");
                system("pause");
                break;
            default:
                system("cls");
                printf("\n\n\n\t>>>> MSG: Please type a valid option !!! <<<< \n\n");
                system("pause");
        }
    }while(option != 6);
}

    /**
     * Sub menu user management module 2
     *
     *@param *network TSocialNetwork reference to make the changes
     *@param user TUsers value to be changed
     */
void SubMenuModule2(TSocialNetwork *network, TUsers user){
    int option = 0;
    int i;
    int id1;
    int id2;
    char name1[100];
    char name2[100];

    do{
        MSG_SUBMENU2(2);
        printf("\n\nType an option:");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
        case 1:
                /**
                    Code for the Register friendship menu option
                */
            system("cls");
            printf("\n\n>>>>>> MSG: Register a friendship: <<<<<<\n\n");
            ReadName(name1);
            ReadName(name2);
            RegisterFriendships(network, name1, name2);
            printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
            system("pause");
            break;
        case 2:
                /**
                    Code for the Search friendship menu option
                */
            system("cls");
            printf("\n\n>>>>>> MSG: Search a friendship: <<<<<<\n\n");
            ReadName(name1);
            ReadName(name2);
            i = SearchFriendships(*network, name1, name2);
            if(i == 1)
                printf("\n\n >>>>>> MSG: Users have friendships! <<<<<<\n\n");
            else
                printf("\n\n >>>>>> MSG: Users have no friendships! <<<<<<\n\n");
            printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
            system("pause");
            break;
        case 3:
                /**
                    Code for the Delete friendship menu option
                */
            system("cls");
            printf("\n\n>>>>>> MSG: Delete a friendship: <<<<<<\n\n");
            ReadName(name1);
            ReadName(name2);
            DeleteFriendships(network, name1, name2);
            printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
            system("pause");
            break;
        case 4:
                /**
                    Code for the Print friendship menu option
                */
            system("cls");
            printf("\n\n>>>>>> MSG: Print a friendship: <<<<<<\n\n");
            ReadName(name1);
            PrintFriendships(*network, name1);
            printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
            system("pause");
            break;
        case 5:
                 /**
                    Code for the Popular user menu option
                */
            system("cls");
            printf("\n\n>>>>>> MSG: Popular User: <<<<<<\n\n");
            int pop = PopularUser(*network);
            printf("The user most popular is: %s", network->usersArray[pop].name);
            printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
            system("pause");
            break;
        case 6:
                 /**
                    Code for the Common friendships menu option
                */
            system("cls");
            printf("\n\n>>>>>> MSG: Popular User: <<<<<<\n\n");
            id1 = ReadID();
            id2 = ReadID();
            int qnt = CommonFriendships(*network, id1, id2);
            printf("\n\nThe number of common friendships is: %d", qnt);
            printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
            system("pause");
            break;
        case 7:
                 /**
                    Code for the Indirect friendships level 1 menu option
                */
            system("cls");
            printf("\n\n>>>>>> MSG: Indirect friendships Level 1: <<<<<<\n\n");
            id1 = ReadID();
            id2 = ReadID();
            int indirectFriendship1 = IndirectFriendships1(*network, id1, id2);
            if(indirectFriendship1 != -1)
                printf("The Intermediate user is: %s", network->usersArray[indirectFriendship1].name);
            else
                printf("Users have a friendship!");
            printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
            system("pause");
            break;
        case 8:
                 /**
                    Code for the Indirect friendships level 2 menu option
                */
            system("cls");
            printf("\n\n>>>>>> MSG: Indirect friendships Level 2: <<<<<<\n\n");
            id1 = ReadID();
            id2 = ReadID();
            int arrayIndirect[2];
            IndirectFriendships2(*network, arrayIndirect, id1, id2);
            printf("\n\nThe first intermediate user is: %s", network->usersArray[arrayIndirect[0]].name);
            printf("\n\nThe second intermediate user is: %s", network->usersArray[arrayIndirect[1]].name);
            printf("\n\n\t >>>>>> MSG: Press a key to continue! <<<<<< \n\n");
            system("pause");
            break;
        case 9:
            system("cls");
            printf("\n\n\n\t>>>> MSG: Exiting the module...!!! <<<< \n\n");
            system("pause");
            break;
        default:
            system("cls");
            printf("\n\n\n\t>>>> MSG: Please type a valid option!!! <<<<\n\n");
            system("pause");
        }
    }while(option != 9);
}

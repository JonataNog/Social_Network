#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socialnetwork.h"
#include "interface.h"
#include "friendship.h"

int main()
{
	//testando branchs
    TSocialNetwork network;
    TUsers user;
    Init(&network);
    int option = 0;
    do{
        system("cls");
        MSG_MENU();
        printf("\n\nType an option: ");
        fflush(stdin);
        scanf("%d", &option);
        switch(option){
            case 1:
                SubMenuModule1(&network, user);
                break;
            case 2:
                SubMenuModule2(&network, user);
                break;
            case 3:
                system("cls");
                printf("\n\n\t >>>>>> MSG: Exiting the program! <<<<<< \n\n");
                break;
            default:
                system("cls");
                printf("\n\n\n\t>>>> MSG: Please type a valid option !!! <<<<");
                system("pause");
        }

    }while(option != 3);

    return 0;
}

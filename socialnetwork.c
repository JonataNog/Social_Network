#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socialnetwork.h"

    /**
     * Reads all user fields
     *
     * @param *user TUsers reference to read
     */
void Read(TUsers *user){

    printf("\nType the user name:");
    fflush(stdin);
    fgets(user->name, 100, stdin);

    printf("\nType the user email:");
    fflush(stdin);
    fgets(user->email, 200, stdin);

    printf("\nType the user login:");
    fflush(stdin);
    fgets(user->login, 50, stdin);

    printf("\nType the user password:");
    fflush(stdin);
    fgets(user->password, 50, stdin);

    printf("\nBirth data:\n");
    printf("\nType the day:");
    fflush(stdin);
    scanf("%d", &user->birth_data.day);

    printf("\nType the month:");
    fflush(stdin);
    scanf("%d", &user->birth_data.month);

    printf("\nType the year:");
    fflush(stdin);
    scanf("%d", &user->birth_data.year);
}

    /**
     * Print all user fields
     *
     * @param *user TUsers reference to print
     */
void Print(TUsers user){

    printf("\nUser name:");
    printf("\n%s", user.name);

    printf("\nUser email:");
    printf("\n%s", user.email);

    printf("\nUser password:");
    printf("\n%s", user.password);

    printf("\nBirth data:\n");
    printf("\ntDay:");
    printf("\n%d", user.birth_data.day);

    printf("\ntMonth:");
    printf("\n%d", user.birth_data.month);

    printf("\ntYear");
    printf("\n%d", user.birth_data.year);
}

    /**
     * Initializes the struct TSocialNetwork and fills the matrix with 0
     *
     * @param *network TSocialNetwork reference to init
     */
void Init(TSocialNetwork *network){
    network->index = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            network->matrix[i][j] = 0;
        }
    }
}

    /**
     * Register an user in the TSocialNetwork
     *
     * @param *network TSocialNetwork reference to register an user
     * @param user TUsers value to be registered on the TSocialNetwork
     */
void Register(TSocialNetwork *network, TUsers user){
    if(network->index < 100){
        user.ID = network->index;
        user.friendship = 0;
        network->usersArray[network->index] = user;
        network->index++;
        printf("\nThe user has been successfully registered!\n");
    }else
        printf("\nUser registration failed!\n");
}

    /**
     * Print all users in the array
     *
     * @param network TSocialNetwork value to print
     */
void Print2 (TSocialNetwork network){
    for(int i = 0; i < network.index; i++){
        if(network.usersArray[i].ID != -1){
            Print(network.usersArray[i]);
        }
    }
}

    /**
     * Search if a user is registered on the TSocialNetwork
     *
     * @param network TSocialNetwork value to search
     * @param user TUsers to be searched
     * @return User ID number or -1 if the user is not registered on TSocialNetwork
     */
int Search(TSocialNetwork network, TUsers user){
    for(int i = 0; i < network.index; i++){
        if(strcmp(network.usersArray[i].name, user.name) == 0){
            return network.usersArray[i].ID;
        }
    }
    return -1;
}

    /**
     * Modify a user in the TSocialNetowrk users array
     *
     * @param network TSocialNetwork reference to make the change
     * @param user TUsers value to be changed
     * @param i int the user index that should be changed
     */
void Modify(TSocialNetwork *network, TUsers user, int i){
    if(i != -1){
        network->usersArray[i] = user;
    }
}

    /**
     * Deletes a user in the TSocialNetwork filling -1 in user's array and excluding this user's friendships
     *
     * @param network TSocialNetwork reference to make the change
     * @param index2 int index of the user to be deleted
     */
void Delete (TSocialNetwork *network, int index2){
    network->usersArray[index2].ID = -1;

    for(int i = 0; i < network->index; i++)
        if(network->matrix[index2][i] == 1)
            network->matrix[index2][i] = 0;

    for(int j = 0; j < network->index; j++)
        if(network->matrix[j][index2] == 1)
            network->matrix[j][index2] = 0;
}

    /**
    * Read a user name in an array
    *
    *@param name char array for reading the name
    */
void ReadName(char name[]){
    printf("Type the name: ");
    fflush(stdin);
    fgets(name, 100, stdin);
}

    /**
    * Read a user ID
    *
    *@return ID number
    */
int ReadID(){
    int id;
    printf("\nType the User ID: ");
    fflush(stdin);
    scanf("%d", &id);
    return id;
}

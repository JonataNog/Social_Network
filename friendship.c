#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "friendship.h"

    /**
     * Register bi-directional friendships through the user's name
     *
     *@param *network TSocialNetwork reference to make the register
     *@param userName1 String to search the name in the usersArray
     *@param userName2 String to search the name in the usersArray
     */
void RegisterFriendships (TSocialNetwork *network, char userName1[], char userName2[]){
    int index1;
    int index2;
    int test1 = 0;
    int test2 = 0;

    for(int i = 0; i < network->index; i++){
        if(strcmp(network->usersArray[i].name, userName1) == 0){
            index1 = network->usersArray[i].ID;
            test1++;
        }else if(strcmp(network->usersArray[i].name, userName2) == 0){
            index2 = network->usersArray[i].ID;
            test2++;
        }
    }

    if(test1 != 0 && test2 != 0){
        network->matrix[index1][index2] = 1;
        network->usersArray[index1].friendship++;
        network->matrix[index2][index1] = 1;
        network->usersArray[index2].friendship++;
        printf("\n\n >>>>>> MSG: The friendship has been successfully registered! <<<<<<\n\n");
    }else if(test1 == 0)
            printf("\n\n>>>>>> MSG: %s is not registered in the social network! <<<<<<\n\n", userName1);
        else
            printf("\n\n >>>>> MSG: %s is not registered in the social network! <<<<<<\n\n", userName2);
}

    /**
     * Searches if there are friendships in the relationship matrix between the two users name
     *
     *@param network TSocialNetwork value to make the search
     *@param userName1 String to search the name in the usersArray
     *@param userName2 String to search the name in the usersArray
     */
int SearchFriendships(TSocialNetwork network, char userName1[], char userName2[]){
    int index1;
    int index2;

    for(int i = 0; i < network.index; i++){
        if(strcmp(network.usersArray[i].name, userName1) == 0)
            index1 = network.usersArray[i].ID;
        else if(strcmp(network.usersArray[i].name, userName2) == 0)
            index2 = network.usersArray[i].ID;
    }

    if(network.matrix[index1][index2] == 1 && network.matrix[index2][index1] == 1)
        return 1;
    else
        return 0;
}

    /**
     * Delete bi-directional friendships through the user's name
     *
     *@param *network TSocialNetwork reference to make the deletion
     *@param userName1 String to search the name in the usersArray
     *@param userName2 String to search the name in the usersArray
     */
void DeleteFriendships(TSocialNetwork *network, char userName1[], char userName2[]){
    int index1;
    int index2;
    int test1 = 0;
    int test2 = 0;

    for(int i = 0; i < network->index; i++){
        if(strcmp(network->usersArray[i].name, userName1) == 0){
            index1 = network->usersArray[i].ID;
            test1++;
        }else if(strcmp(network->usersArray[i].name, userName2) == 0){
            index2 = network->usersArray[i].ID;
            test2++;
        }
    }

    if(test1 != 0 && test2 != 0){
        network->matrix[index1][index2] = 0;
        network->usersArray[index1].friendship--;
        network->matrix[index2][index1] = 0;
        network->usersArray[index2].friendship--;
        printf("\n\n >>>>>> MSG: The friendship has been successfully deleted! <<<<<<\n\n");
    }else if(test1 == 0)
            printf("\n\n>>>>>> MSG: %s is not registered in the social network! <<<<<<\n\n", userName1);
        else
            printf("\n\n >>>>> MSG: %s is not registered in the social network! <<<<<<\n\n", userName2);
}

    /**
     * Prints users who have friendships with the user parameter
     *
     *@param network TSocialNetwork value to make the search
     *@param user TUsers value to search in the usersArray and your friendships in the matrix
     */
void PrintFriendships(TSocialNetwork network, char name[]){
    int index;
    int test = 0;

    for(int i = 0; i < network.index; i++){
        if(strcmp(network.usersArray[i].name, name) == 0){
            index = network.usersArray[i].ID;
            test++;
        }
    }

    if(test != 0){
        printf("List of friendships: \n");
        for(int i = 0; i < network.index; i++){
            if(network.matrix[index][i] == 1)
                Print(network.usersArray[i]);
        }
    }else
        printf("\n\n >>>>>> MSG: Searched user is not registered! <<<<<< \n\n");
}

    /**
     * Checks the user who has the most friendships
     *
     *@param network TSocialNetwork value to make the search
     *@return User ID with the most friendships
     */
int PopularUser(TSocialNetwork network){
    int max = network.usersArray[0].friendship;
    int id = 0;

    for(int i = 1; i < network.index; i++){
        if(network.usersArray[i].friendship > max){
            max = network.usersArray[i].friendship;
            id = network.usersArray[i].ID;
        }
    }
    return id;
}

    /**
     * Checks the number of the common friendships between two users who are not friends
     *
     *@param network TSocialNetwork value to make the search
     *@param id1 int value first user ID
     *@param id2 int value second user ID
     *@return Number of friendships in common
     */
int CommonFriendships(TSocialNetwork network, int id1, int id2){
    int qnt = 0;
    if(SearchFriendships(network, network.usersArray[id1].name, network.usersArray[id2].name) == 0){
        for(int i = 0; i < network.index; i++){
            if(network.matrix[id1][i] == 1 && network.matrix[id2][i] == 1)
                qnt++;
        }
    }else
        printf("Users have a friendship!");

    return qnt;
}

    /**
     * Checks the indirect friendship relationship level 1 between two users who are not friends
     *
     *@param network TSocialNetwork value to make the search
     *@param id1 int value first user ID
     *@param id2 int value second user ID
     *@return Intermediate user ID or -1 if users have a friendship
     */
int IndirectFriendships1(TSocialNetwork network, int id1, int id2){
    int id = -1;
    if(SearchFriendships(network, network.usersArray[id1].name, network.usersArray[id2].name) == 0){
        for(int i = 0; i < network.index; i++){
            if(network.matrix[id1][i] == 1 && network.matrix[id2][i] == 1)
                id = network.usersArray[i].ID;
        }
   }

   return id;
}

    /**
     * Checks the indirect friendship relationship level 2 between two users who are not friends
     *
     *@param network TSocialNetwork value to make the search
     *@param id1 int value first user ID
     *@param id2 int value second user ID
     */
void IndirectFriendships2(TSocialNetwork network, int indirectFriendship[], int id1, int id2){
    if(SearchFriendships(network, network.usersArray[id1].name, network.usersArray[id2].name) == 0){
        for(int i = 0; i < network.index; i++){
            for(int j = 0; j < network.index; j++){
                if(network.matrix[id1][i] == 1 && network.matrix[j][i] == 1 && network.matrix[j][id2] == 1){
                    indirectFriendship[0] = network.usersArray[i].ID;
                    indirectFriendship[1] = network.usersArray[j].ID;
                }
            }
        }
    }else
        printf("Users have a friendship!");
}

#ifndef SOCIALNETWORK_H_INCLUDED
#define SOCIALNETWORK_H_INCLUDED

#include <stdio.h>
#include <string.h>

    /**
     * Struct TData to save the birth data
     */
typedef struct data{
    int day;
    int month;
    int year;
}TData;

    /**
     * Struct TUsers to save the user informations
     * The ID number must be generated by the program and equal to the index of the element registered in the user array
     */
typedef struct users{
    char name[100];
    char email[200];
    char login[50];
    char password[50];
    TData birth_data;
    int ID;
    int friendship;
}TUsers;

    /**
     * Struct TSocialNetwork to save social network informations
     */
typedef struct SocialNetwork{
        /**
         * List of users on the social network
         */
    TUsers usersArray[100];
        /**
         * Relationship matrix
         */
    int matrix[100][100];
        /**
         * Indicates the position in which the next element will be inserted in the list
         * and also informs the number of users registered in the list
         */
    int index;

}TSocialNetwork;

#endif // SOCIALNETWORK_H_INCLUDED

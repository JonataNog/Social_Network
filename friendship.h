#ifndef FRIENDSHIP_H_INCLUDED
#define FRIENDSHIP_H_INCLUDED
#include "socialnetwork.h"

    /**
     * Register Friendships signature
     */
void RegisterFriendships (TSocialNetwork *network, char userName1[], char userName2[]);

    /**
     * Search Friendships signature
     */
int SearchFriendships(TSocialNetwork network, char userName1[], char userName2[]);

    /**
     * Delete Friendships signature
     */
void DeleteFriendships(TSocialNetwork *network, char userName1[], char userName2[]);

    /**
     * Print Friendships signature
     */
void PrintFriendships(TSocialNetwork network, char name[]);


    /**
     * Popular User signature
     */
int PopularUser(TSocialNetwork network);

    /**
     * Commom Friendships signature
     */
int CommonFriendships(TSocialNetwork network, int id1, int id2);

    /**
     * Indirect Friendships 1 signature
     */
int IndirectFriendships1(TSocialNetwork network, int id1, int id2);

    /**
     * Indirect Friendships 1 signature
     */
void IndirectFriendships2(TSocialNetwork network, int indirectFriendships2[], int id1, int id2);
#endif // FRIENDSHIP_H_INCLUDED

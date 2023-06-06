#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "socialnetwork.h"

    /**
     * Main menu interface signature
     */
void MSG_MENU();

    /**
     * Sub menu 1 - User management interface signature
     */
void MSG_SUBMENU1(int module_number);

    /**
     * Sub menu 1 - Friendship management interface signature
     */
void MSG_SUBMENU2(int module_number);

    /**
     * Sub menu module1 - User management interface signature
     */
void SubMenuModule1(TSocialNetwork *network, TUsers user);

    /**
     * Sub menu module2 - Friendship management interface signature
     */
void SubMenuModule2(TSocialNetwork *network, TUsers user);

#endif // INTERFACE_H_INCLUDED

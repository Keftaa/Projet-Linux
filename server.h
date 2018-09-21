//
// Created by Adnan on 14-Sep-18.
//

#ifndef LINUXSERVER_SERVER_H

#define LINUXSERVER_SERVER_H


#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros

#include <fcntl.h>
#include <signal.h>

int egal(char str1[], char str2[]);

#define TRUE   1
#define FALSE  0


#endif //LINUXSERVER_SERVER_H


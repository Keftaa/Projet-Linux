
#include "client.h"

int main(int argc , char *argv[])
{
    int sock;
    int PortServer;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000],con[100],who[100]="_who",quit[100]="_quit";

    ssize_t bytes;
    char buffer[1000];
    int count = 0;


    printf("Pour vous connecter au serveur, tapez  <yourname  \n");
    scanf(" %[^\n]s",con);
    do{
        printf(" Entrer le numero de port du serveur (doit etre >1024) \n");
        scanf("%d",&PortServer);
    }while(PortServer<=1024);

    char connect1[100] = "",nom[100]="";
    char * p;
    char * port;
    p = strtok (con,"<"); // call the strtok with str as 1st arg for the 1st time.

    if (p != NULL) // check if we got a token.
    {
        strcpy(connect1,p); // save the token.
        strcpy(nom,p); // save the token.
    }

    char nul[100];



    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Impossible to creer le socket");
    }
    puts("Socket cree");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( PortServer );



    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("La connexion a echoue");
        return 1;
    }



    char result[100]="NameInApp";

    send(sock , result , strlen(result) , 0);
    send(sock , nom , strlen(nom) , 0);
    puts("Connecte\n");



    //keep communicating with server

    printf("Tapez votre message: ");
    fflush(stdout);
    fcntl(0,F_SETFL,O_NONBLOCK);
    fcntl(sock,F_SETFL,O_NONBLOCK);

    while(1)
    {
        memset(&buffer[0], 0,1000);

        bytes = read(0,buffer,1000);
        if (bytes > 0) {
            if(egal(buffer,quit))
            {send(sock , buffer , 1000 , 0) ;
                exit(0);}
            else if (!egal(buffer,who))
                printf("Moi : ");

            fflush(stdout);

            send(sock , buffer , 1000 , 0) ;

        }
        sleep(1);
        count++;
        if (!(count%3))

        {
            if( read(sock , server_reply , 2000 ) > 0)
            {
                printf("\r%s",server_reply);
                memset(&server_reply[0], 0, sizeof(server_reply));
                printf("Moi : " );
                fflush(stdout);

            }

        }

    }

    printf(" command false   \n");


}


int egal(char m1[],char m2[]){
    int i;


    for ( i = 0 ; i < strlen(m2) ; i++)
        if(m1[i] != m2[i])
            return 0;

    return 1;



}

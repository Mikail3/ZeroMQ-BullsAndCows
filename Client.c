#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <zmq.h>
#include <assert.h>
#include <unistd.h>
#include <sstream>
#include <string>


int main (int argc, char * argv[])

{

    const char *messageGuess = (argc > 1)? argv [1]: "BC?>Guess>";
    const char *messageJoin = (argc > 1)? argv [1]: "BC?>Join>";


    void *context = zmq_ctx_new ();
    void *sender = zmq_socket (context, ZMQ_PUSH); ///If u want to send some , send here
    void *receiver = zmq_socket (context, ZMQ_SUB); ///Benternet pulls , u SUB  ,important voor receive


    int rs = zmq_connect (sender,"tcp://benternet.pxl-ea-ict.be:24041"); ///"tcp://benternet.pxl-ea-ict.be:24041");
    int rr = zmq_connect (receiver, "tcp://benternet.pxl-ea-ict.be:24042");///"tcp://benternet.pxl-ea-ict.be:24042"); ///important voor receive

    char guess[100];
    char sendGuess[100];
    char buf [256];
    int guesshere [256];
    char name[256];
    char sendName [256];
    assert (rs == 0);

    printf("Whats ur name");
    scanf( "%s", name);
    strcpy(sendName, messageJoin);
    strcat (sendName, name) ;
    memset(buf,0,256);
    zmq_send(sender, sendName, strlen(sendName) , 0);



    sleep(1);

    while (true)

    {



    /*
    std::stringstream gc;
    gc << " your guess player" << guess;
    std:: string g = gc.str();
    rs = zmq_send (sender , g.c_str(),  g.size() , 0);
    */
// send guess
     for  (int i = 0; i < *guesshere; i++)
     {
    printf("Whats ur guess?");
    scanf( "%s", guess);
    strcpy(sendGuess, messageGuess);
    strcat (sendGuess, guess) ;
    memset(buf,0,256);
    zmq_send(sender, sendGuess, strlen(sendGuess) , 0);

     }

// receive guess





        zmq_close(receiver);
        zmq_ctx_destroy(context);
        return 0;


}

}

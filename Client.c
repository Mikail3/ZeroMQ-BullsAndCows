#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <zmq.h>
#include <assert.h>
#include <unistd.h>
#include <sstream>
#include <string>


int main ()

{

    void *context = zmq_ctx_new ();
    void *sender = zmq_socket (context, ZMQ_PUSH); ///If u want to send some , send here
    void *receiver = zmq_socket (context, ZMQ_SUB); ///Benternet pulls , u SUB  ,important voor receive


    int rs = zmq_connect (sender,"tcp://benternet.pxl-ea-ict.be:24041"); ///"tcp://benternet.pxl-ea-ict.be:24041");
    int rr = zmq_connect (receiver, "tcp://benternet.pxl-ea-ict.be:24042");///"tcp://benternet.pxl-ea-ict.be:24042"); ///important voor receive

    int guess;

    assert (rs == 0);
    printf("Bulls&Cows Client started\n");


    sleep(1);
    
    /*
    std::stringstream gc;
    gc << " your guess player" << guess;
    std:: string g = gc.str();
    rs = zmq_send (sender , g.c_str(),  g.size() , 0);
    */
    
    
    rs = zmq_send (sender , "BC?>1111>" ,  9 , 0);
    printf("Send bytes = %d", rs );
    char buf[256];
    int Guess [256];
    
    
    

    while (1)
    {


            rr = zmq_recv (receiver, buf ,256 , 0 ); ///receiving message option 1
            buf[rr] = '\0'; ///String stop
            printf("Received: %s" , buf);


    }


        zmq_close(receiver);
        zmq_ctx_destroy(context);
        return 0;
}


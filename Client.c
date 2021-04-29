#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>


int main ( int argc, char * argv [] )

{

    ///Hello world 4 ZMQ
    void *context = zmq_ctx_new ();
    void *sender = zmq_socket (context, ZMQ_PUSH); ///If u want to send some , send here
    void *receiver = zmq_socket (context, ZMQ_SUB); ///Benternet pulls , u SUB  ,important voor receive


    int rs = zmq_connect (sender,"tcp://localhost:24041"); ///"tcp://benternet.pxl-ea-ict.be:24041");
    int rr = zmq_connect (receiver, "tcp://localhost:24042");///"tcp://benternet.pxl-ea-ict.be:24042"); ///important voor receive


    assert (rs == 0);
    printf("Bart saves us\n");

    sleep(1); ///Bcz send and receive too quick
   /// rs = zmq_send (sender , "example>task?>Mikail>" ,  21 , 0);
    rs = zmq_send (sender , "BC?>1111>" ,  9 , 0);
    printf("Send bytes = %d", rs );
    char buf[256];

    while (1) {


            rr = zmq_recv (receiver, buf ,256 , 0 ); ///receiving message option 1
            buf[rr] = '\0'; ///String stop
            printf("Received: %s" , buf);

//            zmq_msg_t msg; ///receiving message option 2
//            int rr = zmq_msg_init (&msg);
//            assert (rr == 0);
//            rr = zmq_msg_recv (&msg, receiver, 0); ///important voor receive
//            zmq_msg_close (&msg);
    }


        zmq_close(receiver);
        zmq_ctx_destroy(context);
        return 0;
}


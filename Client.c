#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <zmq.h>
#include <assert.h>
#include <unistd.h>
#include <sstream>
#include <string>

using namespace std;


int main (int argc, char * argv[])

{

    const char *messageGuess = (argc > 1)? argv [1]: "BC?>Guess>";



    void *context = zmq_ctx_new ();
    void *sender = zmq_socket (context, ZMQ_PUSH); ///If u want to send some , send here
    void *receiver = zmq_socket (context, ZMQ_SUB); ///Benternet pulls , u SUB  ,important voor receive


    int rs = zmq_connect (sender,"tcp://benternet.pxl-ea-ict.be:24041"); ///"tcp://benternet.pxl-ea-ict.be:24041");
    int rr = zmq_connect (receiver, "tcp://benternet.pxl-ea-ict.be:24042");///"tcp://benternet.pxl-ea-ict.be:24042"); ///important voor receive

    int rc = zmq_setsockopt(receiver , ZMQ_SUBSCRIBE , "BC!>" , 4);  ///important , op wat je wilt ontvangen, decides what u receive , BENTERNET SENDS
     sleep(1); ///Bcz send and receive too quick
    printf("BC Client Started, Please enter a 4 digit number\n");
   // rs = zmq_send (sender , "BC?>Join" ,  17 , 0);


    char guess[100];
    char sendGuess[100];
    char buf [256];
    int guesshere [256];


    //assert (rs == 0);

//    printf("Whats ur name");
//    scanf( "%s", name);
//    strcpy(sendName, messageJoin);
//    strcat (sendName, name) ;
//    memset(buf,0,256);
//    zmq_send(sender, sendName, strlen(sendName) , 0);



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
    rc = zmq_recv (receiver, buf ,256 , 0 );
     /// wenselijk heb ik de volgende string ontvangen BC!>0 cows  --> ik heb nodig 1111

     buf[rc] = '\0'; ///String stop
     printf("Received: %s" , buf);

     std :: string strGuess = buf; // numbers in buff
     std :: size_t posPart1 = strGuess.find ( ">");
     std :: string Part1= strGuess.substr(0, posPart1);
     std :: string Part1After = strGuess.substr ( posPart1 + 1);


     std :: size_t posPart2 = Part1After.find(">");
     std :: string Part2= Part1After.substr(0, posPart2);
     std :: string Part2After = Part1After.substr(posPart2 +1);

     std :: cout << '\n' << Part2After;
     }

}

}

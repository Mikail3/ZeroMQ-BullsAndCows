#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <zmq.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;


int main ()

{


    void *context = zmq_ctx_new ();
    void *sender = zmq_socket (context, ZMQ_PUSH);
    void *receiver = zmq_socket (context, ZMQ_SUB);

    int rs = zmq_connect (sender,"tcp://benternet.pxl-ea-ict.be:24041");
    int rr = zmq_connect (receiver, "tcp://benternet.pxl-ea-ict.be:24042");
    int rc = zmq_setsockopt(receiver , ZMQ_SUBSCRIBE , "BC!>" , 4);

    assert (rs == 0);
    sleep(1);
    printf("BC Client Started, Please enter a 4 digit number\n");



   char guess[100];
   char buf [256];
   char choise;
   char input_game;
   int hintplace;
   char BruteForce[100];
   char bufforce [256];


   char bufforceb1 [256];
   char bufforceb2 [256];
   char bufforceb3 [256];
   char bufforceb4 [256];
   char bufforceb5 [256];
   char bufforceb6 [256];
   char bufforceb7 [256];
   char bufforceb8 [256];
   char bufforceb9 [256];
   char bufforceb0 [256];

   char bufforcec1 [256];
   char bufforcec2 [256];
   char bufforcec3 [256];
   char bufforcec4 [256];
   char bufforcec5 [256];
   char bufforcec6 [256];
   char bufforcec7 [256];
   char bufforcec8 [256];
   char bufforcec9 [256];
   char bufforcec0 [256];





    while (true)

    {


    game:



     cout << "What would you like to do?\n"
             "  [G]guess\n"
             "  [H]Hint\n"
             "  [B]Brute Force\n"
             "  [Q]uit\n";;
     std::cin >> choise;
     switch (choise){


             case 'H' :
                {
                     std::cout << "Do u already want a Hint?";
                     std::cout << "Y/N";
                     std::cin >> input_game;
                    // if(input_game != 'n'&& input_game != 'N'&& input_game != 'y'&& input_game != 'Y')
                     if(input_game == 'Y')
                     {
                         cout << "What would you like to do?\n"
                                 "  [1]Hint>1\n"
                                 "  [2]Hint>2\n"
                                 "  [2]Hint>3\n"
                                 "  [3]Hint>4\n";

                         std::cin>>hintplace;
                         switch (hintplace)
                         {

                            case 1 : {
                         std::cout << "U chose hint 1";
                         std::stringstream h1;
                         h1 << "BC?>" << "Hint>1" ;
                         std:: string bone = h1.str();
                         rs =zmq_send (sender , bone.c_str(),  bone.size() , 0);

                          buf[rc] = '\0'; ///String stop
                         std::cout << "Hint 1" << buf;
                          rc = zmq_recv (receiver, buf ,256 , 0 );
                          std :: string strGuess = buf; // numbers in buff
                          std :: size_t posPart1 = strGuess.find ( ">");
                          std :: string Part1= strGuess.substr(0, posPart1);
                          std :: string Part1After = strGuess.substr ( posPart1 + 1);
                          std :: size_t posPart2 = Part1After.find(">");
                          std :: string Part2= Part1After.substr(0, posPart2);
                          std :: string Part2After = Part1After.substr(posPart2 +1);
                          std :: cout << '\n' << Part2After;


                         break;
                          }

                             case 2 : {
                          std::cout << "U chose hint 2";
                          std::stringstream h2;
                          h2 << "BC?>" << "Hint>2" ;
                          std:: string btwo = h2.str();
                         rs=  zmq_send (sender , btwo.c_str(),  btwo.size() , 0);

                          buf[rc] = '\0'; ///String stop
                           std::cout <<  "Here it is! Hint 2" << buf;
                          rc = zmq_recv (receiver, buf ,256 , 0 );
                          std :: string strGuess = buf; // numbers in buff
                          std :: size_t posPart1 = strGuess.find ( ">");
                          std :: string Part1= strGuess.substr(0, posPart1);
                          std :: string Part1After = strGuess.substr ( posPart1 + 1);
                          std :: size_t posPart2 = Part1After.find(">");
                          std :: string Part2= Part1After.substr(0, posPart2);
                          std :: string Part2After = Part1After.substr(posPart2 +1);
                          std :: cout << '\n' << Part2After;

                          goto game;
                           break;
                          }


                             case 3: {
                          std::cout << "U chose hint 3";
                          std::stringstream h3;
                          h3 << "BC?>" << "Hint>3" ;
                          std:: string bthree = h3.str();
                         rs=  zmq_send (sender , bthree.c_str(),  bthree.size() , 0);

                         buf[rc] = '\0'; ///String stop
                          std::cout << "Hint 3" << buf;
                         rc = zmq_recv (receiver, buf ,256 , 0 );
                         std :: string strGuess = buf; // numbers in buff
                         std :: size_t posPart1 = strGuess.find ( ">");
                         std :: string Part1= strGuess.substr(0, posPart1);
                         std :: string Part1After = strGuess.substr ( posPart1 + 1);
                         std :: size_t posPart2 = Part1After.find(">");
                         std :: string Part2= Part1After.substr(0, posPart2);
                         std :: string Part2After = Part1After.substr(posPart2 +1);

                         std :: cout << '\n' << Part2After;


                           goto game;
                           break;
                         }

                             case 4: {
                          std::cout << "U chose hint 4";
                          std::stringstream h4;
                          h4 << "BC?>" << "Hint>4" ;
                          std:: string bfour = h4.str();
                         rs=  zmq_send (sender , bfour.c_str(),  bfour.size() , 0);
                         buf[rc] = '\0'; ///String stop
                          std::cout << "Hint 4" << buf;
                         rc = zmq_recv (receiver, buf ,256 , 0 );
                         //rc = zmq_recv (receiver, buf ,256 , 0 );

                         // split BC> bulls
                         std :: string strGuess = buf; // numbers in buff
                         std :: size_t posPart1 = strGuess.find ( ">");
                         std :: string Part1= strGuess.substr(0, posPart1);
                         std :: string Part1After = strGuess.substr ( posPart1 + 1);
                         std :: size_t posPart2 = Part1After.find(">");
                         std :: string Part2= Part1After.substr(0, posPart2);
                         std :: string Part2After = Part1After.substr(posPart2 +1);

                         std :: cout << '\n' << Part2After;
                          goto game;
                           break;
                          }
                          }
                          }
                           break;
                          }




                 case 'G' :
                    {

                       std::cout << "Type a 4- digit number" << "\n";
                       std::cout << "What's ur guess?" << "\n";
                       cin >> guess;
                       std::stringstream bg;
                       bg << "BC?>" << "Guess>" << guess ;
                       std:: string b = bg.str();
                       rs = zmq_send (sender , b.c_str(),  b.size() , 0);
                       buf[rc] = '\0'; ///String stop
                       printf("Received163: %s" , buf);

                       rc = zmq_recv (receiver, buf ,256 , 0 );
                       //rc = zmq_recv (receiver, buf ,256 , 0 );

                       // split BC> bulls
                       std :: string strGuess = buf; // numbers in buff
                       std :: size_t posPart1 = strGuess.find ( ">");
                       std :: string Part1= strGuess.substr(0, posPart1);
                       std :: string Part1After = strGuess.substr ( posPart1 + 1);
                       std :: size_t posPart2 = Part1After.find(">");
                       std :: string Part2= Part1After.substr(0, posPart2);
                       std :: string Part2After = Part1After.substr(posPart2 +1);

                       std :: cout << '\n' << Part2After;

                       goto game;

                       break;

                      }


                case 'B' :
     {


         std::cout << "This is brute force, sending a Brute Force!" << "\n";
         //std::cin >> BruteForce;
         std::stringstream bf;
         bf << "BC?>" << "Brute Force";
         std::string f = bf.str();

         while(1)

         {

       rs = zmq_send (sender , "BC?>Brute Force>0000",  21 , 0);
       rr = zmq_recv (receiver, bufforceb0 ,256 , 0 );
       bufforceb0[rr] = '\0'; ///String stop
       // split BC> bulls
       std :: string strFB0 = bufforceb0; // numbers in buff //FB0
       std :: size_t posPart1FB0 = strFB0.find ( ">");
       std :: string Part1FB0= strFB0.substr(0, posPart1FB0);
       std :: string Part1AfterFB0 = strFB0.substr ( posPart1FB0 + 1);
       std :: size_t posPart2FB0 = Part1AfterFB0.find(">");
       std :: string Part2FB0= Part1AfterFB0.substr(0, posPart2FB0);
       std :: string Part2AfterFB0 = Part1AfterFB0.substr(posPart2FB0 +1);
       rr = zmq_recv (receiver, bufforcec0 ,256 , 0 );
       bufforcec0[rr] = '\0'; ///String stop
       std :: cout << '\n' <<"How many times Bulls with 0000---" <<Part2AfterFB0;
       // split BC> cows
       std :: string strFC0 = bufforcec0; // numbers in buff //FB0
       std :: size_t posPart1FC0 = strFC0.find ( ">");
       std :: string Part1FC0= strFC0.substr(0, posPart1FC0);
       std :: string Part1AfterFC0 = strFC0.substr ( posPart1FC0 + 1);
       std :: size_t posPart2FC0 = Part1AfterFC0.find(">");
       std :: string Part2FC0= Part1AfterFC0.substr(0, posPart2FC0);
       std :: string Part2AfterFC0 = Part1AfterFC0.substr(posPart2FC0 +1);
       std :: cout << '\n' <<"How many times Cows with 0000---" <<Part2AfterFC0;






         rs = zmq_send (sender , "BC?>Brute Force>1111",  21 , 0);
       // split BC> bulls
        rr = zmq_recv (receiver, bufforceb1 ,256 , 0 );
        bufforceb1[rr] = '\0'; ///String stop
        // split BC> bulls
        std :: string strFB1 = bufforceb1; // numbers in buff //FB0
        std :: size_t posPart1FB1 = strFB1.find ( ">");
        std :: string Part1FB1= strFB1.substr(0, posPart1FB1);
        std :: string Part1AfterFB1 = strFB1.substr ( posPart1FB1 + 1);
        std :: size_t posPart2FB1 = Part1AfterFB1.find(">");
        std :: string Part2FB1= Part1AfterFB1.substr(0, posPart2FB1);
        std :: string Part2AfterFB1 = Part1AfterFB1.substr(posPart2FB1 +1);
        std :: cout << '\n' <<"How many times Bulls with 1111---" <<Part2AfterFB1;
        // split BC> bulls
         rr = zmq_recv (receiver, bufforcec1 ,256 , 0 );
         bufforcec1[rr] = '\0'; ///String stop
        std :: string strFC1 = bufforcec1; // numbers in buff //FB0
        std :: size_t posPart1FC1 = strFC1.find ( ">");
        std :: string Part1FC1= strFC1.substr(0, posPart1FC1);
        std :: string Part1AfterFC1 = strFC1.substr ( posPart1FC1 + 1);
        std :: size_t posPart2FC1 = Part1AfterFC1.find(">");
        std :: string Part2FC1= Part1AfterFC1.substr(0, posPart2FC1);
        std :: string Part2AfterFC1 = Part1AfterFC1.substr(posPart2FC1 +1);
        std :: cout << '\n' <<"How many times Cows with 1111---" <<Part2AfterFC1;





         rs = zmq_send (sender , "BC?>Brute Force>2222",  21 , 0);
         rr = zmq_recv (receiver, bufforceb2 ,256 , 0 );
         bufforceb2[rr] = '\0'; ///String stop
         // split BC> bulls
         std :: string strFB2 = bufforceb2; // numbers in buff //FB0
         std :: size_t posPart1FB2 = strFB2.find ( ">");
         std :: string Part1FB2= strFB2.substr(0, posPart1FB2);
         std :: string Part1AfterFB2 = strFB2.substr ( posPart1FB2 + 1);
         std :: size_t posPart2FB2 = Part1AfterFB2.find(">");
         std :: string Part2FB2= Part1AfterFB2.substr(0, posPart2FB2);
         std :: string Part2AfterFB2 = Part1AfterFB2.substr(posPart2FB2 +1);
         std :: cout << '\n' <<"How many times Bulls with 2222---" <<Part2AfterFB2;
         // split BC> bulls
          rr = zmq_recv (receiver, bufforcec2 ,256 , 0 );
          bufforcec2[rr] = '\0'; ///String stop
         std :: string strFC2 = bufforcec2; // numbers in buff //FB0
         std :: size_t posPart1FC2 = strFC2.find ( ">");
         std :: string Part1FC2= strFC2.substr(0, posPart1FC2);
         std :: string Part1AfterFC2 = strFC2.substr ( posPart1FC2 + 1);
         std :: size_t posPart2FC2 = Part1AfterFC2.find(">");
         std :: string Part2FC2= Part1AfterFC2.substr(0, posPart2FC2);
         std :: string Part2AfterFC2 = Part1AfterFC2.substr(posPart2FC2 +1);
         std :: cout << '\n' <<"How many times Cows with 2222---" <<Part2AfterFC2;




            rs = zmq_send (sender , "BC?>Brute Force>3333",  21 , 0);
            rr = zmq_recv (receiver, bufforceb3 ,256 , 0 );
            bufforceb3[rr] = '\0'; ///String stop
           // split BC> bulls
           std :: string strFB3 = bufforceb3; // numbers in buff //FB0
           std :: size_t posPart1FB3 = strFB3.find ( ">");
           std :: string Part1FB3= strFB3.substr(0, posPart1FB3);
           std :: string Part1AfterFB3 = strFB3.substr ( posPart1FB3 + 1);
           std :: size_t posPart2FB3 = Part1AfterFB3.find(">");
           std :: string Part2FB3= Part1AfterFB3.substr(0, posPart2FB3);
           std :: string Part2AfterFB3 = Part1AfterFB3.substr(posPart2FB3 +1);
           std :: cout << '\n' <<"How many times Bulls with 3333---" <<Part2AfterFB3;
           // split BC> cow
           rr = zmq_recv (receiver, bufforcec3 ,256 , 0 );
           bufforcec3[rr] = '\0'; ///String stop
           std :: string strFC3 = bufforcec3; // numbers in buff //FB0
           std :: size_t posPart1FC3 = strFC3.find ( ">");
           std :: string Part1FC3= strFC3.substr(0, posPart1FC3);
           std :: string Part1AfterFC3 = strFC3.substr ( posPart1FC3 + 1);
           std :: size_t posPart2FC3 = Part1AfterFC3.find(">");
           std :: string Part2FC3= Part1AfterFC3.substr(0, posPart2FC3);
           std :: string Part2AfterFC3 = Part1AfterFC3.substr(posPart2FC3 +1);
            std :: cout << '\n' <<"Line351" <<Part2AfterFC3;
           std :: cout << '\n' <<"How many times Bulls with 3333---" <<Part2AfterFC3;




         rs = zmq_send (sender , "BC?>Brute Force>4444",  21 , 0);
         rr = zmq_recv (receiver, bufforceb4 ,256 , 0 );
         bufforceb4[rr] = '\0'; ///String stop
       // split BC> bulls
       std :: string strFB4 = bufforceb4; // numbers in buff //FB0
       std :: size_t posPart1FB4 = strFB4.find ( ">");
       std :: string Part1FB4= strFB4.substr(0, posPart1FB4);
       std :: string Part1AfterFB4 = strFB4.substr ( posPart1FB4 + 1);
       std :: size_t posPart2FB4 = Part1AfterFB4.find(">");
       std :: string Part2FB4= Part1AfterFB4.substr(0, posPart2FB4);
       std :: string Part2AfterFB4 = Part1AfterFB4.substr(posPart2FB4 +1);
       std :: cout << '\n' <<"How many times Bulls with 4444---" <<Part2AfterFB4;
       // split BC> bulls
       rr = zmq_recv (receiver, bufforcec4 ,256 , 0 );
       bufforcec4[rr] = '\0'; ///String stop
       std :: string strFC4 = bufforcec4; // numbers in buff //FB0
       std :: size_t posPart1FC4 = strFC4.find ( ">");
       std :: string Part1FC4= strFC4.substr(0, posPart1FC4);
       std :: string Part1AfterFC4 = strFC4.substr ( posPart1FC4 + 1);
       std :: size_t posPart2FC4 = Part1AfterFC4.find(">");
       std :: string Part2FC4= Part1AfterFC4.substr(0, posPart2FC4);
       std :: string Part2AfterFC4 = Part1AfterFC4.substr(posPart2FC4 +1);
       std :: cout << '\n' <<"How many times Cows with 4444----" <<Part2AfterFC4;


       rs = zmq_send (sender , "BC?>Brute Force>5555",  21 , 0);
       rr = zmq_recv (receiver, bufforceb5 ,256 , 0 );
       bufforceb5[rr] = '\0'; ///String stop
       // split BC> bulls
       std :: string strFB5 = bufforceb5; // numbers in buff //FB0
       std :: size_t posPart1FB5 = strFB5.find ( ">");
       std :: string Part1FB5= strFB5.substr(0, posPart1FB5);
       std :: string Part1AfterFB5 = strFB5.substr ( posPart1FB5 + 1);
       std :: size_t posPart2FB5 = Part1AfterFB5.find(">");
       std :: string Part2FB5= Part1AfterFB5.substr(0, posPart2FB5);
       std :: string Part2AfterFB5 = Part1AfterFB5.substr(posPart2FB5 +1);
       std :: cout << '\n' <<"How many times Bulls with 5555---" <<Part2AfterFB5;
       // split BC> bulls
       rr = zmq_recv (receiver, bufforcec5 ,256 , 0 );
       bufforcec5[rr] = '\0'; ///String stop
       std :: string strFC5 = bufforcec5; // numbers in buff //FB0
       std :: size_t posPart1FC5 = strFC5.find ( ">");
       std :: string Part1FC5= strFC5.substr(0, posPart1FC5);
       std :: string Part1AfterFC5 = strFC5.substr ( posPart1FC5 + 1);
       std :: size_t posPart2FC5 = Part1AfterFC5.find(">");
       std :: string Part2FC5= Part1AfterFC5.substr(0, posPart2FC5);
       std :: string Part2AfterFC5 = Part1AfterFC5.substr(posPart2FC5 +1);
       std :: cout << '\n' <<"How many times Cows with 5555---" <<Part2AfterFC5;




       rs = zmq_send (sender , "BC?>Brute Force>6666",  21 , 0);
       rr = zmq_recv (receiver, bufforceb6 ,256 , 0 );
        bufforceb6[rr] = '\0';
       // split BC> bulls
       std :: string strFB6 = bufforceb6; // numbers in buff //FB0
       std :: size_t posPart1FB6 = strFB6.find ( ">");
       std :: string Part1FB6= strFB6.substr(0, posPart1FB6);
       std :: string Part1AfterFB6 = strFB6.substr ( posPart1FB6 + 1);
       std :: size_t posPart2FB6 = Part1AfterFB6.find(">");
       std :: string Part2FB6= Part1AfterFB6.substr(0, posPart2FB6);
       std :: string Part2AfterFB6 = Part1AfterFB6.substr(posPart2FB6 +1);
       std :: cout << '\n' <<"How many times Bulls with 6666---" <<Part2AfterFB6;
        rr = zmq_recv (receiver, bufforcec6 ,256 , 0 );
        bufforcec5[rr] = '\0';
       // split BC> bulls
       std :: string strFC6 = bufforcec6; // numbers in buff //FB0
       std :: size_t posPart1FC6 = strFC6.find ( ">");
       std :: string Part1FC6= strFC6.substr(0, posPart1FC6);
       std :: string Part1AfterFC6 = strFC6.substr ( posPart1FC6 + 1);
       std :: size_t posPart2FC6 = Part1AfterFC6.find(">");
       std :: string Part2FC6= Part1AfterFC6.substr(0, posPart2FC6);
       std :: string Part2AfterFC6 = Part1AfterFC6.substr(posPart2FC6 +1);
       std :: cout << '\n' <<"How many times Cows with 6666-----" <<Part2AfterFC6;





       rs = zmq_send (sender , "BC?>Brute Force>7777",  21 , 0);
       rr = zmq_recv (receiver, bufforceb7 ,256 , 0 );
        bufforceb7[rr] = '\0';
       // split BC> bulls
       std :: string strFB7 = bufforceb7; // numbers in buff //FB0
       std :: size_t posPart1FB7 = strFB7.find ( ">");
       std :: string Part1FB7= strFB7.substr(0, posPart1FB7);
       std :: string Part1AfterFB7 = strFB7.substr ( posPart1FB7 + 1);
       std :: size_t posPart2FB7 = Part1AfterFB7.find(">");
       std :: string Part2FB7= Part1AfterFB7.substr(0, posPart2FB7);
       std :: string Part2AfterFB7 = Part1AfterFB7.substr(posPart2FB7 +1);
       std :: cout << '\n' <<"How many times Bulls with 7777-----" <<Part2AfterFB7;
       // split BC> bulls
       rr = zmq_recv (receiver, bufforcec7 ,256 , 0 );
        bufforcec7[rr] = '\0';

       std :: string strFC7 = bufforcec7; // numbers in buff //FB0
       std :: size_t posPart1FC7 = strFC7.find ( ">");
       std :: string Part1FC7= strFC7.substr(0, posPart1FC7);
       std :: string Part1AfterFC7 = strFC7.substr ( posPart1FC7 + 1);
       std :: size_t posPart2FC7 = Part1AfterFC7.find(">");
       std :: string Part2FC7= Part1AfterFC7.substr(0, posPart2FC7);
       std :: string Part2AfterFC7 = Part1AfterFC7.substr(posPart2FC7 +1);
       std :: cout << '\n' <<"How many times Cows with 7777-----" <<Part2AfterFC7;





       rs = zmq_send (sender , "BC?>Brute Force>8888",  21 , 0);
       rr = zmq_recv (receiver, bufforceb8 ,256 , 0 );
        bufforceb8[rr] = '\0';
       // split BC> bulls
       std :: string strFB8 = bufforceb8; // numbers in buff //FB0
       std :: size_t posPart1FB8 = strFB8.find ( ">");
       std :: string Part1FB8= strFB8.substr(0, posPart1FB8);
       std :: string Part1AfterFB8 = strFB8.substr ( posPart1FB8 + 1);
       std :: size_t posPart2FB8 = Part1AfterFB8.find(">");
       std :: string Part2FB8= Part1AfterFB8.substr(0, posPart2FB8);
       std :: string Part2AfterFB8 = Part1AfterFB8.substr(posPart2FB8 +1);
       std :: cout << '\n' <<"How many times Bulls with 8888-----" <<Part2AfterFB8;
       // split BC> bulls
        rr = zmq_recv (receiver, bufforcec8 ,256 , 0 );
         bufforcec8[rr] = '\0';
       std :: string strFC8 = bufforcec8; // numbers in buff //FB0
       std :: size_t posPart1FC8 = strFC8.find ( ">");
       std :: string Part1FC8= strFC8.substr(0, posPart1FC8);
       std :: string Part1AfterFC8 = strFC8.substr ( posPart1FC8 + 1);
       std :: size_t posPart2FC8 = Part1AfterFC8.find(">");
       std :: string Part2FC8= Part1AfterFC8.substr(0, posPart2FC8);
       std :: string Part2AfterFC8 = Part1AfterFC8.substr(posPart2FC8 +1);
       std :: cout << '\n' <<"How many times Cows with 8888-----" <<Part2AfterFC8;





        rs = zmq_send (sender , "BC?>Brute Force>9999",  21 , 0);
        rr = zmq_recv (receiver, bufforceb9 ,256 , 0 );
         bufforceb9[rr] = '\0';
        // split BC> bulls
        std :: string strFB9 = bufforceb9; // numbers in buff //FB0
        std :: size_t posPart1FB9 = strFB9.find ( ">");
        std :: string Part1FB9= strFB9.substr(0, posPart1FB9);
        std :: string Part1AfterFB9 = strFB9.substr ( posPart1FB9 + 1);
        std :: size_t posPart2FB9 = Part1AfterFB9.find(">");
        std :: string Part2FB9= Part1AfterFB9.substr(0, posPart2FB9);
        std :: string Part2AfterFB9 = Part1AfterFB9.substr(posPart2FB9 +1);
        std :: cout << '\n' <<"How many times Bulls with 9999----" <<Part2AfterFB9;
        // split BC> bulls
        rr = zmq_recv (receiver, bufforcec9 ,256 , 0 );
         bufforcec9[rr] = '\0';
        std :: string strFC9 = bufforcec9; // numbers in buff //FB0
        std :: size_t posPart1FC9 = strFC9.find ( ">");
        std :: string Part1FC9= strFC9.substr(0, posPart1FC9);
        std :: string Part1AfterFC9 = strFC9.substr ( posPart1FC9 + 1);
        std :: size_t posPart2FC9 = Part1AfterFC9.find(">");
        std :: string Part2FC9= Part1AfterFC9.substr(0, posPart2FC9);
        std :: string Part2AfterFC9 = Part1AfterFC9.substr(posPart2FC9 +1);
        std :: cout << '\n' <<"How many times Cows with 9999----" <<Part2AfterFC9;
        std :: cout << '\n' <<"End is reached";
        goto game;

         }

        break;



     }


                case 'Q' :
                 {
                    std::cout << "This option is not ready yet" << "\n";
                    goto game;
                    break;

                 }

     }


//                 buf[rc] = '\0'; ///String stop
//                 printf("Received163: %s" , buf);
//                 rc = zmq_recv (receiver, buf ,256 , 0 );
//                 //rc = zmq_recv (receiver, buf ,256 , 0 );

//                 // split BC> bulls
//                 std :: string strGuess = buf; // numbers in buff
//                 std :: size_t posPart1 = strGuess.find ( ">");
//                 std :: string Part1= strGuess.substr(0, posPart1);
//                 std :: string Part1After = strGuess.substr ( posPart1 + 1);
//                 std :: size_t posPart2 = Part1After.find(">");
//                 std :: string Part2= Part1After.substr(0, posPart2);
//                 std :: string Part2After = Part1After.substr(posPart2 +1);

//                 std :: cout << '\n' << Part2After;

       }

    }



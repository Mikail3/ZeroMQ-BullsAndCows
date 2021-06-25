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

int main()
{
        void *context = zmq_ctx_new ();
        void *sender = zmq_socket (context, ZMQ_PUSH);
        void *receiver = zmq_socket (context, ZMQ_SUB);

        int rs = zmq_connect (sender,"tcp://benternet.pxl-ea-ict.be:24041");
        int rr = zmq_connect (receiver, "tcp://benternet.pxl-ea-ict.be:24042");
        int rc = zmq_setsockopt(receiver , ZMQ_SUBSCRIBE , "BC?>" , 4);
        int rg = zmq_setsockopt(receiver , ZMQ_SUBSCRIBE , "BC?>Guess>" , 11);
        int rh = zmq_setsockopt(receiver , ZMQ_SUBSCRIBE , "BC?>Hint" , 9);

        assert (rs == 0);
        printf("BC Server Started!\n");
        sleep(1);

        rs = zmq_send (sender , "BullsCows Started" ,  17 , 0);
        rs = zmq_send (sender , "---Welcome to BULLS & COWS!---" ,  30 , 0);

        int Guesses[256];
        int size = 0;
        char buf[256];
        //char Part2Copy [256];
        char buf2[145];
        char Part2After[256];
        char bufhint[100];
        int Part2Copy[100];
while(1)
{


    /* ///option1 for rand
    int  = 4;
    std :: string result = "";

    for (int i = 0; i < NUM_DIGITS; i++)
    {
           result.push_back(rand()%10 + '0'); ///zorgt dat je strings aan elkaar concatineert , voeg er iets toe aan achter.
    }
    */

    //seed random number generator
    std::srand( std::time(nullptr) );

    //note that NUM_DIGITS should not be set so high
    //that MAX_NUMBER is not representable as an `int`
    // NUM_DIGITS is what cows should be, replacing number in this case 4
    const int NUM_DIGITS = 4;

    //set this to the highest possible number that
    //corresponds to NUM_DIGITS
    constexpr int MAX_NUMBER = 9999;

    //this variable holds the entire number
    int random;

    //this converts the int to an string
    //std::string str = std::to_string(random);

    //this array holds the individual digits
    int digits[NUM_DIGITS];

    ///generate the random number
    for (int i = 0; i < MAX_NUMBER; i++)
    {
    random = std::rand()%(MAX_NUMBER+ '0');
    }

    //calculate the individual digits of the random number
    int remaining = random;
    int divisor = (MAX_NUMBER + 1 ) / 10;
    for ( int i = 0; i < NUM_DIGITS; i++ )
    {
        digits[i] = remaining / divisor;
        remaining = remaining % divisor;
        divisor/= 10;
    }

    //print the whole random number
    std::cout << "Whole random number:\n" << random << "\n\n";

    //print the individual digits
    //std::cout << "Individual digits:\n";
    std::cout << "Individual digits:\n";
    std::cout << "First Digit" << digits[0] << "\n";
    std::cout << "Second Digit" << digits[1] << "\n";
    std::cout << "Third Digit" << digits[2] << "\n";
    std::cout << "Fourth Digit" << digits[3] << "\n";

    for ( int i = 0; i < NUM_DIGITS; i++ )
    {
        std::cout << digits[i] << "\n";
    }

   while (1) {

        beginbc:
//        std::stringstream id;
//        id << "BC!>input a " << NUM_DIGITS << "-digit number : ";
//        std:: string s = id.str();
//        rs = zmq_send (sender , s.c_str(),  s.size() , 0);
//        sleep(1);



        std::string gs= "";
        rr = zmq_recv (receiver, buf ,256 , 0 );
        buf[rr] = '\0'; ///String stop
        std::cout << "Receiving from the client.." << buf;


        std :: string strGuess = buf;
        std :: size_t posPart1 = strGuess.find ( ">");
        std :: string Part1= strGuess.substr(0, posPart1);
        std :: string Part1After = strGuess.substr ( posPart1 + 1);
        std :: size_t posPart2 = Part1After.find(">");
        std :: string Part2= Part1After.substr(0, posPart2);
        std :: string Part2After = Part1After.substr(posPart2 +1); //Any message after oooo> gets put into Part2After [ BC?>oooo>xxxx ]


        std:: stringstream np; // numbers are here Guess>1234 -> 1234
        np << '\n' << Part2After << '\n' ;
        std:: string p = np.str();
        rs = zmq_send (sender , p.c_str() , p.size () , 0);

        std :: cout << '\n' <<Part2After << '\n'; //converting the string to an int for the hint part
        int HintNumber;
        std::istringstream(Part2After) >> HintNumber;
        //std :: cout<< Part2After << "Lijn144" <<'\n';

        if (Part2After.size() ==4)

        {
            goto bullscowsresult;
        }



       if (Part2After.size()>4 )
        {
            //cin.clear();
            //cin.ignore(256,  '\n');

            std::stringstream fd;
            fd << "BC!>" << NUM_DIGITS << "-Digits bruh pls !!!\n";
            std:: string f = fd.str();
            rs = zmq_send (sender , f.c_str(),  f.size() , 0);
            goto beginbc;
            continue;
       }
       // goto bullscowsresult;

       if (Part2After.size()== 1 )

       {
           if (HintNumber == 1 )
           {
               std::stringstream sh1;
               sh1 << "BC!>Hint1>" << digits[0] << "--Hint on first place!";;
               std:: string h1 = sh1.str();
               rs = zmq_send (sender , h1.c_str(),  h1.size() , 14);


           }
           if (HintNumber == 2 )
           {
               std::stringstream sh2;
               sh2 << "BC!>Hint2>" << digits[1] << "--Hint on second place!";;
               std:: string h2 = sh2.str();
               rs = zmq_send (sender , h2.c_str(),  h2.size() , 14);


           }
           if (HintNumber == 3 )
           {
               std::stringstream sh3;
               sh3 << "BC!>Hint3>" << digits[2] << "--Hint on third place!";;
               std:: string h3 = sh3.str();
               rs = zmq_send (sender , h3.c_str(),  h3.size() , 14);


           }
           if (HintNumber == 4 )
           {
               std::stringstream sh4;
               sh4 << "BC!>Hint4>" << digits[3] << "--Hint on fourth place!";;
               std:: string h4 = sh4.str();
               rs = zmq_send (sender , h4.c_str(),  h4.size() , 14);

           }
    }





//           std::string hs1= "";
//           rh = zmq_recv (receiver, bufhint ,256 , 0 );
//           hs1 = bufhint;
//           bufhint[rh] = '\0'; ///String stop
//           printf("Received150: %s" , bufhint);
//            //String splitsing for finding >Hint
//           std :: string strHint = "BC?>Hint>"; //This is the string
//           std :: size_t posPart1Hint = strHint.find ( ">");
//           std :: string Part1Hint= strHint.substr(0, posPart1Hint);
//           std :: string Part1AfterHint = strHint.substr (posPart1Hint+1);
//           std :: size_t posPart2Hint = Part1AfterHint.find(">");
//           std :: string Part2HintHint= Part1AfterHint.substr(0, posPart2Hint);
//           std :: string Part2AfterHint = Part1AfterHint.substr(posPart2Hint+1);
//           std :: cout << '\n' << "Line166" << Part2AfterHint;
//           int HintNumber;
//           std::istringstream(Part2AfterHint) >> HintNumber;
//           std :: cout << '\n' << "Chosen Hint place" << HintNumber;





        else
        {
        bullscowsresult:
        int bulls = 0;
        int cows = 0;

        std :: string Part2Copy = Part2After ;
        std :: string resultCopy= std::to_string(random);
        std :: cout << '\n' << "Line306" <<Part2Copy << '\n';
        //std :: cout << '\n' << "Line307" << resultCopy << '\n';

        for (int i = 0; i < NUM_DIGITS; i++) ///loop cows
        {
            if (resultCopy[i] == Part2Copy[i])
            {    /// if the same
                cows++;
                resultCopy[i] = -1;
                Part2Copy[i] = -1;

            }
        }

        for (int i = 0; i < NUM_DIGITS; i++) ///loop bulls
        {
            if ( Part2Copy [i] >= 0 )
            {
              for (int j = 0; j < NUM_DIGITS; j++) /// loop eelk NUM_DIGITS
              {

                 if ( Part2Copy[j] >= 0 && resultCopy[j] == Part2Copy[i])
                 {    /// if the same
                    bulls++;
                    resultCopy[j] = -1;
                    Part2Copy[i] = -1;
                    std :: cout << '\n'<<"line 169" <<Part2Copy[i] << '\n';

                }
             }
          }

        }
        /// if 4 cows = RIGHT
        if (cows == 4)
        {
            size++;
            break;
        }

             std::stringstream bcb;
             bcb << "BC!>" << bulls << " bulls\n";
             std:: string bc = bcb.str();
             rs = zmq_send (sender , bc.c_str(),  bc.size() , 0);

             std::stringstream bcc;
             bcc << "BC!>" << cows << " cows\n";
             std:: string bc2 = bcc.str();
             rs = zmq_send (sender , bc2.c_str(),  bc2.size() , 0);




        size++;
        }
    }

    std::stringstream fi; ///finale
    fi << "BC!>\n";
    fi << "You guessed it right,leave here if you want to quit!\n";
    fi << "The correct number is " << random << endl;
    fi<< "These are all the numbers you'd guessed.\n";

    for (int i = 0; i < size; i++)
    {
        std::stringstream gu;
        gu << "BC!>" << Part2Copy[i] << endl;
        std:: string g = gu.str();
        rs = zmq_send (sender , g.c_str(),  g.size() , 0);
    }
    rs = zmq_send (sender , "BullsCows Stopped, Restarting!" ,  31 , 0);


}
}

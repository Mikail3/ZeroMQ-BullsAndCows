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

void SplitNummer(int number, int array[], int size)
{
    for (; number != 0; number /= 10)
        array[--size] = number%10;
}
int main()
{

    void *context = zmq_ctx_new ();
    void *sender = zmq_socket (context, ZMQ_PUSH);
    void *receiver = zmq_socket (context, ZMQ_SUB);

    int rs = zmq_connect (sender,"tcp://benternet.pxl-ea-ict.be:24041");
    int rr = zmq_connect (receiver, "tcp://benternet.pxl-ea-ict.be:24042"); ///important voor receive
    int rc = zmq_setsockopt(receiver , ZMQ_SUBSCRIBE , "BC?>" , 4); ///important , op wat je wilt ontvangen, decides what u receive , BENTERNET SENDS
    assert (rs == 0);
    printf("Bulls&Cows Server started\n");
    sleep(1); ///Bcz send and receive too quick, we put sleep

    rs = zmq_send (sender , "BullsCows Started" ,  17 , 0);
    srand(time(NULL));
    int Guesses[100];
    int size = 0;	/// guesses
    /// randomizer
    const short nummer = 4;
    int result = rand()%9000 + 1000;
    int resultArray[nummer];
    int resultArrayCopy[nummer];
    char Response;
    char buf [256];
    char PlayerName;
    //SplitNummer(result, resultArray, nummer);	/// resultaat gaat naar array

    /* randomizer
    const short nummer = 4;
    std :: string result = "";
    for (int i = 0; i < nummer; i++) ///loop randomizer
    {
    result.push_back(rand()%10 + '0'); ///zorgt dat je strings aan elkaar concatineert , voeg er iets toe aan achter.
    }
    */

    StartGame:
    while(true)
    {
        std::stringstream id;
        id << "input a " << nummer << "-digits number : ";
        std:: string s = id.str();
        rs = zmq_send (sender , s.c_str(),  s.size() , 0);
        sleep(1);

         std::string gs= "1111";
         rr = zmq_recv (receiver, buf ,256 , 0 ); ///receiving message option 1
         /// wenselijk heb ik de volgende string ontvangen BC?>1111>  --> ik heb nodig 1111
         gs = buf;
         buf[rr] = '\0'; ///String stop
         printf("Received: %s" , buf);

         std :: string strGuess = "BC?>1111>";
         std :: size_t posPart1 = strGuess.find ( ">");
         std :: string Part1= strGuess.substr(0, posPart1);
         std :: string Part1After = strGuess.substr ( posPart1 + 1);


         std :: size_t posPart2 = Part1After.find(">");
         std :: string Part2= Part1After.substr(0, posPart2);
         std :: string Part2After = Part1After.substr(posPart2 +1);


         std :: cout << '\n' << Part2 << '\n' ;

         if (!cin)/// (Guesses[size] < 1000 || Guesses[size] > 9999) check if input is int
                 {
                     cin.clear();
                     cin.ignore(256,  '\n');

                     std::stringstream fd;
                     fd << "BC!>!!! " << nummer << "-Digits bruh pls !!!\n";
                     std:: string f = fd.str();
                     rs = zmq_send (sender , f.c_str(),  f.size() , 0);

                     continue;
        }
        else
        {
        /// bulls and cows
        int bulls = 0;
        int cows = 0;
        /// inputted number as array
        int numberArr[nummer];
        SplitNummer(Guesses[size], numberArr, nummer);
        /// loop find bulls and cows

       memcpy(resultArrayCopy, resultArray, nummer*sizeof(int));  ///Overwriting resultArrayCopy to resultArray
        for (int i = 0; i < nummer; i++)
        {
            if (resultArrayCopy[i] == numberArr[i])
            {    // if the same
                cows++;
                resultArrayCopy[i] = -1;
                numberArr[i] = -1;
            }
        }

        for (int i = 0; i < nummer; i++) //loop bulls
        {
            if ( numberArr[i] >= 0 )
            {
              for (int j = 0; j < nummer; j++) /// loop eelk nummer
              {

                 if ( resultArrayCopy[j] >= 0 && resultArrayCopy[j] == numberArr[i])
                 {    // if the same
                    bulls++;
                    resultArrayCopy[j] = -1;
                    numberArr[i] = -1;
                    break;
                }
             }
          }

        }
        /// if 4 cows = RIGHT
        if (cows == 4) {
            size++;
            break;
        }
        /// weergeven van de aantallen
           std::stringstream bc; ///bullscows
           bc << "BC!>" << bulls << " bulls\n";
           bc << "BC!>" << cows << " cows\n";
           std:: string b = bc.str();
           rs = zmq_send (sender , b.c_str(),  b.size() , 0);
           size++;
        }
    }

    std::stringstream fi;

    fi << "BC!>" "---\n";
    fi << "You guessed it right\n";
    fi << "The correct number is " << result << endl;;
    fi  << "These are all the numbers you'd guessed.\n";
    std:: string f = fi.str();
    rs = zmq_send (sender , f.c_str(),  f.size() , 0);

        for (int i = 0; i < size; i++)
    {

        std::stringstream gu; // total guesses
        gu << "BC!>" << Guesses[i] << endl;
        std:: string g = gu.str();
        rs = zmq_send (sender , g.c_str(),  g.size() , 0);
        
        std::stringstream ag;
        ag <<  "Would u Like to play again? ( Y/N) .\n"; 
        std:: string a = ag.str();
        rs = zmq_send (sender , a.c_str(),  a.size() , 0);
        
      
        
        

        /*
    cout << "Would u Like to play again? ( Y/N) .\n";
    cin >> Response;
    if (Response == 'Y' ) //not "Y" but only one 'Y')
    {
    goto StartGame;
    }
    else if (Response == 'N')
    {
    cout << "Bye, would u like a cookie?.\n";

    }
    */


    }
     rs = zmq_send (sender , "BullsCows Stopped" ,  17 , 0);
    return 0;

    return 0;
}

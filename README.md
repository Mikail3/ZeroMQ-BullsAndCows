# ZeroMQ-BullsAndCows
Server is built using -> C++

Client is built using  -> C

Your .pro file should be edited we need ; lib, libzmq and the zmq.h includes -> See the [needs] branch

# Gameplay rules
Bulls&Cows is a guessing game.
The computer randomly generates a number that contains 4 characters from 1000 - 9000.

If you guess a correct number -> you get a "Cow"

If you guess the correct number but the number is on the wrong place -> you get "Bulls"

Need some help? This webiste could come in clutch https://www.grin.com/document/312138#:~:text=The%20code%2Dbreaker%20tries%20to,the%20least%20number%20of%20attempts.

# Commands
2 Commands that are being used;

1) **this is what you expect** :

* BullsCows>game?>message> 
* BullsCows>join?>message>

2) **this is what it replies** :

* BullsCows>join!>message 
* BullsCows>game!>message>



 -> [ Messages to the server are being sent with an " ? " ]
 
 -> [ Replies from the server are with an " ! " ]
 
 * You run the client first and it sends a command BullsCows>join?>join to the Broker
 * The Broker is listening to the server and replies with BullsCows>join!>Game is ready & BullsCows>game!>Make a guess firts
 * The client receives BullsCows>join!>Game is ready & BullsCows>game!>Make a guess first
 

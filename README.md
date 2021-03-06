<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
***
***
***
*** To avoid retyping too much info. Do a search and replace for the following:
*** github_username, repo_name, twitter_handle, email, project_title, project_description
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][https://www.linkedin.com/in/mikail-cinar-037bb5197/]

-->

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/Mikail3/ZeroMQ-BullsAndCows">
    <!--<img src="https://github.com/Mikail3/ZeroMQ-BullsAndCows/blob/dev/BC.PNG"
         alt="Logo" width="80" height="80"> -->
  </a>

  <h3 align="center">ZeroMQ Bulls&Cows</h3>

  <p align="center">
    project_description
    <br />
    <a href="https://github.com/Mikail3/ZeroMQ-BullsAndCows"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Mikail3/ZeroMQ-BullsAndCows">View Demo</a>
    ·
    <a href="https://github.com/Mikail3/ZeroMQ-BullsAndCows/issues">Report Bug</a>
    ·
    <a href="https://github.com/Mikail3/ZeroMQ-BullsAndCows/issues">Request Feature</a>
  
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
         <li><a href="#includes">Includes</a></li>
      </ul>
    </li>
    <li><a href="#usage and expectations">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<!--
[![Product Name Screen Shot][product-screenshot]](https://example.com)

Here's a blank template to get started:
**To avoid retyping too much info. Do a search and replace with your text editor for the following:**
`github_username`, `repo_name`, `twitter_handle`, `email`, `project_title`, `project_description`
-->
The main goal of this project was to learn about network programming with the open source messaging libary ZeroMQ

In order to achieve the logic behind the different types of sockets, I made a game with a single client whom is the player, and a server where the game is implemented.

Bulls&Cows a guessing game based on the computer generating 4 random integers, also called mastermind.

U as the player have to guess a number ranging from 0000-9999, the main goal is to guess 4 bulls!

Two things might happen;


`the user guesses the correct number on the correct place and gets cows`


`the user guesses the correct number on the incorrect place and gets bulls `




### Built With

* [https://www.qt.io] `v15.4.1`
* [https://zeromq.org]() 
* [MinZMQt_Windows_distributable]() `Benternet`



<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Port forwarding
Surf to your providers website where you will be port forwarding your `TCP to 24059` and `UDP to 24058` 


### Prerequisites

This is an example of how to list things you need to use the software and how to install them. 

Create the folders in the same dir as the game, following folders have to be made:


`include , lib , libzmq `

#### Includes for ZeroMQ

Option 1: ZeroMQ includes for MINGW64 with `MSYS2`
  ```sh
  $ pacman -S mingw-w64-x86_64-zeromq
  ```
Option 2: ZeroMQ includes for MINGW64 prebuilt for MINGW64
  ```sh
   git clone https://github.com/Mikail3/ZeroMQ-BullsAndCows/includes.git
   ```

### Installation

 Clone the repo
   ```sh
   git clone https://github.com/Mikail3/ZeroMQ-BullsAndCows.git
   ```
 ### .pro File
Make sure to change the `.pro` file in QT ,the following lines have to be added:


`DEFINES += ZMQ_STATIC`
`LIBS += -L$$PWD/../lib -lzmq -lws2_32 -lIphlpapi`
`INCLUDEPATH += $$PWD/../include`



<!-- USAGE EXAMPLES -->
## Usage and expectation

1. Run the `Server`
2. Run the `Broker aka Benternet`
3. Run the `Client`
4. Make a 4 digit guess on the client, the client pushes `BC?>Guess>1111`
5. The message gets pushed by using `zmq_send` over the broker.
6. The server is subscribed using `ZMQ_SUBSCRIBE`on on `BC?>` and receives `BC?>Guess>1111`while using `zmq_receive`
7. The received message gets splitted and parsed with `std::string`, and the number 1111 is being processed by the server and a `std::substring` is being made.
8. The server checks the received number by the client, if input is larger or smaller then 4 digits the server responds with `BC!>4-Digits Bruh pls!`.
9. The server replies and pushes the amount of bulls or cows with `zmq_send` (`BC!>0 bulls and BC!>4 bulls`), the client parses the reply with `std::string` aswell.
10. The client is subscribed on `BC!>` and receives what the result is by filtering the exclamation mark.
11. Right answer? Check the broker! And the client can continue guessing. Leaving the game does not restart it, the next game will continue where you left off.
12. Enjoy! Still not clear? Check the `Wiki` for a flowchart



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/github_username/repo_name/issues) for a list of proposed features (and known issues).



<!-- CONTRIBUTING -->
## Contributing

Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Mikail Cinar- [@Linkedin](https://www.linkedin.com/in/mikail-cinar-037bb5197/) 

Project Link: [https://github.com/Mikail3/ZeroMQ-BullsAndCows](https://github.com/Mikail3/ZeroMQ-BullsAndCows)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

*  Bart Stukken (https://github.com/Bart-PXL)






<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/github_username

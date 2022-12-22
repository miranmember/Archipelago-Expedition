# Archipelago-Expedition
Welcome to the Archipelago Expedition project! This project is a simulation of a network of islands that are connected by ferry routes. The goal of this project is to allow the user to input commands to interact with the network of islands.
## Getting Started
To get started, clone this repository and navigate to the project directory. Compile the source code by running the following command:
```
make Project6
```
You can then run the program by executing the following command:
```
./archipelago
```

## Commands
The following commands are available for interacting with the network of islands:

q: Quit the program.
?: Show the list of available commands.
#: Ignore the rest of the line. This is useful for commenting out lines in the command file.
s <int1> <int2>: Show the shortest path between the two islands with the given IDs.
t <int1> <int2>: Test if it is possible to travel between the two islands with the given IDs.
r <int>: Resize the network of islands to the given number of islands.
i <int1> <int2>: Insert a ferry route between the two islands with the given IDs.
d <int1> <int2>: Delete the ferry route between the two islands with the given IDs.
l: List all the islands and their connections.
f <filename>: Process the commands in the given file.
## Example
To see an example of how to use these commands, you can run the following command:

Copy code
./archipelago < input1.txt
This will process the commands in the input1.txt file and output the results to the terminal.

## Class Descriptions
The following is a brief description of the classes used in this project:

+ Island: This class represents a single island in the network. It has an ID, a list of adjacent islands, and a flag indicating whether it has been visited during a search.
+ ArchipelagoExpedition: This class represents the entire network of islands. It has an array of Island objects and a list of strings representing the commands to be processed.
+ FileList: This class represents a list of strings, where each string is a line from a file. It is used to store the commands from a file.
+ IslandQueue: This class is a queue implemented using a linked list. It is used to store the islands that need to be visited during a breadth-first search.
+ MyList: This is a custom implementation of a linked list. It has functions for inserting and deleting elements, as well as functions for retrieving the length of the list and the nth element in the list. It also has a printList function for printing the elements of the list.
+ Node: This class represents a single node in the linked list. It has an int value representing the island ID and a pointer to the next node in the list.

#include "island.h"

class ArchipelagoExpedition
{
 private:
   // Create the Data Members for the Archipelago Network here
   Island *expedition;
   int numIslands;
   FileList FL;
   // Add file data member here
   // you can either use a linked list of strings
   // or a dynamic array of strings
 public:
  
 // Use a constructor to initialize the Data Members for your expedition
 ArchipelagoExpedition()
 {
   numIslands = 10;
   expedition = new Island[numIslands]();
   FileList FL;
 }

  
 void depthFirstSearchHelper(int x, int y){
   for(int i = 0; i < numIslands; i++){
     expedition[i].setVisited(false);
   }

   if(dfs(x,y) == true)
    printf("You can get from island %d to island %d in one or more ferry rides\n", x, y);
  else
    printf("You can NOT get from island %d to island %d in one or more ferry rides\n", x, y);
 }


 bool dfs(int x, int y){
   for(int i = 0; i < expedition[x-1].getAdjacent()->getListLength(); i++){
     int island = expedition[x-1].getAdjacent()->getNthElem(i);
     if(island == y)
      return true;

     if(expedition[island-1].getVisited() == false){
       expedition[x-1].setVisited(true);

       if ( dfs(island,y) == true )
        return true;
     }
   }
   return false;
 }
  
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \r\n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL )
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
      exit(1);
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();
     
    else if ( strcmp (command, "t") == 0) 
      doTravel();

    else if ( strcmp (command, "s") == 0) 
      doShortestPath();
     
    else if ( strcmp (command, "r") == 0) 
      doResize();

    else if ( strcmp (command, "i") == 0) 
      doInsert();

    else if ( strcmp (command, "d") == 0) 
      doDelete();

    else if ( strcmp (command, "l") == 0) 
      doList();

    else if ( strcmp (command, "f") == 0) 
      doFile();

    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input
  }
 }
 
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  s <int1> <int2> \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }

 bool bfs(int b, IslandQueue &IslandQueue) {
	 while (!IslandQueue.empty()) {
		 int a = IslandQueue.front();
		 IslandQueue.pop();
		 for (int i = 0; i < expedition[a - 1].getAdjacent()->getListLength() + 1; i++) {
			 int c = expedition[a - 1].getAdjacent()->getNthElem(i);
			 if (expedition[c].getpreviousLocation() == -1) {
				 expedition[c].setpreviousLocation(a);
				 if (c == b) {
					 return true;
				 }
				 IslandQueue.push(c);
			 }
		 }
	 }
	 return false;
 }

 Stack breadthFirstsearch(int x, int y) {
	 Stack pathList;
	 for(int i = 0; i < numIslands + 1; i++){
     	expedition[i].setpreviousLocation(-1);
   	 }
	 IslandQueue IslandQueue;
	 IslandQueue.push(x);

	 if (bfs(y, IslandQueue) == false) {
		 cout << "You can NOT get from island " << x << " to island " << y << endl;
		 return pathList;
	 }

	 cout << "You can get from island " << x << " to island " << y << endl;
	 int currentIsland = y;
	 pathList.push(currentIsland);
	 do {
		 currentIsland = expedition[currentIsland].getpreviousLocation();
		 pathList.push(currentIsland);
	 } while (currentIsland != x);
	 IslandQueue.clear();
	 return pathList;
 }

 void doShortestPath(){
	int x = 0;
    int y = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");


   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   x = atoi ( next );
   if ( x == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \r\n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   y = atoi ( next );
   if ( y == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   if (x > this->numIslands || y > this->numIslands) {
	   cout << "Invalid value for island" << endl;
	   return;
   }

	 cout << "Performing the shortest path Command from " << x << " to " << y << endl;
	 Stack pathList;
	 pathList = breadthFirstsearch(x, y);
	 if (!pathList.empty()) {
		cout << "shortest path from " << x << " to " << y << ": ";
		while (!pathList.empty()) {
			if (pathList.getHead()->getNext() == nullptr) {
				cout << pathList.top() << endl;
				pathList.pop();
				break;
			}
			cout << pathList.top() << " - ";
			pathList.pop();
		}
	 }
	 pathList.clear();
 }

 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");


   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \r\n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   
   printf ("Performing the Travel Command from %d to %d\n", 
            val1, val2);
   depthFirstSearchHelper(val1, val2);
 }

 void clear() {
	//  for (int i = 0; i < numIslands; i++) {
	// 	 delete expedition[i].getAdjacent();
	//  }
	//  delete[] expedition;
 }
 
 void doResize()
 {
   int val1 = 0;
   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi(next);
   
   printf ("Performing the Resize Command with %d\n", val1 );

   clear();
   numIslands = val1;
   expedition = new Island[numIslands]();
 }
 
 void doInsert()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \r\n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   if(val1 <= numIslands && val2 <= numIslands){
    printf ("Performing the Insert Command for %d\n", val1 );
    expedition[val1-1].getAdjacent()->insert(val2);}
   else
    printf("Invalid value for island\n");
 }
 
 void doDelete()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \r\n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \r\n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if (val1 > this->numIslands || val2 > this->numIslands) {
	   cout << "Invalid value for island" << endl;
	   return;
   }

   printf ("Performing the Delete Command for %d\n", val1 );
   expedition[val1-1].getAdjacent()->remove(val2);
 }
 
 void doList()
 {
   printf ("Displaying the adjacency list:\n" );
   for(int i = 0; i < numIslands; i++){
     printf("%d -->  ", i+1);
     expedition[i].getAdjacent()->printList();
     printf("\n");
   }
 }
 
 void doFile()
 {
   // get a filename from the input
   char* fname = strtok (NULL, " \r\n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   printf ("Performing the File command with file: %s\n", fname);
   string F = fname;

   if (FL.inUse(F)) {
	   cout << "File is already in use" << endl;
	   return;
   }

   FILE *file;
   file = fopen(fname, "r");
   if (!file) {
	   cout << "Cannot open the file" << endl;
   }
   FL.push(F);
   processCommandLoop(file);
   fclose(file);
   FL.remove(F);
 }
};

int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the island adjcency list
  ArchipelagoExpedition islandData;
   
  // call the method that reads and parses the input
  islandData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  islandData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
 
  return 1;
 }

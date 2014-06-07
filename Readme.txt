Program 5 GraphMaker was created for Spring 2014 CS101 by Christopher Dilday.

The IntList ADT was created by altering the Linked List ADT from program 1, which
I worked on with Alex Vincent. We did not work together for this project, though I
did ask for help when I ran into the problem I'm about to explain.


Every part of these files work perfectly except for the main Graph function doBFS.
Unfortunately this means that I will likely not even get half on this program which
will make passing this class difficult, but I've reached out for help to everyone I
know that has taken this class, and even posted on the forum for help with no luck.

While I was searching for help, GraphMaker, the main read-in program, was created, which
properly read-in and stores all edges in the adjacency list (G->graph) as well as the 
queries. It's just when I try and run doBFS, it fails at seemingly random points when 
I try and access the queue, even though I can prove it's properly instantiated. I've 
had this issue before with a different program, but then it was memory managements issues
that I have done everything to solve in the program with no such luck. I've tried three different 
ways of doing BFS on a graph, and all three times run into the same issue where it tries either
a delete function in IntList or a get function and it fails without even entering the function
even though earlier in doBFS it managed to use them just fine. I've tried Valgrind and it
just tells me there's a problem without giving any insight as to where or why, and I've
tried malloc'ing everything to the proper size that it would need even if it wouldn't need
it otherwise. The Linked List works perfectly as well, so It can't be that.

Essentially what I'm saying is I've done everything in my ability to solve a problem with
a source that I am completely ignorant to or is specific to my file/timeshare space that 
I can't control. Every other portion of the graph works, and if you uncomment the line
in GraphMaker in the first while loop that I've labeled, it will show the edges, and to
print the whole graph uncomment the printGraph line after the loop. it then properly reads
the queries and would print them had I got BFS working correctly. 
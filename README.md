ID: 214173957
Email: nevobiton0@gmail.com
# Assignment 2 - Graph and Operators overloading
in this assigment, as following to assignment 1, I was asked to make exclusive oprators that will work with the Graph class, I created the action operators: +, -, +=, -=, ++(pre and post), --(pre and post), *, *=, <<. and I created also the comparison operatos: <, >, <=, >=, ==, !=.

Every operator function got the args it needed, (+ two graphes, ++ one graph and so on), most of the action operators were simply just traversing the graph and making the action, it I was needing to plus 2 graphs, I Created new Graph and initialized his adjacency matrix in the place of[i][j] be the first graph in[i][j] + second graph in [i][j]. Same was done with a number add or ++ add. The actions operators were quite simple and intuitive to code. the * operator was just matrix multiplication and returning the new matrix. And finally, now a user can use my graph class as regular primitive type and use simple actions like plus or minus with it.

My way of thinking in related to the comparison operators was to depend on former comparison operators I have already written.
For instance, the == operator was just traversing through both the graph and check if first[i][j] == second[i][j] for every i and j (within the graphs vertices amount). After creating the == operator, Creating the != was simple, it returns the opposite that == returns. That usage of former operators reallt simplified the coding. same as >= after writing > and ==. 
Writing the >,< operators was just following the definition, firstly I checked if the graphes are equal, if yes return false. after that I traverse through the graph and checked if every edge of the alledgly smaller graph is in the larger graph (to check if its contained in the graph), if yes, return true. if No, just check if the larger one has more edges or vertices than the smaller one, if yes return true.

making the <= was just asking if (g1 == g2 || g1 < g2), which is the definition of <= (same with opposite direction).
And finnaly creating the output operator, it prints the adjacency matrix of the graph to a ostream provided.

After making all these operators I find their usage really helpful, Now my Graph class can be used simply without needing to iterate it every time.

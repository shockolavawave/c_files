#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*	task-pe-task
	
	here are a few instuctions for playing it.
	compile the code and run the program and press enter to begin.
	the tasks are simple; scoring is obligatory.
	
	IMP: here, there are 27 tasks in first version
		 hence, there is a (27) in the third line of the while loop block.
		 that number should always be equal to the number of tasks or else
		 the game won't be fun enough or it might crash as well.
		 This game was originally made for windows environment. Do make
		 required changed for different platforms.

*/

int main()
{
	char c, *tasks[] = {
							"Task 1: Sing your favourite song",
							"Task 2: Sing a lullaby (any language)",
							"Task 3: Sing a song in your mother tongue",
							"Task 4: Tongue twister:\n(kaccha papad, pakka papad) x 5",
							"Task 5: Tongue twister:\n(She sells sea shells on the sea shore) x 5",
							"Task 6: Tongue twister:\n(road roller) x 10",
							"Task 7: Tongue twister:\n(Can you can a can as a canner can can a can?) x 3",
							"Task 8: Tongue twister:\n(Black background, brown background) x 10",
							"Task 9: Name 10 objects starting from the letter _..",	
							// the game conductor will give random letter and set a time limit
							"Task 10: Name 5 Englsih movies starting from the letter _..",
							// the game conductor will give random letter and set a time limit
							"Task 11: Name 10 ___ in 30 secs\n(code 1)",	// code 1 : food dishes
							"Task 12: Name 10 ___ in 30 secs\n(code 2)",	// code 2 : sports
							"Task 13: Name 10 ___ in 30 secs\n(code 3)",	// code 3 : fruits
							"Task 14: Name 10 ___ in 30 secs\n(code 4)",	// code 4 : vehicles
							"Task 15: Name 10 ___ in 30 secs\n(code 5)",	// code 5 : colours
							"Task 16: Name 10 ___ in 30 secs\n(code 6)",	// code 6 : state capitals
							"Task 17: Moo like a cow and croak like a frog\n(each for five seconds)",
							"Task 18: Neigh like a horse and caw like a crow\n(each for five seconds)",
							"Task 19: Quack like a duck and hiss like a snake\n(each for five seconds)",
							"Task 20: Hoot like an owl and coo like a pigeon\n(each for five seconds)",
							"Task 21: Crow like a rooster and trumpet like an elephant\n(each for five seconds)",
							"Task 22: Roar like a lion and meow like a cat\n(each for five seconds)",
							"Task 23: Bark like a dog and click like a lizard\n(each for five seconds)",
							"Task 24: Bleet like a goat and cheep like a chick\n(each for five seconds)",
							"Task 25: Tell a (laughable) joke",
							"Task 26: Speak about the thing you love/like the most for 1 min",
							"Task 27: Hum the entire airtel tune",
					   };
	int a;
	
	srand(time(0));
	
	puts("Wecome to task-pe-task!" "\n"
		 "Press enter to begin!");
	
	// the while loop
	while(c = getchar(), c!='e')
	{
		fflush(stdin);
		system("cls");
		a = rand()%27;		puts(tasks[a]);
		
		puts("\nNext task! Press any key to get.");
	}
	
	puts("Thank you for using the program! ^_^");
	
	return 0;
}

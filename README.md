# Philosophers
Philosopher project 42

## Strategies

The magic receipe is to make the philos odd or even start the routine with 2000 microsecond late. In addition you have to separeted the eat routine, if the philo is even you can make him take the right fork first and the left in second. If the philo is odd you can make him the left first and the right after for exemple. You can also make the countrary.

In my code I use usleep instead of using my sleep fonction because the perfomances was too low. But it can higher the time takes by the program to go out when a philo dies and the time to eat and the time to sleep are very long.

## Mutexes 

It is not necessary to initialize differents mutexes for each elements that have to be a shared ressources. You can make 2 mutexes, one for a fork, and one for all the rest (the print, all the flags, etc.). The other fork can just be a mutexe pointer to the other fork.

## Supervize

I use my main program for supervize philo's death. Your main program is already a thread. I simply made a while loop to check all philos 1 by 1.

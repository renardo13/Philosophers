# Philosophers
Philosopher project 42 Mandatory part

```make```

```./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]```

## Strategies
The magic receipe is to make the philos odd OR even start the routine with 2000 microsecond late. In addition you have to separeted the eat routine, if the philo is even you can make him take the right fork first and the left in second. If the philo is odd you can make him take the left first and the right after for exemple. You can also make the countrary.

A good organization of your code is the key for philo. 
I made 2 structures : one relative to the informations of the philos themselves, shared between one philo and the main, like last_meal, ph->id, etc. and one named "data" that countain all the ressources that will be shared between them (+ the supervizor) like printf, the time, the dead_flag, etc.).

In my code I use usleep instead of using my sleep fonction because the perfomances was too low. But it can higher the time taked by the program to go out when a philo dies when the time to eat and the time to sleep are very long.

## Mutexes 
It is not necessary to initialize differents mutexes for each elements that have to be a shared ressources. You can make 2 mutexes, one for a fork, and one for all the rest (the print, all the flags, etc.). The other fork can just be a mutexe pointer to the other fork.

## Supervize
I use my main program for supervize philo's death. Your main program is already a thread. I simply made a while loop to check all philos 1 by 1.

## Makefile
You can compile with the flag ```-fsanitize=thread``` to check if there is data races, you can add ```-g3``` to have the line of the data race.

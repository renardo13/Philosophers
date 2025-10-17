### This project is about multithreading in C

The Philosophers project is about the classic Dining Philosophers Problem dealing with concurrency, synchronization and resource management.
Each philosopher alternates between thinking, eating, and sleeping, sharing limited resources (forks) that must be handled carefully to avoid deadlocks and race conditions.

each philosopher runs in its own `thread`, operating simultaneously while accessing shared data protected by `mutexes`.
Proper thread synchronization ensures that no two philosophers try to use the same fork at once, and that timing and state management remain consistent across all threads.

In the bonus version, the simulation of philosophers become separate `processes` communicating through `semaphores`, turning the problem into inter process synchronization.

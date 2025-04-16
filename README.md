# 🍝 Philosophers

![Philosophers](https://img.shields.io/badge/Project-Philosophers-blue)
![Language](https://img.shields.io/badge/Language-C-orange)
![Threading](https://img.shields.io/badge/Concept-Threading%20%26%20Mutexes-brightgreen)

## 📜 The Dining Philosophers Problem

*"I never thought philosophy would be so deadly..."*

This project is an implementation of the famous Dining Philosophers problem, a classic synchronization and concurrency challenge introduced by Edsger Dijkstra in 1965 to illustrate the challenges of avoiding deadlock and resource starvation in concurrent systems.


### The Scenario

- A number of philosophers sit at a round table with a bowl of spaghetti in the middle
- Philosophers alternate between three states: eating, thinking, or sleeping
- There are as many forks on the table as there are philosophers
- To eat, a philosopher needs both their left and right forks
- After eating, they put the forks back and start sleeping
- Once they wake up, they begin thinking
- The simulation stops when a philosopher dies of starvation
- Philosophers don't communicate with each other
- Every philosopher needs to eat and should never starve

## 🛠️ Technical Implementation

This implementation uses:
- Threads to represent each philosopher
- Mutexes to protect the forks and prevent data races
- Timestamps to track when philosophers last ate to prevent starvation

### Key Program Components

- **Threads**: Each philosopher runs as an independent thread
- **Mutexes**: Protect shared resources (forks) and critical sections
- **Time Management**: Using `gettimeofday` to track timestamps accurately

## 🚀 How to Run

### Compilation

```bash
# Clone the repository
git clone https://github.com/yourusername/philosophers.git
cd philosophers/philo

# Compile the program
make
```

### Running the Program

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Parameters

- `number_of_philosophers`: Number of philosophers and forks
- `time_to_die` (ms): Time since a philosopher's last meal before they die
- `time_to_eat` (ms): Time it takes to eat a meal
- `time_to_sleep` (ms): Time a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat` (optional): If specified, simulation stops when all philosophers have eaten this many times

### Examples

```bash
# 5 philosophers, 800ms time to die, 200ms to eat, 200ms to sleep
./philo 5 800 200 200

# 4 philosophers, each must eat at least 5 times
./philo 4 410 200 200 5
```

## 🎯 Project Goals

This project teaches:
- Basics of threading in C
- Mutex usage for thread synchronization
- Handling race conditions
- Solving deadlock situations
- Resource allocation strategies

## 🧵 Threading Challenges

The implementation addresses several key challenges:

### Deadlock Prevention

If all philosophers pick up their left fork simultaneously, none can pick up the right fork, resulting in deadlock. This implementation prevents deadlock by having even-numbered philosophers pick up right fork first, odd-numbered philosophers pick up left fork first (resource hierarchy solution).

### Race Conditions

Multiple threads accessing shared data could lead to inconsistencies. Mutexes are used to protect:
- Fork state
- Last meal time records
- Output printing

### Optimization

The philosophers need to minimize waiting time while ensuring fairness. Key optimizations include:
- Staggering initial start times
- Careful timing of critical sections
- Minimizing mutex lock times

## 📊 Project Structure

```
.
├── philo/
│   ├── check_end.c     # Death verification and simulation end conditions
│   ├── header.h        # Main header with structs and function prototypes
│   ├── initialising.c  # Setup functions for mutexes and philosopher data
│   ├── Makefile        # Compilation directives
│   ├── parsing.c       # Command line argument validation
│   └── philo.c         # Main functions and philosopher routine
└── README.md           # This file
```

## 🧪 Testing

Test your implementation with these scenarios:

1. **Basic functionality**:
   ```bash
   ./philo 5 800 200 200
   ```
   All philosophers should survive and alternate eating

2. **Death scenario**:
   ```bash
   ./philo 4 310 200 100
   ```
   A philosopher should eventually die

3. **Optional exit condition**:
   ```bash
   ./philo 5 800 200 200 7
   ```
   Should exit after all philosophers have eaten 7 times

4. **Edge cases**:
   ```bash
   ./philo 1 800 200 200     # Only one philosopher
   ./philo 200 800 200 200   # Many philosophers
   ```

## 🔍 Implementation Details

### Philosopher Lifecycle

1. **Initialize**: Create threads and mutexes
2. **Routine**:
   - Try to take both forks
   - Eat for time_to_eat milliseconds
   - Release forks
   - Sleep for time_to_sleep milliseconds
   - Think until forks become available
   - Repeat
3. **Monitoring**: A separate monitoring mechanism checks if any philosopher has starved

### State Tracking

The program tracks and displays philosopher state changes:
- Taking a fork: `timestamp_in_ms X has taken a fork`
- Eating: `timestamp_in_ms X is eating`
- Sleeping: `timestamp_in_ms X is sleeping`
- Thinking: `timestamp_in_ms X is thinking`
- Death: `timestamp_in_ms X died`

## 🔗 Resources

For more information about the Dining Philosophers problem:
- [The Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Dijkstra's Solution - GeeksforGeeks](https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/)
- [Mutex vs Semaphore - StackOverflow](https://stackoverflow.com/questions/62814/difference-between-binary-semaphore-and-mutex)

## 📝 License

This project is part of the 1337 School curriculum. Feel free to use it as a reference, but plagiarism is strictly prohibited.

---
© 2023 yoelansa

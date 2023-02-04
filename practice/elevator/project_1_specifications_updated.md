# Elevator Sim
## Description
The Elevator Sim simulates the use of an elevator in a moderately sized high-rise building in New York (50 floors which includes the lobby, floor 1).

All good bulding have names, this building is no exception. Throughout the remainder of this document the building will be refered to as, "the Medford."

### The Tempo
The tempo of the simulation will be controlled by a central loop. Each iteration of this loop will be considered a "tick" of the clock. For each tick of the clock, all activities of the program of the data structures that support those activities should update.

In this program you will rely heavily on random number generation to control activities. For example, on any givent tick, there will be some probability of a new person entering the buildings lobby. That person will have assigned a random destination floor, and so on.

### People
You will model and individual person as a class. The person need only have two fields: a unique ID, and a destination floor. The Unique ID will be asigned based on a counter that you maintain. The floor will be assigned uniformily at random. The random values will range from 1 - 50 (floors 1 thru 50).

People will arrive at random throughout the day. The probability of a person entering the building on any tick is 0.035. That means that a person might enter the building approxamatly every 28.57 ticks.

People will not move from floor to floor. They simply enter the building at the lobby and get in line for the elevator to take them to their randomly selected floor.

The proabaility of a Person on any floor leaving the building on any tick is the different than arriving, 0.015. All Floors should be checked on each tick. The person leaving does't matter, simply remove a Person from the Floor's bag an add it to the Floor's elevator queue. 

### The Floors
You will have a line for people waiting for the elevator. This line will be serviced by the elevator. When the elevator stops on any floor at any given tick, its passangers destined for that floor will get out. The number of passagers an elevator can take depends on its capacity. See the elevator design.

### The Elevator
The elevator is a simple machine. Its maximum catacity is 6. It should initially start in the lobby. Once they take on passengers from the lobby, they will move upwards dropping the passengers at their floors until the elevator is empty. Once the elevator is empty, it will check the call set for passengers who need to be brought to the lobby. If there are none, then it will check the lobby for passengers who need to be brought up. If there are no passengers in the lobby then it will not do anything to maximize power savings. 

When checking the call set, the elevator should respond to the highest floor first, pick up the passengers on that floor then start moving downward. On its way down it can stop at any floor that has a person waiting to go to the lobby. Once moving downward it will continue moving only in that direction until it reaches the lobby then it switches to moving upward.

When the elevator stops to pick up or drop off a passenger, it should take 10 ticks at the floor to allow the passenger to disembark. It should also pause for 10 ticks when it stops to pick up a passenger. If a call comes in for a floor and that floor is in the direction of the elvators current motion, the elevator should stop at that floor as long as it hasn't reached its capacity. Once an elevator is full and moving in any direction, it will continue moving in that direction until it's empty. This is because people only go from the lobby to their floor or from their floor to the lobby.

## Design
You will use the data structures that were discussed and implemented in class to construct this simulator. Some will require modification and others can be used as-is.

### The Building
- Write a class that represents the building. 
- The Building will have floors and the elevator.

### Person
- The Person class will have a constructor that sets its two elements. 
	-  ID
	- Floor destination
	- These elements should not change value once they are set.

### Floors
- A Bag should represent each floor. This is where the Person objects will be stored when they arrive to their respective floors. 
- Each floor should have an elevator queue for the Persons leaving the floor.
- The lobby need only have an elevator queue. When a new Person enters the Building they will be immediately added to the queue. You can create a floor Bag for the lobby and not use it. 
- An array of Bags and an array of elevator queues to represent all floors is a good idea.

### Elevator
- The Elevator class will have an array of booleans for the call set. If there's a Person waiting for the Elevator on any floor, the element that represents that floor will be set (will equal true). 
- The Elevator will contain a Bag to hold the Persons that are in it.
- It should control which direction it travels.
- It should require 4 ticks to move from one floor to an adjacent floor. 
- It should pause 10 ticks to allow for Persons to embark or disembark. 
- When the elevator picks up the Persons waiting on a floor, the element that represents that floor will be unset (set to false) only if the elevator takes all of the Persons on that floor, otherwise, it will remain set.

### Controller
- You will write a Controller class that will orchestrate all of the actions of the simulator. Indeed, it is the simulator.
- One of the members of the Controller will be a Building. 
- The Controller is responsible for:
    - Creating the new Persons that enter the Building
    - Creating the main loop that generates the ticks (just the main loop of the program).
    - Calling update on the Building on each tick
    - Recording and or outputting any information to the user concerning. 
    - Determening when a Person on any floor is ready to leave

## Other Design Notes
- Only the main function should seed the random number generator. 
- You can create a separate cpp and h file for common library function sch as a function that returns a random value in that falls with in a certain range. 


**No class should take input from the uesr for print output except the program file that holds the main function and/or the Controller class**
**In other words, only the Controller and the cpp file with the main function should include iostream**


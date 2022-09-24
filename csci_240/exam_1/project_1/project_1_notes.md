# Elevator Sim
## The Tempo
- a tick represent each loop
## The Building
- a clas has floors and elevator
- 50 floors
- floor 1 is lobby
- floor 50 is highest floor
## People
- a class with only two fields
- id
- destination floor
- 0.035 chance to enter the building
- do not move from floor to floor
## The Floors
- a Bag for each floor to store Person object when arrive
- a elevator queue for each floor for Person to leave
- an array of floors
- an array of elevator queues
## The Elevator
- a class contain a Bag to store Person in elevator
- maximum capacity is 6
- start in the lobby
- an array of booleans for the call set
- control which directin to travel
- take 4 ticks to move from one floor to an adjacent floor
- pause 10 ticks for Person to embark or disembark
## The Controller
- all actions happen here
- Building is a member in Controller
- create new Persons entering the Building
- create the main loop that generates the ticks
- call update on each tick
- record and output any info
- determine when a Person on any floor is ready to leave
## Questions
1) a Bag class representing a floor or a floor class contains a Bag?
- 
2) create a Bag class for floor and elevator?
- 
3) create a separate queue class for elevator class or a queue inside the elevator class
- 
4) how to simulate up and down movement for elevator
- 
5) how to simulate which floor the elevator is at
- 

## Quiz 4
### System Design
#### Architecture
- Model-View-Controller
- Client-Server
- Layered
- Peer-to-Peer
- Pipe-and-Filter

#### Functional Dcomposition
- design process led by breaking down the functionality
    - start at the highest level and then break that highest level functionality into its sub-phases. We continue to break them down again and again until we have something small enough.
    - we have higher level functions to call lower level functions

#### Relational Database Design
- design process led by breaking down the data
    - identify the data
    - how do we access the data
    - have a table with rows and columns

#### Object-Oriented Design
- an "object" contains both data and methods
- a "class" is a blueprint for making objects
- design process led by breaking down the entities identified in the domain and the functionality that accompanies each entity
    - not the most efficient data design
    - end up doing functional decompostion
    - still need to figure out how to store the data

#### User Interface Design
- design process led by envisioning the user interface and iterating
- drawing out the ideas
- probably get overwhelmed when try to figuring everything out in your brain all at the same time and you will not be able to make much progress

#### Sketching
- start with sketching your ideas

### Purposes of Designs
#### Think
- think about your design
- put your ideas into sketches
- others can see your ideas/design
#### Communciate
- use your sketches to communicate with others
- others can see and analyze your design
- others can offer their opinions
#### Prescribe
- decides what to do
- let the developers code it
- the prescription is the finalized design that will be coded up
- like the blueprint that is given to developers to code
#### designs are used iteratively to think, talk, and prescribe
- things may not work as expected
- need to think agian, then talk, and finally prescribe again
- things keep improving

### Abstraction
- abstractions are formed by removing irrelevant information and retaining/highlighting relevant information
- every design notation supports a certain kind of abstraction
- software engineering is all about constructing and elaborating abstractions/models
- realational database design does not need to think about UI design
- UI design does not need to think about how data is stored on the disk
- abstraction is similar to functional decomposition in a way that we do not have to think about everything all at once
- each design allows you to only focus on one area of design

### Diagrams
#### UML Class Diagrams
- industry standard for software design/modeling
- different types of UML diagrams are used to represent different aspects (structure, behavior, interactions) of a system
    - class digrams
    - activity diagrams
    - sequence diagrams
    - use case digarams
- UML class digrams
    - used in decomposing a system into modules known as classes
    - typically used to...
        - model domain concepts
        - create a detailed, object-oriented design of the code
    - it does not say exactly what each function does
    - but it does say what functions should exist
    - minus sign: private members
        - -Attributes : type
    - plus sign: public members
        - +Operations (parameter) : return type
    - superclass <- subclass
        - empty arrow
        - inheritance
        - subclass can reuse functions in the superclass unless overriden
#### Associations
- association relations can be directional or non-directional
- they can be bi-directional or uni-directional
- if no arrowheads, we assume bi-directional
- if only one arrowheads, it means uni-directional
- label next to classes describe what they do
- A    B
- 1 to 1 : one B with each A; one A with each B
#### Multiplicities
- * describe how many reference a class has
- 1 to * : one A qith each Bs, zero or more Bs
#### Relationships
- aggregation
    - one object contains (or is composed of) a set of other objects
    - aggregation relationships are transitive and assymetric
        - open diamond to represent aggregation
        - crate <>- bottle
            - crate contains bottles
            - bottles are contained within a crate
        - bottle <>- sand
            - crate contains sand
        - cannot be reversed
- composition
    - a variant of aggregatoin which adds the property of existence dependency
        - closed diamond to represent composition
        - house <//>- room
        - you cannot have a room without having a house

### Design Principles
#### Cohesion/Coupling
- high cohesion
    - grouping related functionality
- low coupling
    - ungrouping unrelated functionality/ reducing interdependency
    - grouping together the things that should be grouped together and they are highly interdependent
    - they know all about each other and have access to each other's data
- effects
    - changes do not propagate
    - reuse is facilitated
    - components do not know all the internal state of other components
#### Information Hiding
- hide design decisions that are most likely to change, thereby protecting other parts of the program from change if the design decision is changed
- "showing only those details to the outside world which are necessary for the outside world and hiding all other details from the outside world"
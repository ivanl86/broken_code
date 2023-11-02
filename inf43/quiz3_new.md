## Course Quiz 3
### Flow
- basic flow
    - goal is achieved in the expected way
- alternative flow
    - goal is achieved in an alternative way
- exception
    - goal is not achieved

### Use Cases
- use cases is often part of the requirement
### Sofatware Architecture
- software architecture is the blueprint of a software system's construct and design
- a software architecture consists of
    - components
    - connectors
- components and connectors are arranged to configurations
- perscriptive srchitecture
    - as-designed/as-intended architecture
    - how a software should be
    - like a doctor's prescription
- descriptive architecture
    - as-implemented/as-realized architecture
    - what reality actually is
- when a syste change
    - ideally its prescriptive architecture is modified first
    - in practice, the system - and thus its descriptive architecture - is often directly modified
- architectural erosion
    - developer sloppiness
    - short deadline
    - lack of (documented) perscriptive architecture
    - code optimizations
    - inadequate techniques or tool support
    ### Software Architectural Style
    - a named collection of architectural design decisions that
        - are applicable in a given development context
        - constrain architectural design decisions
        - results in beneficial qualities in each resulting system
    - a named, commonly used set of components/connectors/configurations
        - each component/connector has its own job
### Model-View-Controller
- benefits
- modularity
- anticipation of change
    - ex. ATM (anything has GUI)
        - goals
            - withdrawals, deposits, transfers, balance checks
            - separation of concerns
    - controller (rules) -> bank account (model) -> ATM display(view) -> controller
### Client-Server
- sharing data and services over a wide range of clients
- centralized control over access, functionality, data
    - ex. MMO rpg
        - goals
            - multi-player, online
            - control access to data and players
    - all game clients -> game server
### Layered
- benefits
- modularity
- bstraction
- anticipation
- reuse
    - ex. restaurant
        - goals
            - prepare and serve food to customers
            - enforce a specific protocol of interaction
                - abstract away irrelevant details
                - minimize the effects of changes
            - separate concerns
                - keep each part focused on a specific task
### Peer-to-Peer
- benefits
    - efficient (skip the central server)
    - inefficient (go through every user)
    - robust (difficult to remove a file from p2p server)
    - ex. Skype
        - goals
            - online video chat and vocie calls
            - share same functionlaity between mulitple people without slowing down video/audio streaming

### Pipe-and-Filter
- benefits
- modularity
- reuse
- anticipation of change
    - ex. Instagram, Youtube
        - translate a high-level programming language into a low-level one that computer can execute
        - separate different steps of translation so I can modify steps easily
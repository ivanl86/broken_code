use cases is often part of the requirement

types of flows
basic flow: goal is achieved in the expected way
alternative flow: goal is achieved in an alterante way
exception flow: goal is not achieved

use cases
    map well to design and implementation constrcuts
    make it easy to verify/validate a design and implementation against user goals
    framed in terms of user goals and flows of events, user requests and system responses

actor represent external entities that interact with the system
    human
    hardware
    another software system

a use case is  initiated by an actor(primary actor) to invoke a certain functionality in the system
a use case is a dialogue between actors and the system

actors are discovered by

what actors will create, read, update, or delete (crud) that information

buy a product
    basic flow
        customers 

add item deadline
    basic flow
        user selects list item to which they want to add a deadline
        system presents detailed view of list item
        user selects the deadline field
        system presents user with a way to enter a date and time
        user enters

observations about www's architecture
    there is no single piece of code that implements the architecture
    stylistic constraints of the web's architectural style are not apparent in the code
    ont of the world's most successful applications is only understood adeuqtely from an architectural vantage point

a software architecture consists of components and connectors
    components and connectors are arranged into configuration

prescriptive architecture
    as-designed/as-intended architecture
    how a software should be
    like a doctor's prescription

descriptive architecture
    as-implemented/as-realized architecture
    what reality actually is

when a system evolves
    ideally its prescriptive architecture is modified first


architectural erosion
    short deadlines
    developer sloppiness
    lack of prescriptive architecture
    code optimizations
    inadequate techniques or tool support

architectural styles
    model-view-controller
        ex. atm (anything has gui)
        controller (rules) -> bank account (model) -> atm display (view) -> controller
            benefits
                modularity
                anticipation of change
    client-server
        ex. multi-player online games
        game client 1 -> game server
        game client 2 -> game server
        game client 3 -> game server
        most modern client-server applications run on servers in the cloud
        software develpers no longer have to manage physical servers
        instead they are managed by third party
            benefits
                sharing data and services over a wide range of clients
                centralized control over access, functionality, data
    layered
        ex. working in resturants
            benefits
                modularity
                abstraction
                anticipation of change
                reuse
    peer-to-peer
        ex. skype
            benefits
                efficient (skip the central server)
                inefficient (go through every user)
                robust (diffcult to remove a file from p2p server)
    pipe-and-filter
        ex. compiler
        filter -> pipe -> sort
            benefits
                modularity
                reuse
                anticiption of change
    publish-subscribe
        ex. instagram, youtube
evolution

a named collection of architectural design decisions that
    are applicable in a given development context
    constrain architectureal design decisions
    result in beneficial qualities in each resulting system
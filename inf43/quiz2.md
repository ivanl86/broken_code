# Course Quiz 2
## Software Failure
- complexity
    - software engineers do not know what they were building until they were building it then realize how complicated it is
        - transitioning from old system to new system
- hubble psychology
    - being over-optimism and not addressing all the complexity and problems or figure out how much time it takes to finish the project
    - software engineers are overly optimistic and believe that as long as funding is keep coming in, the project will be completed successfully and any setback will be disregarded
    - the managment is over-optimism and is reluctant to address all the problems and complexity in the project because they knows that the project is too big to fail

- the managment does not have a clear goal on what the product is and what the product can do
- unlike building a building, software has way less constrains and software engineers may not know what they are building until they start building it
### Top Software Failure Causes
- lack of user input/involvement (requirements issues)
- incomplete requirements and specifications (requirements issues)
- changing requirements and specifications (requirements issues)
- lack of discipline in development processes (lack of rigor/formality)
- lack of methodical usage of metrics (lack of rigor/formality)
- lack of resources
## Requirements
- what the software should do (without saying how it should do it)
    - we are saying it should be written in Python and use neral network and there is a database
    - these are how it should do
    - we should talk about what the software is
- requirements address what a customer needs, not what a customer wants
    - if you ask someone in 1990, do you want a car, they will tell you that no, they want a faster horse. They would not know what car is
- we grown to care about requirements because projects stumble or fail as a result of poor requirements than for any other reason
### Requirements Phase
- requirements analysis
    - the activity of figuring out what to build
    - the activity of discovering, observing, gathering customers needs
    - trying to figure out what the customer wants or what we are going to build
    - analysis is the first portion of discovery or learning
- requirements specification
    - after you know what the customer want or what you are going to build, you need to document it
    - you need to write down and you need to communicate it
    - it can be communicated to the developers, to the designers, and back to the customers to verify it is what they want
    - specification is the activity of capturing the analysis so it can be used for different purposes
    - the document that you produce is called the requirement specification
    - the activity of writing it down and the document itself is also called requirements specification

#### Requirement Analysis
- interview customer
    - you have the customer come in and ask him questions about what kind of product he wants
- observe customer
    - go to the site to observe how the customer do their to understand what they need
    - online streaming websites observe what the customers watch and collect these data
        - by knowing how customers use your current software, you can find out what you want to build next
    - usage data is analyzed and business metrics are recorded to discover the value of new (potential) features
        - data analytics
        - a/b testing
        - prototyping
        - market research
        - this information is used to create/prioritize/analyze/evaluate requirements

### Requirement Specification
- serves as an agreement between the developers, the software engineers and the customer
    - before we start doing anything, both parties have agree what we are going to build
- serves as a fundamental reference
    - defines "what" to do but not "how" to do
- it can include environmental requirements
    - the customer require the software to run on smartphone
    - may be on iOS, Android or both
- any kind of constraints
- any kind of qualities
- specification is the definition of our direction for the remainder of the time

### Analysis and Specification
- both only take a small precentage of the overall project budget, however, getting it wrong can cause the later phases to their cost to grow like crazy, becuase you have to rip out all of the code or you set up the architecture of the system wrong, then that causes downstream effect that ends up being a nightmare or it can cause a failure altogether

### How Software Failure Causes Relate to Requirements Issues
- it does not cost a lot to get things right in the first place but if you get the requirements wrong in the first place, it cost a lot of money.
- if you misunderstood about what the product is that you are going to build, all the work and time are wasted or most them are wasted
- lack of user input/involvement is often listed as the most common problem
- most of the time the developers do not know better than the users
- requirements analysis and requirements specification are the smallest portion of cost, but if you get them wrong, it has the potential to become a huge problem later and cost a lot.

### Document Structure
- general docutment structure
#### Sections
- introduction
    - describe what the document about
    - who created this document
    - who was it created for
    - a briefy introduction to the documents itself
- executive summary
    - a short and succinct description of the product
    - a short summary of what the software should do
    - meant for executives to read and they are busy so keep it short
        - one page or less
    - only include main goals, key features, and key risks/obstacles
- application context
    - describe the context in which the software that you are describing
    - how it will be used
    - physical context
        - ex. used in hosptial by nurses
    - surrounding software
        - ex. it run on android phones
    - can be short, does not need many pages to describe
- environmental requirements
    - what platforms it is on
        - operating systems, types of machines, memory size, hard disk space
    - software
        - is it a web app, mobile app, or desktop app?
        - is it open source, linux, apache or php/mysql?
        - is it enterprise software, .net, or enterprise java, j2ee?
    - what progrmaming languages does it use?
    - standards
    - it may touch the "how" part which it should be avoided
    - it may overlap with application context especially the second part
- functional requirements
    - what are the features and how does it work?
    - how does it work from the user's perspective not internally
    - it identifies the concepts, the functions, the features
    - what kind of information are provided to the users?
    - what is the system supposed to do?
    - what is the input to the system?
    - it should describe what happens when things work correctly
    - it should also describe what happens if something goes wrong
        - ex. if for some reason, a transaction failed what is the fallback plan?
        - the bill should remain unpaid
        - should allow to accept other kind of payments
    - what is the expected output from a particular input
- non-functional requirements
    - we want it to
        - be correct
        - be beautiful
        - be elegant
        - develop it in a way that is highly maintainable
        - be intuitive for users
        - be usable
        - be scalable
    - it describes the qualities of the software
- software qualities
- other requirements
    - anything that do not fit in any other section
    - do they need
        - documentation
        - manuals
        - tutorials
    - cost
- time schedule
    - customer may need it in a certain way
- potential risks
    - try to learn from the customers because they probably know better than us
    - learn what could go wrong
        - we should document it
    - hopefully we can take some steps to avoid the potential risks
        - the potential risk could be we run out of money before we actually start making money, and thus the whole project goes under
        - maybe there is legal challenges
            - we may have done a patent review and did not find anything but there is some patent that we did not find and someone may come in and sue us into non-existence
        - risks could be there is not enough engagement with the users
    - learn what may go wrong and try to mitigate these risks
- assumptions
    - document any kind of assumptions that we have about how things are going to work or what we think is going to happen
    - the funding that we think is avaliable
    - we assume that there will not be any legal implications of what we are building
    - if in the future, some state does not allow to have electric scooters on the sidewalk, then your electric scooter project is done
    - risks and assumptions are close related 
- future changes
    - we can document future changes
    - customer may only pay for the product up to this point for this set of features
        - even though the customer is not commiting to anything beyond this point, it still might be worthwhile capturing the fucture changes we anticipate beyond this document
    - document potential future changes can allow flexibility
    - capture things that we anticipate doing in the future, then it allows the developers actually to make it so that it can be extensible in that way
- glossary
    - if the product you are making use all kinds of acronyms or technical terms that everyone might not know, it is nice to have a glossary
- reference documents
    - pointers to existing processes and tools used within an organization
    - pointers to other, existing software that provides similar functionality
    - pointers to literature
- user interface
    - some requirement documents have sketches of the UI is imagined to look like
    - sometimes the user might already know how it should look like

###
    - document is structure to address the fundamental principles

### Specification Methods
- natural language
- diagrams
- formal language
- models

### Verification
- is the requirement specification complete
    - make sure to inlcude all requirements
- is each of the requirements understandable
    - make sure the customer can understand it
- is each of the requirements unambiguous
    - it should not be multiple ways to interpret the result
- are any of the requirements in conflict
    - avoid something like A says B cannot be part of the requirement while B says A cannot be part of the requirement
- can each of the requirements be verified
    - the requirement document is the list of all the things that testers need to test 
- are all terms and concepts defined
    - make sure all terms are defined so people can understand it
- is the requirement specification unbiased

### Acceptance Test Plan
- it often goes along with the specification document
- if we actually can correctly made everything in the specification, then our acceptance test plan will pass

### Ziv's Law
- the concept with software is that we often do not know what we are building until we are building something
- once we have built something, we almost inevitably realize that is not exactly what we wanted
- and we changed it, then from the changing, we learned someting else that we liked and we did not like
- and we change it again and again
- the changeability of software is both good and bad
- basically it is saying we are probably not going to truly realize knowing exactly what it is that we want
- uncertainty is inherent and inevitable in software engineering processes and products

### Which category employs the most computer programmers in the U.S.?
- in-house staff writing systems for internal use
    - the most common situation is that some other department in your own company that is asking the IT department to make some software for them
    - the customer can played by anyone including from internal like any department from your company and it can also be external like another company

### Summary of the Online Readings
- some commonnalities
    - they are poorly managed
    - they do not know how far behind they are on the project
    - they do not know how to measure their progress
    - they went overbudge
    - unexpected cost increase
- Wishful Thinking
    - talks about hubble psychology
- Five Enduring Government
    - all five project share some commonalities
        - they all went overbudge
        - they all delayed for many years
        - they all got canceled eventually
- TSB IT Migration
    - the migration causes many problems
        - custmers' account balance disappear or getting extra money they should not get
- Minnesota's L and R System
    - faces performance issues
    - bugs
    - lack of transprency and unexpected cost increase
- Shopa Failure
    - lack of claer goal
    - conflict between the IT team and the sales team
- Doctors
    - lack of user involvement
    - engineers need to spend more time in hospital environment to gain a deeper understanding of how healthcare professionals, particularly doctors, work.
    - the disconnection between techonologists and healthcare providers often results in tech products and applications that do not effectively address the needs and challenges of medical practitioners
    - developers need to observe their workflow and understand their requirements

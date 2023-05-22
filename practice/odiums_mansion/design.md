# Design Notes
## Nouns, Verbs, and Adjectives
- Mansion
    - 64 chambers
- Artifacts
- Aldracs
    - Stench
- Chest of gold
    - Glimmering light
- Pits
    - Soft breeze
- Sensations
- User actions

## Details
### Goal
- Find the chest of gold in the Mansion
- Then return to the starting location
### Mansion
- has a total of 64 chambers
- 8 x 8 grid
### Artifacts
- None of the artifacts share a cell with another
- None of the artifacts can move including Aldracs
### Aldracs
- There is only one Aldracs in the Mansion
- It gives out Stench sensation at its directly adjcent cells
### Chest of Gold
- There is only one chest of gold in the Mansion
- It gives out Glimmering light sensation at its directly adjcent cells
### Pits
- There are 12 pits in the Mansion
- It gives out soft Breeze sensation at its directly adjcent cells
### Sensations
- All sensations only appear in directly adjcent cell of a artifact
- Multiple sensations may present in the same cell
- G represents gold
- S represents stench
- B represents breeze
- U represents user
### User Actions
- Right, Left, Up, Down present by R, L, U, D
- User inputs should be case insensitive
- User cannot move outside of the mansion
- Any invalid move is ignored and a turn is not skipped
- User can only pick the chest of gold when they are in the same cell
- It gives out message when the user picks up the chest of gold
- There should be icon near the printed grid indicate if user picks up the chest of gold

## Game Flow
- Prompts the user if he/she wants to play the game in the beginning and each time the game ends
- Prints the grid at the beginning of each turn
- Clear the screen before printing the grid
- User wins if he/she carries the gold back to starting location
- User loses if he/she enters a room with Aldracs or pit

## Notes

// who: <your name and Mt SAC username goes here>
// what: <the function of this program>
// why: <the name of the lab>
// when: <the due date of this lab.>

#include <iostream>

#include "odiums_mansion.h"

int main(int argc, char const *argv[])
{
    welcomeMessage();
    if (wantToPlay("Do you want to play Aldrac Dungeon Simulator? (y/n) "))
    {
        do
        {
            play();
        } while (wantToPlay("Do you want to play Aldrac Dungeon Simulator again? (y/n) ")); 
    }
    return 0;
}

int Dungeon::userStartingPosition()
{
    return this->grid.at(MIN_ROW).at(MIN_COL);
}

void Dungeon::setUserStartingPosition()
{
    this->grid.at(MIN_ROW).at(MIN_COL) += USER_POSITION;
    this->currRow = MIN_ROW;
    this->currCol = MIN_COL;
}

int Dungeon::getUserCurrPosition()
{
    int * const userPositionPtr{&this->grid.at(currRow).at(currCol)};
    return *userPositionPtr;
    return this->grid.at(currRow).at(currCol);
}

void Dungeon::clearPreviousUserPosition()
{
    this->grid.at(this->previousRow).at(this->previousCol) -= USER_POSITION;
    this->previousRow = this->currRow;
    this->previousCol = this->currCol;
}

void Dungeon::setGoldPostion()
{
    int row{random(SAFE_ZONE, MAX_ROW)};
    int col{random(SAFE_ZONE, MAX_COL)};
    while (this->grid.at(row).at(col) != EMPTY)
    {
        row = random(SAFE_ZONE, MAX_ROW);
        col = random(SAFE_ZONE, MAX_ROW);
    }
    this->grid.at(row).at(col) = GOLD_CHEST_POSITION;
}

void Dungeon::setAldracPosition()
{
    int row{random(SAFE_ZONE, MAX_ROW)};
    int col{random(SAFE_ZONE, MAX_COL)};
    while (this->grid.at(row).at(col) != EMPTY)
    {
        row = random(SAFE_ZONE, MAX_ROW);
        col = random(SAFE_ZONE, MAX_ROW);
    }
    this->grid.at(row).at(col) = ALDRACS_CHAMBER;
}

void Dungeon::setPitPosition()
{
    int row{random(SAFE_ZONE, MAX_ROW)};
    int col{random(SAFE_ZONE, MAX_COL)};
    while (this->grid.at(row).at(col) != EMPTY)
    {
        row = random(SAFE_ZONE, MAX_ROW);
        col = random(SAFE_ZONE, MAX_ROW);
    }
    this->grid.at(row).at(col) = PIT_POSITION;
}

void Dungeon::initializeObjectsPosition(Dungeon dungeon)
{
    dungeon.setUserStartingPosition();
    dungeon.setGoldPostion();
    dungeon.setAldracPosition();
    for (size_t i = 0; i < MAX_PIT; ++i)
        dungeon.setPitPosition();
}

bool Dungeon::moveRight()
{
    if (this->currCol < MAX_COL)
    {
        this->grid.at(currRow).at(++currCol) += USER_POSITION;
        clearPreviousUserPosition();
        return true;
    }
    std::cout << "You cannot move right any further!";
    return false;
}

bool Dungeon::moveLeft()
{
    if (this->currCol > MIN_COL)
    {
        this->grid.at(currRow).at(--currCol) += USER_POSITION;
        clearPreviousUserPosition();
        return true;
    }
    std::cout << "You cannot move left any further!";
    return false;
}

bool Dungeon::moveUp()
{
    if (this->currRow > MIN_ROW)
    {
        this->grid.at(--currRow).at(currCol) += USER_POSITION;
        clearPreviousUserPosition();
        return true;
    }
    std::cout << "You cannot move up any further!";
    return false;
}

bool Dungeon::moveDown()
{
    if (this->currRow < MAX_ROW)
    {
        this->grid.at(++currRow).at(currCol) += USER_POSITION;
        clearPreviousUserPosition();
        return true;
    }
    std::cout << "You cannot move down any further!";
    return false;
}

bool Dungeon::pickUpGold()
{
    if (getUserCurrPosition() == USER_POSITION + GOLD_CHEST_POSITION)
        return this->foundGold = true;
    else return false;
}

bool Dungeon::ifFoundGold()
{
    return this->foundGold;
}

void Dungeon::printGrid()
{

}

int random(int start, int end)
{
    return rand() % (end - start + 1) - start;
}

void welcomeMessage()
{
    std::cout << "Welcome to Aldrac Dungeon Simulator\n\n";
}

void header()
{
    std::cout << "Aldrac Dungeon Simulator\n"
              << "Avoid at all costs the pits and the evil Aldrac, cursed be his name\n";
}

bool wantToPlay(std::string prompt)
{
    char c;
    std::cout << prompt;
    do
    {
        std::cin >> c;
        c = tolower(c);
        if (c == 'y' or c == 'n')
            return (c == 'y' ? true : false);
        else std::cout << "Invalid Input!\nPlease try again!\n";
    } while (true);
}

char getChar(std::string prompt)
{
    char c;
    std::cout << prompt;
    do
    {
        std::cin >> c;
        c = tolower(c);
        if (c == 'r' or c == 'l' or c == 'u' or c == 'd' or c == 'p')
            return c;
        else std::cout << "Invalid Input!\nPlease try again!\n";
    } while (true);
}

void play()
{
    Dungeon dungeon;
    dungeon.initializeObjectsPosition(dungeon);
    header();
    dungeon.printGrid();
    do
    {
        if (enterMove(dungeon))
        {
            header();
            dungeon.printGrid();
        }
    } while (!endGame(dungeon));
}

bool enterMove(Dungeon dungeon)
{
    switch (getChar("Enter Your Move\n(R)ight, (L)eft, (D)own, (P)ickup gold:"))
    {
    case 'r':
        return dungeon.moveRight();
    case 'l':
        return dungeon.moveLeft();
    case 'u':
        return dungeon.moveUp();
    case 'd':
        return dungeon.moveDown();
    default:
        return false;
    }
}

bool endGame(Dungeon dungeon)
{
    if (dungeon.getUserCurrPosition() == dungeon.userStartingPosition()
        && dungeon.ifFoundGold())
        return escaped();

    else if (dungeon.getUserCurrPosition() == USER_POSITION + ALDRACS_CHAMBER)
        return killedByAldrac();

    else if (dungeon.getUserCurrPosition() == USER_POSITION + PIT_POSITION)
        return fallIntoAPit();

    else return false;
}

bool escaped()
{
    std::cout << "You successfully found the gold chest and safely escaped Odium's Mansion!"
              << "You can enjoye your life before you spent all those shiny golds!\n"
              << "Well Done!\n";
    return true;
}

bool killedByAldrac()
{
    std::cout << "You enter the evil Aldracian's chamber, cursed be his name!\n"
              << "You will never leave!\n"
              << "GAME OVER\n";
    return true;
}

bool fallIntoAPit()
{
    std::cout << "You stepped into one of the bottomless pits!\n"
              << "You continue to fall until eternity!\n"
              << "GAME OVER\n";
    return true;
}

void clearScreen()
{
    if(WINDOWS)
        system("CLS");
    else
        system("clear");
}

void clearInstream()
{
    std::cin.clear();
    // Wrong input remains on the stream, so you need to get rid of it
    std::cin.ignore(INT_MAX, '\n');
}

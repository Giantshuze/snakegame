#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "snake.h"


SnakeBody::SnakeBody()
{
}


SnakeBody::SnakeBody(int x, int y): mX(x), mY(y)
{
}

int SnakeBody::getX() const
{
    return mX;
}

int SnakeBody::getY() const
{
    return mY;
}

void SnakeBody::setX(int x){
    mX = x;
}

void SnakeBody::setY(int y){
    mY = y;
}

bool SnakeBody::operator == (const SnakeBody& snakeBody)
{
		// TODO overload the == operator for SnakeBody comparision.
    if (mX == snakeBody.getX() && mY == snakeBody.getY())
        return true;
    return false;
}

Snake::Snake(int gameBoardWidth, int gameBoardHeight, int initialSnakeLength): mGameBoardWidth(gameBoardWidth), mGameBoardHeight(gameBoardHeight), mInitialSnakeLength(initialSnakeLength)
{
    this->initializeSnake();
    this->setRandomSeed();
}

void Snake::setRandomSeed()
{
    // use current time as seed for random generator
    std::srand(std::time(nullptr));
}

void Snake::initializeSnake()
{
    // Instead of using a random initialization algorithm
    // We always put the snake at the center of the game mWindows
    int centerX = this->mGameBoardWidth / 2;
    int centerY = this->mGameBoardHeight / 2;

    for (int i = 0; i < this->mInitialSnakeLength; i ++)
    {
        this->mSnake.push_back(SnakeBody(centerX, centerY + i));
    }
    this->mDirection = Direction::Up;
}

bool Snake::isPartOfSnake(int x, int y)
{
		// TODO check if a given point with axis x, y is on the body of the snake.
    for (int i = 0; i < getLength(); i++){
        if (x == mSnake[i].getX() && y == mSnake[i].getY())
            return true;
    }
    return false;
}

/*
 * Assumption:
 * Only the head would hit wall.
 */
bool Snake::hitWall()
{
		// TODO check if the snake has hit the wall






    return false;
}

/*
 * The snake head is overlapping with its body
 */
bool Snake::hitSelf()
{
		// TODO check if the snake has hit itself.
        
    





		return false;
}


bool Snake::touchFood()
{
    SnakeBody newHead = this->createNewHead();
    if (this->mFood == newHead)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Snake::senseFood(SnakeBody food)
{
    this->mFood = food;
}

std::vector<SnakeBody>& Snake::getSnake()
{
    return this->mSnake;
}

bool Snake::changeDirection(Direction newDirection)
{
    switch (this->mDirection)
    {
        case Direction::Up:
        {
						// what you need to do when the current direction of the snake is Up
						// and the user inputs a new direction?  TODO
            if (newDirection != Direction::Down){
                mDirection = newDirection;
                break;
            }
            else{
                break;
            }

        }
        case Direction::Down:
        {
						// what you need to do when the current direction of the snake is Down
						// and the user inputs a new direction? TODO
            if (newDirection != Direction::Up){
                mDirection = newDirection;
                break;
            }
            else{
                break;
            }

        }
        case Direction::Left:
        {
						// what you need to do when the current direction of the snake is Left
						// and the user inputs a new direction? TODO
            if (newDirection != Direction::Right){
                mDirection = newDirection;
                break;
            }
            else{
                break;
            }

        }
        case Direction::Right:
        {
						// what you need to do when the current direction of the snake is Right
						// and the user inputs a new direction? TODO
        if (newDirection != Direction::Left){
                mDirection = newDirection;
                break;
            }
            else{
                break;
            }
        
        default:
        //Unexpected ERROR
            return false;
        }
    }

    return true;
}

SnakeBody Snake::getHead(){
    return mSnake[0];
}

SnakeBody Snake::createNewHead()
{
		/* TODO
		 * read the position of the current head
		 * read the current heading direction 
		 * add the new head according to the direction
		 * return the new snake
		 */
    int nowHeadx, nowHeady;
    nowHeadx = getHead().getX();
    nowHeady = getHead().getY();
    SnakeBody forwardHead(nowHeadx, nowHeady);
    switch (mDirection)
    {
    case Direction::Up:
        forwardHead.setY(nowHeady - 1);
        break;
    
    case Direction::Down:
        forwardHead.setY(nowHeady + 1);
        break;

    case Direction::Left:
        forwardHead.setX(nowHeadx - 1);
        break;

    case Direction::Right:
        forwardHead.setX(nowHeadx + 1);
        break;

    default:
        SnakeBody forwardHead(nowHeadx, nowHeady);
        break;
    }
    mSnake.emplace(mSnake.begin(), forwardHead);

    SnakeBody newHead = this->mSnake[0];
    return newHead;
}

/*
 * If eat food, return true, otherwise return false
 */
bool Snake::moveFoward()
{
    /* 
		 * TODO 
		 * move the snake forward. 
     * If eat food, return true, otherwise return false
     */




    //Create a new head and return whether a food is got
    if (this->touchFood()){
        return true;
    }
    else{
        //Pop the last SnakeBody(tail)
        this->mSnake.pop_back();
        return false;
    }
}

bool Snake::checkCollision()
{
    if (this->hitWall() || this->hitSelf())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int Snake::getLength()
{
    return this->mSnake.size();
}


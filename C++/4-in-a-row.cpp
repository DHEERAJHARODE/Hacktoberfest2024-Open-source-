#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

class GameElement {
protected:
    int x;
    int y;
    int width;
    int height;

public:
    GameElement(int xPos, int yPos, int w, int h) : x(xPos), y(yPos), width(w), height(h) {}

    virtual void updatePosition(int dx, int dy) {
        x += dx;
        y += dy;
    }

    virtual void display() {
        // Implementation for displaying the game element
    }
};

class Paddle : public GameElement {
private:
    int speed;

public:
    Paddle(int xPos, int yPos, int w, int h, int s) : GameElement(xPos, yPos, w, h), speed(s) {}

    void moveLeft() {
        updatePosition(-speed, 0);
    }

    void moveRight() {
        updatePosition(speed, 0);
    }

    bool checkCollision(GameElement* ball) {
        return (x < ball->getX() + ball->getWidth() && x + width > ball->getX() &&
                y < ball->getY() + ball->getHeight() && y + height > ball->getY());
    }
};

class Ball : public GameElement {
private:
    int radius;
    int velocityX;
    int velocityY;

public:
    Ball(int xPos, int yPos, int r, int vX, int vY) : GameElement(xPos, yPos, r * 2, r * 2), radius(r), velocityX(vX), velocityY(vY) {}

    void move() {
        updatePosition(velocityX, velocityY);
    }

    void reflectHorizontal() {
        velocityX *= -1;
    }

    void reflectVertical() {
        velocityY *= -1;
    }

    bool checkCollision(Paddle* paddle, vector<GameElement*>& bricks) {
        if (paddle->checkCollision(this)) {
            reflectVertical();
        }

        for (int i = 0; i < bricks.size(); i++) {
            if (bricks[i]->checkCollision(this)) {
                reflectVertical();
                bricks.erase(bricks.begin() + i);
                return true;
            }
        }

        return false;
    }
};

class Brick : public GameElement {
private:
    int durability;

public:
    Brick(int xPos, int yPos, int w, int h, int d) : GameElement(xPos, yPos, w, h), durability(d) {}

    bool checkCollision(Ball* ball) {
        if (x < ball->getX() + ball->getWidth() && x + width > ball->getX() &&
            y < ball->getY() + ball->getHeight() && y + height > ball->getY()) {
            durability--;
            if (durability <= 0) {
                return true;
            }
        }
        return false;
    }
};

class Game {
private:
    int screenWidth;
    int screenHeight;
    vector<GameElement*> bricks;
    Paddle* paddle;
    Ball* ball;
    int score;
    int lives;
    bool gameOver;

public:
    Game(int width, int height) : screenWidth(width), screenHeight(height), paddle(nullptr), ball(nullptr), score(0), lives(3), gameOver(false) {
        srand(time(0));
    }

    void initializeGame() {
        int brickWidth = 60;
        int brickHeight = 20;
        int numBricks = 10;
        int brickX = 30;
        int brickY = 50;
        for (int i = 0; i < numBricks; i++) {
            int color = rand() % 256;
            Brick* brick = new Brick(brickX, brickY, brickWidth, brickHeight, 1);
            bricks.push_back(brick);
            brickX += brickWidth + 5;
        }
        paddle = new Paddle(screenWidth / 2 - 50, screenHeight - 50, 100, 10, 5);
        ball = new Ball(screenWidth / 2, screenHeight / 2, 8, 2, -2);
    }

    void handleInput() {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'a':
                    paddle->moveLeft();
                    break;
                case 'd':
                    paddle->moveRight();
                    break;
                case 'q':
                    gameOver = true;
                    break;
            }
        }
    }

    void updateGame() {
        ball->move();
        if (ball->getX() <= 0 || ball->getX() + ball->getWidth() >= screenWidth) {
            ball->reflectHorizontal();
        }
        if (ball->getY() <= 0) {
            ball->reflectVertical();
        }
        if (ball->getY() + ball->getHeight() >= screenHeight) {
            lives--;
            if (lives <= 0) {
                gameOver = true;
            }
            else {
                ball->updatePosition(screenWidth / 2, screenHeight / 2);
            }
        }
        if (ball->checkCollision(paddle, bricks)) {
            score++;
        }
    }

    void displayGame() {
        system("cls");
        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                if (i == 0 || i == screenHeight - 1 || j == 0 || j == screenWidth - 1) {
                    cout << "#";  // display borders
                }
                else if (i >= paddle->getY() && i < paddle->getY() + paddle->getHeight() &&
                         j >= paddle->getX() && j < paddle->getX() + paddle->getWidth()) {
                    cout << "=";  // display paddle
                }
                else if (i >= ball->getY() && i < ball->getY() + ball->getHeight() &&
                         j >= ball->getX() && j < ball->getX() + ball->getWidth()) {
                    cout << "O";  // display ball
                }
                else {
                    bool brickPresent = false;
                    for (int k = 0; k < bricks.size(); k++) {
                        if (i >= bricks[k]->getY() && i < bricks[k]->getY() + bricks[k]->getHeight() &&
                            j >= bricks[k]->getX() && j < bricks[k]->getX() + bricks[k]->getWidth()) {
                            brickPresent = true;
                            break;
                        }
                    }
                    if (brickPresent) {
                        cout << "*";  // display brick
                    }
                    else {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
        cout << "Score: " << score << "  Lives: " << lives << endl;
    }

    bool checkGameOver() {
        return gameOver;
    }

    ~Game() {
        delete paddle;
        delete ball;
        for (int i = 0; i < bricks.size(); i++) {
            delete bricks[i];
        }
    }
};

int main() {
    int screenWidth = 80;
    int screenHeight = 30;
    Game game(screenWidth, screenHeight);
    game.initializeGame();

    while (!game.checkGameOver()) {
        game.handleInput();
        game.updateGame();
        game.displayGame();
        Sleep(50);  // Delay for smoother rendering
    }

    return 0;
}


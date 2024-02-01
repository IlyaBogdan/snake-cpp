#include <iostream>
#include <stdlib.h>

#include <chrono>
#include <thread>

#include "crossplatforming.hpp"
#include "GraphicEngine.hpp"

#include "Map.hpp"
// #include "Controller.hpp"
// #include "Snake.hpp"
// #include "Food.hpp"

int width, height, size;

Map map;
// Snake snake;
// Controller controller;
// Food food;

void setup() {
    width = 30;
    height = 15;
    size = width * height;

    map = Map::init(width, height);
    // snake = Snake::init(width * height);
    // controller = Controller::run();
    // food = Food::init(width + 1, size - width);

    // snake.setStepUp(width);
}

// int foodPosition;

// void renderFood() {
//     if (!food.getOnTheMap()) {

//         foodPosition = food.check();

//         while(!map.takePosition(foodPosition, 2)) {
//             foodPosition = food.check();
//         }

//         food.setOnTheMap();
//     } else {
//         map.takePosition(foodPosition, 2);
//     }
// }

// bool renderSnake() {
//     try {
//         int headPositoion = map.takePosition(snake.getBody(), 1, true);
//         if (headPositoion != 0) {
//             snake.addBodyLenght();
//             food.setEated();
//         }
//     } catch (int e) {
//         return false;
//     }

//     return true;
// }

// int direction;

// void directSnake() {
//     direction = controller.getDirection();
//     snake.setDirection(direction).move();
// }

// void statusBar() {
//     std::cout << "Scores: " << snake.getScores() << std::endl;
//     std::cout << std::endl;
// }

// void result() {
//     system("clear");
//     std::cout << std::endl;
//     std::cout << "Game over!" << std::endl;
//     std::cout << "Scores: " << snake.getScores() << std::endl;
//     std::cout << std::endl;
// }

// void mainLoop() {

//     while (true) {
//         system("clear");

//         statusBar();
//         map.clear();

//         directSnake();
//         renderFood();
//         if (!renderSnake()) break;      
//         map.render();

//         std::this_thread::sleep_for(std::chrono::milliseconds(200));
//     }    
// }

int main() {

    // setup();
    // mainLoop();
    // result();

    GraphicEngine engine = GraphicEngine::start();

    engine.addRendererObject(&map);

    return 0;
}
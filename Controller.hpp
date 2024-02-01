
#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

class Controller {
    public:
        Controller() {}

        static Controller run() {
            Controller controller = Controller();

            return controller;
        }

        int getDirection() {

            if (this->kbhit()) {
                switch (this->getChar()) {

                    case 68: // right
                    case 100:
                        return 1;

                    case 67:  // left
                    case 97:
                        return 2;

                    case 66: // up
                    case 115:  
                        return 3;

                    case 65:  // down
                    case 119:
                        return 4;

                    
                    default:
                        return 1;

                }
            }

            return 0;
        }

    private:
        int getChar() {
            struct termios oldt, newt;
            int ch;
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            ch = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

            return ch;
        }

        bool kbhit() {
            termios term;
            tcgetattr(0, &term);

            termios term2 = term;
            term2.c_lflag &= ~ICANON;
            tcsetattr(0, TCSANOW, &term2);

            int byteswaiting;
            ioctl(0, FIONREAD, &byteswaiting);

            tcsetattr(0, TCSANOW, &term);

            return byteswaiting > 0;
        }
};
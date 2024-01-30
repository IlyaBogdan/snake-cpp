#include <cstdlib>
#include <time.h>

class Food {

    public:
        Food() {}
        Food(int min, int max) {
            this->min = min;
            this->max = max;
        }


        static Food init(int min, int max) {
            Food food = Food(min, max);

            return food;
        }

        int check() {
            if (this->onTheMap) return 1;
            else {
                return this->generatePosition();
            }
        }

        Food setEated() {
            this->onTheMap = false;

            return *this;
        }

        Food setOnTheMap() {
            this->onTheMap = true;

            return *this;
        }

        bool getOnTheMap() {
            return this->onTheMap;
        }

    private:
        bool onTheMap = false;
        int min, max;

        int generatePosition() {
            
            srand((unsigned) time(NULL));
            return this->min + (rand() % this->max - this->min);
        }
};
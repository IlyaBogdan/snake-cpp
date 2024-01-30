class Snake {
    public:
        Snake() {}
        Snake(int maxSize) {
            this->body = createBody(maxSize);
        }

        static Snake init(int maxSize) {
            Snake snake = Snake(maxSize);

            return snake;
        }

        Snake move() {

            for (int i = this->endOfBody() - 1; i > 0; i--) {
                this->body[i] = this->body[i - 1];
            }

            this->body[0] = this->moveHead();

            return *this;
        }

        Snake setDirection(int direction) {

            if (
                (   
                    this->endOfBody() == 1 ||

                    !(
                        (direction == 2 && this->direction == 1) ||
                        (direction == 1 && this->direction == 2) ||
                        (direction == 3 && this->direction == 4) ||
                        (direction == 4 && this->direction == 3)
                    )
                ) && direction != 0
            ) {
                this->direction = direction;
            }

            return *this;
        }

        int* getBody() {
            return this->body;
        }

        void setStepUp(int stepUp) {
            this->stepUp = stepUp;
        }

        int getScores() {
            return this->endOfBody();
        }

        void addBodyLenght() {
            for (int i = this->endOfBody(); i > 0; i--) {
                this->body[i] = this->body[i - 1];
            }

            this->body[0] = this->moveHead();
        }

    private:
        int* body;
        int direction = 1;
        int stepUp = 1;

        int* createBody(int maxSize) {
            int *body = new int[maxSize];

            for (int i = 0; i < maxSize; i++) {
                body[i] = 0;
            }
            body[0] = maxSize / 2;

            return body;
        }

        int endOfBody() {
            int i = 0;
            while(this->body[i] != 0) i++;

            return i;
        }

        int moveHead() {
            int current = this->body[0];

            switch (this->direction) {
                case 1:
                    return current + 1;
                case 2:
                    return current - 1;
                case 3:
                    return current + this->stepUp;
                case 4:
                    return current - this->stepUp;
            }
        }
};
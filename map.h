class Map {
    public:
        Map() {}
        Map(int width, int height) {
            this->width = width;
            this->height = height;

            this->mapPtr = this->createMap();
        }

        static Map init(int width, int height) {
            Map map = Map(width, height);

            return map;
        }

        void clear() {
            const int mapSize = this->width * this->height;

            for (int i = 0; i < mapSize; i++) {
                if (this->mapPtr[i] != -1) this->mapPtr[i] = 0;
            }
        }

        void render() {

            const int mapSize = this->width * this->height;

            for (int i = 0; i < this->width * this->height; i++) {

                switch (mapPtr[i]) {
                    case -1:
                        std::cout << '#'; break;
                    case 0:
                        std::cout << '.'; break;
                    case 1:
                        std::cout << 'O'; break;
                    case 3:
                        std::cout << '@'; break;
                    case 2:
                        std::cout << '$'; break;
                    
                    default:
                        break;
                }

                if (i % this->width == this->width - 1) std::cout << std::endl;
            }

            std::cout << std::endl;
        }

        bool takePosition(int positionIndex, int renderElementCode, bool importantMode=false) {
            if (this->mapPtr[positionIndex] == 0) {
                this->mapPtr[positionIndex] = renderElementCode;

                return true;
            }

            if (importantMode) {

            }

            return false;
        }

        int takePosition(int* positionsStackPointer, int renderElementCode, bool importantMode=false) {
            int i = 0;
            int foodPosition = 0;

            while (positionsStackPointer[i] != 0) {
                int mapIndex = positionsStackPointer[i];
                if (this->mapPtr[mapIndex] == 0) {
                    this->mapPtr[mapIndex] = renderElementCode;
                } 
                else if (this->mapPtr[mapIndex] == -1 || (renderElementCode == 1 && this->mapPtr[mapIndex] == 1)) {
                    throw -1;
                }

                if (importantMode) {
                    if (this->mapPtr[mapIndex] == 2) {
                        this->mapPtr[mapIndex] = renderElementCode;
                        foodPosition = mapIndex;
                    } 
                }

                i++;
            }
            
            return foodPosition;
        }

        int getWidth() {
            return this->width;
        }

        int getHeight() {
            return this->height;
        }
    
    private:
        int width, height;

        int* mapPtr;

        int* createMap() {
            const int mapSize = this->width * this->height;
            int *map = new int[mapSize];

            for (int i = 0; i < mapSize; i++) {
                if (i < this->width) map[i] = -1;
                else if (i % this->width == 0 || i % this->width == this->width - 1) map[i] = -1;
                else if (i >= mapSize - this->width && i <= mapSize) map[i] = -1;
                else map[i] = 0;
            }

            return map;
        }
};
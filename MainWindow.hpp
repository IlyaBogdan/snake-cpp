class MainWindow {
    public:
        MainWindow() {}
        MainWindow(int width, int height) {
            this->width = width;
            this->height = height;

            this->setup();
        }

        MainWindow addObject(Drawable* rendererObject) {
            this->objectStack[0] = rendererObject;
            return *this;
        }

        void render() {
            
            this->renderWindowLoop();
        }

    private:

        int width, height;
        Drawable* objectStack[10];

        void createStack() {
            //this->objectStack = ;
        }

        void setup() {
            // Image icon;
            // if (!icon.loadFromFile("sprites/icon.png")) {
            //     throw 1;
            // }

            //this->window.setIcon(32, 32, icon.getPixelsPtr());
        }

        void renderWindowLoop() {
            RenderWindow window(VideoMode(this->width, this->height), "Crazy Snake!");

            while (window.isOpen()) {

                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed)
                        window.close();
                }

                window.clear();

                for (int i = 0; i < 10; i++) {
                    if (this->objectStack[i]) {
                        window.draw(*(this->objectStack[i]));
                    }
                }
                
                window.display();
            }
        }
        
};
#include <SFML/Graphics.hpp>

using namespace sf;

#include "Renderer.hpp"
#include "MainWindow.hpp"

class GraphicEngine {
    public:
        GraphicEngine() {
            this->setup();
        }

        static GraphicEngine start() {
            GraphicEngine engine = GraphicEngine();
            engine.main();
            return engine;
        }  

        GraphicEngine addRendererObject(Renderer* renderObjectPtr) {
            Drawable* drawableObject = renderObjectPtr->render();
            this->canvas.addObject(drawableObject);
            this->canvas.render();
            
            return *this;
        }

        void main() {
            // for(int i = 0; i < 10; i++) {
            //     this->renderObjects[i]->render();
            // }
            this->canvas.render();
        }

    private:
        int* renderObjects;
        MainWindow canvas;

        void createCanvas() {
            this->canvas = MainWindow(1280, 720);
        }

        void setup() {
            this->createCanvas();

        }
};
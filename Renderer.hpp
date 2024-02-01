class Renderer {
    public:
        Renderer() {};
        virtual ~Renderer() = 0;

        virtual Drawable* render() {};
};

Renderer::~Renderer() {};
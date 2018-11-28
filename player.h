#define SPEED 10

class Player
{
        inline int bufferLocation(int x, int y);
    public:
        double x, y; // FOR DEBBUGUN, MOVE TO PRIVATE PLS
        Player(double startingX, double startingY);
        void update(double deltaTime);
        void draw(wchar_t * screenBuffer);
};
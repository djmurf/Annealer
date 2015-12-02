
class Drum {

    private:
        boolean running = false;
        unsigned int speed;
        unsigned long mark;

        void runLoop();

    public:
        void setSpeed(unsigned int speed);
        void start();
        void stop();
        void loop();

        // Constructor
        Drum();
};

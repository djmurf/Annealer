
class Feeder {

    private:
        boolean feeding     = false;
        boolean returning   = false;
        boolean pausing     = false;

        unsigned int position;
        unsigned long mark;

        static const int stepsToPark = 0;
        static const int stepsToMax = 205;

        // Tikme we puase after a feed before returning
        static const unsigned int pauseTime = 1000;
        static const unsigned int step = 1;
        static const unsigned int feedSpeed = 8;
        static const unsigned int returnSpeed = 4;

        void feedLoop();

    public:
        void init();
        void feed();
        void loop();

};

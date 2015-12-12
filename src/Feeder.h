
class Feeder {

    private:
        boolean feeding     = false;
        boolean returning   = false;
        boolean pausing     = false;

        unsigned long mark;
        unsigned int position;
        unsigned int feedCount;


        static const int stepsToPark = 0;
        static const int stepsToMax = 205;

        // Tikme we puase after a feed before returning
        static const unsigned int pauseTime = 1000;
        static const unsigned int step = 1;
        static const unsigned int feedSpeed = 1024;
        static const unsigned int returnSpeed = 2048;

        void feedLoop();

    public:
        void feed();
        void loop();
        void init();
        int getFeedCount();
        Feeder();

};

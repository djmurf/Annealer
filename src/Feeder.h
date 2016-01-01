
/**
    Wiring config:
    Red, blue, green, black from the front with usb to left.
    Plugs into ramps 1.4 @ Y Position
*/


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

        // Time we puase after a feed before returning
        static const unsigned int pauseTime = 200;
        static const unsigned int step = 1;
        static const unsigned int feedSpeed = 400;
        static const unsigned int returnSpeed = 4196;

        void feedLoop();

    public:
        void feed();
        void loop();
        void init();
        int getFeedCount();
        Feeder();

};

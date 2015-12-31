
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
        unsigned int feedCount;

        // Tikme we puase after a feed before returning
        static const unsigned int pauseTime = 1000;
        static const unsigned int feedSpeed = 512;
        static const unsigned int returnSpeed = 2048;

        void feedLoop();

    public:
        void feed();
        void loop();
        void init();
        int getFeedCount();
        Feeder();

};

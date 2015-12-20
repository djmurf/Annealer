
class Drum {

    private:
        boolean running = false;
        int speed;
        unsigned long mark;

        const float RPM_RATIO = 27;

        void runLoop();

        int timer;
        int stepCounter;
        float actualRotationTime;

    public:
        void start();
        void stop();
        void loop();
        int setRpms();
        float getExposureTime();
        int getRpms();

        // Constructor
        Drum();
};

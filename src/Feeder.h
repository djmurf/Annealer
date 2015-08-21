
class Feeder {

    private:
        Servo servo ;
        boolean feeding = false;
        boolean returning = false;

        unsigned int servoPark = 10;
        unsigned int servoMax = 180;
        unsigned int position = servoPark;
        unsigned int speed = 5;
        unsigned int returnSpeed = 2;

        unsigned long mark = millis();
        void feedLoop();

    public:
        void init();
        void feed();
        void loop();

};


class Display {

    private:
        static const int contrast=8;
        static const int brightness=60;

    public:
        void showMessage();
        // Constructor
        void init();
        void loop();

        void showRpms(int rpms);
        void showFeedCount(int count);
        void showExposureTime(float time);
        void clear();

        Display();
};

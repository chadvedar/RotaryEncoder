#ifndef _ROTARYENCODER
#define _ROTARYENCODER

#include "mbed.h"
#include <chrono>


class RotaryEncoder{
    public:
        RotaryEncoder(PinName clk, PinName sig) : CLK(clk), SIG(sig){}
        Ticker timer_motor_speed;

        bool init();
        void start();
        float rpm;
        float encoder_resolution = 0.005;

    private:
        InterruptIn CLK;
        InterruptIn SIG;

        bool clk = 0;
        int8_t dir = 1;
        int encoder_pulse = 0;

        void set_clk_high();
        void set_clk_low();
        void encoder_callback();

        void calculate_speed();

};

#endif
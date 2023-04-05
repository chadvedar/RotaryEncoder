/*
# Copyright 2023 FIBO
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# Authors: Natee #
*/

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

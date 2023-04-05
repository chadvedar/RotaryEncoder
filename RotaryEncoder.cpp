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

#include "RotaryEncoder.hpp"

bool RotaryEncoder::init(){

    CLK.rise(callback(this, &RotaryEncoder::set_clk_high));
    CLK.fall(callback(this, &RotaryEncoder::set_clk_low));
    SIG.rise(callback(this, &RotaryEncoder::encoder_callback));

    return true;
}

void RotaryEncoder::start(){
    timer_motor_speed.attach(callback(this, &RotaryEncoder::calculate_speed), 20000us);
}

void RotaryEncoder::set_clk_high(){
    clk = 1;
}

void RotaryEncoder::set_clk_low(){
    clk = 0;
}

void RotaryEncoder::encoder_callback(){
    encoder_pulse++;
    if(clk) dir = 1;
    else dir = -1;
}

void RotaryEncoder::calculate_speed(){
    rpm = dir *encoder_pulse* encoder_resolution * 1000000.0 / 20000 * 60.0;
    encoder_pulse = 0;
}

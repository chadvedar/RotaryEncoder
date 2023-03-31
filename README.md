# RotaryEncoder
The code is for calculating angular velocity of motor by data of encoder A B signal.
The code utilize interrupt pin to collect A B signal of encoder.
This code have been tested on NUCLEO-F091RC. 
The code develop based ob mbed libs.

########################## Example #################################
```
#include "mbed.h"
#include "RotaryEncoder.hpp"
using namespace std::chrono;
RotaryEncoder enc(D6, D7);

int main() {
    enc.init();
    enc.start();

    while(1) {
        printf("%f\n", enc.rpm);
        ThisThread::sleep_for(1ms);
    }
}
```
####################################################################

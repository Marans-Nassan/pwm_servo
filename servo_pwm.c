#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/time.h"

#define braco 22
const uint16_t periodo = 19530; // wrap
const float divisor = 128.0;
uint16_t nivel_inic = 2400 * periodo / 19530;
uint16_t nivel_medio = 1470 * periodo / 19530;
uint16_t nivel_baixo = 500 * periodo / 19530;
uint16_t timer = 5000;
uint8_t i;

uint slice;



void pwm_setup(){
gpio_set_function(braco, GPIO_FUNC_PWM);
slice = pwm_gpio_to_slice_num(braco);
pwm_set_clkdiv(slice, divisor);
pwm_set_wrap(slice, periodo);
}


void pwm_acao(uint16_t nivel){
pwm_set_gpio_level(braco, nivel);
pwm_set_enabled(slice, true);
}

int64_t turn_off_callback(alarm_id_t id, void *user_data){
        if (i == 0) pwm_acao(nivel_inic);
        else if (i == 1)pwm_acao(nivel_medio);
        else if (i == 2)pwm_acao(nivel_baixo);
        else return 0;
        i++;
        if(i < 3) add_alarm_in_ms(timer, turn_off_callback, NULL, false);
}

int main(){

pwm_setup();  
add_alarm_in_ms(0, turn_off_callback, NULL, false);

    while (true) {
        sleep_ms(1);
    
    
    }
}

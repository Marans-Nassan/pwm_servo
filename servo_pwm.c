#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/time.h"

#define braco 22
const uint16_t periodo = 19531; // wrap
const float divisor = 128.0;
uint16_t angmin = 500;
uint16_t angmax = 2400;
uint16_t nivel_inici = 2400;
uint16_t nivel_medio = 1470;
uint16_t nivel_baixo = 500; 
uint16_t timer = 5000;
uint8_t i;
volatile bool timer_off = 0;
volatile bool up_down = 1;
uint8_t high_low = 5;
uint slice;
uint16_t ciclo = 500;



void pwm_setup(){
gpio_set_function(braco, GPIO_FUNC_PWM);
slice = pwm_gpio_to_slice_num(braco);
pwm_set_clkdiv(slice, divisor);
pwm_set_wrap(slice, periodo);
pwm_set_enabled(slice, true);
}


void pwm_acao(uint16_t nivel){
pwm_set_gpio_level(braco, nivel);
}

int64_t turn_off_callback(alarm_id_t id, void *user_data){
        if (i == 0)pwm_acao(nivel_inici);
        if (i == 1)pwm_acao(nivel_medio);
        if (i == 2)pwm_acao(nivel_baixo);
        i++;
        if(i <= 3) add_alarm_in_ms(timer, turn_off_callback, NULL, false);
        else timer_off = 1;
    return 0;
}
void movimentacao(){
    if(up_down == 1){
        sleep_ms(10);
        if(ciclo <= angmax)ciclo += high_low;
        else up_down = 0;
    }

    else{
        sleep_ms(10);
        if(ciclo >= angmin)ciclo -= high_low;
        else up_down = 1;
    }
    pwm_acao(ciclo);
}

int main(){
uint16_t ctime = to_us_since_boot(get_absolute_time());
pwm_setup();  
add_alarm_in_us(ctime, turn_off_callback, NULL, false);

    while (true) {
        if(timer_off == 1){
            movimentacao();
        }
        sleep_ms(1);
    }
}
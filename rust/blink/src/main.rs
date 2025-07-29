#![no_std]
#![no_main]

// pick a panicking behavior
use panic_halt as _; // you can put a breakpoint on `rust_begin_unwind` to catch panics
// use panic_abort as _; // requires nightly
// use panic_itm as _; // logs messages over ITM; requires ITM support
// use panic_semihosting as _; // logs messages to the host stderr; requires a debugger

use cortex_m_rt::entry;
use stm32g4::stm32g431;

#[entry]
fn main() -> ! {
    let dp = stm32g431::Peripherals::take().unwrap();

    // Enable GPIOB clock (AHB2 for G4 series)
    dp.RCC.ahb2enr().modify(|_, w| w.gpioben().set_bit());

    // Configure PB13 as output
    dp.GPIOB.moder().modify(|_, w| w.moder13().output());
    dp.GPIOB.otyper().modify(|_, w| w.ot13().push_pull());

    loop {
        // Toggle PB13
        dp.GPIOB.odr().modify(|r, w| {
            if r.odr13().bit_is_set() {
                w.odr13().clear_bit()
            } else {
                w.odr13().set_bit()
            }
        });

        cortex_m::asm::delay(5_000_000); // crude delay
    }
}

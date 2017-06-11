squeezebox is an opensource motion sensing, wind sensing, touch capactive teensy propsheild project inspired by the PushPull

This project uses teensy v3.2 and prop shield as well as sparkfun electret microphone breakout board as it progresses it will also use touch capcitance. i have included an example patch to show proof of concept for motion + microphone. 

Electret mic is wired to A0 using a 10k potentiometer as a voltage divider. Sparkfun Breakout board outputs ~1.65v, teensy analog input tops out at ~1.2v causing program crash.

This project uses the arudino sound library RMS without an audioshield (see code for details).
RMS is sent as midi on ctlin 1(pd)

Propshield motion detection triggers 3 ctrlins (2,3,4).

PD patch interaction FM synthesis: 
Motion:
heading alters pitch (2)
roll alters modulation index (4)
electret microphone controls volume (1)
pitch does not alter anything at this moment (3)

Built device is housed in top portion of a Woodstock childrens accordion for proof of concept:
https://www.amazon.com/Woodstock-Kids-Accordion-Music-Collection/dp/B00008XL18

Updates to build and readme will follow as project progresses.
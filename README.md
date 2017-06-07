squeezebox is an opensource motion sensing, wind sensing, touch capactive teensy propsheild project inspired by the PushPull

sparkfun electret microphone breakout board is wired to A0 using a 10k potentiometer as a voltage divider. i use the arudino sound library RMS without an audioshield (see code for details)
this sends midi on ctlin 1

propshield motion detection triggers 3 ctrlins (2,3,4).

PD patch interaction FM synthesis: 
Motion:
roll alters modulation index (4)
heading alters attack/decay (2)

electret microphone controls volume (1)


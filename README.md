# rgb-led-fading
=======
This arduino class provides a simply way to fade RGB led
Its a proof of concept in order to develope your code.

Usage:
Constructor:
    RGB lampada(redPin, grnPin, bluPin, 30, 1000)
the first three define colors Pin, the fourth defines
the delay beetween each small variation, increasing
this means slowing down the fading beetween colors.
The last one defines the delay when the desired color
is reached.

Inside your code call every cycle:
    lambda.update() 
to let the system work.
=======


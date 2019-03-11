# AlarmClock

This code utilizes a Piezo speaker, 16X2 LCD Display, and three buttons (among various resistors and a potentiometer)

The time is initialized in the code to 1:00 on 3/10/2019. This time is dislayed on the LCD Display. Holding down one button allows for the alarm to be set. When this button is held down, the alarm time is displayed on the screen. The other two buttons (hour and minute) can then be pressed to increment the alarm hour and minute respectively. These changes are shown in real time on the screen. Once the alarm set button is released, the alarm is set, and can no longer be changed until the button is held down again. When the alarm time is equal to the tracked time, the piezo speaker sounds at 1kHz. The alarm cannot be turned off because it can't bother you if you've gotten out of bed, right?

# IntroductionToRobotics
My repository with all the code from my homework and projects from my university robotics course. 

- Lab
  - [Lab 2: LEDs and Potetiometers](/Lab/Lab%202)
  - [Lab 3: Pushbuttons and Buzzers](/Lab/Lab%203)
  - [Lab 4: 7-segment Displays and Joysticks](/Lab/Lab%204)
- Homework 
  - <details>
    <summary>Homework 1: Controlling an RGB led with 3 potentiometers</summary>
    <ol>
      <li> <b>Code:</b> <a href="/Homework/Homework_1.ino">Homework_1.ino</a></li>
      <li> <b>Technical Task:</b> Use a separate potentiometer in controlling each of the color of the RGB led. The control must be done with digital electronics (aka you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led.</li>
      <li> <b>Coding task:</b> Coding style is of utmost importance. You must have a perfectly clean code in order to receive the maximum grade. Keep in mind that magic numbers are not accepted, although you might see them in the lab (as a trade-off for speed). Remember to be consistent in your style, check the style guide and the provided style document and use correct spacing.</li>
      <li> <b>Video:</b> https://youtu.be/HP5m1wVidqQ</li>
    </ol>
    
    ![signal-2021-10-26-223956_001](https://user-images.githubusercontent.com/61534490/138949839-e7d2ab05-39b8-4c67-be94-33af6387f5c7.jpeg) 
    ![signal-2021-10-26-224011_001](https://user-images.githubusercontent.com/61534490/138949855-a489288b-ceac-45ae-8cb0-a0de0ee7be67.jpeg)
    </details>

  - <details>
    <summary>Homework 2: Traffic lights</summary>
    <ol>
      <li> <b>Code:</b> <a href="/Homework/Homework_2.ino">Homework_2.ino</a></li>
      <li> <b>Technical Task:</b> Building the traffic lights for a crosswalk. You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green).</li>
      <li> <b>Coding task:</b> The system has the following states: State 1 (default, reinstated after state 4 ends): green light for cars, red light for people, no sounds. Duration: indefinite, changed by pressing the button. State 2 (initiated by counting down 10 seconds after a button press): the light should be yellow for cars, red for people and no sounds. Duration: 3 seconds. State 3 (iniated after state 2 ends): red for cars, green for people and a beeping sound from the buzzer at a constant interval. Duration: 10 seconds. State 4 (initiated after state 3 ends): red for cars, blinking green for people and a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3. This state should last 5 seconds. Be careful: pressing the button in any state other than state 1 should NOT yield any actions.</li>
      <li> <b>Video:</b> https://youtu.be/99ff-oNFGz4</li>
    </ol>
  
    ![signal-2021-11-03-232115_001](https://user-images.githubusercontent.com/61534490/140195230-48a50108-2552-40d6-98bb-9c022f5307b9.jpeg)
    ![signal-2021-11-03-232115_002](https://user-images.githubusercontent.com/61534490/140195446-c2c7a526-4653-48e8-9d5e-be4b0842340c.jpeg)
    </details>
    
  - <details>
    <summary>Homework 3: EMF Detector</summary>
    <ol>
      <li> <b>Code:</b> <a href="/Homework/Homework_3.ino">Homework_3.ino</a></li>
      <li> <b>Technical Task:</b> Buil a Ghost Detector using a buzzer and a 7-segment display (or a led bar / or 8 leds in a row that simulate a led bar).</li>
      <li> <b>Coding task:</b> It should print the value on the 7-segment display (or light the led bar) and should make a sound based on the intensity. The catch: it’s really easy, but one of the mistakes you can do is not calibrate for the interval on the values you are going to get.</li>
      <li> <b>Video:</b> https://youtu.be/UK0OZxlMHN4</li>
    </ol>
  
    ![signal-2021-11-10-234530_001](https://user-images.githubusercontent.com/61534490/141199099-ef416178-ee76-4572-9532-8a7cdbe326c0.jpeg)
    ![signal-2021-11-10-234530_002](https://user-images.githubusercontent.com/61534490/141199108-9a687aa3-bfd1-40a0-bf3c-69b23f14fedc.jpeg)
    </details>
    
  - <details>
    <summary>Homework 4: 4 digit 7-segment with Joystick</summary>
    <ol>
      <li> <b>Code:</b> <a href="/Homework/Homework_4.ino">Homework_4.ino</a></li>
      <li> <b>Technical Task:</b> The current homework involves using a joystick in setting the values on each digit of a 4-digit 7-segment display connected to a shift register 74hc595. </li>
      <li> <b>Coding task:</b> First state: you can use a joystick axis to cycle through the 4 digits; using the other axis does nothing. A blinking decimal point shows the current digit position. When pressing the button, you lock in on the selected digit and enter the second state. In this state, the decimal point stays always on, no longer blinking and you can no longer use the axis to cycle through the 4 digits. Instead, using the other axis, you can increment on decrement the number on the current digit. Pressing the button again returns you to the previous state. For bonus, save the last value in eeprom and load it when starting arduino. Also, keep in mind that when changing the number, you must increment it for each joystick movement - it should not work continuosly increment if you keep the joystick in one position. </li>
      <li> <b>Video:</b> https://youtu.be/6ubtYIeCjNU </li>
    </ol>
  
    ![signal-2021-11-17-132059_002](https://user-images.githubusercontent.com/61534490/142274505-84b0242a-cf51-47a0-b8f9-785736a2746b.jpeg)
    ![signal-2021-11-17-132059_003](https://user-images.githubusercontent.com/61534490/142274513-304c49fa-e5e8-4769-b39b-0efd848540b7.jpeg)
    </details>


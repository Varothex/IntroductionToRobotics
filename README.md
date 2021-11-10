# IntroductionToRobotics
My repository with all the code from my homework and projects from my university robotics course. 

- Lab
  - [Lab 2](/Lab/Lab%202)
  - [Lab 3](/Lab/Lab%203)
  - [Lab 4](/Lab/Lab%204)
- Homework 
  - <details>
    <summary>Homework 1-Controlling an RGB led with 3 potentiometers</summary>
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
    <summary>Homework 2-Traffic lights</summary>
    <ol>
      <li> <b>Code:</b> <a href="/Homework/Homework_2.ino">Homework_2.ino</a></li>
      <li> <b>Technical Task:</b> Building the traffic lights for a crosswalk. You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green).</li>
      <li> <b>Coding task:</b> The system has the following states: State 1 (default, reinstated after state 4 ends): green light for cars, red light for people, no sounds. Duration: indefinite, changed by pressing the button. State 2 (initiated by counting down 10 seconds after a button press): the light should be yellow for cars, red for people and no sounds. Duration: 3 seconds. State 3 (iniated after state 2 ends): red for cars, green for people and a beeping sound from the buzzer at a constant interval. Duration: 10 seconds. State 4 (initiated after state 3 ends): red for cars, blinking green for people and a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3. This state should last 5 seconds. Be careful: pressing the button in any state other than state 1 should NOT yield any actions.</li>
      <li> <b>Video:</b> https://youtu.be/99ff-oNFGz4</li>
    </ol>
  
    ![signal-2021-11-03-232115_001](https://user-images.githubusercontent.com/61534490/140195230-48a50108-2552-40d6-98bb-9c022f5307b9.jpeg)
    ![signal-2021-11-03-232115_002](https://user-images.githubusercontent.com/61534490/140195446-c2c7a526-4653-48e8-9d5e-be4b0842340c.jpeg)
    </details>


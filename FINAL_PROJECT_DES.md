# EGRE 347 FInal Project
 Final Project for Time Manger For EGRE 347 By Michael Lindsay and Hunter Mitchell  

 For Michael Lindsay’s and Hunter Mitchell’s final project we are designing a scheduler for our pi that can be used through a touch display, and which our device will be similar to a pager/schedule logger. When the scheduler is opened it will first read in the data stored from the last run and report any overdue and upcoming events to the display. The user is then able to navigate through the program with a menu: they can schedule new events, search specific events with keywords, and check specific dates.

 When scheduling a new event the program will alert the user with an onscreen warning and a harsh sound if the newly scheduled event is within an hour of any other currently scheduled events, especially if it collides with another event.

 When searching through events, when they access an event they can edit or remove that event from the scheduler. The user can also check to see what events are scheduled on specific dates, and they can edit and remove events here as well.

 When the user is finished and closes the program, all data in the program will be saved to an external file to be accessed later.

 We will be using a HDMI display to essentially display onto a remote display. Our creation will mimic something like a pager that gives the ability to change your calendar on the go. Our sought out display for the Raspberry Pi is located at : https://www.amazon.com/OSOYOO-Screen-Monitor-Display-Raspberry/dp/B085PYS8P2/ref=sr_1_9?crid=2M9B8JSTMSOC6&keywords=raspberry+pi+4+display&qid=1649884527&sprefix=raspberry+pi+4+display%2Caps%2C62&sr=8-9

 We also incorporated the aspect of LED's if the entered time is overlapped , open , or an hour close to a current event 

1. Goal
Homework 4 Due Date: For this homework due date I will have fully implemented the Computer Vision Aspect of the Game. It will still be run through the terminal so the program will take in the name of a photo which will be scanned by the computer vision functions and converted to a playable sudoku game.

2. I had to totally redo my makefile system to use cmake which is needed to make OpenCV work properly. This was more complicated then I expected and took a while to get working. I then implemented the computer vision part so my application can take in an image and divide it into the 81 cells in a sudoku board. I did not realize that the character recognizition part was not a built in function in OpenCV so I had to add a second library, Tesseract OCR, which will handle the character recognition. The tesseract code to recognize a simple character is very basic and I have implemented the code but similarly to OpenCV I am having trouble with the make file. It should not be super hard to fix and I plan to have that completed over the weekend so I can start with the Qt part on Monday and basically maintain my planned schedule.

3. Nothing has really changed, as mentioned above I just need to get Tesseract linking to my application through cmake properly but will get that done by Monday. Will still impliment the GUI for the game using Qt as planned.

4. <img src="checkpoint4Image.png">
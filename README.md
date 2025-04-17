## 🖼 Image Editor

### Overview
This is a simple C++ image processing project. The program supports basic image editing operations on 24-bit BMP files using custom image handling functions.

### Features
- Load and display BMP images
- Apply various filters and transformations, including:
  - Black & White Filter
  - Invert Filter
  - Merge Filter
  - Flip Image (horizontally or vertically)
  - Rotate Image
  - Darken and Lighten Image
- Save modified images to new files
- Simple console-based menu interface

### Technologies Used
- C++
- BMP image format
- Console Application

### Project Structure
- Editor.cpp: Main program file  
- bmplib.cpp: Image processing utility functions  
- bmplib.h: Header file for image utilities  
- .bmp files: Sample BMP images for testing (e.g., crowd.bmp, elephant.bmp, fruit.bmp, etc.)

### How to Run
1. Make sure you have g++ installed.
2. Open terminal and navigate to the project directory.
3. Compile the project:
   ```bash
   g++ Editor.cpp -o image_editor

/*
// On linux compile with:
// g++ -std=c++17 main.cpp -o prog -lSDL2

// C++ Standard Libraries
#include <iostream>

// Third-party library
#include <SDL2/SDL.h>

#include "render.h"



int main(int argc, char* argv[]){

    InitializeProgram();
    
    MainLoop();
    
    CleanUp();
    
    
}
*/

#include <opencv2/opencv.hpp>

// Function to draw a line with an arrowhead
void drawArrow(cv::Mat& img, cv::Point start, cv::Point end, cv::Scalar color, int thickness = 1, int arrowSize = 5) {
    cv::line(img, start, end, color, thickness);
    double angle = atan2(start.y - end.y, start.x - end.x);
    cv::Point arrowTip1(end.x + arrowSize * cos(angle + CV_PI / 4),
                        end.y + arrowSize * sin(angle + CV_PI / 4));
    cv::Point arrowTip2(end.x + arrowSize * cos(angle - CV_PI / 4),
                        end.y + arrowSize * sin(angle - CV_PI / 4));
    cv::line(img, end, arrowTip1, color, thickness);
    cv::line(img, end, arrowTip2, color, thickness);
}

// Function to draw the HUD symbology on the image
void drawHudSymbology(cv::Mat& img) {
    // Define colors (BGR format)
    cv::Scalar white(255, 255, 255);
    cv::Scalar red(0, 0, 255);
    cv::Scalar green(0, 255, 0);

    // Draw pitch ladder
    cv::Point pitchStart(img.cols / 2, 20);
    cv::Point pitchEnd(img.cols / 2, img.rows - 20);
    drawArrow(img, pitchStart, pitchEnd, white, 2);

    // Draw roll indicator
    cv::Point rollStart(img.cols / 2 - 50, img.rows / 2);
    cv::Point rollEnd(img.cols / 2 + 50, img.rows / 2);
    drawArrow(img, rollStart, rollEnd, white, 2);

    // Draw heading indicator
    cv::Point headingCenter(img.cols / 2, img.rows / 2);
    int headingRadius = 40;
    double headingAngle = CV_PI / 4; // Change this angle as needed
    cv::Point headingEnd(headingCenter.x + headingRadius * cos(headingAngle),
                         headingCenter.y - headingRadius * sin(headingAngle));
    cv::circle(img, headingCenter, headingRadius, white, 2);
    cv::line(img, headingCenter, headingEnd, white, 2);

    // Draw some text labels
    int font = cv::FONT_HERSHEY_SIMPLEX;
    cv::putText(img, "PITCH", cv::Point(pitchStart.x - 40, pitchStart.y), font, 0.5, white, 1, cv::LINE_AA);
    cv::putText(img, "ROLL", cv::Point(rollStart.x - 40, rollStart.y - 10), font, 0.5, white, 1, cv::LINE_AA);
    cv::putText(img, "N", cv::Point(headingEnd.x - 10, headingEnd.y - 10), font, 0.5, white, 1, cv::LINE_AA);
}

int main() {
    // Open the webcam
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Cannot open webcam!" << std::endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        // Draw the HUD symbology on the frame
        drawHudSymbology(frame);

        // Show the frame
        cv::imshow("HUD Symbology", frame);

        // Exit when 'q' is pressed
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // Release the webcam and close the OpenCV windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}

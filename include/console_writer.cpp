#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "console_writer.h"

/*
    text -> The text to print
    delayCh -> Delay between characters
    delayS -> Additional delay after spaces
    color -> ANSI color code to use (0 = no color)
*/


void write(const std::string& text, int delayCh, int delayS, int color) {
    if (color != 0) {
        std::cout << "\033[" << color << "m";
        for (size_t i = 0; i < text.length(); i++) {
            std::cout << text[i];
            std::this_thread::sleep_for(std::chrono::milliseconds(delayCh));
            if (text[i] == ' ') {
                std::this_thread::sleep_for(std::chrono::milliseconds(delayS));
            }
        }
        std::cout << "\033[0m";
    }
    else {
        for (size_t i = 0; i < text.length(); i++) {
            std::cout << text[i];
            std::this_thread::sleep_for(std::chrono::milliseconds(delayCh));
            if (text[i] == ' ') {
                std::this_thread::sleep_for(std::chrono::milliseconds(delayS));
            }
        }
    }
}

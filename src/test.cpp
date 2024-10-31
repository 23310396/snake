#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;
    
    
    
    while (true)
    {
        
        int direccion=1;
        int FD=frame*direccion;
        if(frame>100)
            {
                direccion=-1;
            }
        auto can = Canvas(300,100);
        can.DrawBlockCircle(100,75-FD,15);
        can.DrawBlockCircle(200,75-FD,15);
        can.DrawBlockLine(115,75-1-FD,185,75-1-FD);
        can.DrawBlockLine(75-FD,75,85-FD,75);
        can.DrawBlockLine(215+FD,75,225+FD,75);
        can.DrawBlockLine(75-FD,75,75-FD,40);
        can.DrawBlockLine(225+FD,75,225+FD,50);
        can.DrawBlockLine(75,40-FD,225,50-FD);
        can.DrawBlockLine(75+2*FD,40,75+2*FD,30);
        can.DrawBlockLine(75,30-FD,70,30-FD);
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Red, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}
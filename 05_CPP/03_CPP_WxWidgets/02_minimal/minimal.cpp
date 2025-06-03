
// minimal.cpp
// LINUX
// g++ minimal.cpp -o minimal `wx-config --cxxflags --libs`
// ./minimal
// WINDOWS
// g++ minimal.cpp -o minimal.exe $(wx-config --cxxflags --libs)
// minimal.exe

#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(NULL, wxID_ANY, "Hola, wxWidgets!") {}
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

// REFERENCIA
// OpenAI. (2025, 2 de abril). ChatGPT (versión del 2 de abril de 2025) 
// [Modelo de lenguaje de gran tamaño]. 
// https://chatgpt.com/share/67edeb7f-f6d8-800a-a08a-0c3255e6a0dd

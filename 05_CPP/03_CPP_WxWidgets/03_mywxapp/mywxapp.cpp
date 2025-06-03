
// mywxapp.cmp

#include <wx/wx.h>

// Definición de la clase de la aplicación
class MyApp : public wxApp
{
public:
    virtual bool OnInit(); // Método que inicializa la aplicación
};

// Definición de la clase de la ventana
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title); // Constructor de la ventana

private:
    void OnButtonClick(wxCommandEvent& event); // Maneja el evento de clic en el botón
};

// Implementación de la clase MyApp
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // Crear la ventana principal
    MyFrame* frame = new MyFrame("Hello wxWidgets");
    frame->Show(true); // Mostrar la ventana
    return true;
}

// Implementación de la clase MyFrame
MyFrame::MyFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    // Crear un panel en la ventana
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Crear un botón en el panel
    wxButton* button = new wxButton(panel, wxID_ANY, "Click Me", wxPoint(10, 10));

    // Conectar el evento del botón con el método OnButtonClick
    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
}

// Manejo del evento de clic en el botón
void MyFrame::OnButtonClick(wxCommandEvent& event)
{
    wxMessageBox("Hello, wxWidgets!", "Información", wxOK | wxICON_INFORMATION);
}


// g++ `wx-config --cxxflags` -o mywxapp  mywxapp.cpp `wx-config --libs`

// https://chatgpt.com/share/67f1cfc3-b4bc-800a-8e01-e26731232b06
//


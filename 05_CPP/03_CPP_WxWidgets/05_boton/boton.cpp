
// boton.cpp

#include <wx/wx.h>
// Definir la clase de la aplicación
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// Definir la clase de la ventana
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);  // Constructor de la ventana

private:
    void OnButtonClick(wxCommandEvent& event);  // Manejo del clic en el botón
};

// Implementación de la clase MyApp
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("Ejemplo wxWidgets");
    frame->Show(true);  // Mostrar la ventana
    return true;
}

// Implementación de la clase MyFrame
MyFrame::MyFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    // Crear un panel dentro de la ventana
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    // Crear un botón
    wxButton* button = new wxButton(panel, wxID_ANY, "¡Haz clic aquí!", wxPoint(10, 10));

    // Asociar el evento de clic con el método OnButtonClick
    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
}

// Manejo del evento de clic en el botón
void MyFrame::OnButtonClick(wxCommandEvent& event)
{
    wxMessageBox("¡Hola, wxWidgets!", "Información", wxOK | wxICON_INFORMATION);
}

//  REFERENCIA
//  https://chatgpt.com/share/67f1cfc3-b4bc-800a-8e01-e26731232b06

// LINUX
// g++ `wx-config --cxxflags` -o ejemplo02 ejemplo02.cpp `wx-config --libs`
// ./ejemplo2
//
// WINDOWS
// g++ boton.cpp -o boton.exe $(wx-config --cxxflags --libs)
// boton.exe

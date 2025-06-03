
// mi_programa.cpp

#include <wx/wx.h>

// Definición de la clase MyApp que hereda de wxApp
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// Definición de la clase MyFrame que hereda de wxFrame
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);

private:
    void OnButtonClicked(wxCommandEvent& event);

    wxPanel* m_panel;
    wxStaticText* m_label;
    wxTextCtrl* m_textCtrl;
    wxButton* m_button;
};

// Implementación de la macro para inicializar la aplicación
wxIMPLEMENT_APP(MyApp);

// Implementación del método OnInit de MyApp
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("Aplicación wxWidgets con Controles");
    frame->Show(true);
    return true;
}

// Constructor de MyFrame
MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    // Crear el panel principal
    m_panel = new wxPanel(this, wxID_ANY);

    // Crear una etiqueta
    m_label = new wxStaticText(m_panel, wxID_ANY, "Ingrese su nombre:",
                               wxPoint(20, 20));

    // Crear un cuadro de texto
    m_textCtrl = new wxTextCtrl(m_panel, wxID_ANY, "",
                                wxPoint(20, 50), wxSize(250, 25));

    // Crear un botón
    m_button = new wxButton(m_panel, wxID_ANY, "Saludar",
                            wxPoint(20, 90), wxSize(80, 30));

    // Conectar el evento del botón con el manejador de eventos
    m_button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
}

// Manejador de eventos para el botón
void MyFrame::OnButtonClicked(wxCommandEvent& event)
{
    wxString nombre = m_textCtrl->GetValue();
    wxString mensaje = "Hola, " + nombre + "!";
    wxMessageBox(mensaje, "Saludo", wxOK | wxICON_INFORMATION);
}

// REFERENCIA
// OpenAI. (2025, 2 de abril). ChatGPT (versión del 2 de abril de 2025) 
// [Modelo de lenguaje de gran tamaño]. 
// https://chat.openai.com/chat/67edeb7f-f6d8-800a-a08a-0c3255e6a0dd

// LINUX
// g++ mi_programa.cpp -o mi_programa `wx-config --cxxflags --libs`
// ./mi_programa
// WINDOWS
// g++ mi_programa.cpp -o mi_programa.exe $(wx-config --cxxflags --libs)
// ./mi_programa.exe

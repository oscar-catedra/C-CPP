
// app_slider.cpp

#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);

private:
    void OnSliderScroll(wxCommandEvent& event); // Evento para manejar el deslizamiento
    wxSlider* m_slider; // Barra deslizante
    wxTextCtrl* m_textCtrl; // Cuadro de texto para mostrar el valor
    wxBoxSizer* m_sizer;

    wxDECLARE_EVENT_TABLE();
};

// Mapa de eventos
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_SLIDER(wxID_ANY, MyFrame::OnSliderScroll)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("Barra Deslizante wxWidgets");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    // Crear un panel para la ventana
    wxPanel* panel = new wxPanel(this);

    // Crear la barra deslizante (slider)
    m_slider = new wxSlider(panel, wxID_ANY, 50, 0, 100, wxPoint(20, 20), wxSize(250, 30));

    // Crear un cuadro de texto para mostrar el valor de la barra deslizante
    m_textCtrl = new wxTextCtrl(panel, wxID_ANY, "50", wxPoint(20, 70), wxSize(100, 30));

    // Crear un sizer para organizar los controles
    m_sizer = new wxBoxSizer(wxVERTICAL);
    m_sizer->Add(m_slider, 0, wxALL, 10);
    m_sizer->Add(m_textCtrl, 0, wxALL, 10);

    panel->SetSizerAndFit(m_sizer);
}

// Evento que maneja el deslizamiento
void MyFrame::OnSliderScroll(wxCommandEvent& event)
{
    // Obtener el valor de la barra deslizante
    int value = m_slider->GetValue();

    // Actualizar el cuadro de texto con el valor actual del slider
    m_textCtrl->SetValue(wxString::Format("%d", value));
}

// REFERENCIA
// https://chatgpt.com/share/67f1cfc3-b4bc-800a-8e01-e26731232b06

// LINUX
// g++ `wx-config --cxxflags` -o app_slider app_slider.cpp `wx-config --libs`
// ./app_slider
//
// WINDOWS
// g++ app_slider.cpp -o app_slider.exe $(wx-config --cxxflags --libs)
// app_slider.exe 


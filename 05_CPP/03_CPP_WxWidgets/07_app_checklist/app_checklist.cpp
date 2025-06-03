
// app_checklist.cpp

#include <wx/wx.h>
#include <wx/checklst.h>

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
    void OnButtonClick(wxCommandEvent& event);  // Maneja el evento de clic en el botón

    wxCheckListBox* m_checkListBox;  // Lista de selección múltiple
    wxBoxSizer* m_sizer;  // Contenedor (Sizer)
    wxDECLARE_EVENT_TABLE();
};

// Mapa de eventos
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MyFrame::OnButtonClick)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("Menú de Selección Múltiple wxWidgets");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    // Crear un panel para la ventana
    wxPanel* panel = new wxPanel(this);

    // Crear la lista de selección múltiple (wxCheckListBox)
    wxArrayString choices;
    choices.Add("Manzanas");
    choices.Add("Plátanos");
    choices.Add("Cerezas");
    choices.Add("Peras");
    choices.Add("Uvas");

    m_checkListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(20, 20), wxSize(250, 100), choices);

    // Crear un botón
    wxButton* button = new wxButton(panel, wxID_ANY, "Mostrar Selección", wxPoint(20, 130));

    // Crear un sizer para organizar los controles
    m_sizer = new wxBoxSizer(wxVERTICAL);
    m_sizer->Add(m_checkListBox, 0, wxALL, 10);
    m_sizer->Add(button, 0, wxALL, 10);

    panel->SetSizerAndFit(m_sizer);
}

// Maneja el clic en el botón
void MyFrame::OnButtonClick(wxCommandEvent& event)
{
    // Crear un array para almacenar las selecciones
    wxArrayInt selections;

    // Obtener las selecciones de la lista de selección múltiple
    m_checkListBox->GetCheckedItems(selections);

    wxString message = "Seleccionaste:\n";

    // Construir un mensaje con las selecciones
    for (size_t i = 0; i < selections.GetCount
	(); ++i)
    {
        message += m_checkListBox->GetString(selections[i]) + "\n";
    }

    // Mostrar las selecciones en un cuadro de mensaje
    wxMessageBox(message, "Selección Múltiple", wxOK | wxICON_INFORMATION);
}

// REFERENCIA
// https://chatgpt.com/share/67f1cfc3-b4bc-800a-8e01-e26731232b06
//
// LINUX
// g++ `wx-config --cxxflags` -o app_checklist app_checklist.cpp `wx-config --libs`
// ./app_checklist
//
// WINDOWS
// g++ app_checklist.cpp -o app_checklist.exe $(wx-config --cxxflags --libs)
// app_checklist.exe

 


// main.cpp

#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Ejemplo wxWidgets", wxDefaultPosition, wxSize(400, 300)) {
        auto* boton = new wxButton(this, wxID_ANY, "Haz clic aquí", wxPoint(120, 100), wxSize(150, 50));
        boton->Bind(wxEVT_BUTTON, &MyFrame::OnBotonClic, this);
    }

private:
    void OnBotonClic(wxCommandEvent&) {
        wxMessageBox("¡Hola desde wxWidgets!", "Mensaje");
    }
};

class MyApp : public wxApp {
public:
    bool OnInit() override {
        auto* frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);


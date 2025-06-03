
// tictactoe.cpp

#include <wx/wx.h>
#include <array>

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
    void OnButtonClick(wxCommandEvent& event);
    void ResetGame(wxCommandEvent& event);  // Reiniciar juego
    void OnExit(wxCommandEvent& event);     // Salir del juego
    bool CheckWinner();
    void UpdateButtonLabel(int row, int col);

    wxButton* m_buttons[3][3];  // Matriz de botones (3x3)
    wxBoxSizer* m_sizer;         // Sizer para organizar los controles
    wxString m_turn;             // Turno actual ("X" o "O")
    std::array<std::array<wxString, 3>, 3> m_board;  // Tablero 3x3
    bool m_gameOver;             // Si el juego terminó

    wxDECLARE_EVENT_TABLE();
};

// Mapa de eventos
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MyFrame::OnButtonClick)
    EVT_BUTTON(wxID_ANY, MyFrame::ResetGame)  // Manejamos el evento del botón de reinicio
    EVT_BUTTON(wxID_EXIT, MyFrame::OnExit)    // Manejamos el evento del botón de salida
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame("3 en Raya - Tic-Tac-Toe");
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title), m_turn("X"), m_gameOver(false)
{
    // Crear un panel para la ventana
    wxPanel* panel = new wxPanel(this);
    
    // Crear un sizer para la disposición de los botones
    m_sizer = new wxBoxSizer(wxVERTICAL);

    // Crear la cuadrícula de botones 3x3
    for (int i = 0; i < 3; ++i)
    {
        wxBoxSizer* rowSizer = new wxBoxSizer(wxHORIZONTAL);
        for (int j = 0; j < 3; ++j)
        {
            m_buttons[i][j] = new wxButton(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 100));
            rowSizer->Add(m_buttons[i][j], 0, wxALL, 5);
            m_board[i][j] = "";  // Inicializar el tablero vacío
        }
        m_sizer->Add(rowSizer, 0, wxALIGN_CENTER);
    }

    // Añadir un botón para reiniciar el juego
    wxButton* resetButton = new wxButton(panel, wxID_ANY, "Reiniciar", wxDefaultPosition, wxSize(100, 50));
    m_sizer->Add(resetButton, 0, wxALL | wxALIGN_CENTER, 10);

    // Añadir un botón para salir
    wxButton* exitButton = new wxButton(panel, wxID_EXIT, "Salir", wxDefaultPosition, wxSize(100, 50));
    m_sizer->Add(exitButton, 0, wxALL | wxALIGN_CENTER, 10);

    panel->SetSizerAndFit(m_sizer);

    // Conectar el evento de clic del botón de reinicio
    resetButton->Bind(wxEVT_BUTTON, &MyFrame::ResetGame, this);

    // Conectar el evento de clic del botón de salida
    exitButton->Bind(wxEVT_BUTTON, &MyFrame::OnExit, this);
}

// Maneja el clic en los botones del tablero
void MyFrame::OnButtonClick(wxCommandEvent& event)
{
    if (m_gameOver) return;  // Si el juego terminó, no hacer nada

    // Buscar el botón que fue presionado
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (event.GetEventObject() == m_buttons[i][j] && m_board[i][j] == "")
            {
                // Marcar el tablero con el símbolo del jugador actual
                m_board[i][j] = m_turn;
                UpdateButtonLabel(i, j);
                
                // Comprobar si hay un ganador
                if (CheckWinner())
                {
                    wxMessageBox(m_turn + " ha ganado!", "¡Victoria!", wxOK | wxICON_INFORMATION);
                    m_gameOver = true;
                }
                else
                {
                    // Cambiar turno
                    m_turn = (m_turn == "X") ? "O" : "X";
                }
                return;
            }
        }
    }
}

// Actualizar la etiqueta de un botón con el valor del turno
void MyFrame::UpdateButtonLabel(int row, int col)
{
    m_buttons[row][col]->SetLabel(m_board[row][col]);
}

// Comprobar si hay un ganador
bool MyFrame::CheckWinner()
{
    // Comprobar filas y columnas
    for (int i = 0; i < 3; ++i)
    {
        if (m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2] && m_board[i][0] != "")
            return true;
        if (m_board[0][i] == m_board[1][i] && m_board[1][i] == m_board[2][i] && m_board[0][i] != "")
            return true;
    }

    // Comprobar diagonales
    if (m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2] && m_board[0][0] != "")
        return true;
    if (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0] && m_board[0][2] != "")
        return true;

    return false;
}

// Reiniciar el juego
void MyFrame::ResetGame(wxCommandEvent& event)
{
    m_gameOver = false;
    m_turn = "X";

    // Limpiar el tablero
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            m_board[i][j] = "";
            m_buttons[i][j]->SetLabel("");
        }
    }
}

// Salir del juego
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);  // Cierra la ventana y termina la aplicación
}

// REFERENCIA
// OPENAI. chatGPT
// https://chatgpt.com/share/67f1cfc3-b4bc-800a-8e01-e26731232b06

// LINUX
// g++ `wx-config --cxxflags` -o tictactoe tictactoe.cpp `wx-config --libs`
// ./tictactoe
//
// WINDOWS
// g++ tictactoe.cpp -o tictacto.exe $(wx-config --cxxflags --libs)


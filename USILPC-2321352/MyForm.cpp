#include "MyForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Cambia "USILPC2321352" al nombre del espacio de nombres de tu proyecto.
    USILPC2321352::MyForm form;
    Application::Run(% form);
    return 0;
}
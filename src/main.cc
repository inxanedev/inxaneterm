#include "main_window.h"
#include <gtkmm.h>
#include <iostream>
int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("com.inxane.inxaneterm");
    MainWindow window(
    	argc < 2
    	? (gdouble)1
    	: g_ascii_strtod(argv[1], NULL)
    );
    return app->run(window);
}

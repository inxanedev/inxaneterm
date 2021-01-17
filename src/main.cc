#include "main_window.h"
#include <gtkmm.h>
#include <iostream>
int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <font scale>" << std::endl;
	} else {
    	auto app = Gtk::Application::create("com.inxane.inxaneterm");
    	MainWindow window(g_ascii_strtod(argv[1], NULL));
    	return app->run(window);
    }
}

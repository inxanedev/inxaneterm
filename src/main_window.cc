#include "main_window.h"
#include <vte/vte.h>
#include <gtkmm.h>

MainWindow::MainWindow(gdouble scale) {
    set_default_size(800, 600);
    set_title("InxaneTerm");

    Gtk::Box* vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    add(*vbox);

    GtkWidget* terminal = vte_terminal_new();
	char* startterm[2] = {0, 0};
	startterm[0] = vte_get_user_shell();
	
    VteTerminal* term = VTE_TERMINAL(terminal);	
	vte_terminal_spawn_sync(
		term,
		VTE_PTY_DEFAULT,
		nullptr,
		startterm,
		nullptr,
        G_SPAWN_SEARCH_PATH,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    );
    
	vte_terminal_set_font_scale(term, scale);

	gtk_widget_set_vexpand(terminal, true);
    gtk_widget_set_halign(terminal, GTK_ALIGN_FILL);
    gtk_widget_set_hexpand(terminal, true);
    gtk_widget_set_valign(terminal, GTK_ALIGN_FILL);
    vbox->add(*Glib::wrap(terminal));
    vbox->show_all();
}



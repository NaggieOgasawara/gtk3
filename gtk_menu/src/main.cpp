#include	<gtkmm.h>
#include	"examplewindow.h"

int main(int argc, char *argv[])
{
	auto app =
	Gtk::Application::create(argc,argv, "org.gtkmm.example");
	
	ExampleWindow window(app);
	
	// Show the window and returns when ot is closed.
	return app->run(window);
}

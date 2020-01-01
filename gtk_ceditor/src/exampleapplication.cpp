#include "exampleapplication.h"
#include "examplewindow.h"
#include <iostream>

ExampleApplication::ExampleApplication()
: Gtk::Application("org.gtkmm.example.main_menu")
{
  Glib::set_application_name("Project");
}

Glib::RefPtr<ExampleApplication> ExampleApplication::create()
{
  return Glib::RefPtr<ExampleApplication>(new ExampleApplication());
}

void ExampleApplication::on_startup()
{
  //Call the base class's implementation:
  Gtk::Application::on_startup();

  //Create actions for menus and toolbars.
  //We can use add_action() because Gtk::Application derives from Gio::ActionMap.

  //File|New sub menu:
  add_action("newstandard",
    sigc::mem_fun(*this, &ExampleApplication::on_menu_file_new_generic));

  add_action("openproj",
    sigc::mem_fun(*this, &ExampleApplication::on_menu_file_open_generic));

  add_action("saveproj",
    sigc::mem_fun(*this, &ExampleApplication::on_menu_file_save_generic));

  //File menu:
  add_action("quit", sigc::mem_fun(*this, &ExampleApplication::on_menu_file_quit));

  //Help menu:
  add_action("about", sigc::mem_fun(*this, &ExampleApplication::on_menu_help_about));

  m_refBuilder = Gtk::Builder::create();

  //Layout the actions in a menubar and an application menu:
  Glib::ustring ui_info =
    "<interface>"
    "  <!-- menubar -->"
    "  <menu id='menu-example'>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_File</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>New _Standard</attribute>"
    "          <attribute name='action'>app.newstandard</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;n</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>Open _Project</attribute>"
    "          <attribute name='action'>app.openproj</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>Save _Project</attribute>"
    "          <attribute name='action'>app.saveproj</attribute>"
    "        </item>"
    "      </section>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Quit</attribute>"
    "          <attribute name='action'>app.quit</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;q</attribute>"
    "        </item>"
    "      </section>"
    "    </submenu>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_Edit</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Copy</attribute>"
    "          <attribute name='action'>win.copy</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;c</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Paste</attribute>"
    "          <attribute name='action'>win.paste</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;v</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Something</attribute>"
    "          <attribute name='action'>win.something</attribute>"
    "        </item>"
    "      </section>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Add</attribute>"
    "          <attribute name='action'>win.add</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;a</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Insert</attribute>"
    "          <attribute name='action'>win.insert</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;i</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Delete</attribute>"
    "          <attribute name='action'>win.delete</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;d</attribute>"
    "        </item>"
    "      </section>"
    "    </submenu>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_Help</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_About</attribute>"
    "          <attribute name='action'>win.about</attribute>"
    "        </item>"
    "      </section>"
    "    </submenu>"
    "  </menu>"
    "</interface>";

  try
  {
    m_refBuilder->add_from_string(ui_info);
  }
  catch (const Glib::Error& ex)
  {
    std::cerr << "Building menus failed: " << ex.what();
  }

  //Get the menubar and the app menu, and add them to the application:
  auto object = m_refBuilder->get_object("menu-example");
  auto gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);
//  if (!(gmenu && appMenu)) {
  if (!(gmenu)) {
    g_warning("GMenu or AppMenu not found");
  }
  else
  {
    set_menubar(gmenu);
  }
}

void ExampleApplication::on_activate()
{
  //std::cout << "debug1: " << G_STRFUNC << std::endl;
  // The application has been started, so let's show a window.
  // A real application might want to reuse this window in on_open(),
  // when asked to open a file, if no changes have been made yet.
  create_window();
}

void ExampleApplication::create_window()
{
  auto win = new ExampleWindow();

  //Make sure that the application runs for as long this window is still open:
  add_window(*win);

  //Delete the window when it is hidden.
  //That's enough for this simple example.
  win->signal_hide().connect(sigc::bind<Gtk::Window*>(
    sigc::mem_fun(*this, &ExampleApplication::on_window_hide), win));

  win->show_all();
}

void ExampleApplication::on_window_hide(Gtk::Window* window)
{
  delete window;
}

//
//	新しいプロジェクトを作る
//
void ExampleApplication::on_menu_file_new_generic()
{
  std::cout << "'Create new project' was selected." << std::endl;
}

//
//	プロジェクトを開く
//
void ExampleApplication::on_menu_file_open_generic()
{
  std::cout << "'Open project' was selected." << std::endl;
}

//
//	プロジェクトを保存する
//
void ExampleApplication::on_menu_file_save_generic()
{
  std::cout << "'Save project' was selected." << std::endl;
}

//
//	終了する
//
void ExampleApplication::on_menu_file_quit()
{
  std::cout << G_STRFUNC << std::endl;
  quit(); // Not really necessary, when Gtk::Widget::hide() is called.

  // Gio::Application::quit() will make Gio::Application::run() return,
  // but it's a crude way of ending the program. The window is not removed
  // from the application. Neither the window's nor the application's
  // destructors will be called, because there will be remaining reference
  // counts in both of them. If we want the destructors to be called, we
  // must remove the window from the application. One way of doing this
  // is to hide the window.
  std::vector<Gtk::Window*> windows = get_windows();
  if (windows.size() > 0)
    windows[0]->hide(); // In this simple case, we know there is only one window.
}

void ExampleApplication::on_menu_help_about()
{
  std::cout << "App|Help|About was selected." << std::endl;
}

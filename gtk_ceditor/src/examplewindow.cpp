#include "examplewindow.h"
#include <iostream>

ExampleWindow::ExampleWindow()
: Gtk::ApplicationWindow(),
  m_Box(Gtk::ORIENTATION_VERTICAL)
{
  mCursor = 0;	

  set_title("Main menu example");
  set_default_size(300, 100);

  // ExampleApplication displays the menubar. Other stuff, such as a toolbar,
  // is put into the box.
  add(m_Box);

  // Create actions for menus and toolbars.
  // We can use add_action() because Gtk::ApplicationWindow derives from Gio::ActionMap.
  // This Action Map uses a "win." prefix for the actions.
  // Therefore, for instance, "win.copy", is used in ExampleApplication::on_startup()
  // to layout the menu.

  // Add the TreeView, inside a ScrolledWindow:
  m_ScrolledWindow.add(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  
  m_Box.pack_start(m_ScrolledWindow);
  
  // Create the Tree model:
//  m_refTreeModel = Gtk::ListStore::create(m_Columns);
//  m_TreeView.set_model(m_refTreeModel);
  m_refTreeModel = TreeModel_Dnd::create();
  m_TreeView.set_model(m_refTreeModel);

  //Enable Dtag-and-Drop of TreeView rows:
  //See also the derived TreeModel's *_vfunc overrides.
  m_TreeView.enable_model_drag_source();
  m_TreeView.enable_model_drag_dest();

  //Fill the TreeView's model
  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  row[m_refTreeModel->m_Columns.m_col_id] = 1;
  row[m_refTreeModel->m_Columns.m_col_name] = "Billy Bob";
  row[m_refTreeModel->m_Columns.m_col_number] = 10;
  row[m_refTreeModel->m_Columns.m_col_percentage] = 15;
  row[m_refTreeModel->m_Columns.m_col_draggable] = true;
  row[m_refTreeModel->m_Columns.m_col_receivesdrags] = true;
  
  row = *(m_refTreeModel->append());
  row[m_refTreeModel->m_Columns.m_col_id] = 2;
  row[m_refTreeModel->m_Columns.m_col_name] = "小笠原長数";
  row[m_refTreeModel->m_Columns.m_col_number] = 20;
  row[m_refTreeModel->m_Columns.m_col_percentage] = 30;
  row[m_refTreeModel->m_Columns.m_col_draggable] = true;
  row[m_refTreeModel->m_Columns.m_col_receivesdrags] = true;
  
  //Add the TreeView's view columns:
  //This number will be shown with the default number formatting.
  m_TreeView.append_column("ID", m_refTreeModel->m_Columns.m_col_id);
  m_TreeView.append_column("Name", m_refTreeModel->m_Columns.m_col_name);
  m_TreeView.append_column_numeric("Formatted number", m_refTreeModel->m_Columns.m_col_number,
    "%010d"); /* 10 digits, using leading zeros. */
  m_TreeView.append_column_editable("Draggable",
    m_refTreeModel->m_Columns.m_col_draggable);
  m_TreeView.append_column_editable("Receives Drags",
    m_refTreeModel->m_Columns.m_col_receivesdrags);


  // Display a progress bar instead of a decimal number:
  auto cell = Gtk::manage(new Gtk::CellRendererProgress);
  int cols_count = m_TreeView.append_column("Some percentage", *cell);
  auto pColumn = m_TreeView.get_column(cols_count - 1);
  if(pColumn)
  {
    pColumn->add_attribute(cell->property_value(), m_refTreeModel->m_Columns.m_col_percentage);
  }
  //Edit menu:
  add_action("copy", sigc::mem_fun(*this, &ExampleWindow::on_menu_others));
  add_action("paste", sigc::mem_fun(*this, &ExampleWindow::on_menu_others));
  add_action("something", sigc::mem_fun(*this, &ExampleWindow::on_menu_others));
  add_action("add", sigc::mem_fun(*this, &ExampleWindow::on_menu_edit_add));
  add_action("insert", sigc::mem_fun(*this, &ExampleWindow::on_menu_edit_ins));
  add_action("delete", sigc::mem_fun(*this, &ExampleWindow::on_menu_edit_del));

  //Choices menus, to demonstrate Radio items,
  //using our convenience methods for string and int radio values:
  m_refChoice = add_action_radio_string("choice",
    sigc::mem_fun(*this, &ExampleWindow::on_menu_choices), "a");

  m_refChoiceOther = add_action_radio_integer("choiceother",
    sigc::mem_fun(*this, &ExampleWindow::on_menu_choices_other), 1);

  m_refToggle = add_action_bool("sometoggle",
    sigc::mem_fun(*this, &ExampleWindow::on_menu_toggle), false);

  //Help menu:
  add_action("about", sigc::mem_fun(*this, &ExampleWindow::on_menu_others));

  //Create the toolbar and add it to a container widget:

  m_refBuilder = Gtk::Builder::create();

  Glib::ustring ui_info =
    "<!-- Generated with glade 3.18.3 -->"
    "<interface>"
    "  <requires lib='gtk+' version='3.4'/>"
    "  <object class='GtkToolbar' id='toolbar'>"
    "    <property name='visible'>True</property>"
    "    <property name='can_focus'>False</property>"
    "    <child>"
    "      <object class='GtkToolButton' id='toolbutton_new'>"
    "        <property name='visible'>True</property>"
    "        <property name='can_focus'>False</property>"
    "        <property name='tooltip_text' translatable='yes'>New Standard</property>"
    "        <property name='action_name'>app.newstandard</property>"
    "        <property name='icon_name'>document-new</property>"
    "      </object>"
    "      <packing>"
    "        <property name='expand'>False</property>"
    "        <property name='homogeneous'>True</property>"
    "      </packing>"
    "    </child>"
    "    <child>"
    "      <object class='GtkToolButton' id='toolbutton_quit'>"
    "        <property name='visible'>True</property>"
    "        <property name='can_focus'>False</property>"
    "        <property name='tooltip_text' translatable='yes'>Quit</property>"
    "        <property name='action_name'>app.quit</property>"
    "        <property name='icon_name'>application-exit</property>"
    "      </object>"
    "      <packing>"
    "        <property name='expand'>False</property>"
    "        <property name='homogeneous'>True</property>"
    "      </packing>"
    "    </child>"
    "  </object>"
    "</interface>";

  try
  {
    m_refBuilder->add_from_string(ui_info);
  }
  catch (const Glib::Error& ex)
  {
    std::cerr << "Building toolbar failed: " <<  ex.what();
  }

  Gtk::Toolbar* toolbar = nullptr;
  m_refBuilder->get_widget("toolbar", toolbar);
  if (!toolbar)
    g_warning("GtkToolbar not found");
  else
    m_Box.pack_start(*toolbar, Gtk::PACK_SHRINK);
}

ExampleWindow::~ExampleWindow()
{
}







//
//	追加（リストの最後に追加）
//
void ExampleWindow::on_menu_edit_add()
{
  std::cout << "Add item was selected." << std::endl;
  add_item( -1 );
  show_list();
}

//
//	挿入（指定した場所の前に挿入する）
//
void ExampleWindow::on_menu_edit_ins()
{
  std::cout << "Insert item was selected." << std::endl;
  add_item( mCursor );
  show_list();
}

/*
 *  param:挿入位置
 */
int ExampleWindow::add_item(int pos)
{
  SChar   tmpChar;
  int     rc = 0;

  if ( pos < 0 ) {
    createDefaultChar( &tmpChar );
    tmpChar.name = "add";
    mChar.push_back( tmpChar );  
  } else {
    if( mChar.size() < pos ) {
	  std::cout << "ins pos error." << std::endl;
	  rc = 1;
    } else {
      createDefaultChar( &tmpChar );
      tmpChar.name = "ins";
      mChar.insert( mChar.begin() + pos, 1, tmpChar );  	  
    }
  }
/*
  switch( com.size() ) {
    case 1:
      tmpChar.name = "";
      createDefaultChar( &tmpChar );
      mChar.push_back( tmpChar );
      break;
    case 2:
      tmpChar.name = com[ 1 ];
      createDefaultChar( &tmpChar );
      mChar.push_back( tmpChar );
      break;
    other: 
      rc = 1;
      break;
  }
*/
  return( rc );
}

/*
 *  ins,pos
 */
int ExampleWindow::ins_item(vector<string> com)
{
  SChar   tmpChar;
  int     rc = 0;
  int     no;

  if ( com.size() != 2 ) {
    rc = 1;
  } else {
    createDefaultChar( &tmpChar );
    no = atoi( com[ 1 ].c_str() );
    mChar.insert( mChar.begin() + no, tmpChar );
  }

  return( 0 );
}

//
//	削除
//
void ExampleWindow::on_menu_edit_del()
{
  std::cout << "Delete item was selected." << std::endl;	
}

/*
 *  erase
 *  erase,pos
 */
int ExampleWindow::erase_item(vector<string> com)
{
  int   rc = 0;
  int   no;

  switch( com.size() ) {
    case 1:
      if ( mChar.size() > 0 )
        mChar.erase( mChar.end() );
      else
        rc = 1;
      break;
    case 2:
      no = atoi( com[ 1 ].c_str() );
      if ( mChar.size() < no )
        rc = 1;
      else
        mChar.erase( mChar.begin() + no );
      break;
    other:
      rc = 1;
      break;
  }

	return( rc );
}


/*
 *  move,pos,pos
 */
int ExampleWindow::move_item(vector<string> com)
{
  int   rc = 0;
  int   pos1, pos2;

  if ( com.size() != 3 ) {
    rc = 1;
  } else {
    pos1 = atoi( com[ 1 ].c_str() );
    pos2 = atoi( com[ 2 ].c_str() );
  }
  return( rc );
}


int ExampleWindow::show_list()
{
  cout << "cursor is " << mCursor << endl;
  for(int i = 0; i < mChar.size(); i++) {
    cout << i << " : " << mChar[ i ].name << endl;
//    drawSChar( i );
  }
}


void ExampleWindow::createDefaultChar(SChar* c)
{
  for(int i = 0; i < 32*32; i++ )
    c->data[i] = i/4;
}



void ExampleWindow::on_menu_others()
{
  std::cout << "A menu item was selected." << std::endl;
}

void ExampleWindow::on_menu_choices(const Glib::ustring& parameter)
{
  //The radio action's state does not change automatically:
  m_refChoice->change_state(parameter);

  Glib::ustring message;
  if (parameter == "a")
    message = "Choice a was selected.";
  else
    message = "Choice b was selected.";

  std::cout << message << std::endl;
}

void ExampleWindow::on_menu_choices_other(int parameter)
{
  //The radio action's state does not change automatically:
  m_refChoiceOther->change_state(parameter);

  Glib::ustring message;
  if (parameter == 1)
    message = "Choice 1 was selected.";
  else
    message = "Choice 2 was selected.";

  std::cout << message << std::endl;
}

void ExampleWindow::on_menu_toggle()
{
  bool active = false;
  m_refToggle->get_state(active);

  //The toggle action's state does not change automatically:
  active = !active;
  m_refToggle->change_state(active);

  Glib::ustring message;
  if (active)
    message = "Toggle is active.";
  else
    message = "Toggle is not active.";

  std::cout << message << std::endl;
}

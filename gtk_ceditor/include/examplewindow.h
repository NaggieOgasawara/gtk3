#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include	<iostream>
#include	<fstream>
#include	<iomanip>
#include	<stdlib.h>
#include	<string>
#include	<ctype.h>
#include	<gtkmm.h>

#include	"CPallet.h"
#include	"SChar.h"
#include	"treemodel_dnd.h"
#include    "treeview_withpopup.h"

int const BUFSIZE = 2048;

using namespace std;

class ExampleWindow : public Gtk::ApplicationWindow
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

  int add_item(int pos);
  int ins_item(vector<string> com);
  int move_item(vector<string> com);
  int erase_item(vector<string> com);
  int show_list();

protected:
/*
  //Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns() {
      add(m_col_id);
      add(m_col_name);
      add(m_col_number);
      add(m_col_percentage);
    };
    
    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<short> m_col_number;
    Gtk::TreeModelColumn<int> m_col_percentage;
  };
  
  ModelColumns m_Columns;
*/

  //Child widgets:
//  Gtk::Box m_VBox;
  
  Gtk::ScrolledWindow m_ScrolledWindow;
//  Gtk::TreeView m_TreeView;
  TreeView_WithPopup m_TreeView;
  
  
//  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
  Glib::RefPtr<TreeModel_Dnd> m_refTreeModel;

  //Child widgets:
  Gtk::Box m_Box;

  Glib::RefPtr<Gtk::Builder> m_refBuilder;

  //Two sets of choices:
  Glib::RefPtr<Gio::SimpleAction> m_refChoice;
  Glib::RefPtr<Gio::SimpleAction> m_refChoiceOther;

  Glib::RefPtr<Gio::SimpleAction> m_refToggle;

  //Signal handlers:
  void on_menu_edit_add();
  void on_menu_edit_ins();
  void on_menu_edit_del();
  void on_menu_others();

  void on_menu_choices(const Glib::ustring& parameter);
  void on_menu_choices_other(int parameter);
  void on_menu_toggle();

private:
  string        mFileName;
  int			mCursor;
  unsigned long mPallet[256];
  bool          mDirty;
  unsigned int  mSize;
  CPallet*      mCPallet;
  ifstream      mIs;
//  ostream       mOs(mIs.rdbuf());
  vector<SChar> mChar;
  
  void  createDefaultChar(SChar* c);

  // Override default signal handler:
  
};

#endif //GTKMM_EXAMPLEWINDOW_H
